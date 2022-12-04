#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "elemento.h"
#include "dragao.h"


Tipo *Elemento;

int MAX_ELEM = 5;
int qtdElemento = 0;
int codAtualE = 1;

int inicializarElemento()
{
	Elemento = (Tipo*) malloc (MAX_ELEM * sizeof (Tipo));
		if(Elemento == NULL)
		{
			return 0;
		}
	
	int i;
	for(i = 0; i < MAX_ELEM; i++)
	{
		strcpy(Elemento[i].nome, "");
		strcpy(Elemento[i].vulnerabilidade, "");
		Elemento[i].codigo = 0;
	}
	
		strcpy(Elemento[0].nome, "Fogo");
		strcpy(Elemento[0].vulnerabilidade, "Água");
		Elemento[0].codigo = codAtualE++;
		qtdElemento++;
}

int cadastrarElemento(Tipo e)
{
	if(qtdElemento < MAX_ELEM)
	{
		e.codigo = codAtualE++;
		Elemento[qtdElemento] = e;
		qtdElemento++;
		return 1;
	}
	else
		return 0;
}

int quantidadeElemento()
{
	return qtdElemento;
}

int obterElementoPeloIndice(int indice, Tipo* e)
{
	*e = Elemento[indice];
	return 1;
}

int obterElementoPeloCodigo(int codigo, Tipo* e)
{
	int i;
		for(i = 0; i < quantidadeElemento(); i++)
		{
			*e = Elemento[i];
			
				if(e->codigo == codigo)
			{
				return 1;
			}
		}
	return 0;
}

int excluirElemento(int codigo)
{
	int i;
		for(i = 0; i < qtdElemento; i++)
		{
			if(Elemento[i].codigo == codigo)
			{
				Elemento[i] = Elemento[qtdElemento-1];
				Elemento[qtdElemento-1].codigo = 0;
				qtdElemento--;
				return 1;
			}
		}
		return 0;
}

int aumentarQuantidadeE()
{
	if(qtdElemento == MAX_ELEM)
	{
		MAX_ELEM +=2;
		
		Tipo* novoElementoC = (Tipo*) realloc (Elemento, MAX_ELEM * sizeof(Tipo));
			if(novoElementoC != NULL)
			{
				Elemento = novoElementoC;
				free(novoElementoC);
				novoElementoC = NULL;
				return 1;
			}
	}
}

int reduzirQuantidadeE()
{
	if(qtdElemento < (MAX_ELEM * 0.4))
	{
		MAX_ELEM = qtdElemento +2;
			
		Tipo* novoElementoD = (Tipo*) realloc (Elemento, MAX_ELEM * sizeof(Tipo));
			if(novoElementoD != NULL)
			{
				Elemento = novoElementoD;
				free(novoElementoD);
				novoElementoD = NULL;
				return 1;
			}
	}
}

int retMAXE()
{
	return MAX_ELEM;
}

int alterarElemento(int codigo, Tipo e)
{
	int i;
	
	for(i = 0; i < qtdElemento; i++)
	{
		Tipo g = Elemento[i];
		
			if(g.codigo == codigo)
			{
				Elemento[i] = e;
				return 1;
			}
	}
	return 0;
}

int encerraElemento()
{
	free(Elemento);
}
