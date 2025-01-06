class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());

        int b1=0,m1=0;
        int b2=0,m2=0;

        for(int i=0;i<boxes.size();i++){
            ans[i]+=m1;
            b1+=boxes[i]-'0';
            m1+=b1;

            int j=boxes.size()-1-i;
            ans[j]+=m2;
            b2+=boxes[j]-'0';
            m2+=b2;
        }return ans;

    }
};