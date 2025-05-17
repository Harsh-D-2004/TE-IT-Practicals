
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void reverseArray(char Arr[]){

	int Size = 4; 
	
	for(int i = Size - 1 ; i>=0 ; i--){
		printf("%d \t" , Arr[i]);
	}
	
	printf("\n");

}

int main(int argc , char * argv[]){
	
	printf("Control in second program \n");
	
	reverseArray(argv[1]);
	
	printf("Array reversed \n");
	
	printf("Exited successfully \n");
	
	exit(0);

}
