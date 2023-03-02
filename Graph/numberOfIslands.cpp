#include <bits/stdc++.h>
using namespace std;
void doCount(vector<vector<char>>& grid, int i, int j){
    if(i==grid.size() || j==grid[0].size() || i<0 || j<0 || grid[i][j]=='0')
        return;
    grid[i][j] = '0';
    doCount(grid, i+1, j);
    doCount(grid, i, j+1);
    doCount(grid, i-1, j);
    doCount(grid, i, j-1);
}
int numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
        
    int count = 0;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            if(grid[i][j] == '1'){
                doCount(grid, i, j);
                count++;
            }
    return count;
}