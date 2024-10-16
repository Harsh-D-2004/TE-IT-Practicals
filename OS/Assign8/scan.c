#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
	
		
	int size_of_disk = 0;
	int initial_head = 0;
	int index = 0;
	int direction = 0;
	int n = 0;
	int temp = 0;
	int total_movement = 0;
	int i = 0;
	
	printf("Enter the size of disk : \n");
	scanf("%d" , &size_of_disk);
	
	printf("Enter the no of requests : \n");
	scanf("%d" , &n);
	
	int req[n];
	
	printf("Enter the requests : \n");
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d" , &req[i]);
	}
	
	printf("Enter the initial head position: \n");
	scanf("%d" , &initial_head );
	
	printf("Enter the direction of traversal (0 : lower and 1 : higher): \n");
	scanf("%d" , &direction );
	
	for(int i = 0 ; i < n-1 ; i++){
		temp = 0;
		for(int j = 0 ; j < n-i-1 ; j++){
			
			if(req[j] > req[j+1]){
				temp = req[j];
				req[j] = req[j+1];
				req[j+1] = temp;
			}
		}
	}
	
	for(int i = 0 ; i< n ; i++){
		if(initial_head < req[i]){
			index = i;
			break;
		}
	}
	
	printf("Index : %d \n" , index);
	
	if(direction == 1){
		for(i = index ; i < n ; i++){
			total_movement = total_movement + abs(req[i] - initial_head);
			initial_head = req[i];
			printf("%d \t" , initial_head);
		}
		total_movement = total_movement + abs(size_of_disk - 1 - initial_head);
		initial_head = size_of_disk - 1;
		printf("%d \t" , initial_head);
		for(i = index - 1 ; i >= 0 ; i--){
			total_movement = total_movement + abs(initial_head - req[i]);
			initial_head = req[i];
			printf("%d \t" , initial_head);
		}
		
	}else{
		for(i = index - 1 ; i >= 0 ; i--){
			total_movement = total_movement + abs(initial_head - req[i]);
			initial_head = req[i];
			printf("%d \t" , initial_head);
		}
		total_movement = total_movement + abs(initial_head - 0);
		initial_head = 0;
		printf("%d \t" , initial_head);
		for(i = index ; i < n ; i++){
			total_movement = total_movement + abs(req[i] - initial_head);
			initial_head = req[i];
			printf("%d \t" , initial_head);
		}	
	}
	
	printf("\n");
	
	printf("Total movement covered : %d \n" , total_movement);

	return 0;
	
}
