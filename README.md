# Trabalho Final ED1

Trabalho realizado pelos alunos:
  - Vinícius Alves Martins - 11811BSI259
  - Nayara de Oliveira Faustino - 11911BSI233
  
O projeto foi desenvolvido da seguinte maneira:
Inicialmente, pensamos a respeito de como seria a funcionalidade do programa para atender as especificações do trabalho, ou seja, permitir que, a qualquer momento, pudesse imprimir a lista (cardápio), fila ou pilha. Com base nisso, criamos um menu com as seguintes opções:
  
  - 1- Adicionar cliente na fila
  - 2- Imprimir fila de clientes
  - 3- Imprimir pilha de chocolates
  - 4- Imprimir lista (cardapio)
  - 5- Sair
  
#### Opção 1  
Ao selecionar a opção 1, é solicitado ao usuário que informe o nome do cliente e, após isso, será solicitado que informe o ID do item desejado no cardápio. O programa permitirá que o usuário informe a quantidade de itens que desejar (simulando a comanda do cliente que vai incrementando a medida que o mesmo realiza pedidos), e a condiçao de parada ocorre quando o cliente insere o valor 0. Existe uma segunda regra que, caso o cliente informe um ID que não pertence ao cardápio, e que também não é a condição de parada da adição de itens, ele informa a mensagem "Por favor, insira um numero pertencente ao cardapio!", e aguarda um novo ID válido.

Quando o usuário informa 0 na etapa de inserção de itens à comanda, ou seja, deseja concluir o pedido e finalizar adição do cliente, o programa exibirá o valor total gasto (somatório dos valores de cada item do cardápio que foi adicionado à comanda) por ele e o chocolate que ele receberá. Vale ressaltar que, ainda que o cliente não tenha consumido nada no restaurante, ou seja, seu primeiro ID informado foi 0, o seu valor total (no caso R$0.00) será exibido e ele também receberá um chocolate, visto que por ser cortesia, todos têm direito.

Ao finalizar a etapa de adição dos itens a comanda, o cliente é adicionado à fila de clientes, e o menu volta a ser exibido.

#### Opção 2
Ao selecionar a opção 2, a fila de clientes é exibida, com as seguintes possibilidades:
  - Caso ela esteja esteja vazia, será exibida a mensagem "Nao ha clientes na fila!"
  - Caso tenha clientes na fila, ela exibirá a posição do cliente na fila, seu nome e o chocolate que ele receberá, respectivamente.
  - Caso ela esteja cheia, será exibida a mesma lista do caso acima, porém com o adicional da mensagem "A fila esta cheia!"
  
#### Opção 3
Ao selecionar a opção 3, será exibido a pilha de chocolates. Caso essa opção seja selecionada antes de qualquer cliente ser atendido, será exibido todos os chocolates da pilha na ordem correta e, a medida que os clientes são atendidos, ou seja, a função pop() é acionada, a pilha vai ficando menor.

#### Opção 4
Ao selecionar a opção 4, o cardápio será exibido ao cliente. Nele é possível encontrar o ID de cada item (que será utilizado na opção 1 - Adicionar clientes na fila), a descrição do item e o seu preço (em reais).

#### Opção 5
Ao selecionar a opção 5, o programa será encerrado.

### Construção do código
#### Base
  Para implementação desse programa, iniciamos pela instanciação da struct Item, que originou no cardápio (lista do tipo struct Item). Após isso criamos a struct Cliente, que receberia os dados do cliente, como seu nome, comanda, chocolate que receberá, e valor total a ser pago no restaurante), e posteriormente implementamos a fila de clientes. 
  
#### Funções
  Para ordenar os comandos que deveriam ser feitos no programa, implementamos algumas funções, como função de adicionar item ao cardápio, printar o cardápio, printar fila de clientes, printar pilha de chocolates, adicionar e retirar chocolates à pilha, entre outras.
  
#### Main
  Na função main, implementamos o menu (conforme descrito no início desse relatório) através do laço do-while, para que, a cada operação realizada, o menu voltasse a ser exibido, a menos que a opção tenha sido a de sair. Nela, estão a implementação da primeira opção, que seria "Adicionar clientes na fila", e as demais consistem na chamada das funções:
  - Opção 2: Função print_fila();
  - Opção 3: Função print_pilha();
  - Opção 4: Função print_cardapio();
  
 ### Resultados obtidos
  Através dessa implementação, conseguimos obter com êxito os seguintes resultados.
    - Criação de clientes e adição à fila
    - Incremento da fila a medida que clientes são criados
    - Decremento da pilha a medida que chocolates são distribuídos ao cliente
    - Incremento de novos itens ao cardápio
    - Exibição da fila de clientes sempre que solicitado
    - Exibição da pilha de chocolates sempre que solicitado
    - Exibição do cardápio sempre que solicitado
    
### Link para vídeo: https://web.microsoftstream.com/video/6b32a761-c98e-43a6-987d-87bd5ee24f72
