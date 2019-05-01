/*
TOI13
Task: Orchid
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int x,n,l,r,mid,ans;
void bs(){
 l=1,r=a.size()-1,ans=0;
while(l<=r){
    mid=(l+r)>>1;
     if(x>=a[mi]){
        ans=mi;
        l=mi+1;
    }
    else{
        r=mi-1;
    }
}
    ans++;
    if(ans){
    if(x>=a[a.size()-1])
        a.push_back(x);
    else
        a[ans]=x;
        }
    return;
}

int main(){
    scanf("%d",&n);
    a.push_back(0);
    scanf("%d",&x);
    a.push_back(x);
    for(int i=1;i<n;i++){
        scanf("%d",&x);
        bs();
    }
    printf("%d ",n-a.size()+1);
}
