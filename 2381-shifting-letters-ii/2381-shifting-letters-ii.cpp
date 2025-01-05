class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> prefix(n + 1, 0); 

        for (auto &shift : shifts) {
            int a = shift[0];
            int b = shift[1];
            int c = shift[2];
            prefix[a] += (2 * c - 1);
            prefix[b + 1] -= (2 * c - 1);
        }
        int currentShift = 0;
        for (int i = 0; i < n; i++) {
            currentShift = (currentShift + prefix[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + currentShift + 26) % 26; 
        }

        return s;
    }
};