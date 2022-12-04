struct strDragao
{
	int codigo;
	char nome[40];
	int idade;
	int codigoElemento;
	float valorDiario;
	int unidadeEstoque;
};

typedef struct strDragao Mitologico;

int inicializarDragao();
int encerraDragao();  
int cadastrarDragao(Mitologico d, int buscar);
int quantidadeDragao();
int obterDragaoPeloIndice(int indice, Mitologico* d);
int obterDragaoPeloCodigo(int codigo, Mitologico* d);
int excluirDragao(int codigo);
int reduzirQuantidadeD(int codigo);
int aumentarQuantidadeD(int codigo);
int reduzirDragaoD();
int aumentarDragaoD();
int retMAXD();
int alterarDragao(int codigo, Mitologico d);

