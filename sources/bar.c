#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  

/*
	Progress bar with time
*/
int bar_print(int time, int bar_len){

	printf("\033[900B");
	for(int j=0;j<bar_len;j++){

 		printf("\033[43m%3d%%\033[0m", (int)(((float)(j+1)/ bar_len) * 100));
		for(int i=0;i<j;i++){
			 printf("\033[41m#\033[0m");
		}
		for(int i=0;i<bar_len-j;i++){
			printf("\033[41m \033[0m");
		}

		usleep((time * 1000000) / bar_len);

		if(j == bar_len-1) return 0;

		// ritorna all’inizio della riga
		printf("\r");
		fflush(stdout);

	}
	

}

/*
	Progress bar with percentage
*/
int bar_print_per(int bar_len, int perc){

	int stat = (perc * bar_len) / 100;

	system("clear");
	printf("\033[900B");
	printf("\033[43m%3d%%\033[0m", perc);

	for(int i=0;i<stat;i++){
		 printf("\033[41m#\033[0m");
	}
	for(int i=0;i<bar_len-stat;i++){
		printf("\033[41m \033[0m");
	}

	printf("\r");
	printf("\033[H");
	fflush(stdout);


}


int main(int argc, char *argv[]) {

	int bar_len = 35;
	int perc;

	if (argc > 1) {
		perc = atoi(argv[1]);
	} else {
		printf("%% not passed");
		return 1;
	}

	bar_print_per(bar_len, perc);
	return 0;

}
