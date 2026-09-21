class Solution {
public:

    int noofstu(vector<int>& arr,int n,int pgs){
        int pages=0,students=1;
        for(int i=0;i<n;i++){
            if(pages+arr[i]<=pgs){
                pages+=arr[i];
            }
            else{
                students+=1;
                pages=arr[i];
            }
        }
        return students;
    }


    int findPages(vector<int>& arr, int n, int m) {
        // Write your code here.
        if(m>n) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int totalStudents=noofstu(arr,n,mid);
            if(totalStudents>m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }

    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};