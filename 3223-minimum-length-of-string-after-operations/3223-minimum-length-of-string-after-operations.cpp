class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++) m[s[i]]++;

        int c=0;
        for(auto x:m){
            if(x.second>=3){
                if(x.second&1==1) c++;
                else c+=2;
            }
            else c+=x.second;
        }return c;
    }
};