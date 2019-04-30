/*
TOI13 Task: Art
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,s,h,w,o,u,v,la;
vector<pair<int,int>> m[4*maxn];
long long t,bit[maxn],ans;
void update(int idx,int val){
    while(idx<=1000000){
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
    return ;
}
long long get(int idx){
    long long sum=0;
    while(idx>0){
        sum+=bit[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int f(){
    int ss=0;
    int l=0,r=1000000,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(get(mid)<=0){
            r=mid-1;
            ss=mid;
        }
        else
            l=mid+1;
    }
    return ss-1;
}

int main(){
    scanf("%d%lld",&n,&t);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&s,&h,&w,&o);
        m[s].push_back(make_pair(h,o));
        if(s+w<=4000000)
        m[s+w].push_back(make_pair(h,-o));
    }
    int last=0;
    for(int i=1;i<=4000000;i++){
        if(m[i].empty()){
            ans+=last;
            continue;
        }
        for(auto j:m[i]){
            update(1,j.second);
            if(j.first+1<=1000000)
            update(j.first+1,-j.second);
        }
        s=f();
        if(s==-1){
            last=0;
            continue;
        }
        int l,r,mid;
        l=0;r=s-1,w=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(get(s-mid)>=t){
                w=s-mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        l=0,r=s-1,h=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(get(s-mid)<=t){
                h=s-mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        if(h==-1||w==-1){
            last=0;
            continue;
        }
        if(get(h)!=t||get(w)!=t){
            last=0;
        }
        else{
            last=w-h+1;
            ans+=last;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
2 2
3 2 2 2
1 2 2 2
*/
