class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x=0;
        int n=derived.size();
        for(int i=0;i<n;i++){
            x^=derived[i];
        }
        if(x) return false;
        return true;
    }
};