
#include<iostream>
#include<stack>
using namespace std;
class SpecialStack {
    stack<int> s;
    int minEle;
public:
    void push(int x) {
        if (s.empty()) { s.push(x); minEle = x; }
        else {
            if (x < minEle) { s.push(2*x - minEle); minEle = x; }
            else s.push(x);
        }
    }
    void pop() {
        if (s.empty()) return;
        int t = s.top(); s.pop();
        if (t < minEle) minEle = 2*minEle - t;
    }
    int getMin() { return minEle; }
};
int main() {
    SpecialStack st;
    st.push(3); st.push(5);
    cout << "Min: " << st.getMin() << endl;
    st.push(2); st.push(1);
    cout << "Min: " << st.getMin() << endl;
    st.pop();
    cout << "Min: " << st.getMin() << endl;
    return 0;
}
