//LongestCommonSubsequence in two strings using dp.

#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string s1, string s2) {
    int  n = s1.length();
    int m = s2.length();

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string s1, s2;
    cout << "Enter the two strings : " << '\n';
    cin >> s1 >> s2;
    int res = LongestCommonSubsequence(s1, s2);
    cout << "longest commom subsequence is " << res << endl;
    return 0;
}
