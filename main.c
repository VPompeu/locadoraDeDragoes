#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "guerreiro.h"
#include "dragao.h"
#include "elemento.h"
#include "locacao.h"

//            ----- MENUS -----

void listarMenu()
{	
		printf("\n    [     0. SAIR               ]\n");
		printf("\n    [     1. GUERREIROS         ]\n");
		printf("\n    [     2. DRAGÕES            ]\n");
		printf("\n    [     3. ELEMENTOS          ]\n");
		printf("\n    [     4. LOCAÇÕES           ]\n");
		printf("\n\n");
}

void subMenuG()
{	
		printf("\n    [     0. VOLTAR                 ]\n");
		printf("\n    [     1. LISTAR GUERREIROS      ]\n");
		printf("\n    [     2. CADASTRAR GUERREIRO    ]\n");
		printf("\n    [     3. PESQUISAR GUERREIRO    ]\n");
		printf("\n    [     4. EXCLUIR GUERREIRO      ]\n");
		printf("\n    [     5. ALTERAR                ]\n");
		printf("\n\n");
}

void subMenuD()
{
		printf("\n    [     0. VOLTAR              ]\n");
		printf("\n    [     1. LISTAR DRAGÕES      ]\n");
		printf("\n    [     2. CADASTRAR DRAGÃO    ]\n");
		printf("\n    [     3. PESQUISAR DRAGÃO    ]\n");
		printf("\n    [     4. EXCLUIR DRAGÃO      ]\n");
		printf("\n    [     5. ALTERAR                ]\n");
		printf("\n\n");
}

void subMenuE()
{
		printf("\n    [     0. VOLTAR                ]\n");
		printf("\n    [     1. LISTAR ELEMENTOS      ]\n");
		printf("\n    [     2. CADASTRAR ELEMENTO    ]\n");
		printf("\n    [     3. PESQUISAR ELEMENTO      ]\n");
		printf("\n    [     4. EXCLUIR ELEMENTO      ]\n");
		printf("\n    [     5. ALTERAR                ]\n");
		printf("\n\n");
}

void subMenuL()
{
		printf("\n    [     0. VOLTAR                  ]\n");
		printf("\n    [     1. LISTAR LOCAÇÕES         ]\n");
		printf("\n    [     2. LOCAR DRAGÃO            ]\n");
		printf("\n    [     3. PESQUISAR LOCAÇÃO       ]\n");
		printf("\n    [     4. EXCLUIR LOCAÇÃO         ]\n");
		printf("\n    [     5. ALTERAR                 ]\n");
		printf("\n\n");
}

//            ----- LISTAR -----

void listaGuerreiro()
{
	printf("\n ### LISTA DE GUERREIROS ### \n");
			
	int i;
	for(i = 0; i < quantidadeGuerreiro(); i++)
	{
		Lutador g;
				
		if(obterGuerreiroPeloIndice(i, &g) == 1)
		{
			printf("Código: %d | Nome: %s | Reino: %s | Título: %s \n",
				g.codigo,
				g.nome,
				g.reino,
				g.titulo);
		}
	}
		if(quantidadeGuerreiro() == 0)
			{
				printf("Não há Guerreiros cadastrado!\n");
			}
}

void listaDragao()
{
	printf("\n ### LISTA DE DRAGÃO ### \n");
			
	int i;
	for(i = 0; i < quantidadeDragao(); i++)
	{
		Mitologico d;

		if(obterDragaoPeloIndice(i, &d) == 1)
		{
			Tipo e;	
				obterElementoPeloIndice(d.codigoElemento, &e);
			printf("Código: %d | Nome: %s | Idade: %d | Valor Diário:R$ %.2f | Quantidade em Estoque:%d | Elemento:%s \n",
				d.codigo,
				d.nome,
				d.idade,
				d.valorDiario,
				d.unidadeEstoque,
				e.nome);
		}
	}
		if(quantidadeDragao() == 0)
			{
				printf("Não há Dragão cadastrado!\n");
			}
}

