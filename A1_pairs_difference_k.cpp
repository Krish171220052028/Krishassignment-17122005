#include <bits/stdc++.h>
using namespace std;
// Count pairs (i<j) with |a[i]-a[j]| == k using two pointers on sorted array
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; long long k; if(!(cin>>n>>k)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    long long cnt=0;
    int i=0,j=1;
    while(j<n){
        long long diff = a[j]-a[i];
        if(i==j || diff<k) j++;
        else if(diff>k) i++;
        else{ // diff==k
            if(a[i]==a[j]){ // handle duplicates
                long long c1=1,c2=1;
                while(j+1<n && a[j+1]==a[j]){ c2++; j++; }
                while(i+1<j && a[i+1]==a[i]){ c1++; i++; }
                cnt += c1 * c2;
                i++; j++;
            }else{
                long long c1=1,c2=1;
                while(i+1<j && a[i+1]==a[i]){ c1++; i++; }
                while(j+1<n && a[j+1]==a[j]){ c2++; j++; }
                cnt += c1 * c2;
                i++; j++;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
