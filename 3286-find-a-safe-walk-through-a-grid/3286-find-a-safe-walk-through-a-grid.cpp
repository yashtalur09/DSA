class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> best(m,vector<int>(n,-1));
        int startHealth=health-grid[0][0];
        if(startHealth<=0) return false;
        q.push({{0,0},startHealth});
        best[0][0]=startHealth;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int heal=q.front().second;
            q.pop();
            if(row==m-1 && col==n-1) return true;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    int newheal=heal-grid[nrow][ncol];
                    if(newheal>0 && newheal>best[nrow][ncol]){
                        best[nrow][ncol]=newheal;
                        q.push({{nrow,ncol},newheal});
                        
                    }
                }
            }
        }
        return false;
    }
};