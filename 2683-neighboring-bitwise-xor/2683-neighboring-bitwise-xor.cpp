class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x=0;
        for(int i=0;i<derived.size();i++){
            if(derived[i]==1) x++;
        }
        if(x&1) return false;
        return true;
    }
};