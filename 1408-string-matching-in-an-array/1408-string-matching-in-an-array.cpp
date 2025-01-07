class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(words[j].find(words[i])!=-1){
                        s.push_back(words[i]);
                        break;
                    }
                }
            }
        }return s;
    }
};