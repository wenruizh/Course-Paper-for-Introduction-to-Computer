#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long cntb = 0;

int cmp(const void *a, const void *b){
    cntb++;                       // increment by for each comparison
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);     // x<y returns negative(ascending order),x==y returns 0,x>y returns positive
}
int main(void)
{
    int sizes[] = {10000, 50000, 100000, 200000};
    for (int s = 0; s < 4; s++) {
        int n = sizes[s];
        int *arr = malloc(n * sizeof(int));
        if (arr == NULL) return 1;
        srand(42);
        for (int i = 0; i < n; i++) arr[i] = rand();
        clock_t t0 = clock();
        qsort(arr, n, sizeof(int), cmp);
        printf("n=%d: qsort %.6f s, compare %lld times\n",
               n, (double)(clock()-t0)/CLOCKS_PER_SEC, cntb);
        cntb = 0;
        free(arr);
    }
    return 0;
}