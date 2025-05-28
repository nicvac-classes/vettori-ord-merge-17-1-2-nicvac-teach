#include <iostream>
#include <vector>

using namespace std;

int main() {
    srand(time(0));   //random generator
    
    int n, m, i, j;

    // Carico il vettore V1 con valori casuali
    cout << "Quanti numeri casuali generare per il vettore V1?" << endl;
    cin >> n;
    vector<int> v1(n);

    i = 0;
    while (i < n) {
        v1[i] = rand() % n;
        i = i + 1;
    }

    // Carico il vettore V2 con valori casuali
    cout << "Quanti numeri casuali generare per il vettore V2?" << endl;
    cin >> m;
    vector<int> v2(m);

    i = 0;
    while (i < m) {
        v2[i] = rand() % m;
        i = i + 1;
    }

    // Ordinamento del vettore V1
    int t;
    bool scambio;

    scambio = true;
    i = 0;
    while (i <= n - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= n - 2 - i) {
            if (v1[j] > v1[j + 1]) {
                scambio = true;
                t = v1[j];
                v1[j] = v1[j + 1];
                v1[j + 1] = t;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    // Ordinamento del vettore V2
    scambio = true;
    i = 0;
    while (i <= m - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= m - 2 - i) {
            if (v2[j] > v2[j + 1]) {
                scambio = true;
                t = v2[j];
                v2[j] = v2[j + 1];
                v2[j + 1] = t;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    // Visualizzo il vettore ordinato V1
    cout << "➡️➡️➡️ V1" << endl;
    i = 0;
    while (i < n) {
        cout << "V1[" << i << "] = " << v1[i] << endl;
        i = i + 1;
    }

    // Visualizzo il vettore ordinato V2
    cout << "➡️➡️➡️ V2" << endl;
    i = 0;
    while (i < m) {
        cout << "V2[" << i << "] = " << v2[i] << endl;
        i = i + 1;
    }

    // Algoritmo di Merge: Fondo i due vettori ordinati in un nuovo vettore ordinato
    int k, i1, i2, i3;

    k = m + n;
    vector<int> v3(k);

    i1 = 0;
    i2 = 0;
    i3 = 0;
    while (i1 < n && i2 < m) {

        // Di volta in vota copio in V l'elemento più piccolo fra V1 e V2.
        if (v1[i1] <= v2[i2]) {
            v3[i3] = v1[i1];
            i1 = i1 + 1;
        } else {
            v3[i3] = v2[i2];
            i2 = i2 + 1;
        }
        i3 = i3 + 1;
    }

    // Se ci sono ancora elementi di V1 da copiare (e quindi non ci sono altri elementi di V2), li accodo in V3.
    while (i1 <= n - 1) {
        v3[i3] = v1[i1];
        i3 = i3 + 1;
        i1 = i1 + 1;
    }

    // Se ci sono ancora elementi di V2 da copiare li accodo in V3.
    while (i2 <= m - 1) {
        v3[i3] = v2[i2];
        i3 = i3 + 1;
        i2 = i2 + 1;
    }

    // Visualizzo il vettore ordinato V3
    cout << "➡️➡️➡️ V3" << endl;
    i = 0;
    while (i < k) {
        cout << "V3[" << i << "] = " << v3[i] << endl;
        i = i + 1;
    }

    // Ricerca binaria: Chiedo il numero da cercare, visualizzo la sua posizione nel vettore.
    int valore;

    cout << "Inserire il valore da cercare: " << endl;
    cin >> valore;

    // Ricerco il valore con il metodo della ricerca binaria
    cout << "Ricerca binaria 🏎️🏎️🏎️" << endl;
    int inizio, fine, medio, indice;

    indice = -1;
    inizio = 0;
    fine = k - 1;
    while (inizio <= fine && indice == -1) {
        medio = inizio + (double) (fine - inizio) / 2;
        if (valore == v3[medio]) {
            indice = medio;
        } else {
            if (valore > v3[medio]) {
                inizio = medio + 1;
            } else {
                fine = medio - 1;
            }
        }
    }
    if (indice != -1) {
        cout << "Il valore " << v3[indice] << " è stato trovato in nella cella " << indice << endl;
    } else {
        cout << "Il valore " << valore << " non è presente nel vettore." << endl;
    }
    
}
