//Alunos: Arthutr B Pinotti e Luiz G Klitzke

#include <stdio.h>
#include <string>
#include <iostream>
#include "windows.h"

#include "Colunar.h"
#include "CercaFerroviaria.h"

using namespace std;

enum EOpcoesGerais
{
    eNenhum           = 0,
    eColunar          = 1,
    eCercaFerroviaria = 2,
    eSair             = 3,
};

int main()
{
    SetConsoleCP      (1252);
    SetConsoleOutputCP(1252);

    long eOpcao = EOpcoesGerais::eNenhum;

    while (eOpcao != EOpcoesGerais::eSair)
    {
        cout << "Escolha qual algoritmo utilizar: " << endl;;
        cout << EOpcoesGerais::eColunar          << " - Colunar"           << endl;
        cout << EOpcoesGerais::eCercaFerroviaria << " - Cerca Ferroviária" << endl;
        cout << EOpcoesGerais::eSair             << " - Sair do programa"  << endl;
        cin >> eOpcao;

        switch (eOpcao)
        {
            case EOpcoesGerais::eColunar:
                CColunar::Opcoes();
                break;

            case EOpcoesGerais::eCercaFerroviaria:
                CCercaFerroviaria::Opcoes();
                break;
        }
    }


    return 0;
}
