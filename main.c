#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CLIENTES 5
#define MAX_CHOCOLATE 20

//Declaracao da estrutura Item
struct Item {
    int id;
    char descricao[100];
    float preco;
};

//Declaracao da estrutura Cliente
struct Cliente {
    char nome_cliente[100];
    int comanda[MAX_ITEMS];
    int chocolate;
    float total;
};

//Declaracao do cardapio = lista de itens
struct Item cardapio[MAX_ITEMS];
int menu_size = 0;

//Declaracao da fila de clientes
struct Cliente filaClientes[MAX_CLIENTES];

//Declaracao da pilha de chocolates
int chocolate_stack[MAX_CHOCOLATE];
int pilha_size = 0;
int top = 0;

//Funcao para adicionar itens ao cardapio
void add_item_cardapio(int id, char descricao[], float preco) {
    cardapio[menu_size].id = id;
    strcpy(cardapio[menu_size].descricao, descricao);
    cardapio[menu_size].preco = preco;
    menu_size++;
}

//Funcao para imprimir o cardapio
void print_cardapio() {
    for (int i = 0; i < menu_size; i++) {
        printf("%d. %s - R$%.2f\n", cardapio[i].id, cardapio[i].descricao, cardapio[i].preco);
    }
}

//Funcao para imprimir a fila de clientes
void print_fila(int num_cliente) {
    if(num_cliente == 0){
            printf("   Nao ha clientes na fila!\n");
    }
    for (int i = 0; i < num_cliente; i++) {
        printf("   %do) %s: Chocolate %d\n", i+1, filaClientes[i].nome_cliente, filaClientes[i].chocolate);
    }
}

//Funcao para adicionar chocolate a pilha
void push_chocolate(int chocolate) {
    chocolate_stack[top++] = chocolate;
    pilha_size++;
}

//Funcao para retirar chocolate da pilha
int pop_chocolate() {
    pilha_size--;
    return chocolate_stack[--top];
}

//Funcao para imprimir a pilha de chocolates
void print_pilha() {
    for (int i = pilha_size-1; i >= 0; i--) {
        printf("   Chocolate %d\n", chocolate_stack[i]);
    }
}

int main()
{
    int opcao;
    int num_cliente = 0;
    char nome_cliente[100];
    int item_id;
    float total;

    //Criacao da pilha de chocolates com a funcao push
    for(int i=1; i<= MAX_CHOCOLATE; i++){
        push_chocolate(i);
    }

    //Adicao dos itens ao cardapio com o metodo add_item_cardapio
    add_item_cardapio(1, "Foie gras com geleia", 60.99);
    add_item_cardapio(2, "Carpaccio de carne", 55.99);
    add_item_cardapio(3, "Risoto de funghi", 45.99);
    add_item_cardapio(4, "Ceviche de salmao", 49.99);
    add_item_cardapio(5, "Lagosta com risoto", 70.99);
    add_item_cardapio(6, "Costela de cordeiro assada", 78.99);
    add_item_cardapio(7, "Peito de peru recheado", 52.99);
    add_item_cardapio(8, "Arroz negro com polvo", 48.99);
    add_item_cardapio(9, "Filet mignon", 69.99);
    add_item_cardapio(10, "Salada Caesar", 23.99);

    printf("=========== RESTAURANTE XX ===========\n");
    printf("--------------------------------------\n");

    do {
        //Menu para selecao das opcoes desejadas
        printf("\n1- Adicionar cliente na fila\n");
        printf("2- Imprimir fila de clientes\n");
        printf("3- Imprimir pilha de chocolates\n");
        printf("4- Imprimir lista (cardapio)\n");
        printf("5- Sair\n");
        printf("O que deseja fazer? ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                if(num_cliente == MAX_CLIENTES){
                    printf("   Nao eh possivel adicionar mais clientes, pois a fila esta cheia!\n");
                    break;
                }
                //Implementacao para adicionar cliente
                printf("\nInforme o nome do cliente: ");
                scanf("%s", nome_cliente);
                strcpy(filaClientes[num_cliente].nome_cliente, nome_cliente);
                total = 0;
                int x = pop_chocolate();

                //Metodo para receber os itens desejado para o cliente (comanda)
                for (int j = 0; j < MAX_ITEMS; j++) {
                    printf("-Informe o ID do item desejado ou 0 para concluir pedido: ", nome_cliente);
                    scanf("%d", &item_id);

                    if (item_id == 0) {
                        if(j==0){
                            filaClientes[num_cliente].total = total;
                            filaClientes[num_cliente].chocolate = x;
                            break;
                        }
                        break;
                    }
                    else if(item_id < 0 || item_id > 10){
                        printf("\tPor favor, insira um numero pertencente ao cardapio!\n");
                    }

                    filaClientes[num_cliente].comanda[j] = item_id;
                    for (int k = 0; k < MAX_ITEMS; k++) {
                        if (cardapio[k].id == item_id) {
                            total += cardapio[k].preco;
                        }
                    }
                }

                filaClientes[num_cliente].total = total;
                printf("- Total: R$%.2f\n", total);
                filaClientes[num_cliente].chocolate = x;
                printf("- Chocolate: %d\n", filaClientes[num_cliente].chocolate);
                num_cliente++;
                break;

            case 2:
                printf("\nListando fila:\n");
                print_fila(num_cliente);
                break;

            case 3:
                printf("\nListando pilha:\n");
                print_pilha();
                break;

            case 4:
                printf("\nCardapio:\n");
                print_cardapio();
                break;

            case 5:
                printf("\nSaindo\n");
                break;

            default:
                printf("\nOpcao invalida\n");
                break;
            }
    }while (opcao != 5);

    return 0;
}
