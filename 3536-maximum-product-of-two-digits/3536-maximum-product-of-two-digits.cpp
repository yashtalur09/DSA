class Solution {
public:
    int maxProduct(int n) {
        int prod=0;
        while(n>0){
            int rem=n%10;
            n=n/10;
            int temp=n;
            while(temp>0){
                int t=temp%10;
                int p=rem*t;
                prod=max(prod,p);
                temp=temp/10;            }
        }
        return prod;
    }
};