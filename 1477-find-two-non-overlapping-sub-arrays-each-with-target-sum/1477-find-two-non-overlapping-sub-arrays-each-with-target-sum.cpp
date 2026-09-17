class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> leasttill(n,INT_MAX);
        int i=0;
        int j=0;
        int sum=0;
        int result=INT_MAX;
        int bestmin=INT_MAX;
        while(j<n){
            sum+=arr[j];
            while(sum>target){
                sum-=arr[i];
                i++;
            }
            if(sum==target){
                int len=j-i+1;
                if(i>0 && leasttill[i-1]!=INT_MAX){
                    result=min(result,len+leasttill[i-1]);
                }
                bestmin=min(bestmin,len);
                
            }
            leasttill[j]=bestmin;
            j++;
        }
        return result==INT_MAX?-1:result;
    }
};