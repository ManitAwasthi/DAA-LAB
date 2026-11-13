#include <stdio.h>
#include <limits.h>

int matrixChain(int p[], int n) {

    int m[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int length = 2; length < n; length++) {

        for (int i = 1; i < n - length + 1; i++) {

            int j = i + length - 1;

            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost =
                    m[i][k] +
                    m[k + 1][j] +
                    p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];
}

int main() {

    int n;
    int p[100];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter %d dimensions: ", n + 1);

    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Minimum multiplications = %d\n",
           matrixChain(p, n + 1));

    return 0;
}
