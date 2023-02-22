#include <bits/stdc++.h>
using namespace std;
int main(){

}
int largestRectangleArea(vector<int>& arr) {
    int l = arr.size()-1;
    int l_min[l+1];
    stack<int> stk;
    for(int i=0; i<=l; i++){
        while(!stk.empty() && arr[stk.top()] >= arr[i])
            stk.pop();
        if(stk.empty())
            l_min[i] = 0;
        else
            l_min[i] = stk.top()+1;
        stk.push(i);
    }

    stack<int> stk2;
    int r_min[l+1];
    for(int i=l; i>=0; i--){
        while(!stk2.empty() && arr[stk2.top()] >= arr[i])
            stk2.pop();
        if(stk2.empty())
            r_min[i] = l;
        else
            r_min[i] = stk2.top()-1;
        stk2.push(i);
    }
    int ans = 0;
    for(int i=0; i<=l; i++)
        ans = max(ans, (r_min[i]-l_min[i]+1)*arr[i]);

    return ans;
}


