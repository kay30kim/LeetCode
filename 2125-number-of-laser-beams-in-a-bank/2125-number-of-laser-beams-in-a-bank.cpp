class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;
        for (auto str : bank) {
            int cnt = 0;
            for (auto cha : str) {
                if (cha == '1')
                    cnt++;
            }
            if (cnt != 0) {
                ans += (prev * cnt);
                prev = cnt;
            }
        }
        return ans;
    }
};