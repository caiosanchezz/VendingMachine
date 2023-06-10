#include <iostream>
#include <stdlib.h> //do exit()
#include <stdio.h>
#include <locale.h>
#include <cmath>
#include <iomanip>  // setprecision


using namespace std;
    
typedef struct {
  int codigo;
  string nome;
  float preco;
  int quantidade;
  int totalVendido;
} produto;

produto estoque[5];

//Inicializando as funções
void menuPrincipal();
void gerarEstoque();
void exibirProdutos();
void operacaoPagamento(int codigo, int quantidade);
void painelAdministrador();
void editarEstoque();
void gerarInventario();
void gerarFaturamento();
void efetuarAlteracao(int codigoProduto, int itemAlteracao);

int main() {

  gerarEstoque();

  menuPrincipal();

}

void menuPrincipal() {

  system("clear||cls");

  int opcao;

  cout << "\n         Vending Machine             ";
  cout << "\n=====================================";
  cout << "\nComo deseja acessar?\n";
  cout << "\n [1] - Modo Usuário";
  cout << "\n [2] - Modo Administrador";
  cout << "\n [3] - Sair\n ";

  cin >> opcao;
  
  while ((opcao != 1) && (opcao != 2) && (opcao != 3) ) {
    
    cout << "\nOpção inválida!!\nFavor, selecione novamente: ";
    cin >> opcao;
  }

  // SAIR DO PROGRAMA
  if (opcao == 3) {
    system("exit");
  }

  // MENU USUÁRIO
  if (opcao == 1) {
    exibirProdutos();
  }

  // MENU ADMINISTRADOR
  if (opcao == 2) {
    system("clear||cls");

    string senha;
    
    cout << "          ADMINISTRADOR        ";
    cout << "\n================================================";
    cout << "\nPara acessar a interface de administração,\nfavor insira a senha: ";
    cin >> senha;

    while (senha != "senha123") {
      cout << "\nSenha incorreta!!!\nTente novamente: ";
      cin >> senha;
    }

    painelAdministrador();
    
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
  estoque[3].preco = 5.90;
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
  cout << "\n=============================================" << endl;
    
  for (int i = 0; i < 5; i++) {
    cout << "\nCódigo: " << i + 1; 
    cout << "\nItem: " << estoque[i].nome;
    cout << "\nR$ " <<  setprecision(3) << estoque[i].preco;
    cout << "\n---------------------------------------------" << endl;
    
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

  cout << "\n            PAGAMENTO              ";
  cout << "\n=================================================" << endl;  

  float valorTotal = estoque[codigo].preco * quantidade;

  int metodoPagamento, verificacao;

  // Informações sobre o item e valor a ser pago
  cout << "\nItem Selecionado: " << estoque[codigo].nome;
  cout << "\nQuantidade: " << quantidade;
  cout << "\nValor Unitário: " <<  setprecision(3) << estoque[codigo].preco;
  cout << "\nTotal a pagar: " <<  setprecision(3) << valorTotal << endl;

  cout << "\nPor favor, informe o método de pagamento: ";
  cout << "\n (1) - Dinheiro";
  cout << "\n (2) - Cartão";
  cout << "\n (3) - PIX / QR Code" << endl;
  cin >> metodoPagamento;

  while ((metodoPagamento != 1) && (metodoPagamento != 2) && (metodoPagamento != 3)) {
    cout << "\nAtenção, o método escolhido não se enquadra nas opções disponíveis!!";
    cout << "\nPor favor, verifique e escolha novamente o método de pagamento: " << endl;
    cin >> metodoPagamento;
  }

  if (metodoPagamento == 1) { // Dinheiro ======================================================================================

    int valorInserido, adicionalInserido, troco;

    cout << "\nInsira o dinheiro: "; // Mudar isso aqui depois pq tá feio
    cin >> valorInserido;

    while (valorInserido < valorTotal)
    {
      cout << "\nQuantia insuficiente, favor insira mais dinheiro: "; // Arrumar depois
      cin >> adicionalInserido;
      valorInserido += adicionalInserido;
    }

    troco = valorInserido - valorTotal;

    cout << "\nTotal inserido: " << valorInserido;
    cout << "\nTroco : " <<  setprecision(3) << troco;

    cout << "\nMuito obrigado :)" << endl;
  }

  if (metodoPagamento == 2) { // Cartão ==========================================================================================

    int opcaoCartao;

    cout << "\nPor favor, selecione: ";
    cout << "\n (1) - Débito ";
    cout << "\n (2) - Crédito" << endl;
    cin >> opcaoCartao;

    while ((opcaoCartao != 1) && (opcaoCartao != 2)) {
      cout << "Caraio viu";
      cin >> opcaoCartao;
    }

    cout << "\nAproxime o cartão da tela :)";
    cout << "\nMuito Obrigado :)" << endl;
  }

  if (metodoPagamento == 3) { // QR CODE ==========================================================================================
    cout << "\nGerando QR Code...";
    cout << "\n ▥ ▥▥▥ ▥";
    cout << "\n ▥ ▥ ▥▥▥";
    cout << "\n ▥▥▥▥▥ ▥";
    cout << "\n ▥▥ ▥▥ ▥";

    cout << "\nPagamento concluído!";
    cout << "\nMuito Obrigado :)" << endl;
  }

  estoque[codigo].quantidade -= quantidade; // Tira do estoque
  estoque[codigo].totalVendido =+ valorTotal; // Armazena o valor total da compra pra fins de faturamento

  // Verificar se o usuário deseja continuar utilizando a máquina
  cout << "\nPara retornar ao menu inicial, pressione '1'";
  cout << "\nPara sair, pressione qualquer tecla...";
  cin >> verificacao;

  if (verificacao == 1) {
    menuPrincipal();
  }
  else {
    system("exit");
  }


}

void painelAdministrador() {

  system("clear||cls");

  int opcaoMenuADM = 0;

  cout << "\n     PAINEL DE CONTROLE - ADMINISTRADOR          ";
  cout << "\n===================================================\n";

  cout << "\n [1] - Alteração/Manutenção de estoque";
  cout << "\n [2] - Inventário de estoque";
  cout << "\n [3] - Relatório de Faturamento\n";
  cout << "\n [4] - <<== Voltar ao menu inicial\n";
  cin >> opcaoMenuADM;

  while ((opcaoMenuADM != 1) && (opcaoMenuADM != 2) && (opcaoMenuADM != 3) &&
         (opcaoMenuADM != 4)) {
    cout << "\nOpção inválida!!";
    cout << "\nPor favor, verifique e escolha novamente: " << endl;
    cin >> opcaoMenuADM;
  }

  if (opcaoMenuADM == 4) {
    menuPrincipal();
  } else {

    if (opcaoMenuADM == 1) {
      editarEstoque();
    }

    if (opcaoMenuADM == 2) {
      gerarInventario();
    }

    if (opcaoMenuADM == 3) {
      gerarFaturamento();
    }
  }
}

void editarEstoque() {

  system("clear||cls");

  int codigo, itemAlteracao;

  cout << "\n     PAINEL DE CONTROLE - ESTOQUE          ";
  cout << "\n===================================================\n"; 

  for (int i = 0; i < 5; i++) {
    cout << "\nCódigo: " << i + 1;
    cout << "\nItem: " << estoque[i].nome;
    cout << "\n---------------------------------------------" << endl;
  }

  cout << "\nInforme o código do produto a ser alterado: ";
  cin >> codigo;  

  codigo = codigo - 1;

  cout << "\nALTERACAÇÃO DE CADASTRO: " << estoque[codigo].nome;
  cout << "\n---------------------------------------------";
  cout << "\n [1] - Descrição";
  cout << "\n [2] - Quantidade";
  cout << "\n [3] - Preço";
  cout << "\n\nSelecione o item a ser alterado: " << endl;  
  cin >> itemAlteracao;
  
  efetuarAlteracao(codigo, itemAlteracao);

}

void gerarInventario() {

  system("clear||cls");

  int verificacao;

  for (int i = 0; i < 5; i++) {
    cout << "\nItem: " << estoque[i].nome;
    cout << "\nCódigo: " << i + 1;
    cout << "\nQuantidade em estoque: " << estoque[i].quantidade;
    cout << "\n---------------------------------------------" << endl;
  }

  cout << "\n\nPara voltar ao painel de controle, aperte [1] ";
  cin >> verificacao;

  painelAdministrador();

}

void gerarFaturamento() {

  system("clear||cls"); 

  int verificacao;
  float faturamentoTotal = 0, previsaoTotal = 0;

  cout << "\n             FATURAMENTO POR PRODUTO            ";

  for (int i = 0; i < 5; i++) {
    cout << "\n================================================";
    cout << "\nProduto: " << estoque[i].nome;
    cout << "\nFaturamento parcial (até o momento): R$ " << setprecision(3) << estoque[i].totalVendido;
    cout << "\nFaturamento futuro: R$ " << setprecision(3) << estoque[i].preco * estoque[i].quantidade;

    faturamentoTotal += estoque[i].totalVendido;
    previsaoTotal += (estoque[i].preco * estoque[i].quantidade);
    
  }

  cout << "\n\n\n                FATURAMENTO GERAL               ";
  cout << "\n================================================";
  cout << "\nFaturamento total até o momento: R$ " << setprecision(3) << faturamentoTotal;
  cout << "\nPrevisão de faturamento total futuro: R$ " << setprecision(3) << previsaoTotal;

  cout << "\n\nPara voltar ao painel de controle, aperte [1] ";
  cin >> verificacao;

  painelAdministrador();
  
}

void efetuarAlteracao(int codigoProduto, int itemAlteracao) {

  system("clear||cls");

  string novaDescricao;
  int novaQuantidade;
  float novoPreco;

  cout << "\nAlterando: " << estoque[codigoProduto].nome;

  switch (itemAlteracao) {
    case 1:
      cout << "\nDescrição atual do produto: " << estoque[codigoProduto].nome;
      cout << "\nDigite a nova descrição: ";
      cin >> novaDescricao;

      estoque[codigoProduto].nome = novaDescricao;
    break;
    
    case 2:
      cout << "\nQuantidade atual do produto: " << estoque[codigoProduto].quantidade;
      cout << "\nDigite a nova quantidade: ";
      cin >> novaQuantidade;

      estoque[codigoProduto].quantidade = novaQuantidade;
    break;

    case 3:
      cout << "\nPreço atual do produto: R$ " << estoque[codigoProduto].preco;
      cout << "\nDigite o novo preço: ";
      cin >> novoPreco;

      estoque[codigoProduto].preco = novoPreco;
    break;

  }

  cout << "\nO item foi alterado com sucesso!!";
  cout << "\nRetornando ao painel de controle...";

  int  a,b;
  for(a=0; a<60500; a++)
  for(b=0; b<6000; b++);

  painelAdministrador();

}