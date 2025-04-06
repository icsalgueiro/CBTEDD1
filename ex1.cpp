#include <iostream>
#include <windows.h>
#include <locale.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    string mensagem;
	
    cout << "Digite a mensagem: ";
    getline(cin, mensagem);
	
    int posicaoInicial = (80 - mensagem.length()) / 2;

    gotoxy(posicaoInicial, 5);
    cout << mensagem;

    for (int i = 0; i < mensagem.length(); i++) {
        char letra = mensagem[i];
        int coluna = posicaoInicial + i;

        for (int linha = 5; linha <= 20; linha++) {
            gotoxy(coluna, linha);
            cout << letra;
            Sleep(30);

            if (linha > 5) {
                gotoxy(coluna, linha - 1);
                cout << " ";
            }
        }
    }

    gotoxy(posicaoInicial, 20);
    cout << mensagem;

    gotoxy(0, 22);
    return 0;
}
