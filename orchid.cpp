#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int x,n,l,r,mi,ans;
void bs(){
 l=1,r=a.size()-1;
 ans=0;
while(l<=r){
    mi=(l+r)/2;
     if(x>=a[mi]){
        ans=mi;
        l=mi+1;
    }
    else{
        r=mi-1;
    }
}
  //  cout<<ans<<"\n";
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
    /*   for(int j=0;j<a.size();j++)
        printf("%d ",a[j]);
    printf("\n");*/
    }
    printf("%d ",n-a.size()+1);



}
/*
      5
      5
      4
      4
      4
      4 4
*/
