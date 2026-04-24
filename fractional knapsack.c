#include <stdio.h>

struct item {
    int weight;
    int profit;
    float ppw; // profit per weight
};

// Function to sort items by profit/weight ratio (descending)
void sort(struct item items[], int n) {
    struct item temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (items[j].ppw < items[j + 1].ppw) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    float totalprofit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct item items[n];

    printf("Enter weights and profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ppw = (float)items[i].profit / items[i].weight;
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    // Sort items by profit/weight ratio
    sort(items, n);

    // Knapsack logic
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            totalprofit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalprofit += items[i].ppw * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalprofit);

    return 0;
}
