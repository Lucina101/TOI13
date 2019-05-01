#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+10,mod=1e9+7;
int n,pre[maxn],suf[maxn],p[maxn];
char s[maxn];

int main(){
    scanf("%d",&n);
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]<<1;
        if(p[i]>=mod)
            p[i]-=mod;
    }
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]<<1;
        pre[i]+=(s[i]-'0');
        if(pre[i]>=mod)
            pre[i]-=mod;
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1];
        suf[i]+=((s[i]-'0')*p[n-i]);
        if(suf[i]>=mod){
            suf[i]-=mod;
        }
    }
    for(int i=1;i<n;i++){
        if(pre[i]==suf[n-i+1]&&suf[i+1]==pre[n-i]){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d\n",n);
}
