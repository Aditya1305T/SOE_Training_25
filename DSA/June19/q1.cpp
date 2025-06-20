class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustee(n+1);
        vector<int> trusted(n+1);

        //here if we dont use auto& i then each element will be copied and then destroyed
        //adds significant overhead for non-Plain Old Data. Also cant benefit from spatial localit
        for(auto& i : trust){
            trustee[i[0]]++;
            trusted[i[1]]++;
        }

        for(int i = 1; i <= n ; i++){
            if(trustee[i] == 0 && trusted[i] == n-1) return i;
        }

        return -1;
    }
};