#include "include_std.h"
bool existfile(char* filename,int mode){
	FILE *fileit;
	fileit=fopen(filename,"r");
	if(fileit==NULL){
		if(mode==2){
			fileit=fopen(filename,"w");
			fclose(fileit);
		}
		return 0;
   	}else{
   		return 1;
   	}
}

char* read_from_file(char* filename,int maxword){
	char* ret= new char[maxword];
	ifstream read_file;
	read_file.open(filename);
	read_file>>ret;
	read_file.close();
	
	//char* ret= new char[maxword];
	//FILE *readfile=fopen(filename,"r");
	//fread(ret,maxword,1,readfile);
	//fclose(readfile);
	return ret;
}
