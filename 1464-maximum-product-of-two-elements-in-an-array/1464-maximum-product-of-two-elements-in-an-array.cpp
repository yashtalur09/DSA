class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==2) return (nums[0]-1)*(nums[1]-1);
        int maxp=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int prod=(nums[i]-1)*(nums[j]-1);
                maxp=max(maxp,prod);
            }
        }
        return maxp;
    }
};