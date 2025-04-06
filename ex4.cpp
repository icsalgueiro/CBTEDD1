#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>      // para toupper
using namespace std;

string paraMaiusculas(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = toupper(texto[i]);
    }
    return texto;
}

int main() {
    ifstream arquivo("nomes.txt");

    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    string linha;
    while (getline(arquivo, linha)) {
        vector<string> palavras;
        stringstream ss(linha);
        string palavra;

        while (ss >> palavra) {
            palavras.push_back(palavra);
        }

        if (palavras.size() == 0) continue;

        string ultimoSobrenome = paraMaiusculas(palavras.back());
        cout << ultimoSobrenome << ", ";

        for (int i = 0; i < palavras.size() - 1; i++) {
            if (i == 0) {
                cout << palavras[i] << " ";
            } else {
                cout << palavras[i][0] << ". ";
            }
        }

        cout << endl;
    }

    arquivo.close();
    return 0;
}