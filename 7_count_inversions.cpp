#include <bits/stdc++.h>
using namespace std;
long long merge_count(vector<int>& a, int l, int r){
    if(r-l<=1) return 0;
    int m=(l+r)/2;
    long long inv = merge_count(a,l,m)+merge_count(a,m,r);
    vector<int> tmp; tmp.reserve(r-l);
    int i=l,j=m;
    while(i<m && j<r){
        if(a[i]<=a[j]) tmp.push_back(a[i++]);
        else { tmp.push_back(a[j++]); inv += (m - i); }
    }
    while(i<m) tmp.push_back(a[i++]);
    while(j<r) tmp.push_back(a[j++]);
    copy(tmp.begin(), tmp.end(), a.begin()+l);
    return inv;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<merge_count(a,0,n)<<"\n";
    return 0;
}
