//Alunos: Kaue Reblin, Luiz G Klitzke
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "windows.h"

using namespace std;

enum EOpcoes
{
    eCriptografar    = 1,
    eDescriptografar = 2,
    eSair            = 3,
};

void Criptografar()
{
    cout << "Informe o texto a ser criptografado: ";
    string sEntrada;
    getline(cin, sEntrada);

    sEntrada.erase(std::remove(sEntrada.begin(), sEntrada.end(), ' '), sEntrada.end());

    cout << "Informe a chave: ";
    string sChave;
    cin >> sChave;

    unsigned int uiTamanhoChave = sChave.size();

    for (int i = 0; i < sEntrada.size(); ++i)
    {
        char& cNovo = sEntrada[i];
        cNovo = toupper(cNovo) + (toupper(sChave[i % uiTamanhoChave]) - 'A');

        if (cNovo > 'Z')
            cNovo = 'A' + cNovo - 'Z' - 1;
    }

    cout << endl << "Texto cifrado: " << sEntrada << endl << endl;
}

void Descriptografar()
{
    cout << "Informe o texto a ser descriptografado: ";
    string sEntrada;
    getline(cin, sEntrada);

    sEntrada.erase(std::remove(sEntrada.begin(), sEntrada.end(), ' '), sEntrada.end());

    cout << "Informe a chave: ";
    string sChave;
    cin >> sChave;

    unsigned int uiTamanhoChave = sChave.size();

    for (int i = 0; i < sEntrada.size(); ++i)
    {
        char& cNovo = sEntrada[i];

        cNovo = toupper(cNovo) - (toupper(sChave[i % uiTamanhoChave]) - 'A');

        if (cNovo < 'A')
            cNovo = 'Z' - ('A' - cNovo) + 1;
    }

    cout << endl << "Texto decifrado: " << sEntrada << endl << endl;
}

int main() {

    SetConsoleCP      (1252);
    SetConsoleOutputCP(1252);

    cout << "[Cifra de Vegenere]" << endl;
    cout << "Escolha uma opção: " << endl;

    int eOpcao = 0;

    while (eOpcao != EOpcoes::eSair)
    {
        cout << EOpcoes::eCriptografar    << " - Criptografar"    << endl;
        cout << EOpcoes::eDescriptografar << " - Descriptografar" << endl;
        cout << EOpcoes::eSair            << " - Sair"            << endl;

        cin >> eOpcao;
        cin.ignore();

        switch (eOpcao)
        {
            case EOpcoes::eCriptografar:
                Criptografar();
                break;

            case EOpcoes::eDescriptografar:
                Descriptografar();
                break;
        }
    }


    return 0;
}