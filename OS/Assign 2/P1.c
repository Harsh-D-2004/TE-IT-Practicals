#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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

int main(int argc, char* argv[]) {

    /*if(argc < 2){
    	printf("Error in running command \n");
    	printf("Use Command :- ./myexe  Size_of_array \n");
    	return 1;
    }*/
    
    int Size = 4;
    int status = 0;
    int pid = 0;
    int pipefd[2];
    
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int Arr[Size];
    
    printf("Enter elements for child:\n");
    for (int i = 0; i < Size; i++) {
        scanf("%d", &Arr[i]);
    }
    
    pid = fork();
    
    if (pid < 0) {
        printf("Child process did not get created\n");
        exit(1);
    }
    else if (pid == 0) {
    
    	printf("------------------------------------------------------------------- \n");
        printf("Child process got created\n");
        printf("PID of child process is: %i\n", getpid());
        printf("Parent PID of child process is: %i\n", getppid());
        printf("------------------------------------------------------------------- \n");
		
		close(pipefd[1]);
		
		int receivedArr[Size];
		
		read(pipefd[0] , receivedArr , sizeof(receivedArr));
		close(pipefd[0]);
		
        char arr[Size]; 

		for (int i = 0; i < Size; i++)
		{
		    arr[i] = receivedArr[i];
		}
		
		char *newargv[] = {NULL , arr , NULL};
    	newargv[0] = argv[1];
    	char *newenviron[] = {NULL};
    	
    	printf("Control passed to another program");
        
        execve(argv[1], newargv, newenviron);
         
        printf("Execve system call failed");
        
        exit(EXIT_FAILURE);
    }
    else{
    
		printf("------------------------------------------------------------------- \n");
        printf("Parent process got created\n");
        printf("PID of parent process is: %i\n", getpid());
        printf("Parent PID of parent process is: %i\n", getppid());
        printf("------------------------------------------------------------------- \n");

        BubbleSort(Arr, Size);
        
        printf("Sorted Array by Parent:\n");
        for (int i = 0; i < Size; i++) {
            printf("%d\n", Arr[i]);
    	}
    	
    	write(pipefd[1] , Arr , sizeof(Arr));
    	close(pipefd[1]);
		
		wait(NULL);
    	
    }

    /*free(Arr);*/
    
    return 0;
}

