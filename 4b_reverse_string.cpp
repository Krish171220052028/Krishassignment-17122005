#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; 
    getline(cin,s);
    if(s.size()==0) getline(cin,s);
    reverse(s.begin(), s.end());
    cout<<s<<"\n";
    return 0;
}
