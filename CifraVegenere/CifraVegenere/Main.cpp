//Alunos: Kaue Reblin, Luiz G Klitzke
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum EOpcoes
{
    eCriptografar    = 1,
    eDescriptografar = 2,
};

void Criptografar()
{
    cout << "Informe o texto de criptografado: ";
    string sEntrada;
    getline(cin, sEntrada);

    sEntrada.erase(std::remove(sEntrada.begin(), sEntrada.end(), ' '), sEntrada.end());

    cout << "Informe a chave: ";
    string sChave;
    cin >> sChave;

    vector<int> aAvanco;

    unsigned int uiTamanhoChave = sChave.size();
    for (int i = 0; i < uiTamanhoChave; ++i)
    {
        aAvanco.push_back(sChave[i] - 'A');
        cout << aAvanco[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < sEntrada.size(); ++i)
    {
        char& cNovo = sEntrada[i];
        cNovo += aAvanco[i % uiTamanhoChave];

        if (cNovo > 'Z')
            cNovo = 'A' + cNovo - 'Z' - 1;
    }

    cout << endl << "Texto cifrado: " << sEntrada << endl;
}

void Descriptografar()
{
    cout << "Informe o texto a ser descriptografado: ";
    string sEntrada;
    getline(cin, sEntrada);
    cin.ignore();

    sEntrada.erase(std::remove(sEntrada.begin(), sEntrada.end(), ' '), sEntrada.end());

    cout << "Informe a chave: ";
    string sChave;
    cin >> sChave;

    vector<int> aAvanco;

    unsigned int uiTamanhoChave = sChave.size();
    for (int i = 0; i < uiTamanhoChave; ++i)
    {
        aAvanco.push_back(sChave[i] - 'A');
        cout << aAvanco[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < sEntrada.size(); ++i)
    {
        char& cNovo = sEntrada[i];
        cNovo -= aAvanco[i % uiTamanhoChave];

        if (cNovo < 'A')
            cNovo = 'A' - cNovo + 1 + 'A';
    }

    cout << endl << "Texto descriptografado: " << sEntrada << endl;
}

int main() {

    int eOpcao = 0;
    cin >> eOpcao;
    cin.ignore();

    switch (eOpcao)
    {
        case eCriptografar:
            Criptografar();
            break;

        case eDescriptografar:
            Descriptografar();
            break;
    }

    return 0;
}