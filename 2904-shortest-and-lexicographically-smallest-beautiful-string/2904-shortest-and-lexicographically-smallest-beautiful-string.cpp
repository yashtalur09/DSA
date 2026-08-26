class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        string ans="";
        int siz=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1') cnt++;
                if(cnt==k){
                    string temp="";
                    temp+=s.substr(i,j-i+1);
                    int t_size=temp.size();
                    if(t_size<siz){
                        ans=temp;
                        siz=t_size;
                    }
                    else if(t_size==siz){
                        if(temp<ans){
                            ans=temp;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};