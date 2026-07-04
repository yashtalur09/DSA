class Solution {
    void dfs(int node,unordered_map<int,vector<vector<int>>> &adj,vector<int> &vis,int &ans){
        vis[node]=1;
        for(auto it:adj[node]){
            int adjnode=it[0];
            int cost=it[1];
            ans=min(ans,cost);
            if(!vis[adjnode]){
                
                dfs(adjnode,adj,vis,ans);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans=INT_MAX;
        unordered_map<int,vector<vector<int>>> adj;
        vector<int> vis(n+1,0);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
        dfs(1,adj,vis,ans);
        return ans;
    }
};