#include <stdio.h>
#include <stdlib.h> 

int CLOOK() {
    int RQ[100], n, TotalHeadMovement = 0, initial, move;
    int size_of_disk = 0;
    
    printf("Enter the size of disk : \n");
    scanf("%d" , &size_of_disk);

    printf("Enter the no of requests: ");
    scanf("%d", &n);

    printf("Enter the requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    printf("Enter the direction of traversal (0: lower, 1: higher): ");
    scanf("%d", &move);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index = 0;
    while (index < n && RQ[index] < initial) {
        index++;
    }

    printf("Index: %d\n", index);

    if (move == 1) {
        for (int i = index; i < n; i++) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
            printf("%d \t" , initial);
        }

        if (index > 0) { 
            TotalHeadMovement += abs(initial - RQ[0]);
            initial = RQ[0];
            printf("%d \t" , initial);

            for (int i = 1; i < index; i++) {
                TotalHeadMovement += abs(RQ[i] - initial);
                initial = RQ[i];
                printf("%d \t" , initial);
            }
        }
    }

    else {
        for (int i = index - 1; i >= 0; i--) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
            printf("%d \t" , initial);
        }

        if (index < n) {  
            TotalHeadMovement += abs(initial - RQ[n - 1]);
            initial = RQ[n - 1];
            printf("%d \t" , initial);

            for (int i = n - 2; i >= index; i--) {
                TotalHeadMovement += abs(RQ[i] - initial);
                initial = RQ[i];
                printf("%d \t" , initial);
            }
        }
    }

    printf("Total movement covered: %d\n", TotalHeadMovement);
    return 0;
}

int main() {
    CLOOK();
    return 0;
}
