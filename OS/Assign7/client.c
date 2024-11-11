
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>

#define SZ 4096 

int main() {
    int shm_id;
    int *shm_ptr;

    printf("Enter shared memory ID: ");
    scanf("%d", &shm_id);

    shm_ptr = (int *)shmat(shm_id, NULL, 0);
    if ((int)shm_ptr == -1) {
        printf("Error attaching to shared memory");
        exit(1);
    }
    printf("Shared memory attached at address %p\n", shm_ptr);

    printf("Data read from shared memory: %d\n", *shm_ptr);

    if (shmdt(shm_ptr) == -1) {
        printf("Error detaching shared memory");
        exit(1);
    }
    printf("Shared memory detached.\n");

    return 0;
}
