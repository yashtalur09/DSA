class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=mini;i<maxi;i++){
            if(!count(nums.begin(),nums.end(),i)){
                ans.push_back(i);

            }
        }
        return ans;
    }
};