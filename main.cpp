#include "lib/include_std.h"
#include "lib/bootloader.h"
#include "lib/system.h"
//#include "lib/include_all.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	if(bootstart()){
		sys_main(argc,argv);
	}
	return 0;
}
