
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && T[i] > T[st.top()]) {
            int idx = st.top(); st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }
    return ans;
}
int main() {
    int n; cout << "Enter number of days: "; cin >> n;
    vector<int> T(n);
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) cin >> T[i];
    vector<int> res = dailyTemperatures(T);
    cout << "Days to wait for warmer temp: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
