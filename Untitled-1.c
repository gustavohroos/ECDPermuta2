#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

typedef struct{
  int codigo, censura, duracao, qtd_total, qtd_alocada;
  char nome[30], genero[30];
}filme;

typedef struct{
  filme filmes[4];  //mudar para 9 depois dos testes
  int disponiveis, locados;
  float preco;
}locadora;

int main(void){

  locadora loc;
  int escolha, l, qtd_filmes, codigo, idade;


    // Inicialização de variáveis
    // codigo = 0;
    // loc.disponiveis = 5;
    // loc.locados = 2;
    // loc.preco = 134.12;
    // qtd_filmes = 2;


    do{
        system("cls");
        printf("====================================\n");
        printf("=             LOCADORA             =\n");
        printf("====================================\n");
        printf("(1) Cadastro Filme\n");
        printf("(2) Locação\n");
        printf("(3) Devolução\n");
        printf("(4) Relatório de Filmes\n");
        printf("(5) Sobre\n");
        
        printf("[6] Finalizar\n");
        
        printf("------------------------------------\n");
        printf("Entre com a opção desejada: ");
        scanf("%i", &escolha);
        
        switch (escolha){
          case 1 :{
          // Cadastro de filme
                do{
                    escolha = 0; // Incialização

                    system("cls");
                    printf("------------------------------------\n");
                    printf("-             CADASTRO             -");
                    printf("------------------------------------\n");
                    printf("(1) Listar filmes cadastrados");
                    printf("(2) Cadastrar filme");
                    
                    printf("[5]  Voltar");
                    printf("------------------------------------\n");
                    printf("Entre com a opção desejada: ");
                    scanf("%i", &escolha);
                    
                    switch (escolha) {
                        case 1: {
                            system("cls");
                            printf("------------------------------------\n");
                            printf("-         LISTA DE FILMES          -");
                            printf("------------------------------------\n");
                            for (l=1; l < qtd_filmes; l++){
                                printf("Código...........: %i", loc.filmes[l].codigo);
                                printf("Nome.............: %s", loc.filmes[l].nome);
                                printf("Gênero...........: %s", loc.filmes[l].genero);
                                printf("Censura..........: %i", loc.filmes[l].censura);
                                printf("Duração (minutos): %i", loc.filmes[l].duracao);
                                printf("Qtd. Total.......: %i", loc.filmes[l].qtd_total);
                                printf("Qtd. Alocada.....: %i", loc.filmes[l].qtd_alocada);
                                printf("------------------------------------\n");
                            }
                            printf("<Pressione qualquer tecla para continuar>");
                            getch(); // ou getche
                        }
                        case 2: {
                            if (qtd_filmes < 4) {
                            
                              system("cls");
                              printf("------------------------------------\n");
                              printf("-       INFORMAÇÕES FILME          -");
                              printf("------------------------------------\n");

                              printf("Código............: ");
                              scanf("%i", &loc.filmes[qtd_filmes + 1].codigo);
                              printf("Nome..............: ");
                              fflush(stdin);
                              gets(loc.filmes[qtd_filmes + 1].nome);
                              printf("Gênero............: ");
                              fflush(stdin);
                              gets(loc.filmes[qtd_filmes + 1].genero);
                              printf("Censura...........: ");
                              scanf("%i", & loc.filmes[qtd_filmes + 1].censura);
                              printf("Duração (minutos).: ");
                              scanf("%i", & loc.filmes[qtd_filmes + 1].duracao);
                              printf("Quantidade total..: ");
                              scanf("%i", & loc.filmes[qtd_filmes + 1].qtd_total);
                              printf("Quantidade alocada: ");
                              scanf("%i", & loc.filmes[qtd_filmes + 1].qtd_alocada);

                                if (loc.filmes[qtd_filmes + 1].qtd_alocada > loc.filmes[qtd_filmes + 1].qtd_total) {
                                    printf("A quantidade alocada não pode ser maior que a total.");
                                    printf("Digite novamente.");
                                    printf("------------------------------------\n");

                                   printf("Quantidade alocada: ");
                                    scanf("%i", & loc.filmes[qtd_filmes + 1].qtd_alocada);
                                }

                                // Atualiza as informações de uso
                                loc.disponiveis = loc.disponiveis + abs(loc.filmes[qtd_filmes + 1].qtd_total - loc.filmes[qtd_filmes + 1].qtd_alocada);
                                loc.locados = loc.locados + loc.filmes[qtd_filmes + 1].qtd_alocada;
                            
                                // Feedback de cadastro
                                
                                printf("Informações cadastradas.");
                                printf("------------------------------------\n");
                                printf("<Pressione qualquer tecla para continuar>");
                                getch(); // ou getche();
                            }
                        }
                        default: {
                            printf("Opção inválida! Tente novamente.");
                            printf("------------------------------------\n");
                            printf("<Pressione qualquer tecla para continuar>");
                            getch(); // ou getche();
                        }
                    
                        if (qtd_filmes >= 4){
                            printf("Quantidade máxima de filmes já cadastrada");
                        }

                    }
                }while(escolha == 5);
            }

            case 2:{
                do{
                    // Locação de filme
                    system("cls");
                    printf("------------------------------------\n");
                    printf("-             LOCAÇÃO              -");
                    printf("------------------------------------\n");
                    printf("(1) Listar filmes disponíveis");
                    printf("(2) Locar filme");
                    
                    printf("[3]  Voltar");
                    printf("------------------------------------\n");
                   printf("Entre com a opção desejada: ");
                    scanf("%i", &escolha);

                    switch (escolha){
                      case 1:{
                            // Mostra somente os filmes disponíveis para locação
                            // (quando a quantidade diponível é maior que a locada)
                            system("cls");
                            printf("------------------------------------\n");
                            printf("-         LISTA DE FILMES          -");
                            printf("------------------------------------\n");
                            for (l= 1; l <  qtd_filmes; l++){
            
                                if (loc.filmes[l].qtd_alocada < loc.filmes[l].qtd_total) {
                                    printf("Código...........: %i", loc.filmes[l].codigo);
                                    printf("Nome.............: %s", loc.filmes[l].nome);
                                    printf("Gênero...........: %s", loc.filmes[l].genero);
                                    printf("Censura..........: %i", loc.filmes[l].censura);
                                    printf("Duração (minutos): %i", loc.filmes[l].duracao);
                                    printf("------------------------------------\n");
                                }
                            }
                            printf("<Pressione qualquer tecla para voltar>");
                            getch(); // ou getche();
                        }
                        case 2:{
                            printf("------------------------------------\n");
                            printf("-            LOCAR FILME           -");
                            printf("------------------------------------\n");
                            printf("> Digite o código do filme que");
                            printf("  deseja locar.");
                            printf("------------------------------------\n");
                            printf(">> FILMES");
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
                                        printf("Você não pode locar esse filme. A classificação indicativa é maior que sua idade");
                                    }
                                    else{
                                        loc.filmes[l].qtd_alocada = loc.filmes[l].qtd_alocada + 1;
                                        loc.locados = loc.locados + 1;
                                        loc.disponiveis = loc.disponiveis - 1;
                                        }
                                }
                            }

                            
                            printf(">> Filme locado.");
                            printf("------------------------------------\n");
                            printf("<Pressione qualquer tecla para continuar>");
                            getch(); // ou getche();
                        
                        }
                    }					
                }while (escolha == 3);
            }

            case 3: {
                do{
                    // Devolução de filme
                    escolha = 0;
                    
                    system("cls");
                    printf("------------------------------------\n");
                    printf("-            DEVOLUÇÃO             -");
                    printf("------------------------------------\n");
                    printf("(1) Devolver filme");
                    
                    printf("[2]  Voltar");
                    printf("------------------------------------\n");
                    printf("Entre com a opção desejada: ");
                    scanf("%i", &escolha);

                    switch (escolha){
                        case 1:{
                            // Devolução de um determinado filme
                            system("cls");
                            printf("------------------------------------\n");
                            printf("-          DEVOLVER FILME          -");
                            printf("------------------------------------\n");
                            printf("> Digite o código do filme que");
                            printf("  deseja devolver.");
                            printf("------------------------------------\n");
                            printf(">> FILMES");
                            printf("------------------------------------\n");
                            
                            // Mostra somente os filmes com 1 ou mais locações
                            for (l = 1; l < qtd_filmes; l++){
                                if (loc.filmes[l].qtd_alocada >= 1) {
                                    printf("Código...........: %i", loc.filmes[l].codigo);
                                    printf("Nome.............: %s", loc.filmes[l].nome);
                                    printf("------------------------------------\n");
                                }
                            }

                           printf("Código: ");
                           scanf("%i",codigo);

                                                        
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
                            getch(); // ou getche();

                        }
                    }
                 }while (escolha == 2);
            }
            case 4:{
                // Relatório de filmes
                system("cls");
                printf("------------------------------------\n");
                printf("-            RELATÓRIO             -");
                printf("------------------------------------\n");
                printf("Preço de locação..: R$ %0.2f", loc.preco);
                printf("Filmes disponíveis: %i", loc.disponiveis);
                printf("Filmes locados....: %i", loc.locados);
                
                printf("[1]  Voltar");
                printf("------------------------------------\n");
                printf("<Pressione qualquer tecla para voltar>");
                getch(); // ou getche();
            }
            case 5:{
                // Relatório de filmes
                system("cls");
                printf("------------------------------------\n");
                printf("-              SOBRE               -");
                printf("------------------------------------\n");
                printf("GERAL");
                printf(" > Disciplina: ECD");
                printf(" > Professor.: Elyssandro Piffer");
                printf(" > Data......: 06/06/2021");
                printf("");
                printf("ACADÊMICO");
                printf(" > Vitor Gibim ............... - RA: 00212191");
                printf("");
                printf("[1]  Voltar");
                printf("------------------------------------\n");
                printf("Entre com a opção desejada: ");
                scanf("%i", & escolha);
            }
            case 6:{
            // Mensagem de finalizção
                system("cls");
                printf("> Programa finalizado...");
                break;
            }
            default:{
                // Mensagem de erro
                system("cls");
                printf(">> Opção inválida! Tente novamente.");
                printf("------------------------------------\n");
                printf("<Pressione qualquer tecla para continuar>"); 
                getch(); // ou getche();   
            }    

        }
    }while(escolha == 6);
}