#ifndef __COMMANDTOOL__
#define __COMMANDTOOL__

#include <vector>
#include <cstring>
#include <sstream>
using namespace std;
class commandTool
{
public:
	static commandTool* Instance()
	{
		return &m_instance;
	}
    static void Stringsplit(string str, const char split,vector<string>& res);
private:
	commandTool(){};
	commandTool(commandTool const&) = delete;
	commandTool& operator=(commandTool const&) = delete;
	static commandTool m_instance;
};
commandTool commandTool::m_instance;

void commandTool::Stringsplit(string str, const char split,vector<string>& res)
    {
        istringstream iss(str);	// 输入流
        string token;			// 接收缓冲区
        while (getline(iss, token, split))	// 以split为分隔符
        {
            if(token == "")continue;
            res.push_back(token);
        }
    }

#endif
