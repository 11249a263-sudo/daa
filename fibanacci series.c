#include <stdio.h>

int main() {
    int n;

    printf("Enter how many terms: ");
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input! Please enter a positive number.\n");
        return 1;
    }

    int a = 0, b = 1, next;

    printf("Fibonacci Series:\n");

    for (int i = 1; i <= n; i++) {
        printf("%d ", a);

        next = a + b;
        a = b;
        b = next;
    }

    printf("\n");

    return 0;
}
