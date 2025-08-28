#include <bits/stdc++.h>
using namespace std;
struct Triple{int r,c; long long v;};
using Sparse = vector<Triple>;

// Multiply A (r x k) * B (k x c). Input as triplets. Output as triplets.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,k,c,n1,n2;
    if(!(cin>>r>>k>>c>>n1>>n2)) return 0;
    Sparse A(n1), B(n2);
    for(int i=0;i<n1;i++) cin>>A[i].r>>A[i].c>>A[i].v; // c is in [0,k)
    for(int i=0;i<n2;i++) cin>>B[i].r>>B[i].c>>B[i].v; // r is in [0,k)
    // Build maps: row->(col,val) for A, col-by-row for B (i.e., B grouped by row)
    unordered_map<int, vector<pair<int,long long>>> Arow, Brow;
    for(auto &t: A) Arow[t.r].push_back({t.c,t.v});
    for(auto &t: B) Brow[t.r].push_back({t.c,t.v}); // B grouped by k-index
    map<pair<int,int>, long long> acc;
    for(auto &[i, vecA]: Arow){
        for(auto &[kidx, Aval]: vecA){
            auto it = Brow.find(kidx);
            if(it==Brow.end()) continue;
            for(auto &[j, Bval]: it->second){
                acc[{i,j}] += Aval * Bval;
            }
        }
    }
    vector<Triple> C;
    C.reserve(acc.size());
    for(auto &p: acc){
        if(p.second!=0) C.push_back({p.first.first, p.first.second, p.second});
    }
    sort(C.begin(),C.end(),[](auto &x, auto &y){ return tie(x.r,x.c)<tie(y.r,y.c); });
    for(auto &t: C) cout<<t.r<<" "<<t.c<<" "<<t.v<<"\n";
    return 0;
}
