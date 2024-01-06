class Solution {
public:
    int findMaxProfit(vector<vector<int>> jobs) {
        int n = jobs.size(), maxProfit = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for (int i = 0; i < n; i ++) {
            int start = jobs[i][0], end = jobs[i][1], profit = jobs[i][2];
            
            while (!pq.empty() && start >= pq.top()[0]) {
                maxProfit = max(maxProfit, pq.top()[1]);
                pq.pop();
            }
            pq.push({end, profit + maxProfit});
        }
        while (pq.empty() == 0) {
            maxProfit = max(maxProfit, pq.top()[1]);
            pq.pop();
        }
        return maxProfit;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        return findMaxProfit(jobs);
    }
};