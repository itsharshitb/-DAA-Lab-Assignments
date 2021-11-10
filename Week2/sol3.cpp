#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void io()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int key;
    cin>>key;
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(abs(arr[i]-arr[j])==key)
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    io();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}