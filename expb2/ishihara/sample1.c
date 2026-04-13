#include <stdio.h>

int main(void) {
    int n = 3;
    double a[3][4] = {
        {6, 2, 3, 1},
        {2, 12, 1, 0},
        {3, 1, 18, 0}
    };
    double x[3];

    // 前進消去
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double m = a[i][k] / a[k][k];
            for (int j = k; j <= n; j++) {
                a[i][j] -= m * a[k][j];
            }
        }
    }

    // 後退代入
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // 結果出力
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.6f\n", i + 1, x[i]);
    }

    return 0;
}