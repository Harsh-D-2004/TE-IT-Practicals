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

void InsertionSort(int Arr[], int Size) {
    int i, key, j;
    
    for (i = 1; i < Size; i++) {
        key = Arr[i];
        j = i - 1;
        
        while (j >= 0 && Arr[j] > key) {
            Arr[j + 1] = Arr[j];
            j = j - 1;
        }
        Arr[j + 1] = key;
    }
}

int main(int argc, char* argv[]) {

    if(argc < 2){
    	printf("Error in running command \n");
    	printf("Use Command :- ./myexe Size_of_array \n");
    	return 1;
    }
    
    int Size = atoi(argv[1]);
    int status = 0;
    int pid = 0;
    
    int *Brr = (int *)malloc(Size * sizeof(int));
    int *Arr = (int *)malloc(Size * sizeof(int));
    
    printf("Enter elements for child:\n");
    for (int i = 0; i < Size; i++) {
        scanf("%d", &Arr[i]);
    }
    
    printf("Enter elements for parent:\n");
    for (int i = 0; i < Size; i++) {
        scanf("%d", &Brr[i]);
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
        
        BubbleSort(Arr, Size);
        
        printf("Sorted Array by Child:\n");
        for (int i = 0; i < Size; i++) {
            printf("%d\n", Arr[i]);
        }
        
        printf("Child Process exited\n");
        
        exit(0);
    }
    else if (pid > 0) {
    	printf("------------------------------------------------------------------- \n");
        printf("Parent process got created\n");
        printf("PID of parent process is: %i\n", getpid());
        printf("Parent PID of parent process is: %i\n", getppid());
        printf("------------------------------------------------------------------- \n");
        
        //sleep(10);
        
        InsertionSort(Brr, Size);
        
        printf("Sorted Array by Parent:\n");
        for (int i = 0; i < Size; i++) {
            printf("%d\n", Brr[i]);
        }
        
        //printf("child process is zombie process");
        
        printf("Parent process exited\n");
        
        //wait(&status);
        
        exit(0);
    }
    
    free(Brr);
    free(Arr);
    
    return 0;
}

