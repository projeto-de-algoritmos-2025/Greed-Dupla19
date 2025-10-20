class Solution {
public:

    // Calcula o número máximo de cursos que podem ser feitos
    int scheduleCourse(vector<vector<int>>& courses) {
        // Critério Guloso: ordena os cursos pelo prazo final (lastDay) em ordem crescente
        // O elemento [i][1] é o lastDay
        // O algoritmo está correto se compararmos o segundo elemento (lastDay)
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
    
        // Max-Heap: Armazena as durações dos cursos atualmente selecionados
        // Max-Heap para encontrar o curso de maior duração para remover
        priority_queue<int> duration_heap;
        
        // Rastreador do tempo atual de conclusão. Long long para evitar potencial overflow
        long long time = 0;

        // passa pelos cursos ordenados
        for (const auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            // tenta adicionar o curso
            time += duration;
            duration_heap.push(duration);

            // verifica a restrição do prazo.
            // se o tempo total de conclusão exceder o prazo final do curso atual, o grupo de cursos selecionado é inválido
            if (time > lastDay) {
                // ação Gulosa: precisamos remover um curso. Para ter a melhor chance de cumprir o prazo, removemos o curso que nos custa mais tempo: o curso com a maior duração (o topo do Max-Heap)
                // subtrai a duração máxima do tempo total
                time -= duration_heap.top();
                
                // remove o curso da heap
                duration_heap.pop();
            }
        }

        return duration_heap.size();
    }
};