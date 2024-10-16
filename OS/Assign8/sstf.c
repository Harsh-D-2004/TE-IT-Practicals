#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int find_min_index(int req_queue[] , int visited[] , int head_pos , int n){

	int min = INT_MAX;
	int index = -1;
	
	for(int i = 0 ; i < n ; i++){
		if(!visited[i] && abs(head_pos - req_queue[i]) < min){
			index = i;
			min = abs(head_pos - req_queue[i]);
		}
	}
	
	return index;
}


void sstf(int req_queue[] , int visited[] , int head_pos , int n){
	
	int min_index = 0;
	int no_of_headcounts = 0;
	
	
	for(int i = 0 ; i<n; i++){
	
		min_index = find_min_index(req_queue , visited , head_pos , n);
		visited[min_index] = 1;
		no_of_headcounts = no_of_headcounts + abs(head_pos - req_queue[min_index]);
		head_pos = req_queue[min_index];
		printf("%d \t" , head_pos);
	}
	
	printf("No of heads : %d \n" , no_of_headcounts);
	
}

int main(){
	
	int no_of_tracks = 0;
	int n = 0;
	int head_pos = 0;
	int no_of_head_moves = 0;
	
	printf("Enter the total number of tracks disk contains : \n");
	scanf("%d" , &no_of_tracks);
	
	printf("Enter the no of reqs : \n"); 
	scanf("%d" , &n);
	
	int req_queue[n];
	
	printf("Enter the requests : \n");
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d" , &req_queue[i]);
	}
	
	printf("Enter the head position : \n");
	scanf("%d" , &head_pos);
	
	int visited[n];
	
	for(int i = 0 ; i < n ; i++){
		visited[i] = 0;
	}
	
	printf("OUTPUT : \n");
	sstf(req_queue , visited , head_pos , n);

}

