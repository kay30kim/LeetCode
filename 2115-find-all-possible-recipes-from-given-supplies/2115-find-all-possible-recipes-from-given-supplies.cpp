class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> graph;
        unordered_map<string,int> indegree;
        for(int i=0; i<ingredients.size(); i++){
            for(auto &ingredient : ingredients[i]){
                graph[ingredient].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        
        queue<string> q;
        for(string ingredient : supplies)
            q.push(ingredient);
        
        while(!q.empty()){
            string ingredient = q.front();
            q.pop();
            for(string recipe : graph[ingredient])
                if(--indegree[recipe]==0)
                    q.push(recipe);
        }
        
        vector<string> ans;
        for(string &recipe : recipes)
            if(indegree[recipe]==0)
                ans.push_back(recipe);
        return ans;
    }
};