#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    getline(cin,a);
    if(a.size()==0) getline(cin,a);
    getline(cin,b);
    cout << (a + b) << "\n";
    return 0;
}
