#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int shm_id;
    pid_t pid;
    char *shm_addr;

    shm_id = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
    if (shm_id < 0)
    {
        perror("shmget failed");
        exit(1);
    }

    // fork a child process
    pid = fork();
    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0)
    { 
        shm_addr = shmat(shm_id, NULL, 0);
        if (shm_addr == (char *)-1)
        {
            perror("shmat failed");
            exit(1);
        }

        printf("Child process read data: %s\n", shm_addr);

        shmdt(shm_addr);
        exit(0);
    }
    else
    { 
        shm_addr = shmat(shm_id, NULL, 0);
        if (shm_addr == (char *)-1)
        {
            perror("shmat failed");
            exit(1);
        }

        sprintf(shm_addr, "Hello, shared memory!");

        wait(NULL);

        shmdt(shm_addr);

        shmctl(shm_id, IPC_RMID, NULL);
        exit(0);
    }
}
