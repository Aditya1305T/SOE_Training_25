class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        //using kadane's algorithm
        int sum = 0;
        int max_sum = INT_MIN;
        for(int i =0 ; i < n; i++){
            sum = max(nums[i], sum+nums[i]);
            max_sum = max(max_sum,sum);
        }
        return max_sum;
    }
};