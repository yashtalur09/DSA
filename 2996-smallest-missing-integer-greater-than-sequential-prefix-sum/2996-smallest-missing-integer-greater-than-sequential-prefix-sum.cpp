class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int prefix=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]+1){
                break;
            }
            else{
                prefix+=nums[i];
            }
        }
        int ans=-1;
        bool flag=true;
        while(flag){
            if(find(nums.begin(),nums.end(),prefix)==nums.end()){
                flag=false;
                ans=prefix;
                break;
            }
            prefix++;
        }
        return ans;
    }
};