class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int longest=1;
        int lastsmaller=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]-1==lastsmaller){
                count++;
                lastsmaller=nums[i];
            }
            else if(nums[i]!=lastsmaller){
                count=1;
                lastsmaller=nums[i];
            }
            longest=max(count,longest);
        }
        return longest;
        
    }
};