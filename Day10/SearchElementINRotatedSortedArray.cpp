// Time - O(N)
// Space - O(1)

int search(vector<int>& nums,int target) {
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==target)
            return i;
    }
    return -1;
     
}


// Better Approach - Binary Search
// Time - O(log (N))
// Space - O(1)


int search(int* nums, int n, int target) {
    // Write your code here.
    int low=0, high=n-1;
        while(low<=high){
            int mid=low+((high-low)>>1);
            if(nums[mid]==target)   return mid;
            if(nums[mid]>=nums[low]){
                if(nums[mid]>=target and nums[low]<=target)
                    high=mid-1;
                else
                    low=mid+1;
            }
            else{
                if(target>=nums[mid] and target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
    return -1;
}