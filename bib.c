#include<stdio.h>
#include"bib.h"

// Inicialização de variáveis
int codigo = 0;
// loc.disponiveis = 5;
// loc.locados = 2;
// loc.preco = 134.12;
// qtd_filmes = 2;


int menu(void)
{
    //Esta função exibe o menu e retorna a opção escolhida pelo usuário

    int op;
    system("clear");
    do
    {
    system("clear");
        printf("====================================\n");
        printf("=             LOCADORA             =\n");
        printf("====================================\n");
        printf("(1) Cadastro Filme\n");
        printf("(2) Locação\n");
        printf("(3) Devolução\n");
        printf("(4) Relatório de Filmes\n");
        printf("(5) Sobre\n");
        
        printf("[0] Finalizar\n");
        
        printf("------------------------------------\n");
        printf("Entre com a opção desejada: ");
        scanf("%i", &op);
        getchar();

    system("clear");

    // Verifica se o usuário quer mesmo finalizar o programa

    if( op == 0){
      int dec = 0;
      printf("Deseja mesmo sair?\n 1. Sim 2. Não: ");
      scanf("%d", &dec);
      if(dec == 2)
      op = 7;
      system("clear");
    }

    // Checa se a opção é válida

    if(op < 0 || op > 7)
    printf("\n---Opcao invalida!---\n");

  }while(op < 0 || op > 6 );

    if(op != 0)
    printf("\nFunção Escolhida: %d\n", op);
    else
    printf("Fim do Programa.\n");

  return op;
}

void Sobre(){
    int escolha;
    system("clear");
    printf("------------------------------------\n");
    printf("-              SOBRE               -\n");
    printf("------------------------------------\n");
    printf("\nGERAL");
    printf("\n > Disciplina: ECD");
    printf("\n > Professor.: Elyssandro Piffer");
    printf("\n > Data......: 06/06/2021\n");
    printf("\nACADÊMICO");
    printf("\n > Vitor Gibim ............... - RA: 00212191\n");
    printf("------------------------------------\n");
    printf("<Pressione qualquer tecla para voltar>");
    getchar();
}

void RelatorioFilmes(){
    locadora loc;
    system("clear");
    printf("------------------------------------\n");
    printf("-            RELATÓRIO             -\n");
    printf("------------------------------------\n");
    printf("\nPreço de locação..: R$ %0.2f", loc.preco);
    printf("\nFilmes disponíveis: %i", loc.disponiveis);
    printf("\nFilmes locados....: %i", loc.locados);
    printf("\n------------------------------------\n");
    printf("<Pressione qualquer tecla para voltar>");
    getchar();

}

void Cadastro(void){
    
    int escolha = 0, qtd_filmes, l, codigo;
    locadora loc;

    system("clear");
    printf("------------------------------------\n");
    printf("-             CADASTRO             -\n");
    printf("------------------------------------\n");
    printf("\n(1) Listar filmes cadastrados");
    printf("\n(2) Cadastrar filme");
    printf("\n[0]  Voltar");
    printf("\n------------------------------------\n");
    printf("Entre com a opção desejada: ");
    scanf("%i", &escolha);
    
    switch (escolha) {
        case 1: {
            system("clear");
            printf("------------------------------------\n");
            printf("-         LISTA DE FILMES          -");
            printf("------------------------------------\n");
            for (l=1; l < qtd_filmes; l++){
                printf("\nCódigo...........: %i", loc.filmes[l].codigo);
                printf("\nNome.............: %s", loc.filmes[l].nome);
                printf("\nGênero...........: %s", loc.filmes[l].genero);
                printf("\nCensura..........: %i", loc.filmes[l].censura);
                printf("\nDuração (minutos): %i", loc.filmes[l].duracao);
                printf("\nQtd. Total.......: %i", loc.filmes[l].qtd_total);
                printf("\nQtd. Alocada.....: %i", loc.filmes[l].qtd_alocada);
                printf("\n------------------------------------\n");
            }
            printf("<Pressione qualquer tecla para continuar>");
            getchar(); 
        }
        case 2: {
            if (qtd_filmes < 4) {
            
                system("clear");
                printf("------------------------------------\n");
                printf("-       INFORMAÇÕES FILME          -\n");
                printf("------------------------------------\n");

                printf("\nCódigo............: ");
                scanf("%i", &loc.filmes[qtd_filmes + 1].codigo);
                printf("\nNome..............: ");
                getchar();
                fgets(loc.filmes[qtd_filmes + 1].nome, sizeof(loc.filmes[qtd_filmes + 1].nome), stdin);
                printf("\nGênero............: ");
                fflush(stdin);
                fgets(loc.filmes[qtd_filmes + 1].genero, sizeof(loc.filmes[qtd_filmes + 1].genero), stdin);
                printf("\nCensura...........: ");
                scanf("%i", & loc.filmes[qtd_filmes + 1].censura);
                printf("\nDuração (minutos).: ");
                scanf("%i", & loc.filmes[qtd_filmes + 1].duracao);
                printf("\nQuantidade total..: ");
                scanf("%i", & loc.filmes[qtd_filmes + 1].qtd_total);
                printf("\nQuantidade alocada: ");
                scanf("%i", & loc.filmes[qtd_filmes + 1].qtd_alocada);

                if (loc.filmes[qtd_filmes + 1].qtd_alocada > loc.filmes[qtd_filmes + 1].qtd_total) {
                    printf("\nA quantidade alocada não pode ser maior que a total.");
                    printf("\nDigite novamente.");
                    printf("\n------------------------------------\n");

                    printf("\nQuantidade alocada: ");
                    scanf("%i", & loc.filmes[qtd_filmes + 1].qtd_alocada);
                }

                // Atualiza as informações de uso
                loc.disponiveis = loc.disponiveis + abs(loc.filmes[qtd_filmes + 1].qtd_total - loc.filmes[qtd_filmes + 1].qtd_alocada);
                loc.locados = loc.locados + loc.filmes[qtd_filmes + 1].qtd_alocada;
            
                // Feedback de cadastro
                
                printf("\nInformações cadastradas.");
                printf("\n------------------------------------\n");
                printf("<Pressione qualquer tecla para continuar>");
                getchar(); 
            }
        }
        default: {
            printf("\nOpção inválida! Tente novamente.");
            printf("\n------------------------------------\n");
            printf("<Pressione qualquer tecla para continuar>");
            getchar(); 
        }
    
        if (qtd_filmes >= 4){
            printf("\nQuantidade máxima de filmes já cadastrada");
        }

    }

}

