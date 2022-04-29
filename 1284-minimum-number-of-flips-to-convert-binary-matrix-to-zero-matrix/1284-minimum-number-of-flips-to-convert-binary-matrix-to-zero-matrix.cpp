class Solution {
private:
    map<vector<vector<int>>, int> visited; // 2-dimension visited map
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
public:
    int minFlips(vector<vector<int>>& mat) {
        if(mat.empty()) return -1;
        int steps = 0;
        queue<vector<vector<int>>> q;
        q.push(mat);
        visited[mat] = 1;
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                vector<vector<int>> v = q.front();
                q.pop();
                if(check(v)) return steps;
                for(int i=0; i<v.size(); i++){
                    for(int j=0; j<v[0].size(); j++){
                        vector<vector<int>> temp = v;
                        changeMat(temp, i,j);
                        if(!visited[temp]){
                            q.push(temp);
                            visited[temp] = 1;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
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