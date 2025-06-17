class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        int total = 0;
        int x = 0;
        for(auto i : nums){
            mp[i]++;
            total+=i;
            if(mp[i] == 1) x+=i;
        }

        return x*2 - total;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val=0;
        for(auto i : nums){
            val^=i;
        }
        return val;
    }
};