class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;

        sort(nums.begin(), nums.end());

        for(int a = 0; a < n-2; a++){
            if(a > 0 && nums[a] == nums[a-1]){
                continue;
            }

            int b = a+1;
            int c = n-1;
            while(b<c){
                if(nums[a]+nums[b]+nums[c] > 0){
                    c--;
                }
                else if(nums[a]+nums[b]+nums[c] < 0){
                    b++;
                }
                else{
                    output.push_back({nums[a],nums[b],nums[c]});
                    b++;
                    while( nums[b-1] == nums[b] && b<c){
                        b++;
                    }
                }
            }
        }

        return output;

    }
};