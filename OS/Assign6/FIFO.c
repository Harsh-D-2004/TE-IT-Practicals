#include <stdio.h>

void fifo(char string[], int frameSize, int count) {
    int faults = 0, front = 0, end = 0;
    char frame[frameSize];

    printf("Page\tFrame\tPage Fault\n");
    printf("============================\n");

    for (int i = 0; i < count; i++) {
        int found = 0;

        for (int j = 0; j < end; j++) {
            if (frame[j] == string[i]) {
                found = 1;
                break;
            }
        }

        if (!found) { 
            faults++;
            if (end < frameSize) {
                frame[end++] = string[i]; 
            } else {
                frame[front] = string[i]; 
                front = (front + 1) % frameSize;
            }
            printf("%c\t", string[i]);
            for (int k = 0; k < end; k++) {
                printf("%c ", frame[k]);
            }
            printf("\tY\n");
        } else {
            printf("%c\t", string[i]);
            for (int k = 0; k < end; k++) {
                printf("%c ", frame[k]);
            }
            printf("\tN\n");
        }
    }
    printf("Total Page Faults: %d\n", faults);
}

int main() {
    char string[50];
    int frameSize, count = 0;

    printf("Enter the reference string: ");
    scanf("%s", string);

    printf("Enter the frame size: ");
    scanf("%d", &frameSize);

    while (string[count] != '\0') count++;

    fifo(string, frameSize, count);
    return 0;
}