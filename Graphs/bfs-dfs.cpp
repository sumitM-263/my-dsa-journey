#include <bits/stdc++.h>
using namespace std;

// direct, connected graph

void bfs(unordered_map<int,vector<int>>& adj, int src, vector<bool>& vis, vector<int>& res){

    queue<int> q;

    q.push(src);

    vis[src] = true;

    while(!q.empty()){

        int u = q.front();
        q.pop();

        res.push_back(u);

        for(auto& v: adj[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }

    return;
}

void dfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& vis, vector<int>& res){

    vis[u] = true;

    res.push_back(u);

    for(auto& v: adj[u]){
        if(!vis[v]){
            dfs(adj,v,vis,res);
        }
    }

    return;
}

vector<int> getBFS(unordered_map<int,vector<int>>& adj,int V){

    vector<int> res;

    vector<bool> visited(V, false);

    bfs(adj, 0, visited, res);

    return res;

}

vector<int> getDFS(unordered_map<int,vector<int>>& adj,int V){

    vector<int> res;
    vector<bool> visited(V, false);

    dfs(adj, 0, visited, res);

    return res;

}

int main(){

    int V, E;
    cin >> V >> E;

    unordered_map<int,vector<int>> adj;

    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);

    }

    vector<int> bfs = getBFS(adj,V);
    vector<int> dfs = getDFS(adj,V);

    for(auto& i: bfs){
        cout << i << ' ';

    }

    cout << '\n';

    for(auto& i: dfs){
        cout << i << ' ';
    }

    cout << '\n';
}