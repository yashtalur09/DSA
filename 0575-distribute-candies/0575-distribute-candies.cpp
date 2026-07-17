class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        int cnt=0;
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(candyType[i]);
        }
        if(st.size()==n/2 || st.size()>n/2) return n/2;
        return st.size();
        
    }
};