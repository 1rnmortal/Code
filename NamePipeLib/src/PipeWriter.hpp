#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<iostream>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<queue>
#include<thread>
#define BUF_SIZE 256
struct LogMsg
{
    char content[BUF_SIZE];
    int size;
};
class PipeWriter
{
    private:
        char* _path;
        void WriteLoop();
        int fd ;
        std::queue<LogMsg> sendList;
    public:
        bool SendMsg(char* msg);
        bool init(char* path) ;
};
