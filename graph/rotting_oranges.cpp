//https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i,j});
            }
        }
        if(fresh==0) return 0;
        int minutes = 0;
        while(!q.empty() && fresh>0){
            int size = q.size();
            while(size--){
            pair<int,int> frontCell = q.front();
            q.pop();

            int r = frontCell.first;
            int c = frontCell.second;

            if(r>0 && grid[r-1][c]==1){
                grid[r-1][c] = 2;
                fresh--;
                q.push({r-1,c});
            }

            if(r<rows-1 && grid[r+1][c] == 1){
                grid[r+1][c] = 2;
                fresh--;
                q.push({r+1,c});
            }

            if(c>0 && grid[r][c-1]==1){
                grid[r][c-1] = 2;
                fresh--;
                q.push({r,c-1});
            }

            if(c+1< cols && grid[r][c+1]==1){
                grid[r][c+1] = 2;
                fresh--;
                q.push({r,c+1});
            }
            }


            minutes++;
        }

        if(fresh>0) return -1;
        return minutes;
    }
};