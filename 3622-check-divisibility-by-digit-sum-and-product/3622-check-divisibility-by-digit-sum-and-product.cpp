class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0;
        int prod=1;
        while(temp>0){
            int rem=temp%10;
            sum+=rem;
            prod=prod*rem;
            temp=temp/10;
        }
        int n_sum=sum+prod;
        return n%n_sum==0;
    }
};