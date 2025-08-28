#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char c; 
    if(!(cin>>c)) return 0;
    if('A'<=c && c<='Z') c = char(c - 'A' + 'a');
    cout<<c<<"\n";
    return 0;
}
