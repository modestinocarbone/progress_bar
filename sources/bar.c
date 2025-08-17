#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  

struct Color {
    int black;
    int red;
    int green;
    int orange;
    int blue;
    int magenta;
};
struct Color color = {40, 41, 42, 43, 44, 45};

/*
	Timed Progress bar 
*/
int bar_print(int time, int bar_len, int col){

	printf("\033[900B");
	for(int j=0;j<bar_len;j++){

 		printf("\033[43m%3d%%\033[0m", (int)(((float)(j+1)/ bar_len) * 100));
		for(int i=0;i<j;i++){
			 printf("\033[%dm#\033[0m", col);
		}
		for(int i=0;i<bar_len-j;i++){
			printf("\033[%dm \033[0m", col);
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
int bar_print_per(int bar_len, int perc, int col){

	int stat = (perc * bar_len) / 100;

	system("clear");
	printf("\033[900B");
	printf("\033[43m%3d%%\033[0m", perc);

	for(int i=0;i<stat;i++){
		 printf("\033[%dm#\033[0m", col);
	}
	for(int i=0;i<bar_len-stat;i++){
		printf("\033[%dm \033[0m", col);
	}

	printf("\r");
	printf("\033[H");
	fflush(stdout);


}


int main(int argc, char *argv[]) {

	int bar_len = 65;
	int val;

	if (argc > 1) {
		val = atoi(argv[1]);
	} else {
		printf("%% not passed");
		return 1;
	}
	   

	// bar_print(val, bar_len, color.green););
	bar_print_per(bar_len, val, color.green);

	return 0;

}
