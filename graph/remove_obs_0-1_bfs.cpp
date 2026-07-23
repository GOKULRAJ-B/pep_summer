
//https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/?envType=problem-list-v2&envId=graph
class Solution {
public:
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        dist[0][0]=0;

        dq.push_front({0,0});
        int x_pos[] = {-1,1,0,0};
        int y_pos[] = {0,0,-1,1};
        while(!dq.empty()){
            auto [x,y] = dq.front();
            dq.pop_front();
            if (x == n - 1 && y == m - 1) return dist[x][y];
            for(int i=0;i<4;i++){
                int nx = x + x_pos[i];
                int ny = y + y_pos[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                int wt = grid[nx][ny];
                if(dist[x][y]+wt < dist[nx][ny]){
                    dist[nx][ny] = wt+dist[x][y];
                    if(wt==0) dq.push_front({nx,ny});
                    else dq.push_back({nx,ny});
                }
            }
        }
        return dist[n-1][m-1];
    }
};