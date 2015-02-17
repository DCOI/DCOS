//#include "include_all.h"
#include "include_std.h"
#include "fuck.h"
#include "sec.h"
//#include "screen.h"
using namespace std;
time_t nowtime;    
int pwdtime=0;
char realway[MAXWD];
char userway[MAXWD];
int permissionid=0;
char nowpermission[10];
struct setplugin{
	bool startani=1;
	bool debugmode=0;
};
void notexist();
void setoperate(int input);
struct showsysdo{
	void a(){
		system("cls"); 
		colors.white();
		cout<<"---------------------------------------------------------------------------"<<endl;
		colors.green();
		cout<<"                      -----------系统设置------------                      "<<endl;
		for (int k=1;k<=3;k++){
			cout<<endl;
		}	
		cout<<"a.关机"<<"  "<<"b.更改密码"<<"  "<<"c.初始化"<<"  "<<"e.返回"<<endl;
		colors.pure();
		cout<<"当前不可用的命令:"<<"  "<<"d.关机（高级）"<<"  "<<"f.权限设置"<<endl;
		colors.green();
		setoperate(1);
	}
	void b(){
		system("cls"); 
		colors.white();
		cout<<"---------------------------------------------------------------------------"<<endl;
		colors.green();
		cout<<"                      -----------系统设置------------                      "<<endl;
		for (int k=1;k<=3;k++){
			cout<<endl;
		}	
		cout<<"a.关机"<<"  "<<"b.更改密码"<<"  "<<"c.初始化"<<"  "<<"d.关机（高级）"<<"  "<<"e.返回"<<endl;
		colors.pure();
		cout<<"当前不可用的命令:"<<"  "<<"f.权限设置"<<endl;
		colors.green();
		setoperate(2);
	}
	void c(){
		system("cls"); 
		colors.white();
		cout<<"---------------------------------------------------------------------------"<<endl;
		colors.green();
		cout<<"                      -----------系统设置------------                      "<<endl;
		for (int k=1;k<=3;k++){
			cout<<endl;
		}	
		cout<<"a.关机"<<"  "<<"b.更改密码"<<"  "<<"c.初始化"<<"  "<<"d.关机（高级）"<<endl;
		cout<<"f.权限设置"<<"  "<<"e.返回"<<endl;
		colors.green();
		setoperate(3);
	}
	void d(){
		system("cls"); 
		colors.white();
		cout<<"---------------------------------------------------------------------------"<<endl;
		colors.green();
		cout<<"                      -----------系统设置------------                      "<<endl;
		for (int k=1;k<=3;k++){
			cout<<endl;
		}	
		cout<<"a.关机"<<"  "<<"b.更改密码"<<"  "<<"c.初始化"<<"  "<<"d.关机（高级）"<<endl;
		cout<<"f.权限设置"<<"  "<<"e.返回"<<endl;
		colors.green();
		setoperate(3);
	}
	void al(){
		system("cls"); 
		colors.white();
		cout<<"---------------------------------------------------------------------------"<<endl;
		colors.green();
		cout<<"                      -----------系统设置------------                      "<<endl;
		for (int k=1;k<=3;k++){
			cout<<endl;
		}	
		cout<<"你是root权限用户，所有功能都完全开放，小心使用！"<<endl; 
		cout<<"a.关机"<<"  "<<"b.更改密码"<<"  "<<"c.初始化"<<"  "<<"d.关机（高级）"<<endl;
		cout<<"f.权限设置"<<"  "<<"e.返回"<<endl;
		colors.green();
		setoperate(3);
	}
};
struct showsysdo showsys;
struct setplugin settinga;
/*struct UserFile{       
	int fnum;//文件编号 
	char fname[20];  //文件名 
	int flength;     //文件长度 
	char flag;       //标志 
	char fpw[20];   //文件保护码 
	struct UserFile *link;
};*/ 
/*
#define FOREGROUND_BLUE      0x0001 // text color contains blue.
#define FOREGROUND_GREEN     0x0002 // text color contains green.
#define FOREGROUND_RED       0x0004 // text color contains red.
#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
#define BACKGROUND_BLUE      0x0010 // background color contains blue.
#define BACKGROUND_GREEN     0x0020 // background color contains green.
#define BACKGROUND_RED       0x0040 // background color contains red.
#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.
*/
int DecryptFile(FILE *sfp,FILE *dfp,char pwd){
	char ch;
	while((ch=fgetc(sfp))!=EOF){
		if((ch>='a')&&(ch<='z')){
			ch=ch^pwd;
			ch=(ch-'a'+25)%26+'a';
		}
		if((ch>='A')&&(ch<='Z')){
			ch=ch^pwd;
			ch=(ch-'A'+25)%26+'A';
		}
		//fputc(ch,dfp);
	}
}
void filemanroot(){
	system("cls");
	colors.white();
	cout<<"--------------------------------------------------------------------------------"<<endl;
	colors.green();
	cout<<"                   "<<"DCOS 文件管理器(root权限版)"<<"                            "<<endl;
	cout<<endl;
	cout<<"        你的根目录为: "<<"./"<<endl; 
	char dir[MAXWD]="dir ";
	char tempp[MAXWD]=" >";
	strcat(tempp,userway);
	//cout<<"tempp="<<tempp<<endl;
	char usl[MAXWD]="file.list";
	//strcat(dir,userway);
	strcat(dir,tempp);
	strcat(dir,usl);
	//cout<<dir<<endl;
	system(dir);
	//system("pause");
	filesystemview();
	char dellist[MAXWD]="del ";
	strcat(dellist,userway);
	strcat(dellist,usl);
	//cout<<dellist<<endl;
	system(dellist);
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"        o.打开文件  d.删除文件  c.创建文件  e.返回"<<endl;
	int fileinput=inputcomm();
	switch(fileinput){
		case 10:{
			fileopne();
			break;
		}
		case 8: {
			fileopne();
			break;
		}
		case 14: {
			fileopne();
			break;
		}
		case 9: {
			startscreen(); 
			break;
		}
	}	
}
void clrmode(){
	system("cls");
	startscreen();
}
void fileman(){
	system("cls");
	colors.white();
	cout<<"--------------------------------------------------------------------------------"<<endl;
	colors.green();
	cout<<"                         "<<"DCOS 文件管理器"<<"                            "<<endl;
	cout<<endl;
	cout<<"        你的根目录为: "<<fileuser<<endl; 
	char dir[MAXWD]="dir ";
	char tempp[MAXWD]=" >";
	strcat(tempp,userway);
	//cout<<"tempp="<<tempp<<endl;
	char usl[MAXWD]="file.list";
	strcat(dir,userway);
	strcat(dir,tempp);
	strcat(dir,usl);
	//cout<<dir<<endl;
	system(dir);
	//system("pause");
	filesystemview();
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<"        o.打开文件  d.删除文件  c.创建文件  e.返回"<<endl;
	int fileinput=inputcomm();
	switch(fileinput){
		case 10:{
			fileopne();
			break;
		}
		case 8: {
			fileopne();
			break;
		}
		case 14: {
			fileopne();
			break;
		}
		case 9: {
			startscreen(); 
			break;
		}
	}
	//inputfile();////////////////////////////////////////////	
}
void changepwdr(char* inputp){
	FILE *pwdin;
	pwdin=fopen("passwd.dat","w");
	fprintf(pwdin,inputp);
	fclose(pwdin);
	restarting();
} 
void restarting(){
	system("cls");
	colors.white();
	cout<<"--------------------------------------------------------------------------------";
	cout<<endl;
	colors.green();
	cout<<"               "<<"重启系统，正在保存文件。。。。"<<"             "<<endl;
	cout<<endl;
	colors.pink();
	for(int i=1;i<=140;i+=5){
		//Sleep(200);
		Sleep(100);
		cout<<"。";
	}
	colors.pure();
	system("cls");
	reload();
}
void filesystemview(){
	char ttemmp[MAXWD];
	strcpy(ttemmp,fileuser);
	char fileo[MAXWD]="file.list";
	strcat(ttemmp,fileo);
	ifstream fin(ttemmp);
	for(string str;getline(fin,str);)//getline()逐行读取文本    
		cout<<str<<endl;
	//cout<<ttemmp<<endl;
	//system("pause");
}
void verpwd(){
	char inputcommand[MAXWD];
	cout<<fileuser<<",请输入你的原密码:"; 
	//cout<<nowpermission<<"]： ";
	cin>>inputcommand;
	//FILE *openpwd;
	//openpwd=fopen("passwd.dat","r");
	//char filepass[MAXWD];
	//fread(filepass,20,1,openpwd);
	//fclose(openpwd);
	if(strcmp(inputcommand,nowpwd)==0){
		system("cls");
		colors.pure();
		cout<<"--------------------------------------------------------------------------------";
		cout<<endl;
		colors.green();
		cout<<"               "<<"密码正确"<<"             "<<endl;
		cout<<"                  请输入新密码:";
		char npd[MAXWD];
		cin>>npd;
		cout<<"                  处理中。。。。:"<<endl;
		cout<<endl;
		for(int i=1;i<=140;i+=5){
			Sleep(100);
			cout<<"。";
		}
		colors.pure();
		system("cls");
		changepwdr(npd);
	}
	else {
		system("cls");
		colors.white();
		cout<<"--------------------------------------------------------------------------------";
		cout<<endl;
		colors.red();
		cout<<"               "<<"密码错误，将会返回"<<"             "<<endl;
		cout<<endl;
		Sleep(2000); 
		system("cls");
		systemdoview(permissionid);
	} 
}
void shutdnlipro(){
	system("shutdown -s -t 30");
}
bool pdperm(int tarper){
	if(permissionid==tarper){
		return 1;
	}
	else return 0;
}
int yesornot(){
	int pd=inputcomm();
	if(pd==11){
		return 1;
	}
	else return 0;
}
void shutdownliteview(){
	system("cls");
	colors.white();
	cout<<"--------------------------------------------------------------------------------";
	cout<<endl;
	cout<<endl;
	colors.qin();
	cout<<"你确定要关闭系统?"<<endl;
	cout<<"输入y.确认，键入其他返回:";
	int jg=yesornot();
	if(jg==1){
		shutdnlipro();
	} 
	else {
		system("cls");
		systemdoview(permissionid);
	}
} 
void startfuckpingce(){
	system("cls");
	colors.white();
	cout<<"--------------------------------------------------------------------------------";
	cout<<endl;
	colors.qin();
	cout<<"                       评测征服者 8.4 Beta 自动版(DCOS预装)"<<endl;
	cout<<endl;
	cout<<"        评测征服者,或称自动AC机,是MrYang发布的自动AC程序,小心使用,后果自负"<<endl;
	cout<<"输入y.确认进入，键入其他返回:"<<endl;
	int jg=yesornot();
	if(jg==1){
		fuckpingceset(permissionid);
	} 
	else {
		system("cls");
		startscreen();
	}
}
void permnoteno(int pid){
	system("cls");
	colors.white();
	cout<<"--------------------------------------------------------------------------------";
	cout<<endl;
	colors.red(); 
	cout<<"               "<<"权限不足，将会返回"<<"             "<<endl;
	colors.qin();
	cout<<"    你的权限为：";
	colors.pink();
	switch(permissionid){
		case 0:{
			cout<<permission0;
			break;
		}
		case 1:{
			cout<<permission1;
			break;
		}
		case 2:{
			cout<<permission2;
			break;
		}
		case 3:{
			cout<<permission3;
			break;
		}
		case 4:{
			cout<<permission4;
			break;
		}
		case 5:{
			cout<<permission5;
			break;
		}
	}
	colors.qin();
	cout<<"权限,不能完成此操作，请申请提权！"; 
	cout<<endl;
	Sleep(2000); 
	system("cls");
	startscreen();
}
bool inputpwd(char* correct){
	char* inputpwd;
	cout<<"        请输入密码: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	inputpwd=secinput("请输入密码: ",MAXWD);
	round_crypt_1(inputpwd);
	if(strcmp(inputpwd,correct)==0){
		return 1;
	}
	else return 0;
}
void checkpasswd(){
	bool check=inputpwd(nowpwd);
	if(check==0){
		if(pwdtime<2){
			pwdtime++;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"        密码错误，请重新输入！"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
			checkpasswd();
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"        非法进入，系统即将退出！"<<endl;
			Sleep(1000); 
			exit(1);
		}
	} 	
}
void startscreen(){
	system("cls");
	//logoview();
	startscreenview();
}
void OutputFile(FILE *fp){
	char ch;
	while((ch=fgetc(fp))!=EOF){
		putchar(ch);
	}
}
int EncryptFile(FILE *sfp,FILE *dfp,char pwd){
	char ch;
	if(sfp==0||dfp==0){
		return 0;
	} 
	while((ch=fgetc(sfp))!=EOF){
		if((ch>='a')&&(ch<='z')){
			ch=(ch-'a'+1)%26+'a';
			ch=ch^pwd;
		} 
		if((ch>='A')&&(ch<='Z')){
			ch=(ch-'A'+1)%26+'A';
			ch=ch^pwd;
		}
	//fputc(ch,dfp);
	}
}
void inputpasswd(){
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
	cout<<"--------------------------------------------------------------------------------";
	cout<<endl;
	colors.green();
	cout<<"                         ------"<<"用户登录"<<"------                          "<<endl;
	cout<<endl;
	cout<<"        你作为";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	cout<<fileuser;
	colors.green();
	cout<<"用户登录"<<endl;
	//cout<<nowpwd<<endl;
	//cout<<"        请输入密码: ";
	checkpasswd();
	/*if(check==0){
		if(pwdtime<2){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"密码错误，请重新输入！"<<endl;
			colors.green();
			bool check=inputpwd(nowpwd);
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"非法进入，系统即将退出！"<<endl;
			Sleep(1000); 
			exit(1);
		}
	} */
}
void changepwdshow(){
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
	cout<<"--------------------------------------------------------------------------------";
	cout<<endl;
	colors.green();
	cout<<"                         ------"<<"更改密码"<<"------                          "<<endl;
	cout<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	cout<<"      更改你的密码：你需要先输入你原来的密码，y.确认，其他字符.退出"<<endl;
	cout<<endl;
	int yesdata=yesornot();
	if(yesdata==1){
		verpwd();
	} 
	else systemdoview(permissionid);
}
void setoperate(int input){
	int back=inputcomm();
	switch(back){
		case 5: {
			shutdownliteview();
			break;
		}
		case 6: {
			changepwdshow();
			break;
		}
		case 8: {
			setnotexist();
			break;
		}
		case 9: {
			system("cls");
			startscreen();
			break;
		}
		case 10: {//2
			if(permissionid<2){
				colors.red();
				cout<<"你的权限不足"<<endl;
				setoperate(permissionid);
				colors.green();
			}
			setnotexist();
			break;
		}
		case 13: {//3
			if(permissionid<3){
				colors.red();
				cout<<"你的权限不足"<<endl;
				setoperate(permissionid);
				colors.green();
			}
			setnotexist();
			break;
		}
		case 1: {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"非法操作，请检查命令是否正确！"<<endl; 
			colors.green();
			setoperate(permissionid);
		}			
		default: {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"非法操作，请检查命令是否正确！"<<endl; 
			colors.green();
			setoperate(permissionid);
		} 
	}
}
int inputroot(){
	char* inputcommand;
	cout<<fileuser<<"@localhost[当前权限:";
	switch(permissionid){
		case 0:{
			cout<<permission0<<"]： ";
			break;
		}
		case 1:{
			cout<<permission1<<"]： ";
			break;
		}
		case 2:{
			cout<<permission2<<"]： ";
			break;
		}
		case 3:{
			cout<<permission3<<"]： ";
			break;
		}
		case 4:{
			cout<<permission4<<"]： ";
			break;
		}
		case 5:{
			cout<<permission5<<"]： ";
			break;
		}
	}
	//cout<<nowpermission<<"]： ";
	inputcommand=secinput("请输入密码: ",MAXWD);
	if(strlen(inputcommand)==1){
		system("cls");
		startscreen();
	}
	else {
		if(strcmp(inputcommand,rootkey)==0){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
			cout<<"--------------------------------------------------------------------------------";
			cout<<endl;
			colors.green();
			cout<<"               "<<"密钥有效，正在配置中"<<"             "<<endl;
			cout<<endl;
			for(int i=1;i<=140;i+=5){
				Sleep(100);
				cout<<"。";
			}
			strcpy(nowpermission,permission5);
			permissionid=5;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
			system("cls");
			startscreen();	
		}
		else {
			system("cls");
			colors.white();
			cout<<"--------------------------------------------------------------------------------";
			cout<<endl;
			colors.red();
			cout<<"               "<<"密钥无效，将会返回"<<"             "<<endl;
			cout<<endl;
			Sleep(2000); 
			system("cls");
			startscreen();
		} 
	}
}
void alreadyroot(){
	system("cls");
	colors.white();
	cout<<"--------------------------------------------------------------------------------";
	cout<<endl;
	colors.red();
	cout<<"               "<<"已经Root，将会返回"<<"             "<<endl;
	cout<<endl;
	Sleep(2000); 
	system("cls");
	startscreen();
}
void systemdoview(int pid){
	switch(permissionid){
		case 0:{
			permnoteno(permissionid);
			break;
		}
		case 1:{
			showsys.a();
			break;
		}
		case 2:{
			showsys.b();
			break;
		}
		case 3:{
			showsys.c();
			break;
		}
		case 4:{
			showsys.d();
			break;
		}
		case 5:{
			showsys.al();
			break;
		}
	}
}
void exitsystem(){
	system("cls");
	colors.white();
	cout<<"--------------------------------------------------------------------------------";
	cout<<endl;
	colors.green();
	cout<<"               "<<"关闭系统，正在保存文件。。。。"<<"             "<<endl;
	cout<<endl;
	colors.pink();
	for(int i=1;i<=140;i+=5){
		//Sleep(200);
		Sleep(100);
		cout<<"。";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);	
}
void indexoperate(){
	int back=inputcomm();
	if(back==4 && permissionid==5){
		back=1;
	}
	switch(back){
		case 0: {
			helpscreen();
			break;
		}
		case 3: {
			if(permissionid!=5){
				fileman();
			}
			else{
				filemanroot();
			}
			break;
		}
		case 2: {
			notexist();
			break;
		}
		case 9:	{
			exitsystem();
			break;
		}
		case 4: {
			getrootper();
			break;
		}
		case 8:	{
			clrmode();
			break; 
		}
		case 7: {
			systemdoview(permissionid);
			break;
		}
		case 13: {
			startfuckpingce();
			break;
		} 
			//system("cls");
			//startview();
		case 1: {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"非法操作，请检查命令是否正确！"<<endl; 
			colors.green();
			indexoperate();
		}			
		/*default: {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"非法操作，请检查命令是否正确！"<<endl; 
			colors.green();
			indexoperate();
		}*/ 
	}
}
void newsetpasswd(){
	char* passwd;
	cout<<endl;
	cout<<"        请输入密码:";
	passwd=secinput("请输入密码: ",MAXWD); 
	round_crypt_1(passwd);
	FILE *pwdfile;
	pwdfile=fopen("passwd.dat","w");
	fprintf(pwdfile,passwd);
	fclose(pwdfile); 
}
void getrootper(){
	if(permissionid==5){
		alreadyroot();
	}
	else{
		int getkey;
		system("cls");
		colors.green();
		cout<<"---------------------------------------------------------------------------"<<endl;
		cout<<"---------------------------------获得最高权限------------------------------";
		cout<<endl;
		cout<<"     root是本系统的最高权限用户"<<endl;
		cout<<"     目前版本需要输入密钥来激活"<<endl;
		cout<<endl;
		cout<<endl;	
		cout<<"          输入单个字符以返回"<<endl;	
		cout<<"          请输入激活权限密钥，回车确定:"<<endl; 
		inputroot();		
	}

}
void helpscreen(){
	system("cls");
	colors.green();
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"-----------------------------------使用帮助--------------------------------";
	cout<<endl;
	cout<<"     DCOS,是Mr.Yang设计的中文操作系统,目前设计有的功能有:"<<endl;
	cout<<"          1.用户名登陆"<<endl;
	cout<<"          2.打开，编辑文件"<<endl;
	cout<<"          3.查看帮助"<<endl;
	cout<<"          4.文件管理"<<endl;
	cout<<"          5.其他到时候再说"<<endl;
	cout<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
	cout<<"                                              e.返回"<<endl;
	cout<<endl;
	colors.green();
	putitexit();
}
int inputcomm(){
	char inputcommand[MAXWD];
	//string inputcommand;
	cout<<fileuser<<"@localhost[当前权限:";
	switch(permissionid){
		case 0:{
			cout<<permission0<<"]： ";
			break;
		}
		case 1:{
			cout<<permission1<<"]： ";
			break;
		}
		case 2:{
			cout<<permission2<<"]： ";
			break;
		}
		case 3:{
			cout<<permission3<<"]： ";
			break;
		}
		case 4:{
			cout<<permission4<<"]： ";
			break;
		}
		case 5:{
			cout<<permission5<<"]： ";
			break;
		}
	}
	cin>>inputcommand;
	//getline(cin,inputcommand);
	/*switch(inputcommand){
		case 'm': return 3;
		case 'h': return 0; 
		case 'e': return 9;
		case 'w': return 2; 
		case 'c': return 8; 		
	}*/
	if(strlen(inputcommand)==1){
		//cout<<inputcommand[0]<<endl;
		//system("pause");
		switch(inputcommand[0]){
			case 'm': return 3;
			case 'h': return 0; 
			case 'e': return 9;
			case 'w': return 2; 
			case 'c': return 8;
			case 'r': return 4; 
			case 's': return 7;
			case 'a': return 5;
			case 'b': return 6;
			case 'd': return 10;
			case 'y': return 11;
			case 'n': return 12;
			case 'f': return 13;
			case 'o': return 14;
			default: return 1;
		}
	}
	else return 1;
}
void startscreenview(){
	nowtime=time(NULL);
	colors.green();
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"    欢迎进入DCOS！！  现在时间为:"<<ctime(&nowtime)<<"    版本号: "<<versionseen;
	if(_Preview_){
		cout<<" 内部测试版本号 "<<_VERSION_IN_<<endl; 
	}else{
		cout<<endl;
	}
	cout<<"    你的工作目录为"<<userway<<endl;
	for (int k=1;k<=3;k++){
		cout<<endl;
	}	
	cout<<"h.查看帮助"<<"  "<<"w.写入文件"<<"  "<<"m.文件管理"<<"  "<<"c.清屏"<<"  "<<"e.退出"<<endl;
	if(permissionid == 5){
		cout<<"s.系统选项"<<"  "<<"f.fuck评测制作"<<endl;
	}
	else{
		cout<<"r.获取最高权限"<<"  "<<"s.系统选项"<<"  "<<"f.fuck评测制作"<<endl;	
	}
	
	//int back=inputcomm();
	indexoperate();
	/*switch(back){
		//case 0: helpscreen();
		case 3: notexist();
		default: {
			cout<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"     "<<"非法操作，请检查命令是否正确！"<<endl; 
			colors.green();
		};
	}*/
}
void setexit(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
	int received=inputcomm();
	if(received==9){
		system("cls");
		startscreen();
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		cout<<"非法操作，请检查命令是否正确！"<<endl; 
		colors.green();
		cout<<endl;
		setexit();
	}
}
void setback(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
	int received=inputcomm();
	if(received==9){
		system("cls");
		systemdoview(permissionid);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		cout<<"非法操作，请检查命令是否正确！"<<endl; 
		colors.green();
		cout<<endl;
		setback();
	}
}
void putitexit_to_manage(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
	int received=inputcomm();
	if(received==9){
		system("cls");
		systemdoview(permissionid);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		cout<<"非法操作，请检查命令是否正确！"<<endl; 
		colors.green();
		cout<<endl;
		putitexit_to_manage();
	}
}
void putitexit(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
	int received=inputcomm();
	if(received==9){
		system("cls");
		startscreen();
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		cout<<"非法操作，请检查命令是否正确！"<<endl; 
		colors.green();
		cout<<endl;
		putitexit();
	}
}
void fileopne(){
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	cout<<"---------------------------------------------------------------------------"<<endl;
	for (int i=1;i<=5;i++){
		cout<<endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
	cout<<"                     "<<"该功能还未完成! e.返回"<<"    "<<endl;
	putitexit_to_manage();	
}
void notexist(){
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	cout<<"---------------------------------------------------------------------------"<<endl;
	for (int i=1;i<=5;i++){
		cout<<endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
	cout<<"                     "<<"该功能还未完成! e.返回"<<"    "<<endl;
	putitexit();
} 
void setnotexist(){
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	cout<<"---------------------------------------------------------------------------"<<endl;
	for (int i=1;i<=5;i++){
		cout<<endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
	cout<<"                     "<<"该功能还未完成! e.返回"<<"    "<<endl;
	setback();
} 
void startcheck(){
	char getcheck;
	char* settfile;
	FILE *startfile;
	FILE *userindex;
	FILE *setfile;
	FILE *pwdfile;
	FILE *permfile;
	startfile=fopen("temp.dat","r");
	if(startfile==NULL){
	//getcheck=fgetc(startfile);
	//if(getcheck==EOF)
		startfile=fopen("temp.dat","w");
		fclose(startfile);
		cout<<"---------------------------------------------------------------------------"<<endl;
		for (int i=1;i<=5;i++){
			cout<<endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
		cout<<"               "<<"检测到你是第一次启动，正在配置文件"<<"             "<<endl;
		cout<<"            ";
		colors.green();
		for(int i=1;i<=100;i+=5){
			//Sleep(200);
			Sleep(100);
			cout<<"。";
		}
		fclose(startfile);
		startfile=fopen("temp.dat","w");
		cout<<endl;
		cout<<endl;
		cout<<"        输入你的用户名：";
		cin>>username;
		fprintf(startfile,username);
		fclose(startfile); 
		permfile=fopen("perm.dat","w");
		char newperm[2]="0";
		fprintf(permfile,newperm);
		fclose(permfile);
		newsetpasswd();
		Sleep(2000);
		//fread(fileuser,20,1,startfile);
		//fgets(fileuser,20,startfile);
		fclose(startfile);
		mkdir(username);
		//cout<<fileuser<<endl;
		//system("pause");
		setfile=fopen("setting.ini","w");
		fprintf(setfile,"1");
		fclose(setfile);
		char indexname[MAXWD]="\\hello.txt";
		char tempchar[MAXWD]=".\\"; 
		strcat(tempchar,username);
		strcat(tempchar,indexname);
		//cout<<tempchar<<endl;
		userindex=fopen(tempchar,"w");
		char hellomess[MAXWD]="Hello,DCOS";
		fprintf(userindex,hellomess);
		fclose(userindex);
		//system("pause");
	}
	//pwdfile=fopen("passwd.dat","r");
	//fread(nowpwd,20,1,pwdfile);
	//fclose(pwdfile);
	nowpwd=read_from_file("passwd.dat",MAXWD);
	//setfile=fopen("setting.ini","r");
	//startfile=fopen("temp.dat","r");
	//fread(settfile,MAXWD,1,setfile);
	//fread(fileuser,MAXWD,1,startfile);
	//fclose(setfile);
	//fclose(startfile);
	//settfile=fgetc(setfile);
	settfile=read_from_file("setting.ini",MAXWD);
	fileuser=read_from_file("temp.dat",MAXWD);
	if(settfile[0]=='0'){
		settinga.startani=0;
	}
	
	
	//permfile=fopen("perm.dat","r");
	char* tempperm;
	//fread(tempperm,MAXWD,1,permfile);
	tempperm=read_from_file("perm.dat",MAXWD);
	permissionid=atoi(tempperm);
	if(permissionid==5){
		permissionid=0;
	} 
	//FILE *keyreadfile=fopen("key.dat","r");
	char nowkey[MAXWD];
	ifstream inkey;
	inkey.open("key.dat");
	inkey>>nowkey;
	inkey.close();
	//fread(nowkey,MAXWD,1,keyreadfile);
	//fclose(keyreadfile);
	if(strcmp(nowkey,cdkey)!=0){
		permissionid=0;
	}
	fclose(permfile);	
	switch(permissionid){
		case 0: {
			strcpy(nowpermission,permission0);
			break;
		}
	}
	char ttemp[20]="\\";
	strcat(ttemp,fileuser);
	getcwd(realway,MAXWD);
	strcpy(userway,realway);
	strcat(userway,ttemp);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
	//pr(nowkey);
	//system("pause");
} 

void startview(){
	colors.green();
	cout<<"---------------------------------------------------------------------------"<<endl;
	for (int i=1;i<=5;i++){
		cout<<endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
}
void startprogram(){
	inputpasswd(); 
	if(settinga.startani){	
		for (int i=1;i<=100;i++){
			system("cls");
			startview();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);
			cout<<"                                 加载中:"<<i<<"%"<<endl;
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
			startview();
			Sleep(100);
		}
	}
}
void reload(){
	startcheck();
	system("cls");
	startprogram();
	Sleep(1000);
	system("cls");
	logoview();
	startscreen();
} 
int sys_main(char argc,char* argv[]){
	startcheck();
	system("cls");
	startprogram();
	Sleep(1000);
	system("cls");
	logoview();
	startscreen();
} 
