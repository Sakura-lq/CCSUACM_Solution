#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline void solve(){
    int n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
    	int x;
    	cin>>x;
    	sum+=x;
	}
	if(sum%n!=0){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
return 0;}