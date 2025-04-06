#include <iostream>
#include <fstream>
#include <sstream> 
#include <vector>

using namespace std;

int main() {
    ifstream arquivo("nomes.txt");

    if (!arquivo) {
        cout << "Erro." << endl;
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

        if (palavras.size() > 1) {
            string ultimo = palavras.back();
            palavras.pop_back();

            cout << ultimo << ", ";

            for (int i = 0; i < palavras.size(); i++) {
                cout << palavras[i];
                if (i < palavras.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        } else {
            cout << palavras[0] << ", " << endl;
        }
    }

    arquivo.close();
    return 0;
}
