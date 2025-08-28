#include <bits/stdc++.h>
using namespace std;
bool isv(char c){
    string v="aeiouAEIOU";
    return v.find(c)!=string::npos;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; 
    getline(cin,s);
    if(s.size()==0) getline(cin,s);
    string t; t.reserve(s.size());
    for(char c: s) if(!isv(c)) t.push_back(c);
    cout<<t<<"\n";
    return 0;
}
