class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int min1=0,min2=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]<=min1){
                min2=min1;
                min1=nums[i];
            }
            else if(min2>=nums[i]){
                min2=nums[i];
            }
        }
        int prod1=nums[n-1]*nums[n-2]*nums[n-3];
        int prod2=min1*min2*nums[n-1];
        return max(prod1,prod2);

    }
};