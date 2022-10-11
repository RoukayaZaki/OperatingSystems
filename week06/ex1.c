#include <stdio.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {

    int n_processes;
    scanf("%d", &n_processes);

    int at[n_processes], bt[n_processes], ct[n_processes], tat[n_processes], wt[n_processes];
    double avg_tat, avg_wt;

    for (int i = 0; i < n_processes; i++) scanf("%d%d", &at[i], &bt[i]);

    
    for (int i = 0 ; i < n_processes; i++) {
        for (int j = i + 1; j < n_processes; j++) {
            if (at[i] > at[j]) {
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
            }
        }
    }

    int t_current = 0;
    for (int i = 0; i < n_processes; i++) {
        if(t_current < at[i]) t_current = at[i];

        ct[i] = bt[i] + t_current;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        t_current = ct[i];
    }
    
    double total_tat = 0, total_wt = 0;
    
    for (int i = 0; i < n_processes; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }
    
    avg_tat = total_tat / n_processes;
    avg_wt = total_wt / n_processes;

    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n_processes; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average TAT: %.2f\n", avg_tat);
    printf("Average WT: %.2f\n", avg_wt);
    return 0;
}