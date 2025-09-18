
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nearestSmaller(vector<int>& arr) {
    vector<int> result;
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && st.top() >= arr[i]) st.pop();
        if (st.empty()) result.push_back(-1);
        else result.push_back(st.top());
        st.push(arr[i]);
    }
    return result;
}
int main() {
    int n; cout << "Enter size of array: "; cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> res = nearestSmaller(arr);
    cout << "Nearest smaller elements: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
