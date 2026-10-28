
#include <stdio.h>
#define MAX 10

int main() {
    int n, r, i, j;
    int max[MAX][MAX], allocation[MAX][MAX], need[MAX][MAX];
    int total[MAX], available[MAX], work[MAX];
    int finish[MAX] = {0}, safeSequence[MAX];
    int count = 0, found;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &r);

    for (i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);

        printf("Enter maximum resources: ");
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

        printf("Enter allocated resources: ");
        for (j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    for (j = 0; j < r; j++) {
        printf("Enter total instances of R%d: ", j + 1);
        scanf("%d", &total[j]);

        available[j] = total[j];

        for (i = 0; i < n; i++)
            available[j] -= allocation[i][j];

        work[j] = available[j];
    }

    printf("\nProcess\tMax\tAllocation\tNeed\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t", i + 1);

        for (j = 0; j < r; j++)
            printf("%d ", max[i][j]);

        printf("\t");

        for (j = 0; j < r; j++)
            printf("%d ", allocation[i][j]);

        printf("\t\t");

        for (j = 0; j < r; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }

    while (count < n) {
        found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < r; j++) {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == r) {
                    for (j = 0; j < r; j++)
                        work[j] += allocation[i][j];

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
            break;
    }

    if (count == n) {
        printf("\nSystem is in a SAFE state.\n");
        printf("Safe Sequence: ");

        for (i = 0; i < n; i++) {
            printf("P%d", safeSequence[i] + 1);

            if (i < n - 1)
                printf(" -> ");
        }

        printf("\n");
    } else {
        printf("\nSystem is NOT in a SAFE state.\n");
    }

    return 0;
}