void listaElemento()
{
	printf("\n ### LISTA DE ELEMENTOS ### \n");
			
	int i;
	for(i = 0; i < quantidadeElemento(); i++)
	{
		Tipo e;
		
		if(obterElementoPeloIndice(i, &e) == 1)
		{
			printf("Código: %d | Nome: %s | Vulnerabilidade: %s \n",
				e.codigo,
				e.nome,
				e.vulnerabilidade);
		}
	}
		if(quantidadeElemento() == 0)
			{
				printf("Não há Elemento cadastrado!\n");
			}
}

void listaLocacao()
{
	printf("\n ### LISTA DE LOCAÇÃO ### \n");
			
	int i;
	for(i = 0; i < quantidadeLocacao(); i++)
	{
		Realizar l;
		
		if(locacaoIndice(i, &l) == 1)
		{
			Lutador g;
				obterGuerreiroPeloCodigo(l.codigoGuerreiro, &g);
			Mitologico d;
				obterDragaoPeloCodigo(l.codigoDragao, &d);
				
			printf("Código da Locação: %d | Guerreiro: %s | Dragão: %s | Valor a pagar:R$ %.2f | Data de início:%s | Data de devolução:%s \n",
				l.codigo,
				g.nome,
				d.nome,
				l.pago,
				l.inicioLocacao,
				l.finalLocacao);
		}
	}
		if(quantidadeLocacao() == 0)
			{
				printf("Não há Locações cadastradas!\n");
			}
}

//            ----- CADASTRAR -----

void cadastrarGuerreiros()
{
	printf("\n ### CADASTRE SEU GUERREIRO ### \n");
		
		Lutador g;
		
		printf("Digite o NOME do seu Guerreiro: \n");
		scanf("%s", g.nome);
		
		printf("Digite o REINO do seu Guerreiro: \n");
		scanf("%s", g.reino);
		
		printf("Digite o TÍTULO do seu Guerreiro: \n");
		scanf("%s", g.titulo);
		
		if(cadastrarGuerreiro(g) == 1)
		{
			printf("Seu Guerreiro foi cadastrado! \n");
			aumentarGuerreiroG();
		}
		else
			printf("Não foi possível cadastrar seu guerreiro! \n");
}

void cadastraDragao()
{
	int achei;
	int achado = 0;
	
	printf("\n ### CADASTRE SEU DRAGÃO ### \n");
		
		Mitologico d;
		Tipo e;
		
		printf("Digite o NOME do seu Dragão: \n");
		scanf("%s", d.nome);
		
		printf("Digite a IDADE NUMÉRICA do seu Dragão: \n");
		scanf("%d", &d.idade);
		
		printf("Digite VALOR DIÁRIO do seu Dragão: \n");
		scanf("%f", &d.valorDiario);
		
		printf("Digite a QUANTIDADE de Dragão cadastrado: \n");
		scanf("%d", &d.unidadeEstoque);
		
		listaElemento();
		
		printf("Digite o CÓDIGO do Elemento do seu Dragão\n");
		scanf("%d", &achei);
		
		if(obterElementoPeloCodigo(achei, &e) == 1)
		{
			d.codigoElemento == achei;
			achado++;
		}
		else
		{
			printf("Código inválido! \n");
		}
		
		if(cadastrarDragao(d, achado) == 1)
		{
			printf("Dragão cadastrado!");
			aumentarDragaoD();
		}
		else
		{
			printf("Falha ao cadastrar!");
		}
}

void cadastraElemento()
{
	
	printf("\n ### CADASTRE SEU ELEMENTO ### \n");
		
		Tipo e;
		
		printf("Digite o NOME do seu Elemento: \n");
		scanf("%s", e.nome);
		
		printf("Digite a VULNERABILIDADE do seu Elemento: \n");
		scanf("%s", e.vulnerabilidade);
		
		if(cadastrarElemento(e) == 1)
		{
			printf("Seu Elemento foi cadastrado! \n");
		}
		else
			printf("Não foi possível cadastrar seu Elemento! \n");
}

