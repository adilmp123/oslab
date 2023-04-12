#include <stdio.h>

int main()
{
    int mem_size, num_blocks, i, j;
    printf("Enter the total memory size: ");
    scanf("%d", &mem_size);
    printf("Enter the number of memory blocks: ");
    scanf("%d", &num_blocks);
    int memory[num_blocks];
    for (i = 0; i < num_blocks; i++) {
        printf("Enter the size of block %d: ", i+1);
        scanf("%d", &memory[i]);
    }
    int process_size, best_fit = -1;
    printf("Enter the size of process: ");
    scanf("%d", &process_size);
    for (i = 0; i < num_blocks; i++) {
        if (memory[i] >= process_size) {
            if (best_fit == -1 || memory[i] < memory[best_fit]) {
                best_fit = i;
            }
        }
    }
    if (best_fit != -1) {
        printf("Memory block %d allocated to process.\n", best_fit+1);
        memory[best_fit] -= process_size;
    }
    else {
        printf("Memory not available for process.\n");
    }
    printf("Memory blocks: ");
    for (j = 0; j < num_blocks; j++) {
        printf("%d ", memory[j]);
    }
    return 0;
}
