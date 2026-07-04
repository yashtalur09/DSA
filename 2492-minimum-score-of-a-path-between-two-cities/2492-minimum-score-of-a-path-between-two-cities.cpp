class Solution {
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
        queue<pair<int,int>> q;
        for(auto temp:adj[1]){
            q.push({temp[0],temp[1]});
            vis[temp[0]]=1;
        }
        
        vis[1]=1;
        while(!q.empty()){
            auto it=q.front();
            int node=it.first;
            int cost=it.second;
            q.pop();
            
            for(auto it:adj[node]){
                ans=min(ans,it[1]);
                if(!vis[it[0]]){
                    q.push({it[0],it[1]});
                    vis[it[0]]=1;
                }
            }
        }
        return ans;
    }
};