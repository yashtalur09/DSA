class Solution {
public:

    static bool cmp(const pair<int,int>& a,const pair<int,int>& b){
        return a.second>b.second;
    }

    string frequencySort(string s) {
        int n=s.size();
        vector<int> freq(256,0);
        vector<pair<int,int>> p;
        for(char c:s){
            freq[c]++;
        }
        for(int i=0;i<256;i++){
            if(freq[i]>0){
                p.push_back({char(i),freq[i]});
            }
        }
        string ans="";
        sort(p.begin(),p.end(),cmp);
        for(auto it:p){
            int temp=it.second;
            while(temp!=0){
                ans+=it.first;
                temp--;
            }
        }
        return ans;
    }
};