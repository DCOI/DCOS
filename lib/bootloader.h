//#include<synchapi.h> 
#include <windows.h>
//#include<synchapi.h> 
#include <windows.h>
#include "screen.h"
#include "file.h" 
#include "define.h" 
#include <dir.h> 
#include "host_system.h" 
#include "lang.h" 
bool ex_lang_cn_ini;
bool ex_lang_en_ini;
bool ex_lang_fr_ini;
bool ex_lang_jp_ini;
bool ex_lang_ot_ini;

bool install_sys(){
	int install_state;
	bool acc=0;
	cls();
	//getch();
	pr("------------------------------------------");
	pr("1.中文(默认) 2.English(没有) 3.France(没有) 4.Japanese(没有)");
	int inputlang;
	cin>>inputlang;
	screen_info("安装程序正在启动...",150);
	existfile(f_lang_cn_ini,2);
	outlangfile();
	initlang(1);
	//pr("安装程序正在启动...");
	Sleep(1500);
	//int acres=MessageBox(NULL,"欢迎使用DCOS 2015!\n hehe...","DCOS 2015 使用条款",MB_YESNO|MB_ICONINFORMATION);
	//switch(acres){
	//	case IDNO:MessageBox(NULL,TEXT("再见"),TEXT("NO"),MB_OK);break;
    //	case IDYES:acc=1;break;
	//}
	cout<<endl;
	pr("请输入DCOS 激活密钥(若不输入或无效，则不能启用更多功能):");
	char incdkey[MAXWD];
	cin>>incdkey;
	FILE *keyfile=fopen("key.dat","w");
	fprintf(keyfile,incdkey);
	fclose(keyfile);
	cls();
	acc=1;
	if(acc){
		screen_info("配置中...",50);
		install_state=1;
	}else{
		install_state=0;
	}
	cls();
	return install_state;
	//getch();
} 

void verdir(){
	mkdir("ext");
	mkdir("system");
	mkdir("root");
	mkdir("lang");
}

int bootstart(){
    Sleep(500);
	pr("==DCOS Bootloader 0.1 Beta==");
	pr("检查配置中...");
	pr(GetVersionInfoer());
	winversion();
	Sleep(500);
	pr("检查完毕");
	pr("检查文件中...");
	verdir();
    if(existfile(f_extlist_ini,1)){
    	pr("拓展文件列表存在，加载中..."); 
    }else{
    	pr("拓展文件列表不存在，拓展功能不可用...");
    }
    if(existfile(f_lang_cn_ini,1)){
		ex_lang_cn_ini=1;
	}  
    if(existfile(f_lang_fr_ini,1)){
		ex_lang_fr_ini=1;
	}  	
    if(existfile(f_lang_jp_ini,1)){
		ex_lang_jp_ini=1;
	}  
    if(existfile(f_lang_ot_ini,1)){
		ex_lang_ot_ini=1;
	}  
	Sleep(500);
	pr("检查完毕,按任意键继续...");
	Sleep(500);
	getch();
	if(existfile(f_temp_dat,1)==0){
		if(install_sys()){
			return 2;
		}else{
			return 0;
		}
	}
	//getch();    
	//char** inputset;
    //char sysinput;
    system("cls");
	return 1;
 }

