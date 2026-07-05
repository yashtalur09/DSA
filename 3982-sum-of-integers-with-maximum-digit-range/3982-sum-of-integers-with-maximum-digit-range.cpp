class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxrn=INT_MIN;
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            int mini=INT_MAX;
            int maxi=INT_MIN;
            int n=nums[i];
            while(n>0){
                int rem=n%10;
                maxi=max(maxi,rem);
                mini=min(mini,rem);
                n=n/10;
            }
            int rn=maxi-mini;
            maxrn=max(maxrn,rn);
            temp.push_back(rn);
        }
        int sum=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==maxrn){
                sum+=nums[i];
            }
        }
        return sum;
        
    }
};