void aluga()
{
	Realizar l;

	listaGuerreiro();
	
	printf("Digite o CÓDIGO do guerreiro: ");
	scanf("%d", &l.codigoGuerreiro);

	listaDragao();

	printf("Digite o CÓDIGO do dragão: ");
	scanf("%d", &l.codigoDragao);

	printf("Digite a DATA DO ÍNICIO da locação: ");
	scanf("%s", l.inicioLocacao);

	printf("Digite a DATA DO FIM da locação: ");
	scanf("%s", l.finalLocacao);

	printf("Digite o VALOR da locação: ");
	scanf("%f", &l.pago);

	int c = cadastrarLocacao(l);

	if (c == 4)
	{
		printf("Guerreiro não encontrado!\n");
	}
	else if (c == 3)
	{
		printf("Dragão não encontrado!\n");
	}
	else if (c == 2)
	{
		printf("Dragão sem estoque!\n");
	}
	else if (c == 1)
	{
		printf("Dragão locado!\n");
	}
	else
	{
		printf("Error!\n");
	}
}

//            ----- PESQUISAR -----

void pesquisarGuerreiro()
{
	int codigoGuerreiro;
		
		printf("Digite o CÓDIGO do Guerreiro procurado: \n");
		scanf("%d", &codigoGuerreiro);
			
			Lutador g;
					
			if(obterGuerreiroPeloCodigo(codigoGuerreiro, &g) == 1)
			{
				printf("Código: %d | Nome: %s | Reino: %s | Título: %s \n",
				g.codigo,
				g.nome,
				g.reino,
				g.titulo);
			}
			
			else 
			{
				printf("Esse Guerreiro ainda não foi cadastrado! \n");
			}
}

void pesquisarDragao()
{
	int codigoDragao;
		
		printf("Digite o CÓDIGO do Dragão procurado: \n");
		scanf("%d", &codigoDragao);
			
			Mitologico d;
			
			
			if(obterDragaoPeloCodigo(codigoDragao, &d) == 1)
			{
				Tipo e;
					obterElementoPeloCodigo(d.codigoElemento, &e);
				
				printf("Código: %d | Nome: %s | ELemento: %s | Idade: %d | Valor Diário: %.2f | Quantidade em Estoque: %d \n",
				d.codigo,
				d.nome,
				e.nome,
				d.idade,
				d.valorDiario,
				d.unidadeEstoque);
			}
			
			if(d.codigo == 0)
			{
				printf("Esse Dragão ainda não foi cadastrado! \n");
			}
}

void pesquisarElemento()
{
	int codigoElemento;
		
		printf("Digite o CÓDIGO do Elemento procurado: \n");
		scanf("%d", &codigoElemento);
			
			Tipo e;
			
			if(obterElementoPeloCodigo(codigoElemento, &e) == 1)
			{
				printf("Código: %d | Nome: %s | Vulnerabilidade %s \n",
				e.codigo,
				e.nome,
				e.vulnerabilidade);
			}
			
			else
			{
				printf("Esse Elemento ainda não foi cadastrado! \n");
			}
}

void pesquisaLocacao()
{
	int codigoLoc;
		
		printf("Digite o CÓDIGO da LOCAÇÃO que esta procurando: \n");
		scanf("%d", &codigoLoc);
			
			Realizar l;
			
			if(locacaoCodigo(codigoLoc, &l) == 1)
			{
				Lutador g;
					obterGuerreiroPeloCodigo(l.codigoGuerreiro, &g);
				Mitologico d;
					obterDragaoPeloCodigo(l.codigoDragao, &d);
				
				printf("Código: %d | Guerreiro: %s | Dragão: %d | Valor a pagar: %.2f | Data de início:%d | Data de devolução:%s \n",
				l.codigo,
				g.nome,
				d.nome,
				l.pago,
				l.inicioLocacao,
				l.finalLocacao);
			}
			
			else
			{
				printf("Não há locações cadastrados! \n");
			}
}

//            ----- EXCLUIR -----

