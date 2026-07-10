class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        int maxi=0;
        int n=nums.size();
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        if(mpp.size()<3){
            int ans=*max_element(nums.begin(),nums.end());
            return ans;
        }
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(st.find(nums[i])==st.end() && cnt<3){
                st.insert(nums[i]);
                cnt++;
                maxi=nums[i];
            }
        }
        return maxi;
    }
};