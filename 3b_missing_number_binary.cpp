#include <bits/stdc++.h>
using namespace std;

// Binary search on sorted array of length n-1 with values 1..n
// At correct position i, we expect a[i] == i+1. Find first index where mismatch occurs.
int missing_binary(const vector<int>& a){
    int l=0, r=(int)a.size()-1, ans=(int)a.size(); // default missing is n if all prefix matches
    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid] == mid+1) l = mid+1;
        else { ans = mid; r = mid-1; }
    }
    return ans+1; // position ans should be value ans+1
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; 
    if(!(cin>>m)) return 0;
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    cout<<missing_binary(a)<<"\n";
    return 0;
}
