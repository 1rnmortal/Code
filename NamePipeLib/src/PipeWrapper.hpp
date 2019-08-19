#pragma once 
#include "PipeWriter.hpp"
namespace PipeLibWrapper
{
    extern "C"  bool   writeIntoPipe(char* msg);
    extern "C" bool  initPipe(char* path) ;

}
