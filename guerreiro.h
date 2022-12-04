struct strGuerreiro
{
	int codigo;
	char nome[40];
	char reino[40];
	char titulo[40];
};

typedef struct strGuerreiro Lutador;

int inicializarGuerreiro();
int encerraGuerreiros(); 
int cadastrarGuerreiro(Lutador g);
int quantidadeGuerreiro();
int obterGuerreiroPeloIndice(int indice, Lutador* g);
int obterGuerreiroPeloCodigo(int codigo, Lutador* g);
int excluirGuerreiro(int codigo);
int salvarGuerreiro();
int aumentarGuerreiroG();
int diminuirGuerreiroG();
int retMAXG();
int alterarGuerreiro(int codigo, Lutador g);
