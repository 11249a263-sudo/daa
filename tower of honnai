#include <stdio.h>

int step = 1;  

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        printf("Step %d: Move disk 1 from %c to %c\n", step++, source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, destination);

    printf("Step %d: Move disk %d from %c to %c\n", step++, n, source, destination);

    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    printf("\n--- Tower of Hanoi Solution ---\n\n");

    towerOfHanoi(n, 'S', 'D', 'A');

    printf("\nTotal steps: %d\n", step - 1);

    return 0;
}
