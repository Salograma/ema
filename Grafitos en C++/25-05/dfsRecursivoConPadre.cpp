#include <iostream>
#include <bits/stdc++.h>
using namespace std;


const int MAXN = 5;
vector<vector<int>> adj(MAXN);
vector<int> visited(MAXN, false);
bool hayCiclo = false;
void agregarArista(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int actual, int padre){
    if(!visited[actual]){
        visited[actual] = true;
        for(int vecino: adj[actual]){
            if(visited[vecino] && vecino != padre){
                hayCiclo = true;
                break;
            }
            dfs(vecino, actual);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        agregarArista(u,v);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, 0);
        }
    }
    cout << (hayCiclo ? "SI": "NO") << "\n";
}