class Solution {
private:
    struct Point{
        int r,c;
    };
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    bool visited[51][51];
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        image[sr][sc] = color;
        
        queue<Point> q;
        q.push({sr,sc});
        
        while(!q.empty()){
            Point now = q.front();
            q.pop();
            
            for(int k=0; k<4; k++){
                int nr = now.r + dr[k];
                int nc = now.c + dc[k];
                if(nr>=0 && nc >=0 && nr<image.size() && nc<image[0].size()){
                    if(image[nr][nc]==startColor && visited[nr][nc]==false){
                        visited[nr][nc] = true;
                        image[nr][nc]=color;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return image;
    }
};