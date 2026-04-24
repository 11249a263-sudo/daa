#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF INT_MAX

int d[MAX][MAX];
int dp[MAX][1 << MAX];
int n;

// Function for TSP using DP + Bitmask
int g(int i, int mask) {
    // If all cities visited, return cost to go back to start
    if (mask == (1 << n) - 1) {
        return d[i][0];
    }

    // If already computed
    if (dp[i][mask] != -1)
        return dp[i][mask];

    int mincost = INF;

    for (int k = 0; k < n; k++) {
        // If city k not visited
        if (!(mask & (1 << k))) {
            int cost = d[i][k] + g(k, mask | (1 << k));
            if (cost < mincost)
                mincost = cost;
        }
    }

    return dp[i][mask] = mincost;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &d[i][j]);
        }
    }

    // Initialize DP table
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            dp[i][mask] = -1;
        }
    }

    int result = g(0, 1); // Start from city 0, mask = 1 (only city 0 visited)

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
