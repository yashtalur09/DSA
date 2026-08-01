class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        long long sum=0;
        while(n!=0 && !seen.count(n)){
            seen.insert(n);
            int sum=0;
            while(n>0){
            long long rem=n%10;
            sum=sum+rem*rem;
            n=n/10;
            }
            n=sum;

        }
        return n==1;
       
    }
};