class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        // if(n==2){
        //     if(nums[0]>nums[1]) return 1;
        //     else return 0;
        // }
        long long sum1=0;
        long long sum2=0;
        int cnt=0;
        for(int i=0;i<n/2;i++){
            sum1+=nums[i];
        }
        for(int i=n/2;i<n;i++){
            sum2+=nums[i];
        }
        if(sum1>sum2) cnt++;
        for(int i=0;i<n-1;i++){
            sum1=sum1+nums[(n/2+i)%n]-nums[i];
            sum2=sum2-nums[(n/2+i)%n]+nums[i];
            if(sum1>sum2) cnt++;
        }
        return cnt;
    }
};