#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int suma = 0;
        for(int i = 2*n-1; i > n-1; i--){
            suma += a[i];
        }
        cout >> a[i];
    }
}