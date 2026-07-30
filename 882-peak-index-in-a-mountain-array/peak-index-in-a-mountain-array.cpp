class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int res=-1;
        int high =arr.size()-1;
        int low=0;
        while(low<high){
            int mid=(high+low)/2;
            if(arr[mid]<arr[mid+1]){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid;
            }
        }
        return res;
    }
};