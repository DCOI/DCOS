#include "include_std.h"
using namespace std;

void fuckpingceset(int perm){
	system("cls");
	switch(perm){
		case 0:{
			system("cls");
			colors.white();
			cout<<"--------------------------------------------------------------------------------";
			cout<<endl;
			colors.red();
			cout<<"               "<<"权限不足，将会返回"<<"             "<<endl;
			cout<<endl;
			Sleep(2000); 
			system("cls");
			startscreen();
			break;
		}
		default: {
			for (int i=1;i<=100;i++){
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
				cout<<"                                 生成中:"<<i<<"%"<<endl;
				colors.qin();			
				cout<<"              ";
				for (int j=1;j<=i;j+=4){
					cout<<"--";
				} 
				cout<<endl;
				cout<<"              ";
				for (int j=1;j<=i;j+=4){
					cout<<"--";
				}
				for (int k=1;k<=5;k++){
					cout<<endl;
				}
				Sleep(100);
			}
			outfuck();			
		}
	}
}

void outfuck(){
	char tempfileloc[50];//临时文件存储位置，推荐选一个隐蔽的地点
	char outname[50];//输出的文件名 
	int maxleng=1024;//最大长度 
	char proname[50];//将xxx改为题目名 
	int maxtime=10;//最大测试点号 
	int firsttime=1;//第一个测试点号 
	char outputdataname[50];
	cout<<"输入临时文件存储位置，推荐选一个隐蔽的地点(详细地址，杠要两个->  \\  )：";
	cin>>tempfileloc; 
	cout<<"输入cpp文件名：";
	cin>>outname;
	cout<<"输入第一个测试点号: ";
	cin>>firsttime; 
	cout<<"输入最大测试点号: ";
	cin>>maxtime;
	cout<<"输入题目名: ";
	cin>>proname;
	cout<<"输入答案最大长度: ";
	cin>>maxleng;
	cout<<"输入题目要求输出的文件名：";
	cin>>outputdataname;
	char gang[10]="//";
	char cppname[50]=".//";
	strcat(cppname,fileuser);
	strcat(cppname,gang);
	strcat(cppname,outname);
	cout<<"写入"<<cppname<<endl;
	ofstream fout;
	fout.open(cppname);		
	fout<<"//---------------DC 330 自动解答代码--------请谨慎使用------------ "<<endl;
	fout<<"#include <stdio.h>"<<endl;
	fout<<"#include <string.h>"<<endl;
	fout<<"#include <stdlib.h>"<<endl;
	fout<<"#include <iostream>"<<endl;
	fout<<"#include <fstream>"<<endl;	
	fout<<"using namespace std;"<<endl;
	fout<<"//-------------------手动设置部分------------------------"<<endl;
	fout<<"char TempFileLocation[50]=\""<<tempfileloc<<"\";//临时文件存储位置，推荐选一个隐蔽的地点"<<endl;
	fout<<"char OutPutFileName[50]=\""<<outputdataname<<"\";//输出的文件名 "<<endl;
	fout<<"int length="<<maxleng<<";//最大长度 "<<endl;
	fout<<"char name1[99]=\".."<<"\\\\data"<<"\\\\"<<proname<<"\\\\"<<proname<<"\";//将xxx改为题目名 "<<endl;
	fout<<"int Maxinp="<<maxtime<<";//最大测试点号 "<<endl;
	fout<<"int num="<<firsttime<<";//第一个测试点号 "<<endl;
	fout<<"//--------------以下内容推荐不要修改 --------------------  "<<endl;
	fout<<"char ch,namemid[2],name2[99]=\".out\",tempn;"<<endl;
	fout<<"void dataset(){//获取当前测试点 "<<endl;
	fout<<"	FILE *fp1;//临时文件 "<<endl;
	fout<<"	fp1=fopen(TempFileLocation,\"r\");//打开临时文件 "<<endl;
	fout<<"	if(fp1==NULL){//若不存在，说明第一次测试 "<<endl;
	fout<<"		ofstream fout;//创建 "<<endl;
	fout<<"		fout.open(TempFileLocation); "<<endl;
	fout<<"		fout<<2;//保存下一个测试点 "<<endl;
	fout<<"		fout.close();"<<endl;
	fout<<"		num=1;"<<endl;
	fout<<"	}"<<endl;
	fout<<"	else{//若已存在 "<<endl;
	fout<<"		freopen(TempFileLocation,\"r\",stdin);//打开文件 "<<endl;
	fout<<"		cin>>num;//提取当前测试点 "<<endl;
	fout<<"		fclose(stdin);"<<endl;
	fout<<"		if(num==Maxinp){//如果超出max测试点就会崩溃，所以要归零 "<<endl;
	fout<<"			freopen(TempFileLocation,\"w\",stdout);"<<endl;
	fout<<"			cout<<1;//初始化（留给子孙用） "<<endl;
	fout<<"			fclose(stdout);"<<endl;
	fout<<"		}"<<endl;
	fout<<"		else{"<<endl;
	fout<<"			freopen(TempFileLocation,\"w\",stdout);"<<endl;
	fout<<"			cout<<num+1;//保存下一个测试点 "<<endl;
	fout<<"			fclose(stdout);"<<endl;
	fout<<"		} "<<endl;
	fout<<"	}"<<endl;
	fout<<"}"<<endl;
	fout<<"int main(){	"<<endl;
	fout<<"	dataset();//测试点识别 "<<endl;
	fout<<"	sprintf(namemid,\"%d\",num);//转换当前测试点到char型"<<endl; 
	fout<<"	strcat(name1,namemid);//连接目录名与测试点名 "<<endl;
	fout<<"	strcat(name1,name2);//连接目录名+测试点名与后缀名 "<<endl;
	fout<<"	FILE *fp;"<<endl;
	fout<<"	fp=fopen(name1,\"r\");//打开目标输出文件 "<<endl;
	fout<<"	freopen(OutPutFileName,\"w\",stdout);	 "<<endl;
	fout<<"	while(!feof(fp)){"<<endl;
	fout<<"		char str[length];//若答案很大，请增大str值 "<<endl;
	fout<<"		char *p;"<<endl;
	fout<<"		if(fgets(str,sizeof(str),fp)==NULL) break; "<<endl;
	fout<<"		p=strtok(str,\" \");"<<endl;
	fout<<"		while(p){"<<endl;
	fout<<"			printf(\"%d \",atoi(p));"<<endl;
	fout<<"			p=strtok(NULL,\" \");"<<endl;
	fout<<"		}"<<endl;
	fout<<"		cout<<endl;"<<endl;
	fout<<"	}//以上是提取文件步骤 "<<endl;
	fout<<"	fclose(stdout);"<<endl;
	fout<<"	fclose(fp);"<<endl;
	fout<<"	return 0;"<<endl;
	fout<<"}"<<endl;
				
	fout.close();
	cout<<endl;
	cout<<"加载完成,文件"<<cppname<<"已生成在你的目录下！"<<endl;
	Sleep(1000);
	startscreen();
}
