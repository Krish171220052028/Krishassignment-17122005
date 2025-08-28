#include <bits/stdc++.h>
using namespace std;

// Store only diagonal elements of an n x n diagonal matrix
struct Diagonal {
    int n;
    vector<int> d; // size n
    Diagonal(int n): n(n), d(n,0) {}
    int get(int i,int j) const { // 0-indexed
        if(i==j) return d[i];
        return 0;
    }
    void set(int i,int j,int val){
        if(i==j) d[i]=val;
        else if(val!=0) throw runtime_error("Non-zero off-diagonal in Diagonal matrix");
    }
};

int main(){
    Diagonal M(4);
    M.set(0,0,5); M.set(1,1,8); M.set(2,2,3); M.set(3,3,9);
    // print dense
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) cout<<M.get(i,j)<<" ";
        cout<<"\n";
    }
    return 0;
}
