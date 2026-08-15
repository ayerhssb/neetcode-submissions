/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
   public:
    int findpeak(MountainArray& mountainArr) {
        int ans;
        int l = 0, r = mountainArr.length() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                ans = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int pos = findpeak(mountainArr);
        cout<<"pos: "<<pos<<"\n";
        int l = 0, r = pos, ans = -1, n=mountainArr.length();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) == target) {
                ans = mid;
                r = mid-1;
            } else if (mountainArr.get(mid) > target) {
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        if (ans != -1) {
            return ans;
        }
        l = pos+1, r=n-1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) == target) {
                ans = mid;
                // r = mid-1;
                break;
            } else if (mountainArr.get(mid) > target) {
                l = mid + 1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
};