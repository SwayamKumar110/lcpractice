class Solution {
public:
    long long fun(vector<int>& piles,  int k) {
        long long hour = 0;
        for (int i = 0; i < piles.size(); i++) {
            hour += piles[i] / k;
            if (piles[i] % k != 0) {
                hour++;
            }
           
        }
         return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int maxVal = piles[0];
        for (int i = 1; i < n; i++) {
            if (piles[i] > maxVal)
                maxVal = piles[i];
        }
        int high = maxVal;
        int res=-1;
        while(low<=high){
          int mid = low + (high - low) / 2;
            long long hr=fun(piles,mid);
            if(hr>h){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
};