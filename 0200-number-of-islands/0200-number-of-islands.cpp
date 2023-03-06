class Solution {
private:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    struct Point{
        int r,c;
    };
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int r, int c){
        queue<Point> q;
        q.push({r,c});
        while(!q.empty()){
            Point now = q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int nr = now.r + dr[k];
                int nc = now.c + dc[k];
                if(nr >=0 && nr<grid.size() && nc>=0 && nc <grid[0].size()){
                    if(grid[nr][nc]=='1' && visited[nr][nc]==0){           
                        visited[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    visited[i][j] = 1;
                    bfs(grid,visited, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};