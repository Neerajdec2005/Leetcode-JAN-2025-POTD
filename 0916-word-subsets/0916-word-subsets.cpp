class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
           vector<int> v(26);

           for(int i=0;i<words2.size();i++){
                vector<int> x(26);
                for(int j=0;j<words2[i].size();j++){
                    x[words2[i][j]-'a']++;
                }
                for(int j=0;j<26;j++){
                    if(x[j]>v[j]){
                        v[j]=x[j];
                    }
                }
           }

           vector<string> vm;

           for(int i=0;i<words1.size();i++) {
                vector<int> p(26);
                for(int j=0;j<words1[i].size();j++){
                    p[words1[i][j]-'a'] ++;
                }
                int x=1;
                for(int j=0;j<26;j++){
                    if(v[j]>p[j]){
                        x=0;
                        break;
                    }
                }if(x==1) vm.push_back(words1[i]);
           }return vm;
    }
};