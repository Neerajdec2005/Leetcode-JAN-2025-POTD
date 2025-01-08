class Solution {
public:

    bool pre(string s,string t){
        int r=t.find(s);
        int k=t.find(s,t.size()-s.size());
        if(r==0 && k==(t.size()-s.size())) return true;
        return false;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                if(pre(words[i],words[j])) cnt++;
            }
        }return cnt;
    }
};