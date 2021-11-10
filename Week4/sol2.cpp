#include<iostream>
using namespace std;
int ccount,scount;
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
int partition(int arr[],int l, int r)
{
    int i=l-1;
    int pivot = arr[r];

    for(int j=l;j<r;j++)
    {
        ccount++;
        if(arr[j]<pivot)
        {
            scount++;
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    scount++;
    return i+1;
}
void quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        // ccount++;
        int par = partition(arr,l,r);

        quicksort(arr,l,par-1);
        quicksort(arr,par+1,r);
    }
}
void solve()
{
    ccount=0,scount=0;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)    cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"comparisons = "<<ccount<<endl;
    cout<<"swaps = "<<scount<<endl;
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