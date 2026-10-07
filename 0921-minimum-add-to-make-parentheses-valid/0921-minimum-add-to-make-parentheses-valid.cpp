class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        if(n==0) return 0;
        stack<int> st;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    cnt++;
                }
            }
        }
        return st.size()+cnt;
    }
};