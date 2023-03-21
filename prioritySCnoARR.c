#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;
    int burst_time;
    int priority;
    int remaining_time;
};

void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_by_priority(struct Process processes[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (processes[j].priority > processes[j+1].priority) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

int main() {
    int i, n;
    struct Process processes[MAX_PROCESSES];
    bool done[MAX_PROCESSES] = {false};
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter the burst time and priority of process %d: ", i+1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].priority);
        processes[i].pid = i+1;
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    while (true) {
        int min_priority = 99999;
        int min_priority_index = -1;
        
        for (i = 0; i < n; i++) {
            if (!done[i] && processes[i].priority < min_priority && processes[i].remaining_time > 0) {
                min_priority = processes[i].priority;
                min_priority_index = i;
            }
        }
        
        if (min_priority_index == -1) {
            current_time++;
            continue;
        }
        
        processes[min_priority_index].remaining_time--;
        current_time++;
        
        if (processes[min_priority_index].remaining_time == 0) {
            done[min_priority_index] = true;
            int waiting_time = current_time - processes[min_priority_index].burst_time;
            total_waiting_time += waiting_time;
            int turnaround_time = current_time;
            total_turnaround_time += turnaround_time;
        }
        
        if (done[n-1]) {
            break;
        }
    }
    
    float average_waiting_time = (float) total_waiting_time / n;
    float average_turnaround_time = (float) total_turnaround_time / n;
    
    printf("Average waiting time: %0.2f\n", average_waiting_time);
    printf("Average turnaround time: %0.2f\n", average_turnaround_time);
    
    return 0;
}
