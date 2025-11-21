#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    std::string s;
    
    std::cin >> n >> s;
    bool ok = false;
    for(int i = 0; i < n; i++){
        if(ok){
            s[i] ^= 1;
        }
        if(s[i] == '1'){
            ok = !ok;
        }
    }
    std::cout << s << std::endl;
    return 0;
}