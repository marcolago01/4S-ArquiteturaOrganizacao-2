#include "stdafx.h"
#include <omp.h>
#include <iostream>
using namespace std;

const unsigned long TAMANHO_MAXIMO = 4000000000;
const int NUCLEOS = 8;

/*
void eae() {
	
	unsigned long senha = 2999999999;
	cout << senha << endl;
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
	}

	omp_set_num_threads(NUCLEOS);
	#pragma omp parallel
	{
		double inicio = omp_get_wtime();
		nucleo = omp_get_thread_num();
		unsigned long indice_inicio = nucleo * (TAMANHO_MAXIMO / NUCLEOS);
		unsigned long indice_fim = (nucleo + 1) * (TAMANHO_MAXIMO / NUCLEOS);
		for (unsigned long i = indice_inicio; i < indice_fim; i++)
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

*/

int main()
{
	const int NUMERO = 100000;
	int maiorPrimo = 0;
	int a;

	for (int i = 1; i <= NUMERO; i++)
	{
		a = 0;
	#pragma acc parallel loop reduction(+:a)
		for (int k = 1; k <= i; k++)
		{
			if (i % k == 0) {
				a++;
			}
		}
		{
			if (a == 2) {
				maiorPrimo = max(i, maiorPrimo);
			}
		}
	}

	cout << maiorPrimo << endl;

}

}

