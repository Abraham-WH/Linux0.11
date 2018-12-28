//Linux0.11内核--内核空间、用户空间之间的数据传输
#define __LIBRARY__
#include <unistd.h>
#include <errno.h>
#include <asm/segment.h>

char temp[64]= {0};

int sys_iam(const char* name)
{
    int i=0;
    /*  get_fs_byte(addr)
        功能：从用户空间中addr地址处取出一个字节读入内存
        参数：addr	 用户空间中的逻辑地址
        返回：fs:[addr]处的一个字节内容*/
    while((temp[i]=get_fs_byte(name+i))!='\0')
    {
        i++;
        if(i>23)
        {
            break;
            return -EINVAL;
        }
    }
    printk("The string has been read into kernel,the length is :%d\n",i);
    return i;
}

int sys_whoami(char* name,unsigned int size)
{
    int i=0;
    while(temp[i]!='\0')
    {
        //pur_fs_byte(addr, user_addr)
        //从内存入读用户空间地址（内核到用户）
        put_fs_byte(temp[i],(name+i));
        i++;
    }
    i--;
    if (size<i)
        return -1;
    return i;
}
