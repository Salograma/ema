#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[6];
bool visitado[6] = {false};

void bfs(int inicio){
    queue<int> q;
    q.push(inicio);
    visitado[inicio] = true;

    while(!q.empty()){
        int nodo = q.front(); q.pop(); /*Acá se saca el primero de la fila!*/
        cout << nodo << " ";
        for(int vecino: adj[nodo]){ /*Por cada uno de los vecinos del nodo que estoy buscando, lo visito. Si no lo visito, voy por ahí.*/
            if(!visitado[vecino]){
                visitado[vecino] = true;
                q.push(vecino);
            }
        }
    }
}

void dfs(int nodo){
    visitado[nodo] = true; /*Si no visité a mi vecino, lo sigo vistiando. Eso hace que me extienda por una rama del vecino, para que vuelva en el árbol de recursión a mi siguiente vecino.*/
    cout << nodo << "";
    for(int vecino: adj[nodo]){
        if(!visitado[vecino]){
            dfs(vecino);
        }
    }
}