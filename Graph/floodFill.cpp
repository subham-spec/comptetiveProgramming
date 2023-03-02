#include <bits/stdc++.h>
using namespace std;
void doCount(vector<vector<int>>& image, int sr, int sc, int color, int dr[], int dc[], vector<vector<int>>& ans, int pick){
    ans[sr][sc] = color;
    for(int i=0; i<4; i++){
        int y = sc+dc[i];
        int x = sr+dr[i];
        if(x>=0 && y>=0 && x<image.size() && y<image[0].size() && ans[x][y]!=color && image[x][y]==pick)
            doCount(image, x, y, color, dr, dc, ans, pick);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    vector<vector<int>> ans = image;
    int pick = image[sr][sc];
    doCount(image, sr, sc, color, dr, dc, ans, pick);

    return ans;
}