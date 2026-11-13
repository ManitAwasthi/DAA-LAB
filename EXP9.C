#include <stdio.h>

int set[100];
int selected[100];
int n, target;

void subsetSum(int index, int sum) {

    if (sum == target) {

        printf("Subset: ");

        for (int i = 0; i < index; i++) {
            if (selected[i])
                printf("%d ", set[i]);
        }

        printf("\n");
        return;
    }

    if (index == n || sum > target)
        return;

    // Include current element
    selected[index] = 1;
    subsetSum(index + 1, sum + set[index]);

    // Exclude current element
    selected[index] = 0;
    subsetSum(index + 1, sum);
}

int main() {

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nPossible subsets:\n");

    subsetSum(0, 0);

    return 0;
}
