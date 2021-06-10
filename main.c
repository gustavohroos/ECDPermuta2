#include<stdio.h>
#include<stdlib.h>
#include"bib.c"



int main(void){

    int escolha, l, qtd_filmes, codigo, idade;

    for(;;)
    {
        escolha = menu();

        switch (escolha)
        {
        case 1:
            Cadastro();
            break;
        case 2:
            Locacao();
            break;
        case 3:
            DevolucaoFilme();
            break;
        case 4:
            RelatorioFilmes();
            break;
        case 5:
            Sobre();
            break;
        case 0:
            system("clear");
            printf("> Programa finalizado...");
            exit(0);
            break;
        default:
        {
            // Mensagem de erro
            system("clear");
            printf(">> Opção inválida! Tente novamente.");
            printf("------------------------------------\n");
            printf("<Pressione qualquer tecla para continuar>"); 
            getchar();    
        }    
        }
}
return 0;
}
