#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int MAXN = 5;
int adj[MAXN][MAXN];
bool visitados[MAXN] = {false};

void agregarArista(int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void dfs(int u){
    if(!(visitados[u])){
        visitados[u] = true;
        cout << u << endl;
        for(int i = 0; i < MAXN; i++){
            if(adj[u][i] == 1){
                dfs(i);
            }
        }
    }
}

int main(){
    agregarArista(0,1);
    agregarArista(0,2);
    agregarArista(1,3);
    agregarArista(2,4);
    dfs(0);
}