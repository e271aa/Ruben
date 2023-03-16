#include <stdio.h>

typedef struct cliente_registo
{
    int numero_cliente;
    char nome[50];
    char email[50];
    char telefone[15];
    char morada[100];
    struct cliente_registo * seguinte;
} Cliente;

Cliente* inserirClientes(Cliente* inicio, int numcliente, char nome[], char email[], char tel[15], char morada[100];); // Inserção de um novo registo
void listarClientes(Cliente* inicio); // listar na consola o conteúdo da lista ligada
int existeClientes(Cliente* inicio, int numcliente;); // Determinar existência do 'codigo' na lista ligada 'inicio'
Cliente* removerClientes(Cliente* inicio, int numcliente;); // Remover um Cliente a partir do seu código

int guardarClientes(Cliente* inicio);
Cliente* lerClientes();