#include <iostream>

template <typename T>
class AlberoBinario {
private:
    T nodi[100];
    bool occupato[100] = {false};

public:
    AlberoBinario() {

    }

    bool alberoVuoto() const {
        return !occupato[0];
    }

    void insRadice(const T& valore) {
        if (alberoVuoto()) {
            nodi[0] = valore;
            occupato[0] = true;
        }
    }

    T radice() const {
        if (!alberoVuoto()) {
            return nodi[0];
        }
        return T();
    }

    bool isFoglia(int indice) const {
        if (indice >= 0 && indice < 100 && occupato[indice]) {
            return !occupato[2 * indice + 1] && !occupato[2 * indice + 2];
        }
        return false;
    }

    int figlioSinistro(int indice) const {
        int pos = 2 * indice + 1;
        if (indice >= 0 && pos < 100 && occupato[pos]) {
            return pos;
        }
        return -1;
    }

    int figlioDestro(int indice) const {
        int pos = 2 * indice + 2;
        if (indice >= 0 && pos < 100 && occupato[pos]) {
            return pos;
        }
        return -1;
    }

    void insFiglioSinistro(int indice, const T& valore) {
        int pos = 2 * indice + 1;
        if (indice >= 0 && pos < 100 && !occupato[pos]) {
            nodi[pos] = valore;
            occupato[pos] = true;
        }
    }

    void insFiglioDestro(int indice, const T& valore) {
        int pos = 2 * indice + 2;
        if (indice >= 0 && pos < 100 && !occupato[pos]) {
            nodi[pos] = valore;
            occupato[pos] = true;
        }
    }

    void rimuovi(int indice) {
        if (indice >= 0 && indice < 100 && occupato[indice] && isFoglia(indice)) {
            occupato[indice] = false;
        }
    }

    void stampa() const {
        for (int i = 0; i < 100; ++i) {
            if (occupato[i]) {
                T valore = nodi[i];
                int sinistro = figlioSinistro(i);
                int destro = figlioDestro(i);
                std::cout << "Pos " << i << ", Valore: " << valore << ", Figliosinistro: ";

                if (sinistro != -1) {
                    std::cout << nodi[sinistro];
                }
                else {
                    std::cout << "Nessuno";
                }

                std::cout << ", Figliodestro: ";
                if (destro != -1) {
                    std::cout << nodi[destro];
                }
                else {
                    std::cout << "Nessuno";
                }

                std::cout << std::endl;
            }
        }
    }
};