class Solution {
public:
    int magicalString(int n) {
        string one = "12";
        string two = "122";
        int i = 1;
        int j = 2;
        int count = 1; //as j has 1 one already

        if(n < 4) return 1;

        while(two.length() < n){
            one += two[j];
            i++;
            int times = one[i] - '0';
            char ch = (two[ two.length() - 1] == '1' ? '2' : '1');
            if(ch == '1') count+=times; //count ones while adding them (handles >n condition later)
            for(int p = 0; p < times; p++){
                two+= ch;
            }
            j++;
        }

        //handling case where adding 1s exceed n, thus will have to subtract no. of ones that appear after n
        if(two[n] == '1'){  
            count -= two.length()-n;
        }

        // int count = 0;
        // for(int p = 0; p < n; p++){
        //     if(two[p] == '1') count++;
        // }
        // cout<<one<<endl<<two;
        return count;
    }
};