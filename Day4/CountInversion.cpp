#include <bits/stdc++.h> 

long long merge(long long *arr,long long *temp,
int l,int mid,int r){
    int i=l;
    int k=l;
    int j=mid+1;
    long long cnt=0;
    while(i<=mid && j<=r){
        if(arr[i]>arr[j]){
            temp[k] = arr[j++];
            cnt += mid+1-i;
        }
        else{
            temp[k]=arr[i++];
        }
        k++;
    }
    while(i<=mid){
        temp[k] = arr[i];
        i++; k++;
    }
    while(j<=r){
        temp[k] = arr[j];
        j++; k++;
    }
    for(int i=l;i<=r;i++) arr[i] = temp[i];
    return cnt;
}

long long mergeSort(long long *arr,long long *temp,int l,int r){
    long long cnt=0;
    if(l<r){
        int mid = (l+r)/2;
        cnt += mergeSort(arr,temp,l,mid);
        cnt += mergeSort(arr,temp,mid+1,r);
        cnt += merge(arr,temp,l,mid,r);
    }
    return cnt;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long temp[n];
    return mergeSort(arr,temp,0,n-1);
}