class Solution {
public:

    string binaryString(char c){
        int n=(int) c;
        string temp="00000000";
        string t="";
        while(n>0){
            int rem=n%2;
            t+=to_string(rem);
            n=n/2;
        }
        for(int i=0;i<t.size();i++){
            temp[8-i-1]=t[i];
        }
        return temp;
    }
    
    
    bool isPalindromic(string s) {
        string temp1="";
        for(auto c:s){
            temp1+=binaryString(c);
        }
        int i=0;
        int j=temp1.size()-1;
        while(i<j){
            if(temp1[i]!=temp1[j]){
                return false;
                
            }
            i++;
            j--;
        }
        return true;
    }
};