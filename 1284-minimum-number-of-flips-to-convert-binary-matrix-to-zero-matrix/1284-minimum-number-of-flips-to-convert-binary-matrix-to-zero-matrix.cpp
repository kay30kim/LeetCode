class Solution {
private:
    map<vector<vector<int>>,int> visited;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
public:
    int minFlips(vector<vector<int>>& mat) {
        if(mat.empty()) return -1;
        queue<vector<vector<int>>> q;
        q.push(mat);
        visited[mat] = 1;
        int step = 0;
        
        while(!q.empty()){
            int len = q.size();
            printf("%d\n",step);
            for(int i=0; i<len; i++){
                vector<vector<int>> now = q.front();
                q.pop();
                print(now);
                if(check(now)) return step;
                for(int i=0; i<now.size(); i++){
                    for(int j=0; j<now[i].size(); j++){
                        vector<vector<int>> temp = now;
                        changeMat(temp, i, j);
                        if(!visited[temp]){
                            q.push(temp);
                            visited[temp] = 1;
                        }
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
    void print(vector<vector<int>> mat){
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                printf("%d ",mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    bool check(vector<vector<int>> mat){
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j])
                    return false;
            }
        }
        return true;
    }
    void changeMat(vector<vector<int>> &mat, int r, int c){
        mat[r][c] = !mat[r][c];        
        for(int k=0; k<4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr<0 || nr>=mat.size() || nc<0 || nc>=mat[0].size()) continue;
            mat[nr][nc] = !mat[nr][nc];
        }
    }
};