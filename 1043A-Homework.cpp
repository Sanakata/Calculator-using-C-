#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n;
        string a, b, c; cin >> a >> m >> b >> c;
        for(int i = 0; i < m; i++) (c[i] == 'D' ? a += b[i] : a = b[i] + a);
        cout << a << "\n";
    }
}