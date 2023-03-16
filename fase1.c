#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "meio.h"
#include "gestor.h"
#include "cliente.h"

void loading()
{
	printf("\033[32m\n\n\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Bem-vindo(a) a GreenGo! \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\033[0m\n");
	printf("\nA GreenGo e uma empresa de mobilidade eletrica que oferece solucoes de transporte sustentavel para pessoas e empresas. \nCom a nossa frota de veiculos eletricos, ajudamos a reduzir as emissoes de CO2 e a preservar o meio ambiente.\n\n\n");
	printf("2023 - Todos os direitos reservados");
	Sleep(8000);
    system("cls");
}

int menu_principal()
{
	loading();
    int op_p;
	printf("\n\n\t=====================================\n");
    printf("\t|          Menu  Principal          |\n");
    printf("\t=====================================\n");
    printf("\t| 1. Meio de mobilidade eletrica    |\n");
    printf("\t| 2. Cliente                        |\n");
    printf("\t| 3. Gestor                         |\n");
    printf("\t|                                   |\n");
	printf("\t| 0. Sair                           |\n");
    printf("\t=====================================\n");
	printf("\n > Digite a sua escolha: ");
    scanf("%d",&op_p);
    return(op_p);
}

 int menu_meio()
{
    int op_meio;
    system("cls");
	printf("\n\n\t=====================================\n");
	printf("\t|    Meio de mobilidade eletrica    |\n");
	printf("\t=====================================\n");
	printf("\t| 1. Inserir Meio                   |\n");
	printf("\t| 2. Remover Meio                   |\n");
	printf("\t| 3. Listar Meios                   |\n");
	printf("\t| 4. Guardar Meios                  |\n");
	printf("\t| 5. Ler Meios                      |\n");
	printf("\t|                                   |\n");
	printf("\t| 9. Anterior               0. Sair |\n");
	printf("\t=====================================\n");
	printf("\n > Digite a sua escolha: ");
   	scanf("%d",&op_meio);
    return(op_meio);
}

int main()
{
    Meio * meios = NULL; // Lista ligada vazia
	Cliente * clientes = NULL; // Lista ligada vazia
	struct Gestor gestor_admin = {"admin", "admin"};
    int op_p, op_meio, cod, numcliente;
    float bat, aut;
    char tipo[50], input_username[20], input_password[20], nome[50], email[50], tel[15], morada[100];

    do
    {
        op_p = menu_principal();
        switch(op_p)
        {
			case 1: {
                do
                {
                    op_meio = menu_meio();
                    switch(op_meio)
                    {
                        case 1: printf("Olá está a funcionar"); break;
                        case 9: menu_principal ();
                    }
                }
                while (op_meio!=0);
                return 0;
            }
            /*case 1: 
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
                break;*/
            case 2: listarMeios(meios); break;
            case 3: 
                printf("Codigo do meio de mobilidade a remover?\n");
                scanf("%d",&cod);
                meios = removerMeio(meios, cod);
                break;
            case 4: guardarMeios(meios); break;
            case 5: meios = lerMeios(); break;
            case 6: {
                
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
    while (op_p!=0);
 }