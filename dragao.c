#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "dragao.h"
#include "elemento.h"
#include "locacao.h"

Mitologico *Dragao;

int MAX_DRAG = 5;
int qtdDragao = 0;
int codAtualD = 1;


int inicializarDragao()
{
	Dragao = (Mitologico*) malloc (MAX_DRAG * sizeof(Mitologico));
		if(Dragao == NULL)
		{
			return 0;
		}
	
	int i;
	for(i = 0; i < MAX_DRAG; i++)
	{
		(Dragao[i].nome[0] = '\0');
		Dragao[i].codigoElemento = 0;
		Dragao[i].idade = 0;
		Dragao[i].valorDiario = 0;
		Dragao[i].unidadeEstoque = 0;
		Dragao[i].codigo = 0;
	}
	
		strcpy(Dragao[0].nome, "Banguela");
		Dragao[0].codigoElemento = 0;
		Dragao[0].idade = 200;
		Dragao[0].valorDiario = 24.90;
		Dragao[0].unidadeEstoque = 5;
		Dragao[0].codigo = codAtualD++;
		qtdDragao++;
}

int cadastrarDragao(Mitologico d, int buscar)
{
	if(qtdDragao < MAX_DRAG && buscar != 0)
	{
		d.codigo = codAtualD++;
		Dragao[qtdDragao] = d;
		qtdDragao++;
		return 1;
	}
	else
		return 0;
}

int quantidadeDragao()
{
	return qtdDragao;
}

int obterDragaoPeloIndice(int indice, Mitologico* d)
{
	*d = Dragao[indice];
	return 1;
}

int obterDragaoPeloCodigo(int codigo, Mitologico* d)
{
	int i;
		for(i = 0; i < quantidadeDragao(); i++)
		{
			*d = Dragao[i];
			
			if(d->codigo == codigo)
			{
				return 1;
			}
		}
		return 0;	
}

int excluirDragao(int codigo)
{
	int i;
	
		for(i = 0; i < qtdDragao; i++)
		{
			if(Dragao[i].codigo == codigo)
			{
				Dragao[i] = Dragao[qtdDragao-1];
				Dragao[qtdDragao-1].codigo = 0;
				qtdDragao--;
				return 1;
			}
		}
		return 0;
}

int reduzirQuantidadeD(int codigo)
{
	int i;
	
		for(i = 0; i < qtdDragao; i++)
		{
			Mitologico d = Dragao[i];
			
			if(d.codigo == codigo)
			{
				Dragao[i].unidadeEstoque--;
				return 1;
			}
		}
		return 0;
}

int aumentarQuantidadeD(int codigo)
{
	int i;
		
		for(i = 0; i < qtdDragao; i++)
		{
			Mitologico d = Dragao[i];
			
			if(d.codigo == codigo)
			{
				Dragao[i].unidadeEstoque++;
				return 1;
			}
		}
		return 0;
}

int reduzirDragaoD()
{
	if(qtdDragao == MAX_DRAG)
	{
		MAX_DRAG +2;
		
		Mitologico* novoDragaoD = (Mitologico*) realloc (Dragao, MAX_DRAG * sizeof(Mitologico));
			if(novoDragaoD != NULL)
			{
				Dragao = novoDragaoD;
				free(novoDragaoD);
				novoDragaoD = NULL;
				return 1;
			}
	}
}

int aumentarDragaoD()
{
	if(qtdDragao == MAX_DRAG)
	{
		MAX_DRAG +=2;
		
		Mitologico* novoDragaoC = (Mitologico*) realloc (Dragao, MAX_DRAG * sizeof(Mitologico));
			if(novoDragaoC != NULL)
			{
				Dragao = novoDragaoC;
				free(novoDragaoC);
				novoDragaoC = NULL;
				return 1;
			}
	}
}

int retMAXD()
{
	return MAX_DRAG;
}

int encerraDragao()
{
	free(Dragao);
}

int alterarDragao(int codigo, Mitologico d)
{
	int i;
		
		for(i = 0; i < qtdDragao; i++)
		{
			Mitologico c = Dragao[i];
				
				if(c.codigo == codigo)
				{
					Dragao[i] = d;
					return 1;
				}
		}
		return 0;
}





