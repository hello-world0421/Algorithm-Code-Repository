#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int INF = 0x3f3f3f3f3f;
int n, m;
int a[N], b[N];
int f[N];
int main(){
    cin >> n >> m;
    for (int i = 0; i < N;i++){
        f[i] = INF;
    }
    for (int i = 1; i <= n; i++)
            cin >> a[i];
    for (int i = 1; i <= m;i++)
        cin >> b[i];
    for (int i = 1; i <= n;i++){
        for (int j = m; j >= 0;j--){
            for (int k = 0; k < m / a[i];k++){
                f[]
            }
        }
    }
    cout << f[m];
}