class Solution {
    void func(int ind,vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds){
        int n=nums.size();
        
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        func(ind+1,nums,ans,ds);
        ds.pop_back();
        func(ind+1,nums,ans,ds);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        func(0,nums,ans,ds);
        return ans;
    }
};