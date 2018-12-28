//测试文件
#define __LIBRARY__
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
_syscall1(int,iam,const char*,name)
/*系统调用的方式之一：使用_syscall宏
2.6.18版本之前的内核，在include/asm-i386/unistd.h文件中定义有7个_syscall宏，分别是：
_syscall0(type,name)
_syscall1(type,name,type1,arg1)
_syscall2(type,name,type1,arg1,type2,arg2)
_syscall3(type,name,type1,arg1,type2,arg2,type3,arg3)
_syscall4(type,name,type1,arg1,type2,arg2,type3, arg3,type4,arg4)
_syscall5(type,name,type1,arg1,type2,arg2,type3, arg3,type4,arg4,type5,arg5)
_syscall6(type,name,type1,arg1,type2,arg2,type3, arg3,type4,arg4,type5,arg5,type6,arg6)
其中，type表示所生成系统调用的返回值类型，name表示该系统调用的名称，typeN、argN分别表示第N个参数的类型和名称，它们的数目和_syscall后面的数字一样大。
这些宏的作用是创建名为name的函数，_syscall后面跟的数字指明了该函数的参数的个数。*/

int main(int argc,char* argv[])
{
    if(argc>1)
    {
        if(iam(argv[1])<0)
        {
            printf("SystemCall Exception!\n");
            return -1;
        }
    }
    else
    {
        printf("Input Exception!\n");
        return -1;
    }
    return 0;
}
