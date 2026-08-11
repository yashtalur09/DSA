class Solution {
public:
    bool palindrome(int num){
        string ans="";
        while(num>0){
            ans+=(num%2)+'0';
            num=num/2;
        }
        string temp=ans;
        reverse(temp.begin(),temp.end());
        return temp==ans;
    }
    int func(int n){
        int t=0;
        while(true){
            if(n-t>=0 && palindrome(n-t)){
                return t;
            }
            if(palindrome(n+t)){
                return t;
            }
            t++;
        }
    }
    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        int t=0;
        int i=0;
        while(i<n){
            int ans=func(nums[i]);
            res.push_back(ans);
            i++;
        }
        return res;
    }
};