#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "locacao.h"
#include "dragao.h"
#include "guerreiro.h"

Realizar *Locar;

int MAX_LOC = 5;
int qtdLoc = 0;
int aluguelAt = 1;

int inicializarLocacao()
{
	Locar = (Realizar*) malloc (MAX_LOC * sizeof (Realizar));
		if(Locar == NULL)
		{
			return 0;
		}
	int i;
	for(i = 0; i < MAX_LOC; i++)
	{
		Locar[i].pago[0] = '\0';
		Locar[i].codigo = 0;
		Locar[i].codigoDragao = '\0';
		Locar[i].codigoGuerreiro = '\0';
		Locar[i].finalLocacao[0] = '\0';
		Locar[i].inicioLocacao[0] = '\0';
	}
	
		Locar[0].codigo = aluguelAt++;
		Locar[0].codigoGuerreiro = 1;
		Locar[0].codigoDragao = 1;
		strcpy(Locar[0].inicioLocacao, "25/12/2022");
		strcpy(Locar[0].finalLocacao, "26/12/2022");
		strcpy(Locar[0].pago, "Sim");
		qtdLoc++;
}

int cadastrarLocacao(Realizar l)
{
	if(qtdLoc < MAX_LOC)
	{
		l.codigo = aluguelAt++;
		Locar[qtdLoc] = l;
		qtdLoc++;
		return 1;
	}
	
	else
	{
		return 0;
	}
}

int quantidadeLocacao()
{
	return qtdLoc;
}
	
int deletarLocCod(int codigo)
{
	int i;
	for(i = 0; i < qtdLoc; i++)
	{
		if(Locar[i].codigo == codigo)
		{
		Locar[i] = Locar[qtdLoc - 1];
		Locar[qtdLoc - 1].codigo = 0;
		qtdLoc --;
		return 1;
		}
	}
	return 0;
}

int locacaoIndice(int indice, Realizar* l)
{
	*l = Locar[indice];
	return 1;	
}

int locacaoCodigo(int codigo, Realizar* l)
{
	int i;
	for(i = 0; i < qtdLoc; i++)
	{
		*l = Locar[i];
		
			if(l->codigo == codigo)
			{
				return 1;
			}
	}
	return 0;
}

int aumentarQuantidadeL()
{
	if(qtdLoc == MAX_LOC)
	{
		MAX_LOC +=2;
		
		Realizar* novaLocacaoC = (Realizar*) realloc (Locar, MAX_LOC * sizeof (Realizar));
			if(novaLocacaoC != NULL)
			{
				Locar = novaLocacaoC;
				free(novaLocacaoC);
				novaLocacaoC = NULL;
				return 1;
			}
	}
}

int reduzirQuantidadeL()
{
	if(qtdLoc < (MAX_LOC * 0.4))
	{
		MAX_LOC = qtdLoc +2;
		
		Realizar* novaLocacaoD = (Realizar*) realloc (Locar, MAX_LOC * sizeof (Realizar));
			if(novaLocacaoD != NULL)
			{
				Locar = novaLocacaoD;
				free(novaLocacaoD);
				novaLocacaoD = NULL;
				return 1;
			}
	}
}

int retMAXL()
{
	return MAX_LOC;
}

int alterarLocacao(int codigo, Realizar l)
{
	int i;
	
	for(i = 0; i < qtdLoc; i++)
	{
		Realizar k = Locar[i];
		
		if(Locar[i].codigo > 0)
		{
			if(k.codigo == codigo)
			{
				Locar[i] = l;
				return 1;
			}
		}
	}
	return 0;
}

int adeusAluguel()
{
	free(Locar);
}




