#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> scores(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> scores[i][j];
        }
        sort(scores[i].begin(), scores[i].end());
        scores[i].erase(scores[i].begin());
        scores[i].pop_back();
    }

    vector<double> averages;
    for (int i = 0; i < n; ++i)
    {
        double sum = 0;
        for (int j = 0; j < m - 2; ++j)
        {
            sum += scores[i][j];
        }
        double average = sum / (m - 2);
        averages.push_back(average);
    }

    double maxAverage = *max_element(averages.begin(), averages.end());

    cout << fixed << setprecision(2);
    cout << maxAverage << endl;

    return 0;
}
