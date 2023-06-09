#include <bits/stdc++.h> 
    void merge(vector<int>& arr, int l, int m, 
	int r, int& ans)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    int cnt=0;
    for(int i=0;i<n1;i++){
        while(j<n2 and L[i]>(long)2*R[j])
            j++;
        cnt+=j;
    }
    ans+=cnt;

    i=0, j=0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int l, int r, int& ans)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m,ans);
        mergeSort(arr, m + 1, r,ans);
 
        merge(arr, l, m, r,ans);
    }
}
int reversePairs(vector<int> &nums, int n){
	// Write your code here.
	int ans=0;
	mergeSort(nums,0,n-1,ans);
        return ans;	
}