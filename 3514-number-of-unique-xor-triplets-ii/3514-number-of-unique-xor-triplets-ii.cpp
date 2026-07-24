class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return n;
        unordered_set<int> st1,st2;
        for(int i=0;i<n;i++){
            st1.insert(0);
            for(int j=i+1;j<n;j++){
                int tem=nums[i]^nums[j];
                st1.insert(tem);
            }
        }
        for(auto it:st1){
            for(auto n:nums){
                st2.insert(it^n);
            }
        }
        return st2.size();
    }
};