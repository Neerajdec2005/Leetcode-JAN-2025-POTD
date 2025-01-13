class Solution {
public:
    int minimumLength(string s) {
        vector<int> v(26);
        int n=s.size();
        for(int i=0;i<n;i++) v[s[i]-'a']++;

        int cnt=0;
        for(int i=0;i<26;i++){
            if(v[i]!=0){
                if(v[i]&1==1) cnt++;
                else cnt+=2;
            }
        }return cnt;
    }
};