class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3];
        for(auto i : nums){
            arr[i]++;
        }
        int ind = 0;
        for(int i = 0; i < 3; i++){ 
            for(int j=0; j < arr[i]; j++){
                nums[ind++] = i;
            }
        }
    }
};