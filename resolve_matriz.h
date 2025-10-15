#include <vector>
#include <utility>
#include "array_queue.h"

int resolveMatriz(const Cenario& cenario) {
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
    }
}