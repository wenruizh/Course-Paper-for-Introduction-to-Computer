#include <stdio.h>
int cnt=0;
int binary_search(int a[],int n,int t){
    if(a==NULL) return -1;
    int l=-1,r=n;int mid;
    while(r-l>1){
        mid=l+(r-l)/2;
        cnt++;
        if(a[mid]>=t){
            r=mid;

        }else {
            l=mid;

        }
    }
    if(r==n||a[r]!=t) return -1;
    else return r;
}
int main(void)
{
    int a[100000];
    for(int i=0;i<100000;i++){
        a[i]=i;
    }
    binary_search(a,100000,55555);
    printf("%d",cnt);
    return 0;
}