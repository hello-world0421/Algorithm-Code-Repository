#include <bits/stdc++.h>
using namespace std;

static const int MAXSIZE = 9e4 + 5;
int father[MAXSIZE];
int cols, sets;

int flatIndex(int a, int b)
{
    return a * cols + b;
}

void Build(int n, int m, vector<vector<char>> grid)
{
    cols = m;
    sets = 0;
    for (int a = 0; a < n; a++)
        for (int b = 0, ind; b < m; b++)
            if (grid[a][b] == '1')
            {
                ind = flatIndex(a, b);
                father[ind] = ind;
                sets++;
            }
}

int Find(int i)
{
    if (i != father[i])
        father[i] = Find(father[i]);
    return father[i];
}

void Union(int a, int b, int c, int d)
{
    int fx = Find(flatIndex(a, b));
    int fy = Find(flatIndex(c, d));
    if (fx != fy)
    {
        father[fx] = fy;
        sets--;
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    Build(n, m, grid);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '1')
            {
                if (j > 0 && grid[i][j - 1] == '1')
                    Union(i, j, i, j - 1);
                if (i > 0 && grid[i - 1][j] == '1')
                    Union(i, j, i - 1, j);
            }
    return sets;
}