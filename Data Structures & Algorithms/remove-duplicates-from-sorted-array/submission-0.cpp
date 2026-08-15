class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=i+1, cnt=1;
        while(j<nums.size()){
            if(nums[j]!=nums[i]){
                cnt++;
                i++;nums[i]=nums[j];j++;
            }
            else{j++;}
        }
        return cnt;
    }
};