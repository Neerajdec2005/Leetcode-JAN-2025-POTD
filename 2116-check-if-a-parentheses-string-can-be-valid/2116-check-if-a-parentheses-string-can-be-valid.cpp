class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()&1==1) return false;
        int w=0;
        int a=0;
        int b=0;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0') w++;
            else{
                if(s[i]=='(') a++;
                else b++;
            }if(w+a<b) return false;
        }
        w=0,a=0,b=0;
        for(int i=s.size()-1;i>=0;i--){
            if(locked[i]=='0') w++;
            else{
                if(s[i]=='(') a++;
                else b++;
            }if(w+b<a) return false;
        }return true;
    }
};