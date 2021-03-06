#include "stdafx.h"
#include <omp.h>
#include <iostream>
#include <vector>
using namespace std;

const int TAMANHO = 50000000;

enum OPCAO
{
	INICIALIZAR = 1,
	SOMATORIO = 2,
	COPIA = 3
};
void informarTempo(double inicio, double fim, int opcao) {
	double tempo = fim - inicio;

	switch (opcao)
	{
	case 1:
		printf("Tempo para inicializar foi de %f segundos\n", tempo);
		break;
	case 2:
		printf("Tempo para fazer o somatorio foi de %f segundos\n", tempo);
		break;
	case 3:
		printf("Tempo para fazer a copia foi de %f segundos\n", tempo);
	default:
		break;
	}
}

void serial(vector<int> vetor) {
	printf("\n*******SEQUENCIAL**********\n");

	double tempoInicial, tempoFinal;

	//inicializar vetor
	tempoInicial = omp_get_wtime();

	for (int i = 0; i < TAMANHO; i++)
	{
		vetor[i] = 1;
	}

	tempoFinal = omp_get_wtime();
	informarTempo(tempoInicial, tempoFinal, INICIALIZAR);
	//fim inicializar vetor

	//somatório vetor
	tempoInicial = omp_get_wtime();
	long int somatorio = 0;

	for (int i = 0; i < TAMANHO; i++)
	{
		somatorio += vetor[i];
	}

	tempoFinal = omp_get_wtime();
	informarTempo(tempoInicial, tempoFinal, SOMATORIO);
	//fim somatorio vetor

	//copia vetor
	tempoInicial = omp_get_wtime();

	vector<int> vetor2;
	vetor2.resize(TAMANHO);

	for (int i = 0; i < TAMANHO; i++)
	{
		vetor2[i] = vetor[i];
	}

	tempoFinal = omp_get_wtime();
	informarTempo(tempoInicial, tempoFinal, COPIA);
	//fim copia vetor

}
void openmpVetor(vector<int> vetor) {
	printf("\n*******OMP**********\n");

	double tempoInicial, tempoFinal;
	
	//inicializar vetor

	tempoInicial = omp_get_wtime();

	#pragma omp parallel for
		for (int i = 0; i < TAMANHO; i++)
		{
			vetor[i] = 1;
		}

	tempoFinal = omp_get_wtime();
	informarTempo(tempoInicial, tempoFinal, INICIALIZAR);

	//fim inicializar vetor

	//somatório vetor
	tempoInicial = omp_get_wtime();
	long int somatorio = 0;

	#pragma omp parallel for reduction(+:somatorio)
		for (int i = 0; i < TAMANHO; i++)
		{
			somatorio += vetor[i];
		}

	tempoFinal = omp_get_wtime();
	informarTempo(tempoInicial, tempoFinal, SOMATORIO);
	//fim somatorio vetor

	//copia vetor
	tempoInicial = omp_get_wtime();

	vector<int> vetor2;
	vetor2.resize(TAMANHO);

	#pragma omp parallel for
		for (int i = 0; i < TAMANHO; i++)
		{
			vetor2[i] = vetor[i];
		}

	tempoFinal = omp_get_wtime();
	informarTempo(tempoInicial, tempoFinal, COPIA);
	//fim copia vetor
}

int main()
{
	vector<int> vetor;
	vetor.resize(TAMANHO);
	
	serial(vetor);
	openmpVetor(vetor);
}