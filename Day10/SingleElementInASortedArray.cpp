int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int low=0, high=arr.size()-1;
        int mid;
        if(high==0)
            return arr[high];

        while(low<=high){
             mid = (low+high)/2;
            if((mid%2==0 and arr[mid]==arr[mid+1]) or (mid%2==1 and arr[mid]==arr[mid-1]))
                low=mid+1;
            else
                high=mid-1;
        }
        return arr[low];
}