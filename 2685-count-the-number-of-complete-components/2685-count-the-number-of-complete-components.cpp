class Solution {
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &comp,vector<pair<int,int>> &edg){
        vis[node]=1;
        comp.push_back(node);
        for(auto nei:adj[node]){
            if(node < nei){
                edg.push_back({node,nei});
            }
                
            if(!vis[nei]){
                dfs(nei,adj,vis,comp,edg);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt=0;
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<vector<int>> components;
        vector<vector<pair<int,int>>> eds;
        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                vector<int> comp;
                vector<pair<int,int>> edg;
                dfs(i,adj,vis,comp,edg);
                components.push_back(comp);
                eds.push_back(edg);
            }
        }

        for(int i=0;i<components.size();i++){
            int v=components[i].size();
            int edges=eds[i].size();
            int x=v*(v-1)/2;
            if(edges==x) cnt++;
        }
        return cnt;
    }
};