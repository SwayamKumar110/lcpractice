class Solution {
public:
void fun(vector<int>&a ,int n,int idx,vector<int>diary,int sum,vector<vector<int>>&res,int target){
    if(idx==n){
        if(sum==target)
        res.push_back(diary);
        return;
    }
    fun(a,n,idx+1,diary,sum,res,target);
    if(a[idx]+sum<=target){
        diary.push_back(a[idx]);
        sum=sum+a[idx];
            fun(a,n,idx,diary,sum,res,target);
            diary.pop_back();
            sum=sum-a[idx];

    }
    return;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        int idx=0;
        vector<int>diary;
        vector<vector<int>>res;
        int n=candidates.size();
         fun(candidates,n,idx,diary,sum,res,target);
         return res;


        
    }
};