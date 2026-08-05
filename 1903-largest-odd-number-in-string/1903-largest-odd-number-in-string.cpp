class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int ind=-1;
        for(int i=num.size()-1;i>=0;i--){
            int n = stoi(string(1, num[i]));
            if(n%2==1){
                ind=i;
                break;
            }
        }
        for(int i=0;i<=ind;i++){
            ans+=num[i];
        }
        return ans;
    }
};