class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int i=0;
        while(i<nums.size()){
            int j=i+1;
            while(j<nums.size()){
                int l=j+1, k=nums.size()-1;
                while(l<k){
                    long long sum = 1LL * nums[l]+nums[k]+ nums[j]+nums[i];
                    if(sum==target){
                        vector<int> temp = {nums[l],nums[k],nums[j],nums[i]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    if(sum>target){k--;}else{l++;}
                }
                j++;
            }
            i++;
        }
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};