class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(1,-1e7);
        for(int ind = 0; ind<n; ind++) {
            if(arr.back() == nums[ind]) continue;
            if(arr.back() < nums[ind]) arr.push_back(nums[ind]);
            else{
                int i = lower_bound(arr.begin(),arr.end(),nums[ind]) - arr.begin();
                arr[i] = nums[ind];
            }
        }
        return arr.size()-1;
    }
};
