#include "stdafx.h"
#include <omp.h>
#include <iostream>
using namespace std;

const int TAMANHO_MAXIMO = 1000000000;
const int NUCLEOS = 3;

int main()
{
	int senha = 753488822;
	int nucleo;
	bool achou = false;

	

	/*
	for (int i = 0; i <= TAMANHO_MAXIMO; i++)
	{
		if (i == senha && !achou) {
			achou = true;
			double fim = omp_get_wtime();
			printf("Achei a senha %d, levou %f segundos \n", i, fim - inicio);
			break;
		}
	}*/

	omp_set_num_threads(NUCLEOS);
	#pragma omp parallel
	{
		double inicio = omp_get_wtime();
		nucleo = omp_get_thread_num();
		int indice_inicio = nucleo * (TAMANHO_MAXIMO / NUCLEOS);
		int indice_fim = (nucleo + 1) * (TAMANHO_MAXIMO / NUCLEOS);
		for (int i = indice_inicio; i < indice_fim; i++)
		{
			if (i == senha) {
				achou = true;
				double fim = omp_get_wtime();
				printf("Achei a senha %d, levou %f segundos \n", i, fim - inicio);
			}

			if (achou) {
				break;
			}

		}
	}
	

}

