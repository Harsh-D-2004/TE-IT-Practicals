
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SZ 4096  

int main() {
    int shm_id;
    int *shm_ptr;
    int data;

    shm_id = shmget(IPC_PRIVATE, SZ, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("Error creating shared memory");
        exit(1);
    }

    printf("Shared memory created with ID: %d\n", shm_id);

    shm_ptr = (int *)shmat(shm_id, NULL, 0);
    if ((int)shm_ptr == -1) {
        printf("Error attaching shared memory");
        exit(1);
    }
    printf("Shared memory attached at address %p\n", shm_ptr);

    printf("Enter data to write to shared memory: ");
    scanf("%d", &data);
    *shm_ptr = data;
    printf("Data written to shared memory: %d\n", *shm_ptr);

    printf("Waiting for client to read data...\n");
    sleep(10);

    if (shmdt(shm_ptr) == -1) {
        printf("Error detaching shared memory");
        exit(1);
    }
    printf("Shared memory detached.\n");

    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        printf("Error deleting shared memory");
        exit(1);
    }
    printf("Shared memory deleted.\n");

    return 0;
}
