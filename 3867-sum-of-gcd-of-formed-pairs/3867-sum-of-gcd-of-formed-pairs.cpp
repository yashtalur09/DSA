class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefixGcd(n,0);
        int mx=nums[0];
        prefixGcd[0]=nums[0];
        for(int i=1;i<n;i++){
            mx=max(mx,nums[i]);
            prefixGcd[i]=__gcd(mx,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i=0;
        int j=n-1;
        long long sum=0;
        while(i<j){
            sum+=__gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};