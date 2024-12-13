#include <iostream>
#include "AlberoBinario.cpp"

int main() {
    AlberoBinario<int> albero1;

    albero1.insRadice(5);

    albero1.insFiglioSinistro(0, 5);
    albero1.insFiglioDestro(0, 15);

    albero1.insFiglioSinistro(1, 3);
    albero1.insFiglioDestro(1, 7);

    std::cout << "Figlio sinistro della radice: ";
    if (albero1.figlioSinistro(0) != -1) {
        std::cout << std::to_string(albero1.radice());
    }
    else {
        std::cout << "Nessuno";
    }
    std::cout << std::endl;

    std::cout << "Figlio destro della radice: ";
    if (albero1.figlioDestro(0) != -1) {
        std::cout << std::to_string(albero1.radice());
    }
    else {
        std::cout << "Nessuno";
    }
    std::cout << std::endl;

    albero1.rimuovi(3);

    std::cout << "Struttura dell'albero:" << std::endl;
    albero1.stampa();

    return 0;
}