/*
Task: TOI13_Cat
O(nlog(n))->787 ms
O(nlog(maxn))->1050 ms
Kudos to test cases
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int b[maxn],l,r,mid,n,ans;
int a[maxn],ct;
vector<int> c;
bool ch(int x){
    ct=0;
    for(int i=1;i<=n;i++){
        if(b[i]>x){
        ct++;
        a[ct]=b[i];
        if(ct%2==0){
            if(a[ct]!=a[ct-1])
                return false;
        }
    }
    }
    return true;

}

int main(){
    int ma=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        a[i]=b[i];
        ma=max(ma,b[i]);
    }
    sort(a+1,a+1+n);
    c.push_back(0);
    for(int i=1;i<=n;i+=2){
        c.push_back(a[i]);
    }
    l=0,r=c.size()-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(ch(c[mid])){
            ans=c[mid];
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",ans);
}
