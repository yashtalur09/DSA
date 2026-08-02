class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int i=0;
        int j=n-1;
        int alice=0;
        int bob=0;
        while(i<=n/2 && j>i){
            if(piles[i]>=piles[j]){
                alice+=piles[i];
                i++;
            }
            else{
                alice+=piles[j];
                j--;
            }
            if(piles[i]<=piles[j]){
                bob+=piles[i];
                i++;
            }
            else{
                bob+=piles[j];
                j--;
            }
        }
        return alice>bob;
    }
};