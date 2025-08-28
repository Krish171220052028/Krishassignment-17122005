#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& a){
    int n=a.size();
    bool swapped=true;
    for(int i=0;i<n-1 && swapped;i++){
        swapped=false;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                swapped=true;
            }
        }
    }
}

int main(){
    vector<int> a = {64,34,25,12,22,11,90};
    bubble_sort(a);
    for(size_t i=0;i<a.size();++i){
        if(i) cout<<" ";
        cout<<a[i];
    }
    cout<<"\n";
    return 0;
}
