class Solution {
public:
    void rotate(string &s){
        int n=s.size();
        char c=s[0];
        for(int i=1;i<n;i++){
            s[i-1]=s[i];
        }
        s[n-1]=c;
    }
    int countRotations(string s, int k) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int score=0;
            for(int j=0;j<n-1;j++){
                if(s[j]==s[j+1]){
                    score++;
                }
            }
            if(score==k) cnt++;
            rotate(s);
        }
        return cnt;
    }
};