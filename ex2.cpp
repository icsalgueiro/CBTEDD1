#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string mensagem, mensagemSemEspacos, mensagemInversa;

    cout << "Insira uma frase: ";
    getline(cin, mensagem);

    for (int i = 0; i < mensagem.length(); i++) {
        char c = mensagem[i];
        if (c != ' ') {
            mensagemSemEspacos += toupper(c);
        }
    }

    mensagemInversa = mensagemSemEspacos;
    reverse(mensagemInversa.begin(), mensagemInversa.end());

    if (mensagemSemEspacos == mensagemInversa) {
        cout << "essa mensagem é um palíndromo." << endl;
    } else {
        cout << "essa mensagem não é um palíndromo." << endl;
    }

    return 0;
}
