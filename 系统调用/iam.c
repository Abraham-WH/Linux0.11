//�����ļ�
#define __LIBRARY__
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
_syscall1(int,iam,const char*,name)
/*ϵͳ���õķ�ʽ֮һ��ʹ��_syscall��
2.6.18�汾֮ǰ���ںˣ���include/asm-i386/unistd.h�ļ��ж�����7��_syscall�꣬�ֱ��ǣ�
_syscall0(type,name)
_syscall1(type,name,type1,arg1)
_syscall2(type,name,type1,arg1,type2,arg2)
_syscall3(type,name,type1,arg1,type2,arg2,type3,arg3)
_syscall4(type,name,type1,arg1,type2,arg2,type3, arg3,type4,arg4)
_syscall5(type,name,type1,arg1,type2,arg2,type3, arg3,type4,arg4,type5,arg5)
_syscall6(type,name,type1,arg1,type2,arg2,type3, arg3,type4,arg4,type5,arg5,type6,arg6)
���У�type��ʾ������ϵͳ���õķ���ֵ���ͣ�name��ʾ��ϵͳ���õ����ƣ�typeN��argN�ֱ��ʾ��N�����������ͺ����ƣ����ǵ���Ŀ��_syscall���������һ����
��Щ��������Ǵ�����Ϊname�ĺ�����_syscall�����������ָ���˸ú����Ĳ����ĸ�����*/

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
