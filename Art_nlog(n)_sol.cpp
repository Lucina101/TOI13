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
int lifting(bool z){
    int pos=0;
    long long sum=0;
    for(int j=19;j>=0;j--){
        if(pos+(1<<j)<=1000000&&sum+bit[pos+(1<<j)]+z<=t){
            sum+=bit[pos+(1<<j)];
            pos+=(1<<j);
        }
    }
    if(z) return get(pos+1)==t?pos+1:-1;
    return sum==t?pos:-1;

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
        for(pair<int,int> j:m[i]){
            update(1000000-j.first+1,j.second);
        }
        u=lifting(1);v=lifting(0);
        if(u==-1||v==-1){
            last=0;
        }
        else{
            last=v-u+1;
            ans+=last;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

