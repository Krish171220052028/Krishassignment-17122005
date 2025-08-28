#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b; if(!(cin>>a>>b)) return 0;
    if(a.size()!=b.size()){ cout<<"NO\n"; return 0; }
    array<int,256> cnt{};
    for(unsigned char c: a) cnt[c]++;
    for(unsigned char c: b) cnt[c]--;
    for(int x: cnt) if(x){ cout<<"NO\n"; return 0; }
    cout<<"YES\n";
    return 0;
}
