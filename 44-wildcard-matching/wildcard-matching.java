class Solution {
    public boolean isMatch(String s, String p) {
        int n = s.length();

        boolean[] dp = new boolean[n + 1];
        dp[0] = true; // Empty pattern matches empty string

        for (int i = 1; i <= p.length(); i++) {
            char pc = p.charAt(i - 1);
            boolean[] next = new boolean[n + 1];

            if (pc == '*') {
                // '*' matches empty string
                next[0] = dp[0];

                for (int j = 1; j <= n; j++) {
                    // '*' either:
                    // 1. Matches empty -> dp[j]
                    // 2. Matches one/more characters -> next[j - 1]
                    next[j] = dp[j] || next[j - 1];
                }
            } else {
                for (int j = 1; j <= n; j++) {
                    if (pc == '?' || pc == s.charAt(j - 1)) {
                        next[j] = dp[j - 1];
                    }
                }
            }

            dp = next;
        }

        return dp[n];
    }
}