#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#include "guerreiro.h"
#include "locacao.h"

Lutador *Guerreiro;

int MAX_GUER = 5;
int qtdGuerreiro = 0;
int codAtual = 1;

int inicializarGuerreiro()
{
	Guerreiro = (Lutador*) malloc (MAX_GUER* sizeof (Lutador));
	if(Guerreiro == NULL)
	{
		return 0;
	}
			
	int i;
		for(i = 0; i < MAX_GUER; i++)
		{
			(Guerreiro[i].nome[0] = '\0');
			(Guerreiro[i].reino[0] = '\0');
			(Guerreiro[i].titulo[0] = '\0');
			Guerreiro[i].codigo = 0;
		}
	
			strcpy(Guerreiro[0].nome, "Thor");
			strcpy(Guerreiro[0].reino, "Asgard");
			strcpy(Guerreiro[0].titulo, "Deus do trovão");
			Guerreiro[0].codigo = codAtual++;
			qtdGuerreiro++;
}

int cadastrarGuerreiro(Lutador g)
{
	if(qtdGuerreiro < MAX_GUER)
	{
		g.codigo = codAtual++;
		Guerreiro[qtdGuerreiro] = g;
		qtdGuerreiro++;
		return 1;  
	}
	else
		return 0;
}

int quantidadeGuerreiro()
{
	return qtdGuerreiro;
}

int obterGuerreiroPeloIndice(int indice, Lutador* g)
{
	*g = Guerreiro[indice];
		
		return 1;
}

int obterGuerreiroPeloCodigo(int codigo, Lutador* g)
{
	int i;
		for(i = 0; i < qtdGuerreiro; i++)
		{
			*g = Guerreiro[i];
				
				if(g->codigo == codigo)
				{
					return 1;
				}
		}
		return 0;
}

int excluirGuerreiro(int codigo)
{
	int i;

		for(i = 0; i < qtdGuerreiro; i++)
		{
			if(Guerreiro[i].codigo == codigo)
			{
				Guerreiro[i] = Guerreiro[qtdGuerreiro-1];
				Guerreiro[qtdGuerreiro-1].codigo = 0;
				qtdGuerreiro--;
				return 1;
			}
		}
		return 0;
}

int aumentarGuerreiroG()
{
	if(qtdGuerreiro == MAX_GUER)
	{
		MAX_GUER +=2;
		
		Lutador* novoGuerreiroC = (Lutador*) realloc (Guerreiro, MAX_GUER * sizeof(Lutador));
		if(novoGuerreiroC != NULL)
		{
			Guerreiro = novoGuerreiroC;
			free(novoGuerreiroC);
			novoGuerreiroC = NULL;
			return 1;
		}
	}
}

int diminuirGuerreiroG()
{
	if(qtdGuerreiro < (MAX_GUER * 0.4))
	{
		MAX_GUER = qtdGuerreiro +2;
		
		Lutador* novoGuerreiroD = (Lutador*) realloc (Guerreiro, MAX_GUER * sizeof(Lutador));
		if(novoGuerreiroD != NULL)
		{
			Guerreiro = novoGuerreiroD;
			free(novoGuerreiroD);
			novoGuerreiroD = NULL;
			return 1;
		}
	}
}

int retMAXG()
{
	return MAX_GUER;
}

int alterarGuerreiro(int codigo, Lutador g)
{
	int i;
	
		for(i = 0; i < qtdGuerreiro; i++)
		{
			Lutador f = Guerreiro[i];
			
				if(f.codigo == codigo)
				{
					Guerreiro[i] = g;
					return 1;
				}
		}
		return 0;
}

int encerraGuerreiro()
{
	free(Guerreiro);
	Guerreiro = NULL;
}

