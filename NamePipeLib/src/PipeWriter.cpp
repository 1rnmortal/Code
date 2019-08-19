#include "PipeWriter.hpp"
#include <iostream>
#include <cstdlib>
 bool PipeWriter::SendMsg(char* msg)
{
    LogMsg temp;
    temp.size = strlen(msg)+1;
    if (temp.size >= BUF_SIZE)
    {
        printf("Glog error:msg is  too long\n");
        return false;
    }
    strncpy(temp.content,msg,temp.size);
    sendList.push(temp);
    return true;
}


bool PipeWriter::init(char* path)
{

    if(access(path,0)!= 0)
    {
        if ((mkfifo(path, O_CREAT | O_EXCL |O_RDWR) < 0) && (errno != EEXIST))
        {
            perror("can not creat fifoserver");
            exit(1);
        }
    }
    fd = open(path, O_WRONLY | O_NONBLOCK,0);
    if (fd == -1)
    {
        perror("open error;no reading process");
        exit(1);
    }
    std::thread td(&PipeWriter::WriteLoop,this);
    td.detach();
    return true;
}
void PipeWriter::WriteLoop()
{
    while(1)
    {
        while(!sendList.empty())
        {
            LogMsg msg = sendList.front();
            int size = write(fd,msg.content,msg.size);
            sendList.pop();
        }
        sleep(10);
    }
}
