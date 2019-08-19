NamePipeLib
供不能直接读写linux管道文件的语言调用

编译环境
linux
g++ 使用-std=c++11声明使用C++11规范进行编译
g++ PipeWriter.cpp PipeWrapper.cpp -std=c++11 -fPIC -shared -o libpipe.so

使用环境
linux(x64 )

若需要在x86环境下使用需重新编译生成.so文件

###########目录结构描述 │
├─bin 二进制文件 │ └─linux │ └─x64 │ libpipe.so │
└─src 源码 PipeWrapper.cpp PipeWrapper.hpp PipeWriter.cpp PipeWriter.hpp

V1.0 仅打开管道文件及写入数据

V1.01队列为空时加入等待时间10ms
