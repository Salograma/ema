#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
int n, m;
int cat[MAXN];        
bool visitado[MAXN];
vector<int> adj[MAXN];

void agregarArista(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u); 
}

int resultado = 0;

void dfs(int nodo, int padre, int gatos){
    if (cat[nodo] == 1){
        gatos++;
    }
    else{
        gatos = 0;
    }

    if (gatos > m) return;

    bool esHoja = true;
    visitado[nodo] = true;

    for(int vecino : adj[nodo]){
        if(vecino != padre){
            esHoja = false;
            dfs(vecino, nodo, cat[nodo]);
        }
    }

    if(esHoja) resultado++;
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> cat[i];

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        agregarArista(u, v);
    }

    dfs(1, 0, cat[1]);
}