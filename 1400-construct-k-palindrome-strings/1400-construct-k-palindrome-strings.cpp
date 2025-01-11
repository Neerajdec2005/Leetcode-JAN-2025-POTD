class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int h=0;
        for(auto x:m){
            if(x.second&1==1) h++;
        }
        if(h>k) return false;
        else return true;
    }

};