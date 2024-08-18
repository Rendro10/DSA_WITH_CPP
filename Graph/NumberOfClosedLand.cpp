#include<bits/stdc++.h>
using namespace std;

bool isValid(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==0){
            return true;
        }
        return false;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid){
        grid[i][j] = 1;

        int ax[4] = {1,-1,0,0};
        int ay[4] = {0,0,1,-1};

        for(int k=0;k<4;k++){
            int nx = i + ax[k];
            int ny = j + ay[k];

            if(isValid(nx,ny,n,m,grid)){
                dfs(nx,ny,n,m,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();

       //Boundary DFS Traverse to make 0 to 1;

       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(i*j==0 || i==n-1 || j==m-1){
                   if(grid[i][j]==0){
                       dfs(i,j,n,m,grid);
                   }
               }
           }
       }

       // DFS in hole grid to know how much closed land is here->
       int ans =0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==0){
                   ans++;
                   dfs(i,j,n,m,grid);
               }
           }
       }

       return ans;
    }

int main(){

    //LeetCode -> problem 1254(Number of closed isLand)
    vector<vector<int>>grid =  {{1,1,1,1,1,1,1,0},
                                {1,0,0,0,0,1,1,0},
                                {1,0,1,0,1,1,1,0},
                                {1,0,0,0,0,1,0,1},
                                {1,1,1,1,1,1,1,0}};
    cout<<"Number of closed island are/is->"<<closedIsland(grid)<<endl;
    return 0;
}