void excluiGuerreiro()
{
	listaGuerreiro();
	int codigo;
	int certo = 0;
	int i;
	
		printf("Digite o CÓDIGO do guerreiro que deseja excluir: \n");
		scanf("%d", &codigo);
	
		for(i = 0; i <= quantidadeLocacao(); i++)
		{
			Realizar l;
				locacaoCodigo(i, &l);
			
			if(l.codigoGuerreiro == codigo)
			{
				printf("Este Guerreiro não pode ser excluído pois possui locação ativa!\n");
				certo++;
			}
			
			if(certo == 0)
			{
				if(excluirGuerreiro(codigo) == 1)
				{
					printf("Guerreiro excluído!\n");
					diminuirGuerreiroG();
				}
			}
			
			else
			{
				printf("Falha ao excluir!\n");
			}

		}
}

void excluiDragao()
{
	listaDragao();
	int codigo;
	int confirma = 0;
	int i; 
	
		("Digite o CÓDIGO do Dragão que deseja excluir: \n");
		scanf("%d", &codigo);
		
		for(i = 0; i <= quantidadeLocacao(); i++)
		{
			Realizar l;
				locacaoCodigo(i, &l);
				
				if(l.codigoDragao == codigo)
				{
					printf("Dragão esta sendo usado em uma locação!");
					confirma++;
				}
				
				if(confirma == 0)
				{
					if(excluirDragao(codigo) == 1)
					{
						printf("Dragão excluído!");
						reduzirDragaoD();
					}
				}
				
				else 
				{
					printf("Exclusão falhou!");
				}
		}
}

void excluiElemento()
{
	listaElemento();
	int codigo;
	int confirmar = 0;
	int i;
	
		printf("Digite o CÓDIGO do Elemento que deseja excluir: \n");
		scanf("%d", &codigo);
	
		for(i = 0; i <= quantidadeLocacao(); i++)
		{
			Mitologico d;
				obterDragaoPeloCodigo(i, &d);
				
				if(d.codigoElemento == codigo)
				{
					printf("Elemento esta sendo usado em um Dragão!");
					confirmar++;
				}
				
				if(confirmar == 0)
				{
					if(excluirElemento(codigo) == 1)
					{
						printf("Elemento excluído!");
						reduzirQuantidadeE();
					}
				}
				
				else 
				{
					printf("Exclusão falhou!");
				}
		}
}

void excluiLocacao()
{
	int codigo;

	listaLocacao();

	printf("\nDigite o CÓDIGO da LOCAÇÃO que deseja excluir: ");
	scanf("%d", &codigo);
	
		Realizar l;
			locacaoCodigo(codigo, &l);
		
		int codigoDrag = l.codigoDragao;

	if (deletarLocCod(codigo) == 1 && aumentarQuantidadeD(codigoDrag) == 1)
	{
		printf("Locação deletada!\n");
		reduzirQuantidadeL();
	}
	else
	{
		printf("Apagar Locação falhou!");
	}
}

//            ----- ALTERAR -----

void alteraGuerreiro()
{
	listaGuerreiro();
	
	int resposta;
	int resposta1;
	
		printf("Digite o CÓDIGO do Guerreiro que você quer alterar:\n");
		scanf("%d", &resposta);
		
		Lutador g;
		
		if(obterGuerreiroPeloCodigo(resposta, &g) == 1)
		{
			printf("Código: %d | Nome: %s | Reino: %s | Título: %s \n",
				g.codigo,
				g.nome,
				g.reino,
				g.titulo);
				
			printf("O que você quer alterar?\n 1 - Nome\n 2 - Reino\n 3 - Título\n");
			scanf("%d", &resposta1);
			
				switch(resposta1)
				{
					case 1:
							printf("Digite o novo Nome:\n");
							fflush(stdin);
							scanf("%[^\n]s", g.nome);
							break;
					case 2:
							printf("Digite o novo Reino:\n");
							fflush(stdin);
							scanf("%[^\n]s", g.reino);
							break;
					case 3:
							printf("Digite o novo Título\n");
							fflush(stdin);
							scanf("%[^\n]s", g.titulo);
							break;
				}
				
				if(alterarGuerreiro(g.codigo, g) == 1)
				{
					printf("Nome alterado com sucesso!");
				}
				
				else
				{
					printf("Falha na alteração!");
				}
		}
}

