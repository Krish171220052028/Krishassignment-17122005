#include <bits/stdc++.h>
using namespace std;

// Tridiagonal: store three diagonals: lower (n-1), main (n), upper (n-1)
struct TriDiagonal {
    int n;
    vector<int> lower, diag, upper;
    TriDiagonal(int n): n(n), lower(n-1,0), diag(n,0), upper(n-1,0) {}
    int get(int i,int j) const {
        if(i==j) return diag[i];
        if(i==j+1) return lower[j];
        if(j==i+1) return upper[i];
        return 0;
    }
    void set(int i,int j,int val){
        if(i==j) diag[i]=val;
        else if(i==j+1) lower[j]=val;
        else if(j==i+1) upper[i]=val;
        else if(val!=0) throw runtime_error("Non-zero outside tri-diagonals");
    }
};

int main(){
    TriDiagonal M(5);
    for(int i=0;i<5;i++) M.set(i,i,10+i);
    for(int i=0;i<4;i++){ M.set(i+1,i,1); M.set(i,i+1,2); }
    for(int i=0;i<5;i++){ for(int j=0;j<5;j++) cout<<M.get(i,j)<<" "; cout<<"\n"; }
    return 0;
}
