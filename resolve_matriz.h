#include <vector>
#include <utility>
#include "array_queue.h"

int resolveMatriz(const Cenario& cenario) {
    int count = 0;
    const auto& matriz = cenario.matriz;

    size_t height = cenario.altura; //num de linhas
    size_t width = cenario.largura; //num de colunas

    size_t startX = cenario.x;
    size_t startY = cenario.y;

    std::vector<std::vector<int>> novaMatriz(height, std::vector<int>(width, 0));

    structures::ArrayQueue<std::pair<int, int>> fila;

    if (startX < 0 || startY < 0) {
        throw std::out_of_range("Índices de início inválidos.");
    } else if (startX >= height || startY >= width) {
        throw std::out_of_range("Índices de início inválidos.");
    } else if (matriz[startX * width + startY] == '0') {
        return 0;
    } else {
        fila.enqueue({startX, startY});
        novaMatriz[startX][startY] = 1;
        count++;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
        
    while (!fila.empty()) {
        fila.dequeue();

        for (int i = 0; i < 4; i++) {  
            int nx = startX + dx[i];
            int ny = startY + dy[i];

            if (nx >= 0 && nx < static_cast<int>(height) &&
                    ny >= 0 && ny < static_cast<int>(width) &&
                    matriz[nx * width + ny] == '1' &&
                    novaMatriz[nx][ny] == 0) {
                fila.enqueue({nx, ny});
                novaMatriz[nx][ny] = 1;
                count++;
            }
        }
    }
    return count;
}