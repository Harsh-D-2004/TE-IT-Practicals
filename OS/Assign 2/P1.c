#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void BubbleSort(int Arr[], int Size) {
    int temp = 0;
    
    for (int i = 0; i < Size; i++) {
        for (int j = i + 1; j < Size; j++) {
            if (Arr[j] < Arr[i]) {
                temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }
        }
    }
}

int main(int argc , char * argv[]){
	
	int Size = 4;
	
	int Arr[Size];
	
	printf("Enter the elements : \n");
	
	for(int i = 0 ; i < Size ; i++){
		scanf("%d" , &Arr[i]);
	}
	
	int pid = 0;
	
	BubbleSort(Arr , Size);
	
	
	pid = fork();
	
	if(pid < 0){
		printf("Child process did not get created \n");
		return -1;
	}
	else if(pid == 0){
	
		char newArr[Size];
		
		for(int i = 0 ; i < Size ; i++){
			newArr[i] = Arr[i];
		}
		
		char * newargv[] = {NULL , newArr , NULL};
		newargv[0] = argv[1];
		char * newenviron[] = {NULL};
		
		printf("Control passed \n");
		
		execve(argv[1] , newargv , newenviron);
		
		printf("Execve failed \n");
		
		exit(1);
	}
	
	return 0;
}
