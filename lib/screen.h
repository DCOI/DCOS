#include "include_std.h"
#include "color.h"
using namespace std;
int sys_main(char argc,char* argv[]);
void pr(char* word){
	cout<<word<<endl;
}

void pr(string word){
	cout<<word<<endl;
}

void logoview(){
	system("cls");
	colors.white();
	cout<<"DDDDDDDDDD            CCCCCCCC        OOOOOO          SSSSSSSSS  "<<endl;
	cout<<"DDDDDDDDDDDD        CCCCCCCCCCC     OOOOOOOOOO       SSSSSSSSSSS   "<<endl;                                                              
  	cout<<"DDD      DDDD      CCCC      CC    OOOO    OOOO     SSS       SS"<<endl;
  	cout<<"DDD       DDDD    CCC             OOOO      OOOO   SSS          "<<endl;
  	cout<<"DDD        DDD   CCC              OOO        OOO   SSS           "<<endl;
  	cout<<"DDD         DDD  CCC             OOO          OOO  SSS            "<<endl;
  	cout<<"DDD         DDD CCC              OOO          OOO  SSSSS          "<<endl;
  	cout<<"DDD         DDD CCC              OOO          OOO   SSSSSS        "<<endl;
  	cout<<"DDD         DDD CCC              OOO          OOO    SSSSSSSS     "<<endl;
  	cout<<"DDD         DDD CCC              OOO          OOO       SSSSSSS   "<<endl;
  	cout<<"DDD         DDD CCC              OOO          OOO          SSSSS  "<<endl;
  	cout<<"DDD         DDD CCC              OOO          OOO            SSSS "<<endl;
  	cout<<"DDD        DDD   CCC             OOO          OOO             SSS "<<endl;
  	cout<<"DDD        DDD   CCCC             OOO        OOO              SSS "<<endl;
	cout<<"DDD       DDD     CCCC            OOOO      OOOO              SSS "<<endl;
	cout<<"DDD     DDDDD      CCCC      CC    OOOO    OOOO    SSS      SSSS  "<<endl;
	cout<<"DDDDDDDDDDD         CCCCCCCCCCC     OOOOOOOOOO     SSSSSSSSSSSS   "<<endl;
	cout<<"DDDDDDDDD             CCCCCCCC        OOOOOO         SSSSSSSS     "<<endl;
	Sleep(3000);
	system("cls");
}

void screen_info(char* message,int timer){
	system("cls");
	colors.white();
	cout<<"--------------------------------------------------------------------------------";
	cout<<endl;
	colors.green();
	cout<<"               "<<message<<"             "<<endl;
	cout<<endl;
	colors.pink();
	for(int i=1;i<=140;i+=5){
		Sleep(timer);
		cout<<"。";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);	
}

void cls(){
	system("cls");
}
