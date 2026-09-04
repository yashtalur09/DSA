class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi) maxi=nums[i];
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                mini=min(mini,nums[j]);
            }
            int stability=maxi-mini;
            if(stability<=k){
                return i;
            } 
        }
        return -1;
    }
};