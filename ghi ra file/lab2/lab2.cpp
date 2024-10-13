
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    float* a = (float*)malloc(n * sizeof(float));
    if (a == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }
    for (i = 0; i < n; i++)
        a[i] = (float)rand();

    FILE* file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("Khong the mo tep\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%.2f\n", a[i]);
    }

    fclose(file);
    printf("Mang duoc ghi ra tep output.txt\n");

    FILE* fileRead = fopen("output.txt", "r");
    if (fileRead == NULL) {
        printf("Khong the mo tep\n");
        return 1;
    }

    i = 0;
    while (i < n && fscanf(fileRead, "%f", &a[i]) == 1) {
        i++;
    }

    fclose(fileRead);
    printf("Mang da duoc doc tu tep\n");
    for (int j = 0; j < n; j++) {
        printf("%.2f\n", a[j]);
    }

    float tong = 0;
    for (int j = 0; j < n; j++) {
        tong += a[j];
    }
    printf("Tong cac phan tu: %.2f\n", tong);
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                float tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    printf("Mang da duoc sap xep tang dan: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");

    printf("Phan tu lon nhat: %.2f\n", a[n - 1]);
    printf("Phan tu nho nhat: %.2f\n", a[0]);

    return 0;
}

