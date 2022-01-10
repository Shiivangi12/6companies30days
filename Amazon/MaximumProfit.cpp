#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int K, int N, int arr[]) {
        // code here
        int dp[K+1][N];
        for (int t = 0; t <= K; t++)
             dp[t][0] = 0;
         for (int d = 0; d <= N; d++)
             dp[0][d] = 0;
        for(int t =1; t<=K; t++){
            int max = INT_MIN;
            for(int d =1 ; d<N; d++){
                if( dp[t-1][d-1]-arr[d-1] > max)
                    max = dp[t-1][d-1]-arr[d-1];
                if(max + arr[d] >dp[t][d-1])
                   dp[t][d] = max+arr[d];
                else
                   dp[t][d] = dp[t][d-1];
                }
        }
        return dp[K][N-1];
    }
};

int main(){
int t;
cin >>t;
while(t--){
        int N ;
        int K;
cin >>K;
cin >>N;
int A[N];
for(int i =0; i<N;i++){
    A[i];
}
Solution ob;
cout << ob.maxProfit(K,N,A) <<endl;
}
return 0;
}

