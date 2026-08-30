class Solution {
public:
    long long power(long long x, long long y, long long mod) {
    long long ans = 1;

    while (y > 0) {
        if (y & 1)
            ans = (ans * x) % mod;

        x = (x * x) % mod;
        y >>= 1;
    }

    return ans;
}
    int sumDecoded(vector<long long>& nums) {
        int mod=1e9+7;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            long long width=nums[i] % 10;
            long long di = floor(nums[i] / 10);
            string temp1=to_string(di);
            string temp2=temp1.substr(0,width);
            string temp3=temp1.substr(width,temp1.size()-width);
            int x=stoi(temp2);
            int y=stoi(temp3);
            sum=(sum+power(x,y,mod))%mod;
        }
        return sum;
    }
};