
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
int main() {
    int n; cout << "Enter size of array: "; cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> res = nextGreater(arr);
    cout << "Next greater elements: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
