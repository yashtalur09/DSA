class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n>m) return false;
        int j=0;
        
        vector<int> pref(n,m),suff(n,-1);
        for(int i=0;i<n;i++){
            while(j<m && s[i]!=t[j]){
                j++;
            }
            if(j<m){
                pref[i]=j;
                j++;
            }
            else{
                break;
            }
        }
        j=m-1;
        for(int i=n-1;i>=0;i--){
            while(j>=0 && s[i]!=t[j]) j--;
            if(j>=0){
                suff[i]=j;
                j--;
            }
            else{
                break;
            }
        }
        for(int i=0;i<n;i++){
            int a=i-1<0?-1:pref[i-1];
            int b=i+1>=n?m:suff[i+1];
            if(a!=m && b!=-1 && b-a>=2) return true;
        }
        return false;
    }
};