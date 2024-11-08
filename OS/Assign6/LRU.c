#include <stdio.h>

void lru(char string[], int frameSize, int count) {
    int faults = 0, end = 0;
    char frame[frameSize];
    int recent[frameSize];

    printf("Page\tFrame\tPage Fault\n");
    printf("============================\n");

    for (int i = 0; i < count; i++) {
        int found = 0, min = 0;

        for (int j = 0; j < end; j++) {
            if (frame[j] == string[i]) {
                found = 1;
                recent[j] = i;
                break;
            }
        }

        if (!found) { 
            faults++;
            if (end < frameSize) {
                frame[end] = string[i];
                recent[end++] = i;
            } else {
                for (int j = 1; j < end; j++) {
                    if (recent[j] < recent[min]) min = j;
                }
                frame[min] = string[i];
                recent[min] = i;
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
    printf("\nTotal Page Faults: %d\n", faults);
}

int main() {
    char string[50];
    int frameSize, count = 0;

    printf("Enter the reference string: ");
    scanf("%s", string);

    printf("Enter the frame size: ");
    scanf("%d", &frameSize);

    while (string[count] != '\0') count++;

    lru(string, frameSize, count);
    return 0;
}
