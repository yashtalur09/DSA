class Solution {
public:
    string reverseWords(string s) {
        vector<string> t;
        string ans="";
        int n=s.size();
        int i=0;
        while(i<n){
            string temp="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            if(temp.size()>0) t.push_back(temp);
            i++;
        }
        reverse(t.begin(),t.end());
        for(auto it:t){
            string temp2=it;
            for(int i=0;i<temp2.size();i++){
                ans+=temp2[i];
            }
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};