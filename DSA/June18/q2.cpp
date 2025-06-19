class Solution {
  public:
    int findSingle(vector<int> &arr) {
        int ans = 0;
        for(auto i : arr){
            ans ^= i;
        }
        return ans;
        
    }
};