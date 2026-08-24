#include <stdio.h>
int main() {
int bt[20], wt[20], tat[20], n;
float wtavg = 0, tatavg = 0;
printf("Enter the number of processes: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
printf("Enter Burst Time for Process %d: ", i);
scanf("%d", &bt[i]);
}
wt[0] = 0;
tat[0] = bt[0];
for (int i = 1; i < n; i++) {
wt[i] = wt[i - 1] + bt[i - 1];
tat[i] = tat[i - 1] + bt[i];
wtavg += wt[i];
tatavg += tat[i];
}
printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
for (int i = 0; i < n; i++) {
printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
}
printf("Average Waiting Time: %.2f\n", wtavg / n);
printf("Average Turnaround Time: %.2f\n", tatavg / n);
return 0;
}