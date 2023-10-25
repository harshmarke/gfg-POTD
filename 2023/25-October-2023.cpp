int knapSack(int n, int w, int val[], int wt[])
{
    // code here
    int t[n+1][w+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }
        
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(wt[i-1] <= j){
                t[i][j] = max(t[i-1][j], val[i-1] + t[i][j-wt[i-1]]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}

// Time Complexity  : O(n*w) 
// Space Complexity : O(n*w)
