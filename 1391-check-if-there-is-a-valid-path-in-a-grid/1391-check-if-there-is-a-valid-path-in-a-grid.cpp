class Solution {

    unordered_map<int,vector<vector<int>>> directions={
        {1,{{0,-1},{0,1}}},
        {2,{{-1,0},{1,0}}},
        {3,{{0,-1},{1,0}}},
        {4,{{0,1},{1,0}}},
        {5,{{0,-1},{-1,0}}},
        {6,{{-1,0},{0,1}}},
    };
    
    bool dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis){
        int m=grid.size();
        int n=grid[0].size();
        if(i==m-1 && j==n-1) return true;
        vis[i][j]=true;

        for(auto &dir:directions[grid[i][j]]){
            int new_i=i+dir[0];
            int new_j=j+dir[1];

            if(new_i<0 || new_i>=m || new_j<0 || new_j>=n || vis[new_i][new_j]){
                continue;
            }

            for(auto &backDir:directions[grid[new_i][new_j]]){
                if(new_i+backDir[0]==i && new_j+backDir[1]==j){
                    if(dfs(grid,new_i,new_j,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        return dfs(grid,0,0,vis);
    }
};