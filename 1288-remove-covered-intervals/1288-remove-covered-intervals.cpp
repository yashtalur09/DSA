class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int siz=intervals.size();
        int n=intervals.size();
        int j=0;
        while(j<n){
            auto it=intervals[j];
            int a=it[0];
            int b=it[1];
            for(int i=0;i<n;i++){
                if(i==j) continue;
                auto temp=intervals[i];
                int c=temp[0];
                int d=temp[1];
                if(c<=a && b<=d){
                    siz--;
                    break;
                }
            }
            j++;
        }
        return siz;
    }
};