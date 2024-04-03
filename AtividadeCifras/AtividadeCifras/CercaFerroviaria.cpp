#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "windows.h"

#include "CercaFerroviaria.h"

using namespace std;

#define CHAR_CORINGA '.'
#define CHAR_PLACE_HOLDER '@'

enum EOpcoesCercaFerroviaria
{
	eCercaFerroviariaNenhum   = 0,
	eCercaFerroviariaCifrar   = 1,
	eCercaFerroviariaDecifrar = 2,
	eCercaFerroviariaVoltar   = 3,
};

enum EDirecao
{
	eDesce = 1,
	eSobe  = 2,   
};

void CCercaFerroviaria::Cifrar()
{
	cout << "Informe a quantidade de trilhos: ";
	unsigned long ulTrilhos = 0;
	cin >> ulTrilhos;
	cin.ignore();
	std::string sEntrada;

	cout << "Informe o texto a ser cifrado: ";
	getline(cin, sEntrada);

	sEntrada.erase(std::remove(sEntrada.begin(), sEntrada.end(), ' '), sEntrada.end());

	const unsigned long ulTamanhoTexto = sEntrada.size();

	vector<vector<char>> matriz(ulTrilhos);

	for (int iLinha = 0; iLinha < ulTrilhos; ++iLinha)
	{
		vector<char>& linha = matriz[iLinha];
		linha.resize(ulTamanhoTexto);
		fill(linha.begin(), linha.end(), CHAR_CORINGA);
	}

	int iLinha  = 0;
	int iColuna = 0;

	EDirecao eDirecao = eDesce;

	for (int idxChar = 0; idxChar < ulTamanhoTexto; ++idxChar)
	{
		const char c = sEntrada[idxChar];
		matriz[iLinha][iColuna] = c;

		switch (eDirecao)
		{
			case eDesce:
				iLinha ++;
				iColuna++;
				break;

			case eSobe:
				iLinha --;
				iColuna++;
				break;
		}
		
		if (eDirecao == eDesce && iLinha == ulTrilhos - 1)
			eDirecao = eSobe;
		else if (eDirecao == eSobe && iLinha == 0)
			eDirecao = eDesce;
	}

	for (int iLinha = 0; iLinha < ulTrilhos; ++iLinha)
	{
		for (int iColuna = 0; iColuna < ulTamanhoTexto; ++iColuna)
		{
			const char c = matriz[iLinha][iColuna];

			if (c != CHAR_CORINGA)
				cout << c;
		}
	}

	cout << endl << endl << endl;
}

void CCercaFerroviaria::Decifrar()
{
	cout << "Informe a quantidade de trilhos: ";
	unsigned long ulTrilhos = 0;
	cin >> ulTrilhos;
	cin.ignore();
	std::string sEntrada;

	cout << "Informe o texto a ser decifrado: ";
	getline(cin, sEntrada);

	const unsigned long ulTamanhoTexto = sEntrada.size();

	//Cria a matriz
	vector<vector<char>> matriz(ulTrilhos);
	for (int iLinha = 0; iLinha < ulTrilhos; ++iLinha)
	{
		vector<char>& linha = matriz[iLinha];
		linha.resize(ulTamanhoTexto);
		fill(linha.begin(), linha.end(), CHAR_CORINGA);
	}

	//Preenche a matriz com place holders
	int iLinha  = 0;
	int iColuna = 0;
	EDirecao eDirecao = eDesce;

	for (int idxChar = 0; idxChar < ulTamanhoTexto; ++idxChar)
	{
		matriz[iLinha][iColuna] = CHAR_PLACE_HOLDER;

		switch (eDirecao)
		{
			case eDesce:
				iLinha ++;
				iColuna++;
				break;

			case eSobe:
				iLinha --;
				iColuna++;
				break;
		}
		
		if (eDirecao == eDesce && iLinha == ulTrilhos - 1)
			eDirecao = eSobe;
		else if (eDirecao == eSobe && iLinha == 0)
			eDirecao = eDesce;
	}

	unsigned long ulContador = 0;

	//Substitui os place holders pelo texto
	for (int iLinha = 0; iLinha < ulTrilhos; ++iLinha)
	{
		for (int iColuna = 0; iColuna < ulTamanhoTexto; ++iColuna)
		{
			char& c = matriz[iLinha][iColuna];
			if (c != CHAR_PLACE_HOLDER)
				continue;

			c = sEntrada[ulContador];
			++ulContador;
		}
	}

	//Percorre na ordem, printando
	eDirecao = eDesce;
	iLinha  = 0;
	iColuna = 0;
	for (int idxChar = 0; idxChar < ulTamanhoTexto; ++idxChar)
	{
		cout << matriz[iLinha][iColuna];

		switch (eDirecao)
		{
			case eDesce:
				iLinha ++;
				iColuna++;
				break;

			case eSobe:
				iLinha --;
				iColuna++;
				break;
		}

		if (eDirecao == eDesce && iLinha == ulTrilhos - 1)
			eDirecao = eSobe;
		else if (eDirecao == eSobe && iLinha == 0)
			eDirecao = eDesce;
	}

	cout << endl << endl << endl;
}

void CCercaFerroviaria::Opcoes()
{
	long eOpcao = EOpcoesCercaFerroviaria::eCercaFerroviariaNenhum;

	while (eOpcao != EOpcoesCercaFerroviaria::eCercaFerroviariaVoltar)
	{
		cout << "[Cerca ferroviária]" << endl;
		cout << "Escolha a operação: " << endl;
		cout << EOpcoesCercaFerroviaria::eCercaFerroviariaCifrar   << " - Cifrar"   << endl;
		cout << EOpcoesCercaFerroviaria::eCercaFerroviariaDecifrar << " - Decifrar" << endl;
		cout << EOpcoesCercaFerroviaria::eCercaFerroviariaVoltar   << " - Voltar"   << endl;
		cin >> eOpcao;

		switch (eOpcao)
		{
			case EOpcoesCercaFerroviaria::eCercaFerroviariaDecifrar:
				CCercaFerroviaria::Decifrar();
				break;

			case EOpcoesCercaFerroviaria::eCercaFerroviariaCifrar:
				CCercaFerroviaria::Cifrar();
				break;

			case EOpcoesCercaFerroviaria::eCercaFerroviariaVoltar:
				break;
		}
	}
}