//Linux0.11�ں�--�ں˿ռ䡢�û��ռ�֮������ݴ���
#define __LIBRARY__
#include <unistd.h>
#include <errno.h>
#include <asm/segment.h>

char temp[64]= {0};

int sys_iam(const char* name)
{
    int i=0;
    /*  get_fs_byte(addr)
        ���ܣ����û��ռ���addr��ַ��ȡ��һ���ֽڶ����ڴ�
        ������addr	 �û��ռ��е��߼���ַ
        ���أ�fs:[addr]����һ���ֽ�����*/
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
        //���ڴ�����û��ռ��ַ���ں˵��û���
        put_fs_byte(temp[i],(name+i));
        i++;
    }
    i--;
    if (size<i)
        return -1;
    return i;
}
