# Trabalho Final ED1

Trabalho realizado pelos alunos:
  - Vinícius Alves Martins - 11811BSI259
  - Nayara de Oliveira Faustino - 11911BSI233
  
O projeto foi desenvolvido da seguinte maneira:
Inicialmente, pensamos a respeito de como seria a funcionalidade do programa para atender as especificações do trabalho, ou seja, permitir que, a qualquer momento, pudesse imprimir a lista (cardápio), fila ou pilha. Com base nisso, criamos um menu com as seguintes opções:
  
  1- Adicionar cliente na fila
  2- Imprimir fila de clientes
  3- Imprimir pilha de chocolates
  4- Imprimir lista (cardapio)
  5- Sair
  
  
Ao selecionar a opção 1, é solicitado ao usuário que informe o nome do cliente e, após isso, será solicitado que informe o ID do item desejado no cardápio. O programa permitirá que o usuário informe a quantidade de itens que desejar (simulando a comanda do cliente que vai incrementando a medida que o mesmo realiza pedidos), e a condiçao de parada ocorre quando o cliente insere o valor 0. Existe uma segunda regra que, caso o cliente informe um ID que não pertence ao cardápio, e que também não é a condição de parada da adição de itens, ele informa a mensagem "Por favor, insira um numero pertencente ao cardapio!", e aguarda um novo ID válido.

Quando o usuário informa 0 na etapa de inserção de itens à comanda, ou seja, deseja concluir o pedido e finalizar adição do cliente, o programa exibirá o valor total gasto (somatório dos valores de cada item do cardápio que foi adicionado à comanda) por ele e o chocolate que ele receberá. Vale ressaltar que, ainda que o cliente não tenha consumido nada no restaurante, ou seja, seu primeiro ID informado foi 0, o seu valor total (no caso R$0.00) será exibido e ele também receberá um chocolate, visto que por ser cortesia, todos têm direito.

Ao finalizar a etapa de adição do
