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
struct job
{
	char id;
	int dead;
	int profit;
};
bool comp(job a, job b) {
	return (a.profit > b.profit);
}
void printSeq(job arr[], int n) {
	sort(arr, arr + n, comp);
	int res[n];
	bool slot[n];
	for (int i = 0; i < n; i++)
		slot[i] = false;
	for (int i = 0; i < n; i++) {
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			if (slot[j] == false) {
				res[j] = i;
				slot[j] = true;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (slot[i])
			cout << arr[res[i]].id << " ";
	}
}

int main() {
	basics();
	int n;
	cin >> n;
	job arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
	}
	cout << "Sequence ";
	printSeq(arr, n);
}
