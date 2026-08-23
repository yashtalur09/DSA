class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }
        vector<vector<int>> ans;
        for(int i=lower;i<=upper;i++){
            if(mpp.find(i)==mpp.end()){
                if(ans.empty() || ans.back()[1]+1!=i){
                    ans.push_back({i,i});
                }
                else{
                    ans.back()[1]=i;
                }
            }
        }
        return ans;
    }
};