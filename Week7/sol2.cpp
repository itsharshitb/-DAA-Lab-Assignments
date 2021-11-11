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
struct node {
	int u;
	int v;
	int wt;
	node(int first, int second, int w) {
		u = first;
		v = second;
		wt = w;
	}
};
int main() {
	basics();
	int n, m;
	cin >> n >> m;
	vector<node> edges;
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back(node(u, v, wt));
	}
	int src;
	cin >> src;
	int inf = 10000000;
	vector<int> dist(n, inf);
	dist[src] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (auto it : edges) {
			if (dist[it.u] + it.wt < dist[it.v]) {
				dist[it.v] = dist[it.u] + it.wt;
			}
		}
	}
	int fl = 0;
	for (auto it : edges) {
		if (dist[it.u] + it.wt < dist[it.v]) {
			cout << " Negative cycle\n";
			fl = 1;
			break;
		}
	}
	if (!fl) {
		for (int i = 0; i < n; i++) {
			cout << i << " " << dist[i] << endl;
		}
	}
}
