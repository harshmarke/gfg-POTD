int isPalindrome(string s,int i,int j){
    if(i == j) return true;
    if(i > j ) return false;
        
    while(i < j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(string s,int i,int j,vector<vector<int>> &dp){
    if(i >= j){
        return 0;
    }
        
    if(isPalindrome(s,i,j)) return 0;
        
    if(dp[i][j] != -1) return dp[i][j];
        
    int mn = INT_MAX;
        
    for (int k = i; k < j; k++) {
        if (isPalindrome(s, i, k)) {
            int temp = 1 + solve(s, k + 1, j, dp);
            mn = min(mn, temp);
        }
    }
        
    return dp[i][j] = mn;
}

// Time Complexity : O(n^3) 
// Space Complexity : O(n^2)

// Explanation :
The isPalindrome function checks if a given substring is a palindrome. It uses a while loop to compare characters from the beginning and end of the substring, returning true if it's a palindrome and false if not.
The solve function is a recursive function that finds the minimum number of partitions needed for a given substring. It employs memoization with a 2D DP array to avoid redundant calculations. The function iterates through all possible partitions and calculates the minimum number of partitions required for each substring. It calls the isPalindrome function, which takes O(j - i) time.
The palindromicPartition function initializes a 2D DP array and calls the solve function to solve the problem for the entire input string. The result of the problem is stored in the DP array.
