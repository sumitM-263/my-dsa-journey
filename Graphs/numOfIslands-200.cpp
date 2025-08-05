#include <bits/stdc++.h>
using namespace std;

// using bfs
void solve(vector<vector<char>> &grid, int i, int j)
{
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = '0';

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if (x + 1 < m && grid[x + 1][y] == '1')
        {
            q.push({x + 1, y});
            grid[x + 1][y] = '0';
        }

        if (x - 1 >= 0 && grid[x - 1][y] == '1')
        {
            q.push({x - 1, y});
            grid[x - 1][y] = '0';
        }

        if (y + 1 < n && grid[x][y + 1] == '1')
        {
            q.push({x, y + 1});
            grid[x][y + 1] = '0';
        }

        if (y - 1 >= 0 && grid[x][y - 1] == '1')
        {
            q.push({x, y - 1});
            grid[x][y - 1] = '0';
        }
    }

    return;
}

// using dfs
void dfs(vector<vector<char>>& grid,int m, int n, int i, int j){

    if(i>=m || i<0 || j>=n || j<0 || grid[i][j] == '0') return;

    grid[i][j] = '0';

    dfs(grid,m,n,i+1,j);
    dfs(grid,m,n,i-1,j);
    dfs(grid,m,n,i,j+1);
    dfs(grid,m,n,i,j-1); 

    return;
}

int numIslands(vector<vector<char>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                ans++;
                dfs(grid, m, n, i, j);
            }
        }
    }

    return ans;
}
