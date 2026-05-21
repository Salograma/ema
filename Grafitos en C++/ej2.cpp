#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[5];

void agregarArista(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void mostrar(){
    for(int i = 0; i < 5; i++){
        for(int vecino: adj[i]) cout << i << "->" << vecino << " ";
        cout << "\n";
    }
}

int main(){
    agregarArista(0,1);
    agregarArista(0,3);
    agregarArista(1,2);
    mostrar();
}