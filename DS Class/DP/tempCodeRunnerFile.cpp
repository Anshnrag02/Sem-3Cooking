
// int dp(int i) {

// 	if (i == s.size()) return 1;

// 	if (memo[i] != -1) return memo[i];

// 	int ans = 0;
// 	if (s[i] >= '1' && s[i] <= '9') {
// 		ans += dp(i + 1);
// 	}

// 	if (i + 1 < s.size() && (s[i] == '1')) {
// 		ans += dp(i + 2);
// 	}

// 	if (i + 1 < s.size() && (s[i] == '2' && s[i + 1] <= '6')) {
// 		ans += dp(i + 2);
// 	}

// 	return memo[i] = ans;
// }
