class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> l;
        for(int i=0;i<s.size();i++) l.insert(s[i]);

        int cnt=0;
        for(auto x:l){
            int i=-1;
            int j=0;
            for(int k=0;k<s.size();k++){
                if(s[k]==x){
                    j=k;
                    if(i==-1){
                        i=k;
                    }
                }
            }
            unordered_set<int> l1;
            for(int k=i+1;k<j;k++){
                l1.insert(s[k]);
            }cnt+=l1.size();
        }
        
        return cnt;
    }
};