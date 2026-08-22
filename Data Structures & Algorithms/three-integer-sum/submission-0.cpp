class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int i = 0;
        while (i < nums.size()) {
            int j=i+1, k=nums.size()-1;
            int target = -nums[i];
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
            i++;
        }

        for (auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};
