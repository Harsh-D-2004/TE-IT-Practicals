
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void reverseArray(char Arr[]){

	int Size = 4;
	
	printf("Reversed Array....... \n");
	
	for(int i = Size - 1 ; i >= 0 ; i--){
		printf("%d ", Arr[i]);
		printf("\n");
	}
	
	printf("\n");
	
}

int main(int argc, char *argv[])
{	
	printf("Inside Different program \n");	
	
	reverseArray(argv[1]);
	
	printf("Exited from other program \n");
	
	exit(EXIT_SUCCESS);
	
}