void alteraDragao()
{
	listaDragao();
	
	int resposta;
	int resposta1;
	
		printf("Digite o CÓDIGO do Dragão que você quer alterar:\n");
		scanf("%d", &resposta);
		
		Mitologico d;
			
			if(obterDragaoPeloCodigo(resposta, &d) == 1)
			{
				Tipo e;
				
				obterElementoPeloCodigo(d.codigoElemento, &e);
				
				printf("Código: %d | Nome: %s | Idade: %d | Valor: R$ %2.f | Estoque: %d | Elemento: %s | Vulnerabilidade: %s \n",
						d.codigo,
						d.nome,
						d.idade,
						d.valorDiario,
						d.unidadeEstoque,
						e.nome,
						e.vulnerabilidade);
						
				printf("O que você quer alterar?\n 1 - Nome\n 2 - Idade\n 3 - Valor\n 4 - Estoque\n 5- Elemento\n");
				scanf("%d", &resposta1);
				
					switch(resposta1)
					{
						case 1:
								printf("Digite o novo Nome:\n");
								fflush(stdin);
								scanf("%[^\n]s", &d.nome);
								break;
						case 2:
								printf("Digite a nova Idade:\n");
								scanf("%d", &d.idade);
								break;
						case 3:
								printf("Digite o novo Valor: R$\n");
								scanf("%f", &d.valorDiario);
								break;
						case 4: 
								printf("Digite o novo Estoque:\n");
								scanf("%d", &d.unidadeEstoque);
								break;
						case 5:
								listaElemento();
								printf("Digite o CÓDIGO do novo Elemento:\n");
								scanf("%d", &d.codigoElemento);
								break;
					}
					
						if(alterarDragao(d.codigo, d) == 1)
						{
							printf("Dragão alterado!");
						}
						
						else
						{
							printf("Erro na alteração!");
						}
			}
}

void alteraElemento()
{
	listaElemento();
	
	int resposta;
	int resposta1;
	
		printf("Digite o CÓDIGO do Elemento que você quer alterar:\n");
		scanf("%d", &resposta);
		
		Tipo e;
			
			if(obterElementoPeloCodigo(resposta, &e) == 1)
			{
				printf("Código: %d | Nome: %s | Vulnerabilidade: %s \n",
						e.codigo,
						e.nome,
						e.vulnerabilidade);
						
				printf("O que você quer alterar?\n 1 - Nome\n 2 - Vulnerabilidade\n");
				scanf("%d", &resposta1);
				
					switch(resposta1)
					{
						case 1:
								printf("Digite o novo Nome:\n");
								fflush(stdin);
								scanf("%[^\n]s", &e.nome);
								break;
						case 2:
								printf("Digite a nova Vulnerabilidade\n");
								fflush(stdin);
								scanf("%[^\n]s", &e.vulnerabilidade);
								break;
					}
					
						if(alterarElemento(e.codigo, e) == 1)
						{
							printf("Elemento alterado!");
						}
						
						else
						{
							printf("Erro na alteração!");
						}
			}
}

