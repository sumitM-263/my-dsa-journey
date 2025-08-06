#include <bits/stdc++.h>
using namespace std;

// using dfs
void dfs(vector<vector<char>>& A, int i, int j){

    int m = A.size();
    int n = A[0].size();

    if(i<0 || i>=m || j<0 || j>=n || A[i][j] != 'O') return ;


    A[i][j] = '1';
    dfs(A,i+1,j);
    dfs(A,i-1,j);
    dfs(A,i,j+1);
    dfs(A,i,j-1);

}

// using bfs
void bfs(vector<vector<char>>& A, int i, int j){

    int m = A.size();
    int n = A[0].size();

    queue<pair<int,int>> q;

    q.push({i,j});

    A[i][j] = '1';

    while(!q.empty()){

        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        

        if(x+1<m && A[x+1][y] == 'O'){
            A[x+1][y] = '1';
            q.push({x+1,y});
        }
        if(x-1>=0 && A[x-1][y] == 'O'){
            A[x-1][y] = '1';
            q.push({x-1,y});
        }
        if(y+1<n && A[x][y+1] == 'O'){
            A[x][y+1] = '1';
            q.push({x,y+1});
        }
        if(y-1>=0 && A[x][y-1] == 'O'){
            A[x][y-1] = '1';
            q.push({x,y-1});
        }
    }
}


void solve(vector<vector<char>>& mat){

    int m = mat.size();
    int n = mat[0].size();

    for(int i=0;i<m;i++){
        if(mat[i][0] == 'O'){
            bfs(mat,i,0);
        }

        if(mat[i][n-1] == 'O'){
            bfs(mat,i,n-1);
        }
    }

    for(int j=0;j<n;j++){

        if(mat[0][j] == 'O'){
            bfs(mat,0,j);
        }

        if(mat[m-1][j] == 'O'){
            bfs(mat,m-1,j);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == '1'){
                mat[i][j] = 'O';
            }
            else if(mat[i][j] == 'O'){
                mat[i][j] = 'X';
            }
        }
    }
}


int main(){

    int m, n;
    cin >> m >> n;

    vector<vector<char>> A(m,vector<char>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
    }

    solve(A);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}