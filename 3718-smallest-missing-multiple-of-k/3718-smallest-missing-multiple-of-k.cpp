class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans=-1;
        int maxi=*max_element(nums.begin(),nums.end());
        for(int i=k;i<=100000;i=i+k){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
                ans=i;
                break;
            }
        }
        return ans;
    }
};