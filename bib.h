typedef struct filme{
  int codigo, censura, duracao, qtd_total, qtd_alocada;
  char nome[30], genero[30];
};

typedef struct locadora{
  struct filme filmes[4];  //mudar para 9 depois dos testes
  int disponiveis, locados;
  float preco;
}locadora;

locadora loc;

////////////// Funções
void Cadastro();
void Sobre();
void RelatorioFilmes();