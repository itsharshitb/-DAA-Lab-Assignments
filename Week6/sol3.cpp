#include<bits/stdc++.h>
using namespace std;
#define int long long
#define w(x) int  x; cin>>x; while(x--)
void basics()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int n, flag = 0;
vector<vector<int>> arr;
vector<int> vis;
void dfs(int node)
{
	if (vis[node] == -1)
	{
		flag = 1;
		return;
	}
	vis[node] = -1;
	for (auto x : arr[node])
	{
		if (vis[x] != 1)
			dfs(x);
	}
	vis[node] = 1;
}
void solve()
{
	cin >> n;
	vis.resize(n + 1, 0);
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		arr[node1].push_back(node2);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
			if (flag == 1)
				break;
		}
	}
	if (flag)
		cout << "Cycle exist" << endl;
	else
		cout << "Cycle not exist" << endl;
}
int32_t main()
{
	basics();
	solve();
	return 0;
}