#ifndef MEMDBCLIENT
#define MEMDBCLIENT

#include <iostream>
#include <string.h>
#include <random>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <fcntl.h>
using namespace std;

class memdbClient
{
public:
    int id;
    char name[20];
    string host;
    int port;
    int serverfd = -1;

public:
    memdbClient(/* args */);
    ~memdbClient();
    int connection(char *host, int port);
    int ping();
    int sendCommand(char *com);
};

memdbClient::memdbClient(/* args */)
{
    id = gethostid();
    gethostname(name, 100);
}

memdbClient::~memdbClient()
{
    if(serverfd != -1)
        close(serverfd);
}

int memdbClient::connection(char *host, int port) {
    int serv_sock = -1;
    serv_sock =  socket(PF_INET,SOCK_STREAM,0);
    if(serv_sock == -1) {
        perror("socket");
        return -1;
    }
    
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET,host,&servaddr.sin_addr);
    servaddr.sin_port = htons(port);

    if(connect(serv_sock,(const sockaddr*)&servaddr,sizeof(servaddr)) < 0) {
        perror("connect server");
        return -1;
    }
    serverfd = serv_sock;
    return 0;

}
int memdbClient::sendCommand(char *command) 
{
    int ref = send(serverfd,command,strlen(command),0);
    if(ref == 0) {
        close(serverfd);
    } else if(ref == -1) {
        perror("send command");
        return -1;
    }
    return 0;
}
int memdbClient::ping() {
    if(serverfd < 0) {
        printf("There is no connection to the server\n");
        return -1;
    }
}

#endif

int main()
{
    memdbClient client;
    client.connection("10.211.55.3",1736);
    char buf[BUFSIZ];
    while(1) {
        cin.getline(buf,BUFSIZ-1);
        client.sendCommand(buf);
        int ref = recv(client.serverfd,buf,BUFSIZ,0);
        buf[ref] = '\0';
        cout<<buf<<endl;
    }
    return 0;
}