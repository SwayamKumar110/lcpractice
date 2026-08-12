class Solution {
public:
int fun(vector<vector<int>>& matrix, int guess, int n, int m){
    int row=n-1;
    int col=0;
    int count =0;
    while(row>=0 & col<m){
        if(matrix[row][col]<=guess){
            count+=row+1;
            col++;
        }
        else{
            row--;
        }
    }
    return count;    
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[n-1][m-1];
        int res=0;
        while(low<=high){
            int guess=(high+low)/2;
            int ans=fun(matrix,guess,n,m);
            if(ans<k){
                low=guess+1;
            }
            else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
        
    }
};