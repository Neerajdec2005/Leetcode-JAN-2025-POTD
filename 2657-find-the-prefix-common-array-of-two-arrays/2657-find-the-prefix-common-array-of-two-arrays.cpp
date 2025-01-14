class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> m;
        vector<int> v;
        int c=0;
        for(int i=0;i<A.size();i++){
            m[A[i]]++;
            m[B[i]]++;
            if(m[A[i]]==2) c++;
            if(A[i]!=B[i] && m[B[i]]==2) c++;
            v.push_back(c);
        }return v;
    }
};