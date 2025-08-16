#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("let's grab a salad\n");
    fflush(stdout); 

    sleep(5); 

    printf("here it is\n");

    return 0;
}