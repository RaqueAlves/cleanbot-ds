#include <vector>

int resolveMatriz(const Cenario& cenario) {
    const string& matriz = cenario.matriz;

    size_t height = cenario.altura; //num de linhas
    size_t width = cenario.largura; //num de colunas

    size_t startX = cenario.x;
    size_t startY = cenario.y;

    vector<vector<int>> novaMatriz(height, vector<int>(width, 0));
}