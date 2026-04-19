#include <stdio.h>

// Function to print bin status
void printBins(int bin[], int count) {
    printf("\nBin status (remaining space):\n");
    for (int i = 0; i < count; i++) {
        printf("Bin %d: %d\n", i + 1, bin[i]);
    }
}

// First Fit Algorithm
void firstfit(int itemsize[], int n, int capacity) {
    int bin[n];
    int bincount = 0;

    for (int i = 0; i < n; i++)
        bin[i] = 0;

    for (int i = 0; i < n; i++) {
        int placed = 0;

        for (int j = 0; j < bincount; j++) {
            if (bin[j] + itemsize[i] <= capacity) {
                bin[j] += itemsize[i];
                printf("Item %d → Bin %d\n", itemsize[i], j + 1);
                placed = 1;
                break;
            }
        }

        if (!placed) {
            bin[bincount] = itemsize[i];
            printf("Item %d → Bin %d\n", itemsize[i], bincount + 1);
            bincount++;
        }
    }

    printf("Total bins used = %d\n", bincount);
    printBins(bin, bincount);
}

// Best Fit Algorithm
void bestfit(int itemsize[], int n, int capacity) {
    int bin[n];
    int bincount = 0;

    for (int i = 0; i < n; i++)
        bin[i] = 0;

    for (int i = 0; i < n; i++) {
        int bestindex = -1;
        int minspace = capacity + 1;

        for (int j = 0; j < bincount; j++) {
            int space = capacity - bin[j];

            if (space >= itemsize[i] && (space - itemsize[i]) < minspace) {
                bestindex = j;
                minspace = space - itemsize[i];
            }
        }

        if (bestindex != -1) {
            bin[bestindex] += itemsize[i];
            printf("Item %d → Bin %d\n", itemsize[i], bestindex + 1);
        } else {
            bin[bincount] = itemsize[i];
            printf("Item %d → Bin %d\n", itemsize[i], bincount + 1);
            bincount++;
        }
    }

    printf("Total bins used = %d\n", bincount);
    printBins(bin, bincount);
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    if (n <= 0 || capacity <= 0) {
        printf("Invalid input!\n");
        return 1;
    }

    int itemsize[n];

    for (int i = 0; i < n; i++) {
        printf("Enter size of item %d: ", i + 1);
        scanf("%d", &itemsize[i]);

        if (itemsize[i] > capacity) {
            printf("Item size cannot exceed bin capacity!\n");
            return 1;
        }
    }

    printf("\n--- First Fit ---\n");
    firstfit(itemsize, n, capacity);

    printf("\n--- Best Fit ---\n");
    bestfit(itemsize, n, capacity);

    return 0;
}
