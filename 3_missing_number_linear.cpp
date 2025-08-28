#include <bits/stdc++.h>
using namespace std;

// Linear-time using arithmetic sum
// Input: n-1 numbers sorted, from 1..n with one missing
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; 
    if(!(cin>>m)) return 0; // m = n-1
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    long long n = m+1;
    long long expected = n*(n+1)/2;
    long long actual = accumulate(a.begin(), a.end(), 0LL);
    cout << (expected - actual) << "\n";
    return 0;
}
