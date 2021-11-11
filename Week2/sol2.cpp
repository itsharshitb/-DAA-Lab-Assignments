#include<bits/stdc++.h>
using namespace std;
void basics()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] == arr[k]) {
                    cout << i + 1 << ", " << j + 1 << ", " << k + 1 << "\n";

                    ans = 1;
                }
            }
        }
    }
    if (!ans)
        cout << "indices not present" << endl;
}
int main()
{
    basics();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}