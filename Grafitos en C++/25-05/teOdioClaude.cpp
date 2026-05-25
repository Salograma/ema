#include <iostream>
#include <bits/stdc++.h>
using namespace std;


const int MAXN = 4;
vector<vector<int>> adj(MAXN);
stack<int> s;
vector<int> visited(MAXN);

void agregarArista(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int actual, int padre){
    while(!s.empty()){
        int u = s.top();
        visited[u] = true;
        s.pop();
        for(int vecino: adj[u]){
            s.push(vecino);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < n; i++){
        cin >> u >> v;
        agregarArista(u,v);
    }
    dfs(1,0);
}