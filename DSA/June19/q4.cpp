class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0;
        int j = 0;
        int n = s.size();
        int m = g.size();
        while(j < n && i < m){
            if(s[j] >= g[i]){
                i++;
            }

            j++;
        }
        return i;
    }
};