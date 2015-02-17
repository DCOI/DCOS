char eng_permission0[10]="基本";
char eng_permission1[10]="高级用户";
char eng_permission2[10]="管理员"; 
char eng_permission3[10]="高级管理";
char eng_permission4[10]="系统";
char eng_permission5[10]="root";
char chi_permission0[10]="基本";
char chi_permission1[10]="高级用户";
char chi_permission2[10]="管理员"; 
char chi_permission3[10]="高级管理";
char chi_permission4[10]="系统";
char chi_permission5[10]="root";
char permission0[10];
char permission1[10];
char permission2[10]; 
char permission3[10];
char permission4[10];
char permission5[10];

void outlangfile(){
	ofstream fout;
	fout.open("lang/lang_cn.ini");
	fout<<"基本"<<endl<<"高级用户"<<endl<<"管理员"<<endl<<"高级管理"<<endl<<"系统"<<endl<<"root"<<endl;
	fout.close();
}
void initlang(int langid){
	if(langid==1){
		ifstream read_file;
		read_file.open("lang/lang_cn.ini");
		read_file>>permission0>>permission1>>permission2>>permission3>>permission4>>permission5;
		read_file.close();
	}else if(langid==2){
		ifstream read_file;
		read_file.open("lang/lang_en.ini");
		read_file>>permission0>>permission1>>permission2>>permission3>>permission4>>permission5;
		read_file.close();		
	}else{
		ifstream read_file;
		read_file.open("lang/lang_cn.ini");
		read_file>>permission0>>permission1>>permission2>>permission3>>permission4>>permission5;
		read_file.close();		
	}
}
