class Solution {
public:

    // Calcula o número máximo de cursos que podem ser feitos.
    int scheduleCourse(vector<vector<int>>& courses) {
        // 1. Critério Guloso: Ordenar os cursos pelo prazo final (lastDay) em ordem crescente.
        // O elemento [i][1] é o lastDay.
        // O algoritmo está correto se compararmos o segundo elemento (lastDay).
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
    }
};