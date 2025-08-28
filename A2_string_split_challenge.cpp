#include <bits/stdc++.h>
using namespace std;
// Split s into three non-empty consecutive parts s1|s2|s3 such that
// one part is a substring of both of the other two.
bool check(const string& s){
    int n = s.size();
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            string a = s.substr(0,i);
            string b = s.substr(i, j-i);
            string c = s.substr(j);
            auto sub = [](const string& x, const string& y){ return x.find(y)!=string::npos; };
            if(sub(a,b) && sub(c,b)) return true;
            if(sub(b,a) && sub(c,a)) return true;
            if(sub(a,c) && sub(b,c)) return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; if(!(cin>>s)) return 0;
    cout<<(check(s) ? "YES" : "NO")<<"\n";
    return 0;
}
