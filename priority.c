#include <stdio.h>

int main() {

    int n, i, j, t;

    int tat[10], wt[10], bt[10], pid[10], pr[10];

    float awt = 0, atat = 0;

    printf("-----------PRIORITY SCHEDULING--------------\n");

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        pid[i] = i;

        printf("Enter the Burst time of Pid %d: ", i);
        scanf("%d", &bt[i]);

        printf("Enter the Priority of Pid %d: ", i);
        scanf("%d", &pr[i]);
    }

    // Sorting processes based on priority
    for (i = 0; i < n; i++) {

        for (j = i + 1; j < n; j++) {

            if (pr[i] > pr[j]) {

                t = pr[i];
                pr[i] = pr[j];
                pr[j] = t;

                t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;

                t = pid[i];
                pid[i] = pid[j];
                pid[j] = t;
            }
        }
    }

    // Calculating Waiting Time and Turnaround Time
    tat[0] = bt[0];
    wt[0] = 0;

    for (i = 1; i < n; i++) {

        wt[i] = wt[i - 1] + bt[i - 1];

        tat[i] = wt[i] + bt[i];
    }

    printf("\n-------------------------------------------------------\n");

    printf("Pid\tPriority\tBurst Time\tWaiting Time\tTurn Around Time\n");

    printf("-------------------------------------------------------\n");

    for (i = 0; i < n; i++) {

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               pid[i], pr[i], bt[i], wt[i], tat[i]);
    }

    // Calculating Average Waiting Time and Average Turnaround Time
    for (i = 0; i < n; i++) {

        awt += wt[i];

        atat += tat[i];
    }

    awt /= n;

    atat /= n;

    printf("\nAvg. Waiting Time: %f", awt);

    printf("\nAvg. Turn Around Time: %f\n", atat);

    return 0;
}