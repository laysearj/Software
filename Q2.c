#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>

//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct Dados {
    int apagado;
    char nome[20];
    int id;
    int ultimo_Acesso;
    float pontuacao;
} Dados;
    
Dados * usuario;

int main () {
    char nome_arquivo[10] = {'b', 'a', 'n', 'c', 'o', 'X', '.', 't', 'x', 't'};
    int num_usuarios, num_arquivos, num_threads;
    int i, j = 0, sair = 0;
    float somatorio = 0;
    FILE * arquivo = NULL;

    scanf ("%d", &num_usuarios); //verificação
    while (sair == 0) {     
        scanf ("%d", &num_arquivos);
        if (num_arquivos >= 2) {
            scanf ("%d", &num_threads);
            if (num_threads <= num_arquivos/2) {
                sair = 1;
            } else {
                printf ("Quantidade de threads invalida. Digite a quantidade de arquivos e a quantidade de threads novamente: \n");
            }
        } else {
            printf ("Quantidade de arquivos invalida. Digite novamente: \n");
        }
    }   

    usuario = (Dados *) malloc (num_usuarios * sizeof (Dados));

    for (i = 0; i < num_arquivos; i++) { //leitura do arquivo
        nome_arquivo[5] = i+49;

        arquivo = fopen (nome_arquivo, "r+");
        if (arquivo != NULL) {
            while(fscanf (arquivo, "%s %d %d %f", usuario[j].nome, &usuario[j].id, &usuario[j].ultimo_Acesso, &usuario[j].pontuacao) != EOF) {
                j++;
                
                //printf("to aqui");
            }
        } 
    }

    for (i = 0; i < num_usuarios; i++) {
        usuario[i].apagado = 0;
        somatorio += (usuario[i].ultimo_Acesso/(usuario[i].pontuacao * usuario[i].pontuacao));
    }

    somatorio = somatorio/num_usuarios;
    printf ("\n\n\n => SOMATORIO = %f\n\n\n", somatorio);

    for (i = 0; i < num_usuarios; i++) {
        if (2 * (usuario[i].ultimo_Acesso) >= somatorio) {
            usuario[i].apagado = 1;
        }
    }
    

    for (i = 0; i < num_usuarios; i++) {
      //  if (usuario[i].apagado == 1) {
            printf ("\nUSUARIO APAGADO: [%d]\n\n", i+1);
            printf ("Nome: %s\n", usuario[i].nome);
            printf ("Id: %d\n", usuario[i].id);
            printf ("Ultimo Acesso: %d\n", usuario[i].ultimo_Acesso);
            printf ("Pontuacao: %f\n", usuario[i].pontuacao);
        //}
    }

    return 0;
}