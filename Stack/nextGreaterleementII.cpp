#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> ans(nums.size());
    stack<int> stk;
    int n = nums.size();
    for(int i=nums.size()*2-1; i>=0; i--){
        while(!stk.empty() && stk.top()<=nums[i%n])
            stk.pop();
        if(i<n){
            if(!stk.empty())
                ans[i] = stk.top();
            else
                ans[i] = -1;
        }
        stk.push(nums[i%n]);
    }
    return ans;
}
int main(){

}
