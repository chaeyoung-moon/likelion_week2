#include "gis.h"

int getGIS(char* filename, struct coordinate* a, struct coordinate* b);
void convertDMS(struct coordinate* a, struct coordinate* b, int);
void displayDis(struct coordinate* a, struct coordinate* b, int);

struct coordinate a[100];
struct coordinate b[100];

int main(int argc, char* argv[]) {

	if(argc != 3){
		return 1;
	}

	void* handle;
	void (*displayDis)(struct coordinate*,struct coordinate*, int );
	int length = getGIS(argv[1], a, b);
	
	if (!strcmp(argv[2],"euc")){
        	handle= dlopen("./libeuc.so",RTLD_LAZY);
    	}
	else if (!strcmp(argv[2],"man")){
        	handle= dlopen("./libman.so",RTLD_LAZY);
   	}
    	else{
		return 2;
    	}
    	if (!handle) {
		fprintf(stderr, "Error: %s\n", dlerror());
		return EXIT_FAILURE;
	}

	*(void**)(&displayDis) = dlsym(handle,"displayDis");
	convertDMS(a, b, length);
	displayDis(a, b, length);
	dlclose(handle);
	return 0;
}
