#ifndef __MEMDBSERVER__
#define __MEMDBSERVER__

#include <iostream>
#include <cstring>
#include <random>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <list>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include "memdb.cpp"
#include "commandTool.cpp"

using namespace std;

int sockfd = -1;
int epfd = -1;
list<int> FullConnQueue;
list<int> SemiConnQueue;
memdb db;


int startup(int port);
int handleConnection(int sockfd);

int startup(int port = 1736)
{
	int serverfd = 0, option;
	struct sockaddr_in name;
	serverfd = socket(PF_INET, SOCK_STREAM, 0);
	if (serverfd == -1) {
		perror("socket"); //连接失败
        return -1;
    }
	socklen_t optlen;
	optlen = sizeof(option);
	option = 1;
	//快速启动
	setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR, (void *)&option, optlen);

	memset(&name, 0, sizeof(name));
	name.sin_family = AF_INET;
	name.sin_port = htons(port);
	name.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serverfd, (struct sockaddr *)&name, sizeof(name)) < 0) {
		perror("bind"); //绑定失败
        return -1;
    }
	 if (port == 0 )  /*动态分配一个端口 */
	 {
		socklen_t namelen = sizeof(name);
		if (getsockname(serverfd, (struct sockaddr *)&name, &namelen) == -1) {
			perror("getsockname");
            return -1;
        }
		port = ntohs(name.sin_port);
	 }

	 if (listen(serverfd, 5000) < 0) {
	    perror("listen");
        return -1;
     }
     sockfd = serverfd;
	 cout<<"port:"<<port<<endl;
	 return(serverfd);
}

int handleConnection(int sockfd) {
    struct sockaddr_in clienaddr;
    socklen_t addrlen = sizeof(clienaddr);
    int clientfd = -1;
    while(1) {

        clientfd = accept(sockfd,(sockaddr *)&clienaddr,&addrlen);
        if(clientfd == -1) {
            perror("accept");
            continue;
        }
        FullConnQueue.push_back(clientfd);
		cout<<"connected :"<<inet_ntoa(clienaddr.sin_addr)<<endl;
    }
}
int handleCommand( ) {

	int nfds;
	struct epoll_event ev, events[20];
	ev.data.fd = 1;
	ev.events = EPOLLIN ; 

	epfd = epoll_create(5);
	char buf[BUFSIZ];
	while (1)
	{
        if(!FullConnQueue.empty()) {
                ev.data.fd = FullConnQueue.front();
				ev.events = EPOLLIN;
				epoll_ctl(epfd, EPOLL_CTL_ADD, ev.data.fd, &ev);
                FullConnQueue.pop_front();
        }
		nfds = epoll_wait(epfd, events, 200, 100);
		for (int i = 0; i < nfds; i++)
		{
			if (events[i].events & EPOLLIN) 
			{
                int len = BUFSIZ;
				int ref = recv( events[i].data.fd,buf,len,0);
				buf[ref] = '\0';
				cout<<buf<<endl;
				string res;
				vector<string> cmds;
				commandTool::Stringsplit(buf,' ',cmds);
				if(cmds[0] == "add" && cmds.size() >= 3) {
					db.insert_string(cmds[1],cmds[2]);
					res = string("ok!");
				} else if(cmds[0] == "get" && cmds.size() >= 2){
					db.getStringforkey(res,cmds[1]);
				} else if(cmds[0] == "del" && cmds.size() >= 2) {
					db.delete_key(cmds[1]);
					res = string("ok!");
				} else if(cmds[0] == "zadd" && cmds.size() >= 4) {
					db.insert_skiplist(cmds[1],cmds[2],cmds[3]);
					res = string("ok!");
				} else if(cmds[0] == "zget" && cmds.size() >= 2){
					db.getElementforSkiplist(res,cmds[1]);
				} else if(cmds[0] == "zdel" && cmds.size() >= 3) {
					db.delElementforSkiplist(res,cmds[1],cmds[2]);
					
				} else {
					res = string("命令错误\0");
				}
				
				send(events[i].data.fd,const_cast<char*>(res.data()),res.size(),0);
				res = "";
				if(ref == 0) {
					close(events[i].data.fd);
					epoll_ctl(epfd,EPOLL_CTL_DEL,events[i].data.fd,&ev);
				}
			}
		}
	}
}
int setnonblocking(int fd)
{

	int old_option = fcntl(fd, F_GETFL);
	int new_option = old_option | O_NONBLOCK;
	fcntl(fd, F_SETFL, new_option);
	return old_option;
}

int main(int argc, char *argv[]) {
    
    startup(1736);
    cout<<"server startup success"<<endl;
    thread hconn(&handleConnection,sockfd);
    thread hcomm(&handleCommand);
    cout<<"server run!"<<endl;
	hconn.join();
	hcomm.join();
	cout<<"server close!"<<endl;
    return 0;
}


#endif