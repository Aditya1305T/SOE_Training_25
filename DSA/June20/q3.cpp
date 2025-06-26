class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int max_ones = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                ones++;
            }
            else{
                max_ones = max(max_ones, ones);
                ones = 0;
            }
        }
        max_ones = max(max_ones, ones);
        return max_ones;
    }
};