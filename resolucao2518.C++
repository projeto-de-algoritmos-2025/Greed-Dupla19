class Solution {
public:
    static const int MOD = 1e9 + 7;
    // evitar overflow
    
    // calcula total de maneiras para dividir o array em dois
    int modpow(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

    // conta quantos subconjuntos tem soma menor que K
    // o retorno vai ser em módulo MOD
    int countSubsetsLessThanK(vector<int>& nums, int k) {
        vector<int> dp(k, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int s = k - 1; s >= num; s--) {
                dp[s] = (dp[s] + dp[s - num]) % MOD;
            }
        }
        long long count = 0;
        for (int s = 0; s < k; s++) count = (count + dp[s]) % MOD;
        return count;
    }
}