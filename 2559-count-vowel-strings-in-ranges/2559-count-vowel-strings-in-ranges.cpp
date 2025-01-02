class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries){
        int x=0;
        int n=words.size();
        vector<int> pre(n+1);
        for(int i=0;i<n;i++){
            int n1=words[i].size();
            if((words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u' ) && (words[i][n1-1]=='a' || words[i][n1-1]=='e' || words[i][n1-1]=='i' || words[i][n1-1]=='o' || words[i][n1-1]=='u' )){
                x++;
                
            }pre[i+1]=x;
        }
        vector<int> v;
        for(int i=0;i<queries.size();i++){
            v.push_back(pre[queries[i][1]+1]-pre[queries[i][0]]);
        }return v;
    }
};