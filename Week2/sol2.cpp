#include<bits/stdc++.h>
using namespace std;
void io ()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int p=0,q=1,r=2;
    bool f=0,ans=0;
    while (r>p and r>q)
    {
        if(arr[p]+arr[q]==arr[r])
        {
            ans=1;
            cout<<p<<" "<<q<<" "<<r<<endl;
        }
        if(arr[p]+arr[q]<arr[r] and !f)
        {
            f=1;
            p=q+1;
        } else if(f and arr[p]+arr[q]<arr[r]){
            f=0;
            q=p+1;
        } else{
            r++;
        }
    }
    if(!ans)
    cout<<"indices not present"<<endl;
}
int main()
{
    io();
    solve();
}