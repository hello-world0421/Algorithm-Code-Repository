#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    double H, W;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> H >> W;
        double stdW = (H - 100.0) * 0.9;
        W = W / 2.0;
        if(abs(W - stdW) < stdW * 0.1)
            cout << "You are wan mei!" << endl;
        else  if(W - stdW >= stdW * 0.1)
            cout << "You are tai pang le!" << endl;
        else
            cout << "You are tai shou le!" << endl;
    }

    return 0;
}