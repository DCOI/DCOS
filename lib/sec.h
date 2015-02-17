#include<iostream>
#include <conio.h>
using namespace std;
char* secinput(char* info,int maxlength){
	char* password;
	password = new char[maxlength + 1];
	char* p = NULL;	
	int count = 0;
	cout << "请输入密码,以$号结束: ";
	p = password;
	count = 0;
	while ((*p = getch()) != '$') {
		putch('*');
        fflush(stdin);
        p++;
        count++;
    } 
    password[count] = '\0';
    cout<<endl;
    return password;
}


void round_crypt_1(char* ip)//加密函数
{   
//int sys_round_crypt_key_1[]={3,7,8,2,9,5,4};
int i=0;
while(*ip!=NULL)
{

*ip+=sys_round_crypt_key_1[i%7];
if(*ip>122)
*ip=*ip%122+32;
//cout<<*ip;
i++,ip++;
}
//cout<<endl<<"\07";//响铃，可以不要
}

void round_decrypt_1(char* id)//解密函数
{
//int b[]={3,7,8,2,9,5,4};
int i=0;
while(*id!=NULL)
{

*id-=sys_round_crypt_key_1[i%7];
if(*id<32)
*id=*id-32+122;
//cout<<*id;
i++,id++;
}
//cout<<endl<<"\07";//响铃，可以不要

}
