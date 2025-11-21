#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5+10;
int tot;
int sum[N*32];
int root[N],ls[N*32],rs[N*32],a[N];
int sumall[N],sum1[N],sum0[N];
int n;

void pushup(int u){
    sum[u]=sum[ls[u]]+sum[rs[u]];
}

void modify(int &u,int v,int l,int r,int p){
    if(!u)u=++tot;
    if(l==r){
        sum[u]=sum[v]+p;
        return ;
    }
    int mid = l+r>>1;
    if(p<=mid){
        rs[u]=rs[v];
        modify(ls[u],ls[v],l,mid,p);
    }
    else{
        ls[u]=ls[v];
        modify(rs[u],rs[v],mid+1,r,p);
    }
    pushup(u);
}

ll query(int u,int v,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr){
        return sum[u]-sum[v];
    }
    int mid = l+r>>1;
    ll ret = 0;
    if(mid>=ql)ret+=query(ls[u],ls[v],l,mid,ql,qr);
    if(mid+1<=qr)ret+=query(rs[u],rs[v],mid+1,r,ql,qr);
    return ret;
}

void solve(){
    cin>>n;
    int mx = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i])modify(root[i],root[i-1],1,mx,a[i]);
        else root[i]=root[i-1];
        sumall[i]=sumall[i-1]+a[i];
        if(a[i]==1)sum1[i]++;
        if(a[i]==0)sum0[i]++;
        sum1[i]+=sum1[i-1];
        sum0[i]+=sum0[i-1];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        //处理最大可能取到的mex值
        ll mex = 0;
        if(sum0[r]-sum0[l-1]){
            mex = 1;
            while(1){
                ll tmp = query(root[r],root[l-1],1,mx,1,mex);
                if(tmp>=mex)mex=tmp+1;
                else break;
            }
        }
        ll ans = 0;
        //mex=0
        ans = sumall[r]-sumall[l-1];
        //mex=1
        if(mex){
            ll num1 = sum1[r]-sum1[l-1];
            ll s = sumall[r]-sumall[l-1];
            ll tmp = s^1;
            //mex=0的情况>=(s-1)^1,这步可以没有
            if(num1)tmp = max(tmp,(s-1)^1);
            ans = max(ans,tmp);
        }
        //mex>1,gd=1
        if(mex){
            //mex=1时 s^1>=(mex-1)^1
            ll tmp = max((mex-1)^1,mex^1);
            ans = max(ans,tmp);
        }
        cout<<ans<<"\n";
    }
}


int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _= 1;
    // cin>>_;
    while(_--)solve();
}