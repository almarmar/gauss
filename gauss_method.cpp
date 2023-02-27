#include<stdio.h>
#include <stdlib.h>
#include <iostream> 

int main() {
    setlocale(LC_ALL, "Russian");
    int m, n, i, j;
    printf("Введите размерность матрицы:\nКоличество строк:\n");
    scanf_s("%d", &m);
    printf("Количество стобцов:\n");
    scanf_s("%d", &n);
    printf("Введите элементы матрицы:\n");
    double** a = (double**)malloc(m * sizeof(double*));
    for (i = 0; i < m; i++) {
        a[i] = (double*)malloc(n * sizeof(double));
        for (j = 0; j < n; j++) {
            scanf_s("%lf", &a[i][j]);
        }
        printf("\n");
    }
    int k;
    double x[10];
    for (i = 0;i < m - 1;i++) {
        for (k = i + 1;k < m;k++) {
            if (fabs(a[i][i]) < fabs(a[k][i])) {
                for (j = 0;j < n;j++) {
                    double temp;
                    temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
        for (k = i + 1;k < m;k++) {
            double  term = a[k][i] / a[i][i];
            for (j = 0;j < n;j++) {
                a[k][j] = a[k][j] - term * a[i][j];
            }
        }

    }
    for (i = m - 1;i >= 0;i--) {
        x[i] = a[i][n - 1];
        for (j = i + 1;j < n - 1;j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
    printf("Треугольная матрица:\n\n");
    for (i = 0;i < m;i++) {
        for (j = 0;j < n;j++) {
            printf("%.2lf\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\nРешение:\n\n");
    for (i = 0;i < n - 1;i++) {
        printf("x[%d]=%.2lf\n", i + 1, x[i]);
    }
    system("pause");

}