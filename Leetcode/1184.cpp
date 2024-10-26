#include <bits/stdc++.h>
using namespace std;

int distanceBetweenBusStops(vector<int>& distance, int s, int t) {
    int n = distance.size();
    if (s > t) {
        swap(s, t);
    }
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        if (i >= s && i < t) d1 += distance[i];
        else d2 += distance[i];
    }
    return (d1 < d2 ? d1 : d2);
}