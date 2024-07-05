#include <stdio.h>

int getNextGap(int gap) {
    gap = (gap * 10) / 13; // Um valor típico para reduzir o intervalo
    if (gap < 1) {
        return 1; // O intervalo mínimo deve ser 1
    }
    return gap;
}

void combSort(int a[], int n) {
    int gap = n;
    int swapped = 1;

    while (gap != 1 || swapped) {
        gap = getNextGap(gap);
        swapped = 0;

        for (int i = 0; i < n - gap; i++) {
            if (a[i] > a[i + gap]) {
                int temp = a[i];
                a[i] = a[i + gap];
                a[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

int main() {
    int a[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(a) / sizeof(a[0]);
    
    printf("Numeros desordenados: \n");
    for(int i= 0; i<n; i++){
    	printf("%d, ",a[i]);
	}
	printf("\n");

    combSort(a, n);
    
	printf("Numero ordenados: \n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");

    return 0;
}

