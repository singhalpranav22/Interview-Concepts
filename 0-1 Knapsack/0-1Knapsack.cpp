// Input Format
// wt[] : {2,4,5,6} Weights of individual items
// val[] : {2,5,1,9} Profits
// W : Max Capacity of Knapsack
// Output : Max Profit obtained when we put 0 or 1 quantity of each item in knapsack such that their combined weights dont exceed W

// Why DP here ?
// 1. Choice of selecting an item in bag or not
// 2. Otimisation for max profit.


int dp[1002][1002];
memset(dp,-1,sizeof(dp));
int knapSack(int W, int wt[], int val[], int n) 
{ 
  
   if(W==0 || n==0) return 0;
   if(dp[n][W]!=-1)
      return dp[n][W];
    if(wt[n-1]>W)
      return dp[n][W]=knapSack(W,wt,val,n-1);
     else 
     {
         return dp[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),
          knapSack(W,wt,val,n-1));
     }
}