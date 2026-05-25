#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int const MAXN = 10000;
queue<pair<int,int>> q;
bool pusheeImpar = false;
int bfs(int k){
    while(!q.empty()){
        pair<int, int> u = q.front(); q.pop();
        if(u.first <= 1){
            continue;
        }
        int hijo = u.first / 2;
        if(hijo == k || (u.first % 2 != 0 && hijo + 1 == k)){
            return u.second + 1;
        }
        q.push({hijo, u.second + 1});
    }
    return -1;
}
int main(){
    int t;
    int ret = -1;
    cin >> t;
    while(t--){
        q = {};
        long long n, k;
        cin >> n >> k;
        q.push({n,0});
        ret = bfs(k);
        if(n == k){
            cout << 0 << endl;
        }
        else{
        cout << ret << endl;
        }
    }
}