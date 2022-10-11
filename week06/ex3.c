#include "stdio.h"
#define max(a,b) (a < b ? b : a)
#define min(a,b) (a > b ? b : a)

int main() {

    int n_processes, quantum;
    scanf("%d%d", &n_processes, &quantum);

    int at[n_processes], bt[n_processes], ct[n_processes], tat[n_processes], wt[n_processes], pid[n_processes], done[n_processes], iter[n_processes]; 
    double avg_tat, avg_wt;
    
    for (int i = 0; i < n_processes; i++) {
        scanf("%d%d", &at[i], &bt[i]);
        pid[i] = i;
        done[i] = 0;
        iter[i] = 0;
    }

    for (int i = 0 ; i < n_processes; i++) {
        for (int j = i + 1; j < n_processes; j++) {
            if (at[i] > at[j]) {
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
                swap(&pid[i], &pid[j]);
            }
        }
    }

    int t_current = 0, p_unfinished = 1, temp_bt[n_processes];

    for (int i = 0; i < n_processes; i++) {
        temp_bt[i] = bt[i];
    }

    while(p_unfinished) {

        p_unfinished = 0;

        for (int i = 0; i < n_processes; i++) {
            if (done[i]) {
                continue;
            }
            iter[i]++;
            if(t_current < at[i]) t_current = at[i];

            int taken = temp_bt[i];
            if(quantum < taken) taken = quantum;
            ct[i] = taken + t_current;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - taken;

            if (iter[i] > 1) {
                wt[i] = wt[i] - quantum * (iter[i] - 1);
            }

            temp_bt[i] = temp_bt[i] - taken;

            if (temp_bt[i] == 0) {
                done[i] = 1;
            }

            t_current = ct[i];
        }
        for (int i = 0; i < n_processes; i++) {
            if (done[i] == 0) {
                p_unfinished = 1;
                break;
            }
        }

    }

    double t_tat = 0, t_wt = 0;
    for (int i = 0; i < n_processes; i++) {
        t_tat += tat[i];
        t_wt += wt[i];
    }
    avg_tat = t_tat / n_processes;
    avg_wt = t_wt / n_processes;

    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n_processes; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("Average TAT: %.2f\n", avg_tat);
    printf("Average WT: %.2f\n", avg_wt);
    return 0;
}