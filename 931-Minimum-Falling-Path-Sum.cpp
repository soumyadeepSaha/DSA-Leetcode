class Solution {
public:
    //this answer is not accepted by memoization any more so you need to use tabulation
    
    //memoization
    int func1(int i,int j,int n ,vector<vector<int>>&dp,vector<vector<int>>&matrix){
        
        if(j<0 || j>=n)return 1e9;
        if(i==0)return matrix[0][j];
        if(dp[i][j]!=-1)return dp[i][j];
        
        int up = matrix[i][j]+func1(i-1,j,n,dp,matrix);
        int rd=matrix[i][j]+func1(i-1,j+1,n,dp,matrix);
        int ld=matrix[i][j]+func1(i-1,j-1,n,dp,matrix);
        
        return dp[i][j]=min(up,min(ld,rd));
        
    }
    
    
    
    //tabulation
    int func2(int n,vector<vector<int>>&matrix){
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
       
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                
                int up=matrix[i][j]+dp[i-1][j];
                
                int ld= matrix[i][j];
              if(j>0)  ld+=dp[i-1][j-1];
                else ld+=1e9;
                
                int rd=matrix[i][j];
                if(j<n-1) rd+=dp[i-1][j+1];
                else rd+=1e9;
                
                dp[i][j]=min(up,min(ld,rd));
            }
        }
        
        int miin=INT_MAX;
       
            for(int i=0;i<n;i++){
                miin=min(miin,dp[n-1][i]);}
                
                return miin;
    }
    
    
    
    //space optimization to o(n)
    int spaceO(int n,vector<vector<int>>&matrix)
    {
        vector<int>prev(n,0);
       
        
        for(int i=0;i<n;i++)
            prev[i]=matrix[0][i];
        
        for(int i=1;i<n;i++){
            
             vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                
                int up=matrix[i][j]+prev[j];
                
                int ld=INT_MAX;
                if(j>0) ld=matrix[i][j]+prev[j-1];
                
                  int rd=INT_MAX;
                if(j<n-1) rd=matrix[i][j]+prev[j+1];
                
                
                temp[j]=min({up,ld,rd});
                
            }
            
            prev=temp;
        }
        
        int mini=INT_MAX;
        
        for(int i=0;i<n;i++){
            
            mini=min(mini,prev[i]);
        }
        
        return mini;
    }    
    
    
    
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        
        int m = matrix.size();
        int n=matrix[0].size();
        
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //    int mini=INT_MAX;
    //    for(int j=0;j<n;j++){
    //    int ans= func1(n-1,j,n,dp,matrix);
    //    mini=min(mini,ans);
    //    }
        
        
       return func2(n,matrix);
        
		
        // return spaceO(n,matrix);

        // return mini;
    }
};