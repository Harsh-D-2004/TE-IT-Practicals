#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#define Max_Buff 1024

int main() {
    int fd1, fd2, c = 0;
    char *myfifo1 = "myfifo1";
    char *myfifo2 = "myfifo2";

    char buff[Max_Buff];
    char buff2[Max_Buff];
    char str;

    int res = mkfifo(myfifo1, 0777);
    if (res == -1) {
        printf("\nPipe 1 not created");
        return 0;
    }

    printf("\nEnter the string:\n");
    fd1 = open(myfifo1, O_WRONLY); 

    while ((str = getchar()) != '#')
        buff[c++] = str;
    buff[c] = '\0';  
    
    printf("Contents written in pipe \n");

    write(fd1, buff, sizeof(buff));
    close(fd1); 

    fd2 = open(myfifo2, O_RDONLY);
    read(fd2, &buff2, Max_Buff); 

    printf("\nContents of the file:\n%s", buff2); 
    close(fd2); 

    unlink(myfifo2); 

    return 0;
}
