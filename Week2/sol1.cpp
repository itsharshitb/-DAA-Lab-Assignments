#include<iostream>
#include<vector>
using namespace std;
void io()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
void find(int index,int key,vector<int> &arr)
{
    bool flag=0;
    int count=0,lim=arr.size();
    for(int i=index;i<lim;i++)
    {
        if(key==arr[i])
        count++;
        else break;
    }
    for(int i=index-1;i>=0;i--)
    {
        if(key==arr[i])
        count++;
        else break;
    }

    cout<<key<<" - "<<count<<endl;
}
void solve()
{
    int n;
    cin>>n;
    bool flag=0;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int key;
    cin>>key;
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(key<arr[mid])
        r=mid-1;
        else if(key>arr[mid])
        l = mid+1;
        else if(key == arr[mid])
        {
            flag=1;
            find(mid,key,arr);
            break;
        }
    }
    if(!flag)
    cout<<" Key not present"<<endl;
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