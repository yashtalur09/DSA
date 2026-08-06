class Solution {
public:

    int prod(long long n){
        int prd=1;
        while(n>0){
            int rem=n%10;
            prd=rem*prd;
            n=n/10;
        }
        return prd;
    }

    int smallestNumber(int n, int t) {
        long long temp=n;
        long long ans=0;
        int i=1;
        while(i<=10){
            int te=prod(temp);
            if(te%t==0){
                ans=temp;
                break;
            }
            if (temp == LLONG_MAX) break; 
            temp=temp+1;
            i++;
        }
        return ans;
    }
};