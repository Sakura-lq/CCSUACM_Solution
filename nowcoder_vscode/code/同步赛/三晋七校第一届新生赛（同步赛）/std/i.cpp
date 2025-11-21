#include <iostream>
using namespace std;

int main() {
    int n,x;
    cin>>n>>x;
    int cnt=0;
    bool r=false;
    while(x>0){
        int a=n/2,b=n-n/2;
        if(!r&&a%2==1&&b%2==1) //第一次分的时候 分出来两个奇数情况下
            a--,b++;
        x-=a;
        cnt++;
        n-=a;
        r=true;
    }
    cout<<cnt<<'\n';
    return 0;
}