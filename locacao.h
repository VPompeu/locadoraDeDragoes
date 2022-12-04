struct strLocacao
{
	char pago[10];
	char inicioLocacao[30];
	char finalLocacao[30];
	int codigo;
	int codigoGuerreiro;
	int codigoDragao;
};

typedef struct strLocacao Realizar;

int inicializarLocacao(); 
int cadastrarLocacao(Realizar l);
int quantidadeLocacao();
int deletarLocCod(int codigo);
int locacaoIndice(int indice, Realizar* l);
int locacaoCodigo(int codigo, Realizar* l);
int adeusAluguel();
int aumentarQuantidadeL();
int reduzirQuantidadeL();
int retMAXL();
int alterarLocacao(int codigo, Realizar l);
