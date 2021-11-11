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
void findMaj(int arr[], int n) {
	int maxcount = 0;
	int index = -1;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i] == arr[j])
				count++;
		}
		if (count > maxcount) {
			maxcount = count;
			index = i;
		}
	}
	if (maxcount > n / 2)
		cout << "Majority Element =>" << arr[index] << endl;
	else
		cout << "No majority element\n";
}
double findMedian(int a[], int n) {
	sort(a, a + n);
	if (n % 2 != 0)
		return (double)a[n / 2];
	return (double)(a[n - 1 / 2] + a[n / 2]) / 2.0;
}
int main() {
	basics();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	findMaj(arr, n);
	cout << "Median =>" << findMedian(arr, n) << endl;
}
