#include <stdio.h>
#include <string.h>
#include "meio.h"
#include "gestor.h"
#include "cliente.h"

int menu()
{
    int op;
	printf("\n\n\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Bem-vindo(a) a GreenGo! \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tA GreenGo é uma empresa de mobilidade elétrica que oferece soluções de transporte sustentável para pessoas e empresas. Com a nossa frota de veículos elétricos, ajudamos a reduzir as emissões de CO2 e a preservar o meio ambiente.\n\n\n\n\n\n");
	printf("\t2023 - Todos os direitos reservados")
	Sleep(1000);
    system("cls");
	printf("\n\n\t=====================================\n");
    printf("\t|          Menu  Principal          |\n");
    printf("\t=====================================\n");
    printf("\t| 1. Meio de mobilidade eletrica    |\n");
    printf("\t| 2. Cliente                        |\n");
    printf("\t| 3. Gestor                         |\n");
    printf("\t=====================================\n");
	printf("1. Inserir Meio\n");
    printf("2. Listar Meios\n");
    printf("3. Remover Meio\n");
    printf("4. Guardar Meios\n");
    printf("5. Ler Meios\n");
    printf("0. Sair\n");
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("Digite a sua escolha: ");
    scanf("%d",&op);
    return(op);
}

int main()
{
    Meio* meios = NULL; // Lista ligada vazia 
    int op, cod;
    float bat, aut;
    char tipo[50];
    do
    {
        op = menu();
        switch(op)
        {
            case 1: 
                printf("Codigo?\n");
                scanf("%d",&cod);
                scanf("%*c"); 
                printf("Tipo\n");
                scanf("%[^\n]s",tipo);
                printf("Nivel da bateria?\n");
                scanf("%f",&bat);
                printf("Autonomia\n");
                scanf("%f",&aut);
                meios = inserirMeio(meios,cod,tipo,bat,aut);
                break;
            case 2: listarMeios(meios); break;
            case 3: 
                printf("Codigo do meio de mobilidade a remover?\n");
                scanf("%d",&cod);
                meios = removerMeio(meios, cod);
                break;
            case 4: guardarMeios(meios); break;
            case 5: meios = lerMeios(); break;
            case 6: {
                struct Gestor gestor_admin = {"admin", "admin"};
                char input_username[20];
                char input_password[20];
                printf("Digite seu nome de usuario: ");
                scanf("%s", input_username);
                printf("Digite sua senha: ");
                scanf("%s", input_password);
                if (strcmp(input_username, gestor_admin.username) == 0 && strcmp(input_password, gestor_admin.password) == 0) {
                    printf("Login realizado com sucesso como %s!\n", gestor_admin.username);
                } else {
                    printf("Credenciais invalidas. Tente novamente.\n");
                }
                break;
            }
        }
    }
 while (op!=0);
 }