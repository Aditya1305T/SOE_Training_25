class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(mp[target - nums[i]]){
                return {i,mp[target - nums[i]]-1};
            }
            else{
                mp[nums[i]] = i+1;
            }
        }
        return {};
    }
};