class Solution {
public:
unordered_map<int,vector<int>> m;
void rec(vector<int>& p,int& r,int y,vector<int>&m1){
    for(int i=0;i<p.size();i++){
        if(p[i]==y){
            r=1;
            return;
        }else if(m.count(p[i]) && m1[p[i]]==0){
            m1[p[i]]=1;
            rec(m[p[i]],r,y,m1);
        }
    }
}

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& p, vector<vector<int>>& q) {

        for(int i=0;i<p.size();i++){
            m[p[i][0]].push_back(p[i][1]);
        }vector<bool> v;
        for(int i=0;i<q.size();i++){
            vector<int> m1(numCourses);
            int x=q[i][0];
            int y=q[i][1];
            int l=0,r=0;
            if(m.count(x)) {
                l=1;
                rec(m[x],r,y,m1);
            }if(l && r) v.push_back(true);
            else v.push_back(false);
        }return v;
    }
};