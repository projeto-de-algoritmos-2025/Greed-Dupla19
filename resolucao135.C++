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

    }
}