class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());

        int l=0,r=1;
        while(r<n){
            if(abs(v[r-1].first-v[r].first)<=limit){
                r++;
            }else{
                vector<int> x;
                for(int i=l;i<r;i++){
                    x.push_back(v[i].second);
                }sort(x.begin(),x.end());
                for(int i=0;i<x.size();i++){
                    nums[x[i]]=v[l+i].first;
                }
                l=r;
                r++;
            }
        }
        if(r>l){
            vector<int> x;
            for(int i=l;i<r;i++){
                x.push_back(v[i].second);
            }sort(x.begin(),x.end());
            for(int i=0;i<x.size();i++){
                nums[x[i]]=v[l+i].first;
            }
        }
        return nums;
    }
};