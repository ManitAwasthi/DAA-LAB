#include <stdio.h>

struct Activity {
    int start;
    int finish;
};

void sortActivities(struct Activity a[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (a[i].finish > a[j].finish) {

                struct Activity temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {

    int n;
    struct Activity a[100];

    printf("Enter number of activities: ");
    scanf("%d", &n);

    printf("Enter start and finish times:\n");

    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].start, &a[i].finish);

    sortActivities(a, n);

    printf("\nSelected Activities:\n");

    printf("(%d, %d)\n", a[0].start, a[0].finish);

    int last = 0;

    for (int i = 1; i < n; i++) {

        if (a[i].start >= a[last].finish) {

            printf("(%d, %d)\n",
                   a[i].start, a[i].finish);

            last = i;
        }
    }

    return 0;
}
