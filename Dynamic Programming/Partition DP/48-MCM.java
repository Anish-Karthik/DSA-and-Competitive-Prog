class Solution{
    static int dp[][];
    static int f(int i, int j, int arr[]) {
        if(j == i) return 0;
        int res = Integer.MAX_VALUE;
        for(int k = i; k<j;k++)  {
            int steps = (arr[i-1] * arr[k] * arr[j] + f(i,k,arr) + f(k+1,j,arr));
            res = Math.min(res,steps);
        }
        return res;
    }
    static int m(int i, int j, int arr[]) {
        if(j == i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = Integer.MAX_VALUE;
        for(int k = i; k<j;k++)  {
            int steps = (arr[i-1] * arr[k] * arr[j] + f(i,k,arr) + f(k+1,j,arr));
            res = Math.min(res,steps);
        }
        dp[i][j] = res;
        return res;
    }
    static int tab(int arr[]) {
        int N = arr.length;
        for(int i = 0; i<N; i++) dp[i][i] = 0;

        for(int i = N-1; i>0; i--){
            for(int j =i+1; j<N;j++){
                int res = Integer.MAX_VALUE;
                for(int k = i; k<j;k++){
                    int steps = (arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j]);
                    res = Math.min(res,steps);
                }
                dp[i][j] = res;
            }    
        }
        return dp[1][N-1];
    }
    static int matrixMultiplication( int N,int[] arr){
        dp = new int[N][N];
        for(int i = 0; i<N; i++) for(int j =0; j<N;j++) dp[i][j] = -1;
        return tab(arr);
        // return m(1,N-1,arr);
    }
}
