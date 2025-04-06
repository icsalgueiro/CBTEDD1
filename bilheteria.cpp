#include <iomanip>
#include <iostream>

using namespace std;

const int FILEIRAS = 15;
const int POLTRONAS = 40;

char teatro[FILEIRAS][POLTRONAS];

void iniciarTeatro() {
    for (int i = 0; i < FILEIRAS; i++)
        for (int j = 0; j < POLTRONAS; j++)
            teatro[i][j] = '.';
}

float valorFileira(int fileira) {
    if (fileira >= 1 && fileira <= 5)
        return 50.0;
    else if (fileira >= 6 && fileira <= 10)
        return 30.0;
    else
        return 15.0;
}

void reservarPoltrona() {
    int fileira, poltrona;
    cout << "Informe o número da fileira (1 a 15): ";
    cin >> fileira;
    cout << "Informe o número da poltrona (1 a 40): ";
    cin >> poltrona;

    if (fileira < 1 || fileira > 15 || poltrona < 1 || poltrona > 40){
        cout << "Entrada inválida. Tente novamente. \n";
        return;
    }

    if (teatro[fileira - 1][poltrona - 1] == '.') {
        teatro[fileira - 1][poltrona - 1] = '#';
        cout << "Reserva realizada com sucesso!\n";
        cout << "Preço da poltrona: R$ " << fixed << setprecision(2) << valorFileira(fileira) << endl;
    } else {
        cout << "Poltrona já está ocupada.\n";
    }
}

void mostrarMapa() {
    cout << "\nMapa de Ocupação:\n";
    for (int i = 0; i < FILEIRAS; i++) {
        cout << "Fileira " << setw(2) << (i + 1) << ": ";
        for (int j = 0; j < POLTRONAS; j++) {
            cout << teatro[i][j];
        }
        cout << endl;
    }
    cout << "Legenda: '.' = Vago | '#' = Ocupado\n\n";
}

void exibirFaturamento() {
    int ocupados = 0;
    float total = 0.0;

    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            if (teatro[i][j] == '#') {
                ocupados++;
                total += valorFileira(i + 1);  // Fileira começa em 1
            }
        }
    }

    cout << "Qtde de lugares ocupados: " << ocupados << endl;
    cout << fixed << setprecision(2);
    cout << "Valor da bilheteira: R$ " << total << endl << endl;
}

int main() {
    int opcao;
    iniciarTeatro();

    do {
        cout << "Menu:\n";
        cout << "0. Finalizar\n";
        cout << "1. Reservar poltrona\n";
        cout << "2. Mapa de ocupação\n";
        cout << "3. Faturamento\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Encerrando. \n";
                break;
            case 1:
                reservarPoltrona();
                break;
            case 2:
                mostrarMapa();
                break;
            case 3:
                exibirFaturamento();
                break;
            default:
                cout << "Opção inválida. \n";
        }
    } while (opcao != 0);

    return 0;
}
