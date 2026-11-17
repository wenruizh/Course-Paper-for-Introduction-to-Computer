#include <stdio.h>
long long cnt=0;
int seq_search(int a[],int n,int t){
    for(int i=0;i<n;i++){
        cnt++;
        if(a[i]>=t){
            return i;
        }
    }
    return -1;
}
int main(void)
{
    int a[100000];
    for(int i=0;i<100000;i++){
        a[i]=i;
    }

    int ans=seq_search(a,100000,100000);
    printf("%lld %d",cnt,ans);
    return 0;
}