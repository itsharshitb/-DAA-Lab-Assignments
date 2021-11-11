#include <bits/stdc++.h>
using namespace std;
void io()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
bool dfs(int **g, int n, int source, int dest)
{
    stack<int> s;
    int mark[n] = {0};
    s.push(source);
    mark[0] = 1;
    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        for (int i = 0; i < n; i++)
        {
            if (g[v][i] == 1)
            {
                if (i == dest)
                    return true;
                if (mark[i] == 0)
                {
                    s.push(i);
                    mark[i] = 1;
                }
            }
        }
    }
    return false;
}
int main()
{
    io();
    int n;
    scanf("%d", &n);
    int **g = new int *[n];
    for (int i = 0; i < n; i++)
    {
        g[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    int s, d;
    scanf("%d%d", &s, &d);
    if (dfs(g, n, s - 1, d - 1))
        cout << "Path Exist.";
    else
        cout << "Path Not Exist.";
    return 0;
}