#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct _node{
    int val;
    struct _node *next;
}node;
typedef struct{
    node *head;
    int size;
}stack;
stack* create(){
    stack *a;
    a=(stack*)malloc(sizeof(stack));
    a->head=NULL;
    a->size=0;
    return a;
}
void push(stack *a,int num){
    node *p=(node*)malloc(sizeof(node));
    p->val=num;
    p->next=a->head;
    a->head=p;
    a->size++;
}
int empty(stack *a){
    if(a->size==0) return -1;
    else return 1;
}
void pop(stack* a){
    if(empty(a)!=-1){
        a->size--;
        node* p=a->head;
        a->head=a->head->next;
        free(p);
    }
}
int head(stack *a){
    if(a->head==NULL) return -1;
    return a->head->val;
}
int main(void){
    int R = 10;
    double total = 0;
    for(int r = 0; r < R; r++){
        stack *a = create();
        clock_t t0 = clock();
        for(int i = 0; i < 1000000; i++) push(a, i);
        while(empty(a) != -1) pop(a);
        total += (double)(clock() - t0) / CLOCKS_PER_SEC;
        free(a);
    }
    printf("linked stack: 1e6 push + 1e6 pop, avg of 10 = %.4f s\n", total / R);
    return 0;
}