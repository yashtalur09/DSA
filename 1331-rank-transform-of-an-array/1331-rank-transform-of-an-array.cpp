class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        int rank=1;
        unordered_map<int,int> mpp;
        for(auto it:temp){
            if(!mpp.count(it)){
                mpp[it]=rank++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mpp[arr[i]];
        }
        return arr;
    }
};