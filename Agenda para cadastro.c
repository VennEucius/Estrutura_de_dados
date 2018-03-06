// Agenda feita por Vinícius Assumpção Garcia (3° periodo BCC)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 40
 
typedef struct ag dados;
struct ag
{
    char nome[40], cel[40], email[40], fixo[40];
    
};
dados agenda[MAX];
int op;
//Menu--------------------------------------------------------------------------------------------------------------------------
void menu()
{
	setlocale(LC_ALL, "Portuguese");
    printf("//////////  Bem vindo a agenda eletronica! //////////////// \n\n Selecione uma das opções e pressione a tecla Enter:\n\n/// (1) - Cadastrar dados                 ////////////// \n/// (2) - Listagem de todos os nomes     //////////////  \n/// (3) - Consulta de Dados (Por Nome)  //////////////  \n/// (4) - Consulta de Dados (Por email)  //////////////  \n/// (5) - Remoção de um Nome          //////////////  \n/// (0) - Para fechar o programa (X)//////////////  \nOpcão: ");
    scanf("%d", &op);
    while(op < 0 || op > 6)
    {
        printf("Erro! Opcao invalida,entre com um valor valido por favor:\n");
        scanf("%d", &op);
    }
}
// loop for em c
// manipulacao vetores em c
//Dados -------------------------------------------------------------------------------------------------------------------------
void Ler_Dados()
{
    //procurar um dados vazio e ler as novas informacoes nele
    setlocale(LC_ALL, "Portuguese");
    int i;
    for(i = 0; i<MAX; i++)
    {
        if(agenda[i].nome[0] == 0)
        {
            int op1;
            printf(" \n/// Entre com o Nome:\n");
            scanf(" %[^\n]s", &agenda[i].nome);
            printf("/// Por favor entre com o Celular:\n");
            scanf(" %[^\n]s", &agenda[i].cel);
            printf("/// Por favor entre com o email:\n");
            scanf(" %[^\n]s", &agenda[i].email);
            printf("/// Gostaria inserir Telefone Fixo? ((( 0 Para (não) - 1 Para (sim) )))\n");
            scanf("%d", &op1);
            if(op1 == 1)
            {
                printf("/// Tel. Fixo: ");
                scanf(" %[^\n]s", &agenda[i].fixo);
            }
            return;
        }
    }
}
//processo de funcionamento da LISTA de cadastro da agenda ------------------------------------------------------------------------------------------------------------------
void listagem()
{
    int i;
    for(i = 0; i<MAX; i++)
    {
        if(agenda[i].nome[0] != 0)
        {
            printf("\n/// Nome: %s \n/// Telefone Fixo: %s \n/// Celular: %s \n/// email: %s\n/// ", agenda[i].nome, agenda[i].fixo, agenda[i].cel, agenda[i].email);
        }
    }
}
//Pesquisa por nome -------------------------------------------------------------------------------------------------------------------------------------------------------
void name_search()
{
    char name[50];
    int i;
    printf("Entre com o Nome:\n");
    scanf(" %[^\n]s", &name);
    for(i = 0; i<MAX; i++)
    {
        if(strcmp(agenda[i].nome, name) == 0)
        {
            printf("Nome: %s \nTelefone Fixo: %s\nCelular: %s \nemail: %s\n", agenda[i].nome, agenda[i].fixo, agenda[i].cel, agenda[i].email);
        }
    }
}
 
//Pesquisa por email --------------------------------------------------------------------------------------------------------------------------------------------------------
 
void email_search()
{
    char email[50];
    int i;
    printf("Entre com o email:\n");
    scanf(" %[^\n]s", &email);
    for(i = 0; i<MAX; i++)
    {
        if(strcmp(agenda[i].email, email) == 0)
        {
            printf("Nome: %s \nTelefone Fixo: %s\nCelular: %s \nemail: %s\n", agenda[i].nome, agenda[i].fixo, agenda[i].cel, agenda[i].email);
        }
    }
}
//exclusão de cadastros já inseridos-----------------------------------------------------------------------------------------------------------------------------
void excluir()
{
    char name[50];
    int i;
    printf("Entre com o Nome:\n");
    scanf(" %[^\n]s", &name);
    for(i = 0; i<MAX; i++)
    {
        if(strcmp(agenda[i].nome, name) == 0)
        {
            agenda[i].cel[0] = 0;
            agenda[i].email[0] = 0;
            agenda[i].fixo[0] = 0;
            agenda[i].nome[0] = 0;
            return;
        }
    }
}

// Principal -------------------------------------------------------------------------------------------------------------------------------------------------------------
void main() {
    int i;
    for(i = 0; i<MAX; i++)
    {
        agenda[i].cel[0] = 0;
        agenda[i].email[0] = 0;
        agenda[i].fixo[0] = 0;
        agenda[i].nome[0] = 0;
    }
    menu();
    while(op)
    {
        if(op == 1)
        {
            Ler_Dados();
            system("cls");
            menu();
        }
        else if(op == 2)
        {
            listagem();
            system("pause");
            system("cls");
            menu();
        }
        else if(op == 3)
        {
            name_search();
            system("pause");
            system("cls");
            menu();
        }
        else if(op == 4)
        {
            email_search();
            system("pause");
            system("cls");
            menu();
        }
        else if(op == 5)
        {
            excluir();
            system("cls");
            menu();
        }

    }
    getch();
}	
