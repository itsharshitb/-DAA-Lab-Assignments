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
int main() {
    basics();
    int n, m , s;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cin >> s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int > > >pq;
    vector<int> distTo(n + 1, INT_MAX);
    distTo[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        int dist = pq.top().first;
        int prev = pq.top().second;

        pq.pop();
        vector<pair<int, int>>::iterator it;
        for (it = g[prev].begin(); it != g[prev].end(); it++) {
            int next = it->first;
            int nextDist = it->second;
            if (distTo[next] > distTo[prev] + nextDist) {
                distTo[next] = distTo[prev] + nextDist;
                pq.push({distTo[next], next});
            }
        }
    }
    cout << "The distances from source , " << s << ", are : \n";
    for (int i = 1; i <= n; i++)   cout << distTo[i] << " ";
    cout << "\n";
}
