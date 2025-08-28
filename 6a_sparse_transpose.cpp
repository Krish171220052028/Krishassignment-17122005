#include <bits/stdc++.h>
using namespace std;

struct Triple { int r,c; long long v; };
using Sparse = vector<Triple>;

Sparse fastTranspose(const Sparse& a, int rows, int cols){
    vector<int> cnt(cols,0);
    for(auto &t: a) cnt[t.c]++;
    vector<int> pos(cols,0);
    for(int i=1;i<cols;i++) pos[i]=pos[i-1]+cnt[i-1];
    Sparse res(a.size());
    for(auto &t: a){
        int p = pos[t.c]++;
        res[p] = {t.c, t.r, t.v};
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,c,nnz; 
    if(!(cin>>r>>c>>nnz)) return 0;
    Sparse a(nnz);
    for(int i=0;i<nnz;i++) cin>>a[i].r>>a[i].c>>a[i].v;
    auto t = fastTranspose(a,r,c);
    for(auto &x: t) cout<<x.r<<" "<<x.c<<" "<<x.v<<"\n";
    return 0;
}
