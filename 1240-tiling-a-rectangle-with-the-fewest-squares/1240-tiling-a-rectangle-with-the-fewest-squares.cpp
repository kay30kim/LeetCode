//The idea is to find the first number (nSquare) that it is possible to fill the grid with nSquare. For a given nSquare, this is a simple DFS with an additional constraint that you cannot go beyond nSquare steps. The complexity grows exponentially with nSquare, so searching every nSquare does not affect the complexity by much, and since n and m are bounded by 13, we should be OK.
class Solution {
private:
    vector<vector<int>> mapp;
    bool dfs(int nNowSquare, int area, int n, int m, int nSquare){ // nSquare is the maximum value that we can reach in this loop
        if(area == n*m) return true; // All the area is filled with 
        if(nNowSquare > nSquare) return false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mapp[i][j]) continue; // already filled
                for(int p=0; i+p<n && j+p<m && mapp[i][j+p]==0; p++){
                    // fill the board with upper left corner at (i, j) and with length l + 1
                    for(int ii=0; ii<=p; ii++){
                        for(int jj=0; jj<=p; jj++){
                            mapp[i+ii][j+jj] = 1;
                        }
                    }
                    
                    if(dfs(nNowSquare+1, area+(p+1)*(p+1),n,m,nSquare)) return true;
                    
                    // remove the filled cells
                    for(int ii=0; ii<=p; ii++){
                        for(int jj=0; jj<=p; jj++){
                            mapp[i+ii][j+jj] = 0;
                        }
                    }
                }
                // you will have to fill the first empty cell you find, so if you haven't succeeded, you fail
                return false;
            }
        }
        return true;
    }
public:
    int tilingRectangle(int n, int m) {
        mapp = vector<vector<int>>(n, vector<int>(m));
        for(int nSquare=1; ; nSquare++)
            if(dfs(1,0,n,m,nSquare))
                return nSquare;
    }
};