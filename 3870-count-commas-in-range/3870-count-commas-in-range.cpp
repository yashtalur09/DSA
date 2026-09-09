class Solution {
public:
    int countCommas(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(i<1000) cnt+=0;
            else if(i>=1000 && i<=100000) cnt+=1;
            else if(i>=100000 && i<=10000000) cnt+=2;
            else if(i>=10000000 && i<=1000000000) cnt+=3;
            else if(i>=1000000000 && i<=100000000000) cnt+=4;
            else if(i>=100000000000 && i<=10000000000000) cnt+=5;
            else if(i>=10000000000000 && i<=1000000000000000) cnt+=6;
        }
        return cnt;
    }
};