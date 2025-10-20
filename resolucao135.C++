class Solution {
public:
int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);  // Cada criança recebe pelo menos 1

        // Passada da esquerda para a direita
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Passada da direita para a esquerda
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Soma o total de doces
        int total;
        for (int c : candies) {
            total += c;
        }

        return total;
    }
}