#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Block 5
typedef struct{
    int *base;
    int head;
    int size;
    int cap;
}stack;
stack* create(){
    stack* a=(stack*)malloc(sizeof(stack));
    a->base=(int*)malloc(sizeof(int)*Block);
    a->head=0;
    a->size=0;
    a->cap=Block;
    return a;
}
int empty(stack *a){
    if(a->size==0) return 1;
    else return 0;
}
void push(stack *a,int val){
    if(a->size==a->cap){
        int *nb=realloc(a->base,sizeof(int)*(a->cap*2));
        if(nb==NULL) {
            printf("realloc failed\n");
            return ;
        }        
        a->base=nb;
        a->cap*=2;
    }
        a->base[a->head]=val;
        a->size++;
        a->head++;

}
void pop(stack *a){
    if(empty(a)!=1){
        a->size--;
        a->head--;
    }
}
int main(void){
    int R = 10;                    // 10 runs, averaged
    double total = 0;
    for(int r = 0; r < R; r++){
        stack* a = create();
        clock_t t0 = clock();
        for(int i = 0; i < 1000000; i++) push(a, i);   // push 1e6
        while(empty(a) != 1) pop(a);                   // pop all
        total += (double)(clock() - t0) / CLOCKS_PER_SEC;
        free(a->base);
        free(a);
    }
    printf("sequential stack (cap*=2 growth): 1e6 push + 1e6 pop, avg of 10 = %.4f s\n", total / R);
    return 0;
}