#include<iostream>
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
int comp,inven;
void mergearray(int arr[],int l,int mid,int r)
{
    int comparr[r-l+1],k=0;
    for(int i=l;i<=r;i++)
    {
        comparr[k]=arr[i];
        k++;
    }

    int n=mid-l+1;
    int m=r-mid;

    int a[n],b[m];
    for(int i=0;i<n;i++)
    a[i]=arr[l+i];

    for(int i=0;i<m;i++)
    b[i]=arr[mid+1+i];

    int i=0,j=0;
    k=l;
    while(i<n and j<m)
    {
        comp++;
        if(a[i]<=b[j])
        {
            arr[k]=a[i];
            i++;k++;
        }else{
            arr[k]=b[j];
            j++;k++;
        }
    }
    while(i<n)
    {
        arr[k]=a[i];
        k++;i++;
    }
    while(j<m)
    {
        arr[k]=b[j];
        k++;j++;
    }
    for(int i=l;i<=r;i++)
    {
        if(comparr[i]!=arr[i])
        inven++;
    }
}
void partition(int arr[],int l,int r){
    if(l<r)
    {
        int mid = l+(r-l)/2;
        partition(arr,l,mid);
        partition(arr,mid+1,r);

        mergearray(arr,l,mid,r);
    }
}
void solve(){
    comp=0;inven=0;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    partition(arr,0,n-1);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"comparisons = "<<comp<<endl;
    cout<<"inversions = "<<inven<<endl;
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