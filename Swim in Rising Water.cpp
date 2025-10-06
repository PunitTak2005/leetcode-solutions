#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        
        pq.push({grid[0][0], 0, 0});
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int t = cur[0], x = cur[1], y = cur[2];
            if (x == n-1 && y == n-1) return t;
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1; // should not reach
    }
};
