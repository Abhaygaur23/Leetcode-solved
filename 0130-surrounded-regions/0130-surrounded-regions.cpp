class Solution {
public:
    void dfs(int r, int c,vector<vector<int>>& vis, vector<vector<char>>& mat,int dx[],int dy[]){
        vis[r][c] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]=='O' && !vis[nr][nc]){
                dfs(nr,nc,vis,mat,dx,dy);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int dx[4] = {-1,0,1,0}; 
        int dy[4] = {0,1,0,-1}; 
        for(int i = 0; i<n; i++){
            if(mat[i][0]=='O' && !vis[i][0]){
                dfs(i,0,vis,mat,dx,dy);
            }
            if(mat[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,vis,mat,dx,dy);
            }
        }
        for(int i = 0; i<m; i++){
            if(mat[0][i]=='O' && !vis[0][i]){
                dfs(0,i,vis,mat,dx,dy);
            }
            if(mat[n-1][i]=='O' && !vis[n-1][i]){
                dfs(n-1,i,vis,mat,dx,dy);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]=='O' && !vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        return;
    }
};