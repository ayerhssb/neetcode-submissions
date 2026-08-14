class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int l=0, r=n;
        while(l<=r){
            //will have to skip duplicate elements
            // while(l<n && nums[l]==nums[l+1]){l++;}
            // while(r>=0 && nums[r]==nums[r-1]){r--;}
            int mid = l+(r-l)/2;
            if(nums[mid]==target){return true;}

            if(nums[l]==nums[mid] && nums[mid]==nums[r]){l++;r--; continue;}

            if(nums[mid]<=nums[r]){
                if(nums[mid]<target && target<=nums[r]){l=mid+1;}else{r=mid-1;}
            }
            else{
                if(target>=nums[l] && target<nums[mid]){r=mid-1;}else{l=mid+1;}
            }
        }
        return false;
    }
};