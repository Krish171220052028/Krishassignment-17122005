#include <bits/stdc++.h>
using namespace std;

// Iterative binary search: returns index or -1
int binary_search_iter(const vector<int>& a, int target){
    int l=0, r=(int)a.size()-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid]==target) return mid;
        else if(a[mid]<target) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; 
    // Demo: read sorted array then target
    // Example: 7\n1 3 5 7 9 11 13\n9
    if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>x;
    cout<<binary_search_iter(a,x)<<"\n";
    return 0;
}
