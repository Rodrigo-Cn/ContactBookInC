#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAM 200

typedef struct agenda
{
    char nome[TAM];
    char sobrenome[TAM];
    long long numero;

} Agenda;

void excluirContato();

int main ()
{
    FILE *ponteiro;
    ponteiro = fopen("agenda.txt", "a+");
    setlocale(LC_ALL, "");
    Agenda contato[TAM], aux3;
    int opcao, aux, cont=0, aux2=0;

    printf("1 - CADASTRAR CONTATO");
    printf("\n2 - EXIBIR AGENDA COM ORDEM DO NOME DOS CONTADOS");
    printf("\n3 - EXIBIR AGENDA COM ORDEM DO SOBRENOME DOS CONTADOS");
    printf("\n4 - CONSULTAR UM CONTATO PELO NOME");
    printf("\n5 - BUSCAR AS INFORMAÇOES DE UM CONTATO PELO NÚMERO");
    printf("\n6 - ALTERAR UM CONTATO");
    printf("\n7 - REMOVER UM CONTATO");
    printf("\n8 - SAIR");
    printf("\nOPÇÃO: ");
    scanf("%d", &opcao);

    while(opcao!=8)
    {
        if(opcao==1)
        {

            printf("DIGITE O NOME DO CONTATO: ");
            scanf("%s", &contato[cont].nome);

            printf("DIGITE O SOBRONOME DO CONTATO: ");
            setbuf(stdin, 0);
            fgets(contato[cont].sobrenome, TAM, stdin);
            contato[cont].sobrenome[strlen(contato[cont].sobrenome)-1] = '\0';

            printf("DIGITE O NÚMERO DO CONTATO: ");
            scanf("%lld", &contato[cont].numero);
            cont++;

        }
        else if(opcao==2)
        {
            for(int i=0; i<cont; i++)
            {
                printf("CONTATO %d: %s\n", i+1, contato[i].nome);
            }
        }
        else if(opcao==3)
        {
            for(int i=0; i<cont; i++)
            {
                printf("CONTATO %d: %s\n", i+1, contato[i].sobrenome);
            }
        }
        else if(opcao==4)
        {
            char busca[TAM];
            printf("DIGITE O NOME: ");
            scanf("%s", &busca);

            for(int i=0; i<cont; i++)
            {
                if(strcmp(busca,contato[i].nome)==0)
                {
                    printf("NÚMERO: %lld\n", contato[i].numero);
                }
            }
        }
        else if(opcao==5)
        {
            long long int buscaNu;
            printf("DIGITE O NÚMERO: ");
            scanf("%lld", &buscaNu);

            for(int i=0; i<cont; i++)
            {
                if(buscaNu==contato[i].numero)
                {
                    printf("CONTATO: %s %s\n", contato[i].nome, contato[i].sobrenome);
                }
            }
        }
        else if(opcao==6)
        {
            int id, op;
            for(int i=0; i<cont; i++)
            {
                printf("CONTATO %d: %s", i+1, contato[i].nome);
            }

            printf("\nDIGITE A IDENTIFICAÇÃO DO CONTATO QUE DESEJA ALTERAR DADOS: ");
            scanf("%d", &id);

            for(int i=0; i<cont; i++)
            {
                if(id==i+1)
                {
                    printf("1 - ALTERAR NOME");
                    printf("\n2 - ALTERAR SOBRENOME");
                    printf("\n3 - ALTERAR NÚMERO");
                    printf("\n4 - SAIR");
                    printf("\nOPÇÃO: ");
                    scanf("%d", &op);

                    while(op!=4)
                    {
                        if(op==1)
                        {
                            printf("DIGITE O NOVO NOME: ");
                            scanf("%s", &contato[i].nome);
                        }
                        else if(op==2)
                        {
                            printf("DIGITE O NOVO SOBRENOME: ");
                            setbuf(stdin, 0);
                            fgets(contato[i].sobrenome, TAM, stdin);
                            contato[i].sobrenome[strlen(contato[i].sobrenome)-1] = '\0';
                        }
                        else if(op==3)
                        {
                            printf("DIGITE O NOVO NÚMERO: ");
                            scanf("%lld", &contato[i].numero);
                        }
                        else
                        {
                            printf("DIGITE UMA OPÇÃO VÁLIDA\n");
                        }
                        printf("1 - ALTERAR NOME");
                        printf("\n2 - ALTERAR SOBRENOME");
                        printf("\n3 - ALTERAR NÚMERO");
                        printf("\n4 - SAIR");
                        printf("\nOPÇÃO: ");
                        scanf("%d", &op);
                    }
                }
            }
        }
        else if(opcao==7)
        {
            int id2;
            for(int i=0; i<cont; i++)
            {
                printf("\nCONTATO %d: %s", i+1, contato[i].nome);
            }
            printf("\nQUAL CONTATO DESEJA REMOVER? ");
            scanf("%d", &id2);
            int indice=id2-1;
            strcpy(contato[indice].nome," ");
            strcpy(contato[indice].sobrenome," ");
            contato[indice].numero = 0;

            excluirContato(&contato,&aux3,indice);
            cont--;
        }
        printf("\n1 - CADASTRAR CONTATO");
        printf("\n2 - EXIBIR AGENDA COM ORDEM DO NOME DOS CONTADOS");
        printf("\n3 - EXIBIR AGENDA COM ORDEM DO SOBRENOME DOS CONTADOS");
        printf("\n4 - CONSULTAR UM CONTATO PELO NOME");
        printf("\n5 - BUSCAR AS INFORMAÇOES DE UM CONTATO PELO NÚMERO");
        printf("\n6 - ALTERAR UM CONTATO");
        printf("\n7 - REMOVER UM CONTATO");
        printf("\n8 - SAIR");
        printf("\nOPÇÃO: ");
        scanf("%d", &opcao);

    }

    for(int i=0; i<cont; i++)
    {
        fprintf(ponteiro,"%s", contato[i].nome);
        fprintf(ponteiro,"\n%s", contato[i].sobrenome);
        fprintf(ponteiro,"\n%lld\n\n", contato[i].numero);
    }
    fclose(ponteiro);
}

void excluirContato(Agenda *contato, Agenda *aux3, int indice)
{
    for (int i=indice; i<200; i++)
    {
        strcpy(aux3->nome,contato[i].nome);
        strcpy(aux3->sobrenome,contato[i].sobrenome);
        aux3->numero = contato[i].numero;

        strcpy(contato[i].nome,contato[i+1].nome);
        strcpy(contato[i].sobrenome,contato[i+1].sobrenome);
        contato[i].numero = contato[i+1].numero;

        strcpy(contato[i+1].nome,aux3->nome);
        strcpy(contato[i+1].sobrenome,aux3->sobrenome);
        contato[i+1].numero = aux3->numero;
    }
}
