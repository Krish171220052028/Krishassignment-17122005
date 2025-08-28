#include <bits/stdc++.h>
using namespace std;

// Symmetric: store lower triangular and mirror
struct Symmetric {
    int n;
    vector<int> s; // lower triangle
    Symmetric(int n): n(n), s(n*(n+1)/2,0) {}
    int idx(int i,int j) const { if(i<j) swap(i,j); return i*(i+1)/2 + j; }
    int get(int i,int j) const { return s[idx(i,j)]; }
    void set(int i,int j,int val){ s[idx(i,j)] = val; }
};

int main(){
    Symmetric M(3);
    M.set(0,0,1); M.set(1,0,2); M.set(1,1,3); M.set(2,0,4); M.set(2,1,5); M.set(2,2,6);
    for(int i=0;i<3;i++){ for(int j=0;j<3;j++) cout<<M.get(i,j)<<" "; cout<<"\n"; }
    return 0;
}
