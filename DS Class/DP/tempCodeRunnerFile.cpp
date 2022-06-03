nt i = n-1; i>=0; --i){
            for(int j = i ; j<n ; ++j){
                if(i==j){
                    dp[i][j]=0;
                }
                else if(i+1==j){
                    if(s[i]==s[j])
                        dp[i][j]=0;
                    else{dp[i][j]=1;}
                }
                else{
                    if(s[i]==s[j] and dp[i+1][j-1]==0){
                        dp[i][j]=0;
                    }
                    else {
                        for(int k = i ; k<=j ;++k){
                            dp[i][j]=min(1+dp[i][k]+dp[k][j],dp[i][j]);
                        }
                    }
                }
            }
        }