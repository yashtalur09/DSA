class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans(n);
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        for(auto it:mpp){
            auto &pos=it.second;

            long long sum=0;
            for(auto x:pos) sum+=x;

            int m=pos.size();
            long long leftsum=0;

            for(int i=0;i<m;i++){
                long long rightsum=sum-leftsum-pos[i];

                long long left=1ll*pos[i]*i-leftsum;
                long long right=rightsum-1ll*pos[i]*(m-i-1);
                ans[pos[i]]=left+right;
                leftsum+=pos[i];
            }
        }

        return ans;
    }
};