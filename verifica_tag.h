#include "array_stack.h"
#include <iostream>
#include <string>

void verificaTags(const std::string& trecho_programa) {
    structures::ArrayStack<std::string> pilha(1500);

    try {
        for (std::size_t i = 0; i < trecho_programa.length(); i++) {
            std::string tag;

            if (trecho_programa[i] == '<' && trecho_programa[i + 1] != '/') {
                std::size_t j = trecho_programa.find('>', i);
                if (j == std::string::npos) {
                    throw std::runtime_error("Erro: tag de abertura incompleta ou '>' ausente");
                }
                tag = trecho_programa.substr(i + 1, j - i - 1);
                pilha.push(tag);
                i = j;

            } else if (trecho_programa[i] == '<' && trecho_programa[i + 1] == '/') {
                std::size_t j = trecho_programa.find('>', i);
                if (j == std::string::npos) {
                    throw std::runtime_error("Erro: tag de fechamento incompleta ou '>' ausente");
                }
                tag = trecho_programa.substr(i + 2, j - i - 2);

                if (pilha.empty()) {
                    throw std::runtime_error("Erro: tag fechada sem abertura correspondente -> " + tag);
                } else if (pilha.top() != tag) {
                    throw std::runtime_error("Erro: tag de fechamento diferente da abertura -> " + tag);
                } else {
                    pilha.pop();
                }
                i = j;
            }
        }

        if (!pilha.empty()) {
            throw std::runtime_error("Erro: tags abertas não foram fechadas corretamente");
        }

    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}