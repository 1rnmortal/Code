#include "PipeWrapper.hpp"
#include <cstdio>
namespace PipeLibWrapper
{
    PipeWriter* pObj = new PipeWriter();
    bool  writeIntoPipe(char* msg)
    {
        if (NULL != pObj)
            return pObj->SendMsg(msg);
    }
    bool  initPipe(char* path)
    {
        std::cout<< path<<std::endl;
        if (NULL != pObj)
        {
            return pObj->init(path);
        }
        else
        {
            printf("obj is null ");
            
        }
    }

}