void alteraLocacao()
{
	listaLocacao();
	
	int resposta;
	int resposta1;
	
		printf("Digite o CÓDIGO da Locação que você quer alterar:\n");
		scanf("%d", &resposta);
		
		Realizar l;
			
			if(locacaoCodigo(resposta, &l) == 1)
			{
				Lutador g;
					obterGuerreiroPeloCodigo(l.codigoGuerreiro, &g);
				Mitologico d;
					obterDragaoPeloCodigo(l.codigoDragao, &d);
					
				printf("Código: %d | Guerreiro: %s | Dragão: %s | Início: %s | Fim: %s | Pago: %2.f \n",
						l.codigo,
						g.nome,
						d.nome,
						l.inicioLocacao,
						l.finalLocacao,
						l.pago);
						
				printf("O que você quer alterar?\n 1 - Início da Locação\n 2 - Final da Locação\n 3 - Valor a ser pago\n");
				scanf("%d", &resposta1);
				
					switch(resposta1)
					{
						case 1:
								printf("Digite o novo Início de Locação:\n");
								fflush(stdin);
								scanf("%[^\n]s", &l.inicioLocacao);
								break;
						case 2:
								printf("Digite o novo Final da Locação:\n");
								fflush(stdin);
								scanf("%[^\n]s", &l.finalLocacao);
								break;
						case 3:
								printf("Digite o novo Valor Final: R$\n");
								scanf("%f", &l.pago);
								break;
					}
					
						if(alterarLocacao(l.codigo, l) == 1)
						{
							printf("Locação alterada!");
						}
						
						else
						{
							printf("Erro na alteração!");
						}
			}
}

int main(int argc, char *argv[]) 
{
	setlocale(LC_ALL, "Portuguese");
	
	inicializarGuerreiro();
	inicializarDragao();
	inicializarElemento();
	inicializarLocacao();
	
	int codigo;
	int codG, codD, codE, codL;
	
	do
	{
		listarMenu();
		scanf("%d", &codigo);
			
			switch(codigo)
			{
				case 1:
					do
					{
						subMenuG();
						scanf("%d", &codG);
						switch(codG)
						{
							case 0:
									listarMenu();
									system("pause && cls");
									break;
							case 1:
									listaGuerreiro();
									system("pause && cls");
									break;
							case 2:
									cadastrarGuerreiros();
									system("pause && cls");
									break;
							case 3:
									pesquisarGuerreiro();
									system("pause && cls");
									break;
							case 4:
									excluiGuerreiro();
									system("pause && cls");
									break;
							case 5:
									alteraGuerreiro();
									system("pause && cls");
									break;
						}
					}
					while(codG != 0);
					break;
			
				case 2:		
					do
					{
						subMenuD();
						scanf("%d", &codD);
						switch(codD)
						{
							case 0:
									listarMenu();
									system("pause && cls");
									break;
							case 1:
									listaDragao();
									system("pause && cls");
									break;
							case 2:
									cadastraDragao();
									system("pause && cls");
									break;
							case 3:
									pesquisarDragao();
									system("pause && cls");
									break;
							case 4:
									excluiDragao();
									system("pause && cls");
									break;
							case 5:
									alteraDragao();
									system("pause && cls");
									break;
						}
					}
					while(codD != 0);
					break;
					
				case 3:
					do
					{
						subMenuE();
						scanf("%d", &codE);
						switch(codE)
						{
							case 0:
									listarMenu();
									system("pause && cls");
									break;
							case 1:
									listaElemento();
									system("pause && cls");
									break;
							case 2:
									cadastraElemento();
									system("pause && cls");
									break;
							case 3:
									pesquisarElemento();
									system("pause && cls");
									break;
							case 4:
									excluiElemento();
									system("pause && cls");
									break;
							case 5:
									alteraElemento();
									system("pause && cls");
									break;
						}
					}
					while(codE != 0);
					break;
					
				case 4:
					do
					{
						subMenuL();
						scanf("%d", &codL);
						switch(codL)
						{
							case 0:
									listarMenu();
									system("pause && cls");
									break;
							case 1:
									listaLocacao();
									system("pause && cls");
									break;
							case 2:
									aluga();
									system("pause && cls");
									break;
							case 3:
									pesquisaLocacao();
									system("pause && cls");
									break;
							case 4:
									excluiLocacao();
									system("pause && cls");
									break;
							case 5:
									alteraLocacao();
									system("pause && cls");
									break;
						}
					}
					while(codL != 0);
					break;
			}
	}
	while(codigo != 0);	
	
	encerraGuerreiro();
	encerraDragao();
	encerraElemento();
	adeusAluguel();
	
	return 0;
}