void Locacao(void){

    int escolha = 0, qtd_filmes, l, codigo, idade;
    // Locação de filme
    system("clear");
    printf("------------------------------------\n");
    printf("-             LOCAÇÃO              -\n");
    printf("------------------------------------\n");
    printf("\n(1) Listar filmes disponíveis");
    printf("\n(2) Locar filme");
    printf("\n[0]  Voltar");
    printf("\n------------------------------------\n");
    printf("\nEntre com a opção desejada: ");
    scanf("%i", &escolha);

    switch (escolha){
        case 1:{
            // Mostra somente os filmes disponíveis para locação
            // (quando a quantidade diponível é maior que a locada)
            system("clear");
            printf("------------------------------------\n");
            printf("-         LISTA DE FILMES          -");
            printf("------------------------------------\n");
            for (l= 1; l <  qtd_filmes; l++){

                if (loc.filmes[l].qtd_alocada < loc.filmes[l].qtd_total) {
                    printf("\nCódigo...........: %i", loc.filmes[l].codigo);
                    printf("\nNome.............: %s", loc.filmes[l].nome);
                    printf("\nGênero...........: %s", loc.filmes[l].genero);
                    printf("\nCensura..........: %i", loc.filmes[l].censura);
                    printf("\nDuração (minutos): %i", loc.filmes[l].duracao);
                    printf("\n------------------------------------\n");
                }
            }
            printf("<Pressione qualquer tecla para voltar>");
            getchar(); 
        }
        case 2:{
            printf("------------------------------------\n");
            printf("-            LOCAR FILME           -\n");
            printf("------------------------------------\n");
            printf("> Digite o código do filme que deseja locar.\n");
            printf("------------------------------------\n");
            printf("\n>> FILMES\n");
            printf("------------------------------------\n");
            
            // Racaptulação dos códigos caso o usuário tenha esquecido
            for (l = 1; l < qtd_filmes; l++){
                if (loc.filmes[l].qtd_alocada < loc.filmes[l].qtd_total){
                    printf("Código...........: %i ", loc.filmes[l].codigo);
                    printf("Nome.............: %s", loc.filmes[l].nome);
                    printf("------------------------------------\n");
                }
            }


            printf("Código: ");
            scanf("%i", & codigo);
            printf("Idade: ");
            scanf("%i", & idade);

            // Aumenta um exemplar da cópia de filmes alocados
            for (l = 1; l < qtd_filmes; l++){
                if (loc.filmes[l].codigo = codigo){
                    if ((loc.filmes[l].censura < idade) && (loc.filmes[l].qtd_total > loc.filmes[l].qtd_alocada)){
                        printf("\nVocê não pode locar esse filme. A classificação indicativa é maior que sua idade");
                    }
                    else{
                        loc.filmes[l].qtd_alocada = loc.filmes[l].qtd_alocada + 1;
                        loc.locados = loc.locados + 1;
                        loc.disponiveis = loc.disponiveis - 1;
                        }
                }
            }

            
            printf("\n>> Filme locado.\n");
            printf("------------------------------------\n");
            printf("<Pressione qualquer tecla para continuar>");
            getchar(); 
        
        }
    }					

}

void DevolucaoFilme(void){

    int escolha = 0, qtd_filmes, l, codigo;
    
    system("clear");
    printf("------------------------------------\n");
    printf("-            DEVOLUÇÃO             -\n");
    printf("------------------------------------\n");
    printf("\n(1) Devolver filme");
    printf("\n[0]  Voltar");
    printf("------------------------------------\n");
    printf("Entre com a opção desejada: ");
    scanf("%i", &escolha);

    switch (escolha){
        case 1:{
            // Devolução de um determinado filme
            system("clear");
            printf("------------------------------------\n");
            printf("-          DEVOLVER FILME          -");
            printf("------------------------------------\n");
            printf("\n> Digite o código do filme que deseja devolver.");
            printf("\n------------------------------------\n");
            printf(">> FILMES");
            printf("\n------------------------------------\n");
            
            // Mostra somente os filmes com 1 ou mais locações
            for (l = 1; l < qtd_filmes; l++){
                if (loc.filmes[l].qtd_alocada >= 1) {
                    printf("Código...........: %i", loc.filmes[l].codigo);
                    printf("Nome.............: %s", loc.filmes[l].nome);
                    printf("------------------------------------\n");
                }
            }

            printf("Código: "); scanf("%i", &codigo);

                                        
            // Deduz um exemplar da cópia de filmes alocados
            for (l = 1; l < qtd_filmes; l++){
                if (loc.filmes[l].codigo = codigo){
                    loc.filmes[l].qtd_alocada = loc.filmes[l].qtd_alocada - 1;
                    loc.locados = loc.locados - 1;
                    loc.disponiveis = loc.disponiveis + 1;
                }
            }

            
            printf(">> Filme devolvido.");
            printf("------------------------------------\n");
            printf("<Pressione qualquer tecla para continuar>");
            getchar(); 

        }
    }
}