class Solution {
public:
    int maxScore(string s) {
        int cnt=0;
        int o=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') o++;
        }
        int x=0;
        int y=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1') x++;
            else y++;
            cnt=max(cnt,y+(o-x));
        }return cnt;
    }
};