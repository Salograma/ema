#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5;
int adj[MAXN][MAXN] = {0};

void agregarArista(int u, int v){
    adj[u][v] = 1;
}

void mostrar() {
    for (int i = 0; i < MAXN; i++){
        for (int j = 0; j < MAXN; j++){
            cout << "Nodo:" << i << " " << j << "\n";
            cout << adj[i][j] << "\n";
        }
    }
}

int main(){
    char entrada = 's';
    while(entrada != '*'){
        int a, b;
        cout << "Ingrese la arista (u,v) que tiene este grafo separada por espacios" << endl;
        cin >> a >> b;
        agregarArista(a,b);
        cout << "Desea continuar? * si no";
        cin >> entrada;
    }
    mostrar();
}