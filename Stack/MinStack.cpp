#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int>> st;
int mini;
MinStack() {
    mini = INT_MAX;
}
void push(int data) {
    mini = min(mini, data);
    st.push({data, mini});
}    
void pop() {
    if(st.empty())
        return;
    st.pop();
    if(st.empty())
        mini = INT_MAX;
    else
        mini = st.top().second;       
}
int top() {
    if(st.empty())
        return -1;
    return st.top().first;
}    
int getMin() {
    return st.top().second;
}
