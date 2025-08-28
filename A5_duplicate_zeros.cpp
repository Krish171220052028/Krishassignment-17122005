#include <bits/stdc++.h>
using namespace std;
// Duplicate each occurrence of 0 in-place in fixed-length array
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int zeros=0;
    for(int i=0;i<n;i++) if(a[i]==0) zeros++;
    int i=n-1, j=n-1+zeros;
    // Write from the back; ignore writes with j>=n
    while(i>=0){
        if(j<n) a[j]=a[i];
        if(a[i]==0){
            j--;
            if(j<n) a[j]=0;
        }
        i--; j--;
    }
    for(int k=0;k<n;k++){ if(k) cout<<" "; cout<<a[k]; }
    cout<<"\n";
    return 0;
}
