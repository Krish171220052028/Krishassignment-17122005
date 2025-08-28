#include <bits/stdc++.h>
using namespace std;

// Upper triangular: i<=j stored; index mapping row-major by columns after i
struct UpperTri {
    int n;
    vector<int> s;
    UpperTri(int n): n(n), s(n*(n+1)/2,0) {}
    int idx(int i,int j) const { // 0-indexed
        // number of elements in rows before i in upper triangle
        return i*n - (i*(i-1))/2 + (j - i);
    }
    int get(int i,int j) const { if(i>j) return 0; return s[idx(i,j)]; }
    void set(int i,int j,int val){
        if(i>j && val!=0) throw runtime_error("Non-zero below diagonal");
        if(i<=j) s[idx(i,j)] = val;
    }
};

int main(){
    UpperTri M(4);
    int c=1;
    for(int i=0;i<4;i++) for(int j=i;j<4;j++) M.set(i,j,c++);
    for(int i=0;i<4;i++){ for(int j=0;j<4;j++) cout<<M.get(i,j)<<" "; cout<<"\n"; }
    return 0;
}
