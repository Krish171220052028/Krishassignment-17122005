#include <bits/stdc++.h>
using namespace std;
struct Triple{int r,c; long long v;};
using Sparse = vector<Triple>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,c,n1,n2;
    if(!(cin>>r>>c>>n1>>n2)) return 0;
    Sparse A(n1), B(n2);
    for(int i=0;i<n1;i++) cin>>A[i].r>>A[i].c>>A[i].v;
    for(int i=0;i<n2;i++) cin>>B[i].r>>B[i].c>>B[i].v;
    sort(A.begin(),A.end(),[](auto &x, auto &y){ return tie(x.r,x.c)<tie(y.r,y.c); });
    sort(B.begin(),B.end(),[](auto &x, auto &y){ return tie(x.r,x.c)<tie(y.r,y.c); });
    Sparse C; C.reserve(n1+n2);
    int i=0,j=0;
    while(i<n1 || j<n2){
        if(j==n2 || (i<n1 && tie(A[i].r,A[i].c)<tie(B[j].r,B[j].c))){
            C.push_back(A[i++]);
        }else if(i==n1 || tie(B[j].r,B[j].c)<tie(A[i].r,A[i].c)){
            C.push_back(B[j++]);
        }else{
            long long v = A[i].v + B[j].v;
            if(v!=0) C.push_back({A[i].r,A[i].c,v});
            i++; j++;
        }
    }
    for(auto &t: C) cout<<t.r<<" "<<t.c<<" "<<t.v<<"\n";
    return 0;
}
