#include <iostream>
#include <stdlib.h> //do exit()
#include <stdio.h>
#include <locale.h>

using namespace std;
    
typedef struct {
  int codigo;
  string nome;
  double preco;
  int quantidade;
  int totalVendido;
} produto;

produto estoque[5];

//Inicializando as funções
void menuPrincipal();
void gerarEstoque();
void exibirProdutos();
void operacaoPagamento(int codigo, int quantidade);


int main() {

  gerarEstoque();

  menuPrincipal();

}

void menuPrincipal() {

  string opcao;

  cout << "\n         Vending Machine             ";
  cout << "\n=====================================";
  cout << "\n Como deseja acessar?\n";
  cout << "\n (U) - Modo Usuário";
  cout << "\n (A) - Modo Administrador";
  cout << "\n (S) - Sair\n ";

  cin >> opcao;
  
  while ((opcao != "u") && // Melhorar isso aqui porque tá feio demais
    (opcao != "a") && (opcao != "A") &&
    (opcao != "s") && (opcao != "S")) {
    
    cout << "\nOpção inválida!!\nFavor, selecione novamente: ";
    cin >> opcao;
  }

  // SAIR DO PROGRAMA
  if ((opcao == "s") || (opcao == "S")) {
    system("exit");
  }

  // MENU USUÁRIO
  if ((opcao == "u") || (opcao == "U")) {
    system("clear||cls");
    exibirProdutos();
  }

  // MENU ADMINISTRADOR
  if ((opcao == "a") || (opcao == "A")) {
    system("clear||cls");

    string senha;
    
    cout << "          Administrador        ";
    cout << "\n===============================";
    cout << "\nPara acessar a interface de administração,\nfavor insira a senha: ";
    cin >> senha;

    while (senha != "senha123") {
      cout << "\nSenha incorreta!!!\nTente novamente: ";
      cin >> senha;
    }

    cout << "Acesso liberado!";
    
  }
}

// Função pra gerar o estoque inicial da máquina
void gerarEstoque() {

  estoque[0].codigo = 0;
  estoque[0].nome = "Batata";
  estoque[0].preco = 4.50;
  estoque[0].quantidade = 15;
  estoque[0].totalVendido = 0;

  estoque[1].codigo = 1;
  estoque[1].nome = "Goma de mascar";
  estoque[1].preco = 2.00;
  estoque[1].quantidade = 7;
  estoque[1].totalVendido = 0;

  estoque[2].codigo = 2;
  estoque[2].nome = "Barra de chocolate";
  estoque[2].preco = 3.00;
  estoque[2].quantidade = 12;
  estoque[2].totalVendido = 0;

  estoque[3].codigo = 3;
  estoque[3].nome = "Água";
  estoque[3].preco = 5.00;
  estoque[3].quantidade = 25;
  estoque[3].totalVendido = 0;

  estoque[4].codigo = 4;
  estoque[4].nome = "Bolacha recheada";
  estoque[4].preco = 1.50;
  estoque[4].quantidade = 10;
  estoque[4].totalVendido = 0;
    
}

// Função para gerar o menu com os itens (parte do usuário)
void exibirProdutos() {
  
  system("clear||cls"); 
  int indice, quantidade;
  
  cout << "\n            PRODUTOS             ";
  cout << "\n=================================" << endl;
    
  for (int i = 0; i < 5; i++) {
    cout << "Código: " << i + 1 << endl; 
    cout << "Item: " << estoque[i].nome << endl;
    cout << "R$ " << estoque[i].preco << endl << endl;
    
  }

  cout << "Insira o código do produto desejado: ";
  cin >> indice;

  while ((indice != 1) && (indice != 2) && (indice != 3) && (indice != 4) && (indice != 5)) {
    cout << "Operação inválida!!" << endl;
    cout << "O código inserido não corresponde a nenhum dos itens" << endl;
    cout << "Por favor, confira os produtos e insira o código novamente: ";
    cin >> indice;
  }

  indice = indice - 1; // Tratameto do código pra eu não fazer confusão depois :))
  
  cout << "\nItem selecionado: " << estoque[indice].nome << endl;
  cout << "O item tem " << estoque[indice].quantidade << " unidades disponíveis" << endl;
  cout << "Insira a quantidade desejada: ";
  cin >> quantidade;

  while (quantidade > estoque[indice].quantidade) {
    cout << "\nQuantidade acima do estoque disponível!!";
    cout << "\nVerifique a disponibilidade do item e informe novamente a quantidade desejada: ";
    cin >> quantidade;
  }

  operacaoPagamento(indice, quantidade);
  
}

void operacaoPagamento(int codigo, int quantidade) {

  system("clear||cls"); 

  double valorTotal = estoque[codigo].preco * quantidade;
  int metodoPagamento;

  cout << "\nItem Selecionado: " << estoque[codigo].nome;
  cout << "\nQuantidade: " << quantidade;
  cout << "\nValor Unitário: " << estoque[codigo].preco;
  cout << "\nTotal a pagar: " << valorTotal << endl;

  cout << "\nPor favor, informe o método de pagamento: ";
  cout << "\n (1) - Dinheiro";
  cout << "\n (2) - Cartão";
  cout << "\n (3) - PIX / QR Code";
  cin >> metodoPagamento;

  while ((metodoPagamento != 1) && (metodoPagamento != 2) && (metodoPagamento != 3)) {
    cout << "\nAtenção, o método escolhido não se enquadra nas opções disponíveis!!";
    cout << "\nPor favor, verifique e escolha novamente o método de pagamento: " << endl;
    cin >> metodoPagamento;
  }

  switch (metodoPagamento) {
    
    case 1: // Dinheiro ======================================================================================
      
      int valorInserido, adicionalInserido, troco;

      cout << "\nInsira o dinheiro:"; // Mudar isso aqui depois pq tá feio

      while (valorInserido < valorTotal) {
        cout << "\nQuantia insuficiente, favor insira mais dinheiro kkkk"; // Arrumar depois
        cin >> adicionalInserido;
        valorInserido += adicionalInserido;
      }

      troco = valorInserido - valorTotal;

      cout << "\nTotal inserido: " << valorInserido;
      cout << "\nTroco : " << troco;

      cout << "\nMuito obrigado :)"; 
    
    case 2: // Cartão ==========================================================================================

      int opcaoCartao;

      cout << "\nPor favor, aperte: ";
      cout << "\n (1) - Débito ";
      cout << "\n (2) - Crédito";
      cin >> opcaoCartao;

      while ((opcaoCartao != 1) && (opcaoCartao != 2)) {
        cout << "Caraio viu";
        cin >> opcaoCartao;
      }
      

      cout << "\nAproxime o cartão da tela :)";

    case 3: // QR CODE ==========================================================================================
      cout << "\nGerando QR Code...";
      cout << "\n ▥ ▥▥▥ ▥";
      cout << "\n ▥ ▥ ▥▥▥";
      cout << "\n ▥▥▥▥▥ ▥";
      cout << "\n ▥▥ ▥▥ ▥";

  }


}