#include<bits/stdc++.h>
using namespace std;
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
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> adj[n];
	int a, b, wt;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> wt;
		adj[a].push_back({b, wt});
		adj[b].push_back({a, wt});
	}
	int key[n];
	int parent[n];
	bool mst[n];
	for (int i = 0; i < n; i++)
	{
		key[i] = INT_MAX;
		mst[i] = false;
		parent[i] = -1;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	key[0] = 0;
	parent[0] = 0;
	pq.push({0, 0});	//weight and index (priority by weight)

	for (int i = 0; i < n - 1; i++)
	{
		int u = pq.top().second;
		pq.pop();
		mst[u] = true;
		for (auto it : adj[u])
		{
			int v = it.first;
			int weight = it.second;
			if (mst[v] == false and weight < key[v])
			{
				parent[v] = u;
				pq.push({key[v], v});
				key[v] = weight;
			}
		}
	}
	int minWeight = 0;
	for (int i = 0; i < n; i++)
		minWeight += key[i];
	cout << minWeight << endl;
}
int32_t main()
{
	basics();
	solve();
	return 0;
}