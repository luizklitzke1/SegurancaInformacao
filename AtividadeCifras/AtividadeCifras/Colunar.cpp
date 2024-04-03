//Alunos: Arthutr B Pinotti e Luiz G Klitzke

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "windows.h"

#include "Colunar.h"

using namespace std;

#define CHAR_CORINGA 'X'

enum EOpcoesColunar
{
	eColunarNenhum   = 0,
	eColunarCifrar   = 1,
	eColunarDecifrar = 2,
	eColunarVoltar   = 3,
};

void CColunar::Cifrar()
{
	cout << "Informe a quantidade de colunas: ";
	unsigned long ulColunas = 0;
	cin >> ulColunas;
	cin.ignore();
	std::string sEntrada;

	cout << "Informe o texto a ser cifrado: ";
	getline(cin, sEntrada);

	sEntrada.erase(std::remove(sEntrada.begin(), sEntrada.end(), ' '), sEntrada.end());

	const unsigned long ulTamanhoTexto = sEntrada.size();
	const unsigned long ulLinhas	   = ceil((double)ulTamanhoTexto / ulColunas);

	vector<vector<char>> matriz(ulLinhas);

	unsigned long ulContador = 0;

	for (int iLinha = 0; iLinha < ulLinhas; ++iLinha)
	{
		vector<char>& linha = matriz[iLinha];
		linha.resize(ulColunas);

		for (int iColuna = 0; iColuna < ulColunas; ++iColuna)
		{
			if (ulContador < ulTamanhoTexto)
			{
				matriz[iLinha][iColuna] = sEntrada[ulContador];

			}
			else
				matriz[iLinha][iColuna] = CHAR_CORINGA;

			++ulContador;
		}
	}

	for (int iColuna = 0; iColuna < ulColunas; ++iColuna)
	{
		for (int iLinha = 0; iLinha < ulLinhas; ++iLinha)
			cout << matriz[iLinha][iColuna];
	}

	cout << endl << endl << endl;
}

void CColunar::Decifrar()
{
	cout << "Informe a quantidade de colunas: ";
	unsigned long ulColunas = 0;
	cin >> ulColunas;

	cin.ignore();
	std::string sEntrada;

	cout << "Informe o texto a ser decifrado: ";
	getline(cin, sEntrada);

	const unsigned long ulTamanhoTexto = sEntrada.size();
	const unsigned long ulLinhas       = ceil((double)ulTamanhoTexto / ulColunas);

	//Inicializa matriz
	vector<vector<char>> matriz(ulLinhas);
	for (int iLinha = 0; iLinha < ulLinhas; ++iLinha)
	{
		vector<char>& linha = matriz[iLinha];
		linha.resize(ulColunas);
	}

	unsigned long ulContador = 0;

	//Monta dados na matriz
	for (int iColuna = 0; iColuna < ulColunas; ++iColuna)
	{
		for (int iLinha = 0; iLinha < ulLinhas; ++iLinha)
		{
			matriz[iLinha][iColuna] = sEntrada[ulContador];
			++ulContador;
		}
	}

	//Printa resultado
	for (int iLinha = 0; iLinha < ulLinhas; ++iLinha)
	{
		for (int iColuna = 0; iColuna < ulColunas; ++iColuna)
			cout << matriz[iLinha][iColuna];
	}

	cout << endl << endl << endl;
}

void CColunar::Opcoes()
{
	long eOpcao = EOpcoesColunar::eColunarNenhum;

	while (eOpcao != EOpcoesColunar::eColunarVoltar)
	{
		cout << "[Cifra de transposição geométrica colunar]" << endl;
		cout << "Escolha a operação: " << endl;
		cout << EOpcoesColunar::eColunarCifrar   << " - Cifrar"   << endl;
		cout << EOpcoesColunar::eColunarDecifrar << " - Decifrar" << endl;
		cout << EOpcoesColunar::eColunarVoltar   << " - Voltar"   << endl;
		cin >> eOpcao;

		switch (eOpcao)
		{
		case EOpcoesColunar::eColunarDecifrar:
			CColunar::Decifrar();
			break;

		case EOpcoesColunar::eColunarCifrar:
			CColunar::Cifrar();
			break;

		case EOpcoesColunar::eColunarVoltar:
			break;
		}
	}
}
