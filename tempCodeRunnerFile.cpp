#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        if(n < 3){
            if(a*n < b){
                cout << a*n << endl;
            }
            else{
                cout << b << endl;
            }
        }
        else{
        if(3*a <= b){
            cout << a*n << "\n";
        }
        else{
            cout << n/3 * b + (n % 3) * a << "\n";
        }
    }
}
}