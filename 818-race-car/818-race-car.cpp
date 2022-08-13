class Solution {
private:
    int ans;
    struct Point{
        int speed;
        int position;
        int length;
    };
    queue<Point> q;
    map<string,int> visited;
public:
    void bfs(int depth, int speed, int target, int position){
        q.push({1,0,0});
        while(!q.empty()){
            Point now = q.front();
            q.pop();
            
            string nvisited = to_string(now.position)+'_'+to_string(now.speed);
            if(visited[nvisited]==1) continue;
            visited[nvisited]=1;
            
            //printf("%d %d %d\n",now.speed, now.position, now.length);
            if(target==now.position){
                ans=now.length;
                //printf("옴!! %d %d",now.position, now.length);
                break;
            }
            
            // accelerate
            if(now.position+now.speed < target*2){
                if(now.position+now.speed>0)
                    q.push({now.speed*2,now.position+now.speed,now.length+1});
            }
            
            // reverse
            if(now.speed>0)
                q.push({-1,now.position,now.length+1});
            else
                q.push({1,now.position,now.length+1});
        }
    }
    
    int racecar(int target) {
        bfs(0,0,target,0);
        return ans;
    }
};