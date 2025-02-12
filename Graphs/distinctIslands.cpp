#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& visited,vector<pair<int,int>> &vec,int row0,int col0){
    visited[row][col]=1;
    vec.push_back({row- row0,col - col0});
    int m=grid[0].size();
    int n=grid.size();
    int delrow[]={-1,0,1,0};
    int delcol[]={0,-1,0,1};
    for(int i=0;i<4;i++){
        int nrow=row + delrow[i];
        int ncol=col+ delcol[i];
        if(nrow >=0 && nrow<n && ncol >=0 && ncol <m && !visited[nrow][ncol] &&  grid[nrow][ncol]==1){
            dfs(nrow,ncol,grid,visited,vec,row0,col0);
        }
    }
}
int countDistinctIslands(vector<vector<int>>& grid) {
    // code here
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]==1){
            vector<pair<int,int>>vec;
                dfs(i,j,grid,visited,vec,i,j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}
int main(){
    vector<vector<int>> grid= 
   {{1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1},
    {1, 1, 0, 1, 0}};
    cout<<countDistinctIslands(grid);
return 0;
}