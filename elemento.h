struct strElemento
{
	int codigo;
	char nome[40];
	char vulnerabilidade[40];
};

typedef struct strElemento Tipo;

int inicializarElemento();
int encerraElemento(); 
int cadastrarElemento(Tipo e);
int listarElemento();
int quantidadeElemento();
int obterElementoPeloIndice(int indice, Tipo* e);
int obterElementoPeloCodigo(int codigo, Tipo* e);
int excluirElemento(int codigo);
int aumentarQuantidadeE();
int reduzirQuantidadeE();
int retMAXE();
int alterarElemento(int codigo, Tipo e);

