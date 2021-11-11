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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	priority_queue<int, vector<int>, greater<int>> minheap;
	for (int i = 0; i < n; i++) {
		minheap.push(a[i]);
	}
	int ans = 0;
	while (minheap.size() > 1) {
		int e1 = minheap.top();
		minheap.pop();
		int e2 = minheap.top();
		minheap.pop();
		ans += e1 + e2;
		minheap.push(e1 + e2);
	}
	cout << ans;
	return 0;
}