class Solution {
public:
    int findMin(vector<int>& nums, int target){
        int s = 0, e = nums.size() - 1;
        while(s < e){
            int mid = s + (e - s) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[e]){
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return e;
    }

    int bs(vector<int>& nums, int start, int end, int target){
        if(end < start) return -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) return mid;

            if(nums[mid] > target){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        // first find min element from there binary search on left and right half
        int mini = findMin(nums, target);
        // if target haas been found before finding min
        if(nums[mini] == target) return mini;

        int ans = -1;
        // binary search on left sorted
        ans = bs(nums, 0, mini-1, target);
        if(ans != -1) return ans;

        // binary search on right sorted
        return bs(nums, mini, nums.size()-1, target); 
    }
};
