#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

int head[MAXN], nxt[MAXN], to[MAXN], cnt;
int heap[MAXN], heapSize, indegree[MAXN], ans[MAXN];
int n, m;

void build(int n)
{
    cnt = 1;
    heapSize = 0;
    fill_n(head, n + 1, 0);
    fill_n(indegree, n + 1, 0);
}

void addEdge(int u, int v)
{
    nxt[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}

void swap(int i, int j)
{
    int tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

void push(int num)
{
    int i = heapSize++;
    heap[i] = num;
    while (heap[i] < heap[(i - 1) / 2])
    {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

int pop()
{
    int ans = heap[0];
    heap[0] = heap[--heapSize];
    int i = 0;
    int l = 1;
    while (l < heapSize)
    {
        int best = l + 1 < heapSize && heap[l + 1] < heap[l] ? l + 1 : l;
        best = heap[best] < heap[i] ? best : i;
        if (best == i)
            break;
        swap(best, i);
        i = best;
        l = i * 2 + 1;
    }
    return ans;
}

bool isEmpty()
{
    return heapSize == 0;
}

void topoSort()
{
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            push(i);
    int fill = 0;
    while (!isEmpty())
    {
        int cur = pop();
        ans[fill++] = cur;
        for (int ei = head[cur]; ei != 0; ei = nxt[ei])
            if (--indegree[to[ei]] == 0)
                push(to[ei]);
    }
}

int main()
{
    cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0, from, to; i < m; i++)
    {
        cin >> from >> to;
        addEdge(from, to);
        indegree[to]++;
    }
    topoSort();
    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << ' ';
    cout << ans[n - 1] << '\n';

    return 0;
}