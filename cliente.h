#include <stdio.h>

typedef struct cl_registo
{
    int numero_cliente;
    char nome[50];
    char email[50];
    char telefone[15];
    char morada[100];
} Cliente;

Cliente* inserirClientes(Cliente* inicio, int numero_cliente, char nome[], char email[], char telefone[15], char morada[100];); // Inserção de um novo registo
void listarClientes(Cliente* inicio); // listar na consola o conteúdo da lista ligada
int existeClientes(Cliente* inicio, int numero_cliente;); // Determinar existência do 'codigo' na lista ligada 'inicio'
Cliente* removerClientes(Cliente* inicio, int numero_cliente;); // Remover um Cliente a partir do seu código

int guardarClientes(Cliente* inicio);
Cliente* lerClientes();