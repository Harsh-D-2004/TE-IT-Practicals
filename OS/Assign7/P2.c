#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#define MAX_BUF 1024

int main() {
    int words = 0, lines = 0, chars = 0;
    FILE *fp;
    char buf[MAX_BUF];
    int fd, fd1, i = 0;

    char *myfifo1 = "myfifo1";
    char *myfifo2 = "myfifo2";

    mkfifo(myfifo2, 0777);

    fd = open(myfifo1, O_RDONLY);
    read(fd, buf, MAX_BUF); 

    printf("\nMessage received: %s", buf); 

    while (buf[i] != '\0') {
        if (buf[i] == ' ' || buf[i] == '\n') {
            words++;
        } else {
            chars++;
        }
        if (buf[i] == '\n') {
            lines++;
        }
        i++;
    }
    words++;
    lines++;

    printf("\nNo. of lines: %d", lines);
    printf("\nNo. of words: %d", words);
    printf("\nNo. of chars: %d", chars);

    fp = fopen("a.txt", "w+");
    fprintf(fp, "No. of lines: %d\n", lines);
    fprintf(fp, "No. of words: %d\n", words);
    fprintf(fp, "No. of chars: %d\n", chars);
    fclose(fp);

    close(fd);
    unlink(myfifo1);

    fd1 = open(myfifo2, O_WRONLY);
    system("cat a.txt > myfifo2");
    close(fd1);

    return 0;
}
