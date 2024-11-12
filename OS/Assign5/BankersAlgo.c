#include <stdio.h>

void calculateNeed(int need[][10], int max[][10], int alloc[][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

int isSafe(int n, int m, int avail[], int alloc[][10], int need[][10]) {
    int f[n], ans[n], ind = 0;

    for (int i = 0; i < n; i++) f[i] = 0;

    int work[m];
    for (int i = 0; i < m; i++) work[i] = avail[i];

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) { 
                int flag = 1;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }

                if (flag) {
                    for (int k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                    }
                    ans[ind++] = i;
                    f[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }

        if (!found) {
            printf("The system is not in a safe state.\n");
            return 0;
        }
    }

    printf("The system is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < n - 1; i++) printf("P%d -> ", ans[i]);
    printf("P%d\n", ans[n - 1]);

    return 1;
}

void resourceRequest(int n, int m, int avail[], int max[][10], int alloc[][10], int need[][10]) {
    int request[m], p;

    printf("Enter the process number (0 to %d): ", n - 1);
    scanf("%d", &p);

    printf("Enter the requested resources:\n");
    for (int i = 0; i < m; i++) scanf("%d", &request[i]);

    for (int i = 0; i < m; i++) {
        if (request[i] > max[p][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return;
        }
        if (request[i] > avail[i]) {
            printf("Error: Resources not available.\n");
            return;
        }
    }

    for (int i = 0; i < m; i++) {
        avail[i] -= request[i];
        alloc[p][i] += request[i];
        need[p][i] -= request[i];
    }

    if (isSafe(n, m, avail, alloc, need)) {
        printf("Request granted. System remains in a safe state.\n");
    } else {
        printf("Request denied. Rolling back to original state.\n");
        for (int i = 0; i < m; i++) {
            avail[i] += request[i];
            alloc[p][i] -= request[i];
            need[p][i] += request[i];
        }
    }
}

int main() {
    int n, m;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[10][10], max[10][10], avail[10], need[10][10];

    printf("Enter the Allocation matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the Max matrix (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Available resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }
    
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            avail[j] -= alloc[i][j];
        }
    }

    calculateNeed(need, max, alloc, n, m);

    if (isSafe(n, m, avail, alloc, need)) {
        resourceRequest(n, m, avail, max, alloc, need);
    }

    return 0;
}
