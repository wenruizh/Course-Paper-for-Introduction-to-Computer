#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long cntb = 0;   // comparison count
long long cntm = 0;   // move count

void insertion_sort(int a[], int n){
    int f = 0;
    while (f != n) {
        if (f + 1 == n) break;
        for (int i = 0; i <= f; i++) {
            cntb++;                         // one key comparison
            if (a[f+1] <= a[i]) {
                int temp = a[f+1];
                for (int j = f; j >= i; j--) {
                    a[j+1] = a[j];
                    cntm++;                 // one element move
                }
                a[i] = temp;
                break;
            }
        }
        f++;
    }
}

int main(void)
{
    int sizes[] = {10000, 50000, 100000, 200000};
    for (int s = 0; s < 4; s++) {
        int n = sizes[s];
        int *arr = malloc(n * sizeof(int));
        if (arr == NULL) { printf("malloc failed\n"); return 1; }

        srand(42);
        for (int i = 0; i < n; i++) arr[i] = rand();

        clock_t t0 = clock();
        insertion_sort(arr, n);
        double t = (double)(clock() - t0) / CLOCKS_PER_SEC;

        printf("n=%d: insertion sort %.4f s, compare %lld times, move %lld times\n",
               n, t, cntb, cntm);
        cntb = 0;
        cntm = 0;
        free(arr);
    }
    return 0;
}