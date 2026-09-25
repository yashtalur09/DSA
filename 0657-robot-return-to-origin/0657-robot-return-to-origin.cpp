class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.size();
        int r=0,c=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='U'){
                r=r-1;
            }
            else if(moves[i]=='D'){
                r=r+1;
            }
            else if(moves[i]=='L'){
                c=c-1;
            }
            else if(moves[i]=='R'){
                c=c+1;
            }
        }

        if(r==0 && c==0) return true;
        return false;
    }
};