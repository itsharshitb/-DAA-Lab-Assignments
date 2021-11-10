#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
void io()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void countsort(int arr[],int exp,int size);
void redixsort(int arr[], int n)
{
    int maxx = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxx)
        maxx=arr[i];
    }
    int exp = 1;
    while(exp<maxx)
    {
        countsort(arr,exp,n);
        exp*=10;
    }
}
void countsort(int arr[],int exp,int size)
{
    int freq[10];
    memset(freq,0,sizeof(freq));
    //freq array
    for(int i=0;i<size;i++)
    {
        freq[arr[i]/exp % 10]++;
    }
    //prefix sum
    for(int i=1;i<10;i++)
    {
        freq[i]=freq[i]+freq[i-1];
    }
    //putting value
    int ans[size];
    memset(ans,0,sizeof(ans));

    for(int i=size-1;i>=0;i--)
    {
        int index = freq[arr[i]/exp % 10] -1;
        ans[index] = arr[i];
        freq[arr[i]/exp % 10]--;
    }
    //filling original array
    for(int i=0;i<size;i++)
    arr[i] = ans[i];
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    int kth;
    cin>>kth;
    if(kth>n)
    cout<<"not present"<<endl;
    else{
        redixsort(arr,n);    
    }

    //check
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // cout<<arr[kth-1]<<endl;
    int minn=0;
    kth--;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[minn])
        {
            kth--;
        }
        if(!kth)
        {
            cout<<arr[i]<<endl;
            break;
        }
        if(kth!=0 and i==n-1)
        {
            cout<<"not present"<<endl;
        }
    }
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