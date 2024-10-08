#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h> 

void BubbleSort(int Arr[] , int Size)
{	
	int temp = 0;
	
	for(int i = 0 ; i < Size ; i++)
	{
		for(int j = i+1 ; j < Size ; j++)
		{
			if(Arr[j] < Arr[i])
			{
				temp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = temp;
			}
		}
	}
}

void InsertionSort(int Arr[] , int Size)
{
	int i = 0;
	int key = 0;
	int j = 0;
	
	for(i = 1 ; i < Size ; i++)
	{
		key = Arr[i];
		j = i - 1;
		
		while( j >= 0 && Arr[j] > key)
		{
			Arr[j+1] = Arr[j];
			j = j - 1;
		}
		Arr[j+1] = key;
	}
}



int main()
{	
	int Size = 4;
	int status = 0;
	
	int pid = 0;
	
	pid = fork();
	
	if(pid < 0)
	{
		printf("Child process did not get created \n");
		
		exit(0);
	}
	else if(pid == 0)
	{
		printf("Child process got created \n");
		printf("PID of child process is : %i, \n" , getpid());
		printf("Parent PID of child process is : %i, \n" , getppid());
		
		int Arr[4] = {89 , 44 , 10 , 33};
	
		BubbleSort(Arr , 4);
		
		for(int i = 0 ; i < Size ; i++)
		{
			printf(" %i" , Arr[i]);
			printf("\n");
		}
		
		printf("\n");
		
		exit(42);
	}
	else if(pid > 0)
	{
		printf("Parent process got created \n");
		printf("PID of  parent process is : %i , \n" , getpid());
		printf("Parent PID of parent process is : %i, \n" , getppid());
		
		wait(&status);
		
		if(WIFEXITED(status)){
			printf("Child process exired with status : %d\n" , WEXITSTATUS(status));
		}

		int Brr[4] = {84 , 41 , 11 , 30};
	
		InsertionSort(Brr , Size);
		
		for(int i = 0 ; i < Size ; i++)
		{
			printf(" %i" , Brr[i]);
			printf("\n");
		}
		
		printf("Parent process exited \n");
		exit(0);
	}
	
	return 0;
}
