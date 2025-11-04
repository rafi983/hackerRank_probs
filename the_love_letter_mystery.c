#include <stdio.h>
#include <string.h>

int main(void){
    int q;
    if(scanf("%d",&q)!=1) return 0;
    char s[200005];
    while(q--){
        if(scanf("%200000s",s)!=1) return 0;
        int n=(int)strlen(s);
        long long ans=0;
        for(int i=0,j=n-1;i<j;++i,--j){
            int d=s[i]-s[j];
            if(d<0) d=-d;
            ans+=d;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

