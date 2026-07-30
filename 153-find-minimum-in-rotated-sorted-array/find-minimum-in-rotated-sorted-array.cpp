class Solution {
public:
    int findMin(vector<int>& nums) {
        int high=nums.size()-1;
        int low=0;
        int res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[nums.size()-1]){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return nums[res];
    }
};