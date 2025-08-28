#include <bits/stdc++.h>
using namespace std;

// Lower triangular: i>=j elements stored row-major in 1D of size n(n+1)/2
struct LowerTri {
    int n;
    vector<int> s;
    LowerTri(int n): n(n), s(n*(n+1)/2,0) {}
    int idx(int i,int j) const { return i*(i+1)/2 + j; } // 0-index
    int get(int i,int j) const { if(i<j) return 0; return s[idx(i,j)]; }
    void set(int i,int j,int val){
        if(i<j && val!=0) throw runtime_error("Non-zero above diagonal");
        if(i>=j) s[idx(i,j)]=val;
    }
};

int main(){
    LowerTri M(4);
    int c=1;
    for(int i=0;i<4;i++) for(int j=0;j<=i;j++) M.set(i,j,c++);
    for(int i=0;i<4;i++){ for(int j=0;j<4;j++) cout<<M.get(i,j)<<" "; cout<<"\n"; }
    return 0;
}
