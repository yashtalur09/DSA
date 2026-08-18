class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
      
        unordered_map<int, int> freq;

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        if(k==1){
            sort(nums.begin(),nums.end());
            for(int i=n-1;i>=0;i--){
                if(freq[nums[i]]==1) return nums[i];
            }
        }
        if(k==n){
            int maxi=*max_element(nums.begin(),nums.end());
            return maxi;
        }
        if(k>1 && k<n){
            if(freq[nums[0]]==1 && freq[nums[n-1]]==1){
                return max(nums[0],nums[n-1]);
            }
            else if(freq[nums[0]]==1 && freq[nums[n-1]]>1){
                return nums[0];
            }
            else if(freq[nums[0]]>1 && freq[nums[n-1]]==1){
                return nums[n-1];
            }
            else{
                return -1;
            }
        }
        return -1;
    }
};