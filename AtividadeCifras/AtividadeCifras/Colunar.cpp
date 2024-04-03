#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "windows.h"

using namespace std;

#define CHAR_CORINGA 'X'

enum EOpcoes
{
	eNenhum = 0,
	eCifrar = 1,
	eDecifrar = 2,
	eSair = 3,
};

unsigned long ulColunas = 0;

void Cifrar()
{
	cout << "Informe a quantidade de colunas: ";
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

void Decifrar()
{
	cout << "Informe a quantidade de colunas: ";
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

int main()
{
	SetConsoleCP      (1252);
	SetConsoleOutputCP(1252);

	long eOpcao = EOpcoes::eNenhum;

	while (eOpcao != EOpcoes::eSair)
	{
		cout << "[Cifra de transposição geométrica colunar]" << endl;
		cout << "Escolha a operação: " << endl;
		cout << EOpcoes::eCifrar   << " - Cifrar"   << endl;
		cout << EOpcoes::eDecifrar << " - Decifrar" << endl;
		cout << EOpcoes::eSair     << " - Sair"     << endl;
		cin >> eOpcao;

		switch (eOpcao)
		{
		case EOpcoes::eDecifrar:
			Decifrar();
			break;

		case EOpcoes::eCifrar:
			Cifrar();
			break;

		case EOpcoes::eSair:
			break;
		}
	}


	return 0;
}