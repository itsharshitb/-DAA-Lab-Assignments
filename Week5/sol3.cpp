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
int main()
{
    io();
    int n, m, i, j, flag = 0;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    int b[m];
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);
    i = j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            printf("%d ", a[i]);
            i++;
            j++;
            flag = 1;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
    if (flag == 0)
        printf("No Common Element");
    return 0;
}