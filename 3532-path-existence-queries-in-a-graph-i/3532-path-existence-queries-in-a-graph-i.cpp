class Solution {
    class disjointset{
    public:
    vector<int> parent,size;
    disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findupar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findupar(parent[node]);
    }

    void unionbysize(int u,int v){
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

};
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        disjointset ds(n);
        
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])<=maxDiff){
                ds.unionbysize(i,i+1);
            }
        }
        int q=queries.size();
        vector<bool> ans(q,false);
        
        for(int i=0;i<q;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(ds.findupar(u)==ds.findupar(v)){
                ans[i]=true;
            }
        }
        return ans;
    }
};