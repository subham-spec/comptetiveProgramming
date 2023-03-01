#include <bits/stdc++.h>
using namespace std;
void add(vector<int> adj[], int i, int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}
