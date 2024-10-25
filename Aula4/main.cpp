/*
Título: Manipulação de Struct
Autor: Ricardo Hideki T. Junior
Data: 2024.10.11
*/

//Declaração de Bibliotecas
#include <iostream>
#include <limits>
#include <iomanip> 
#include <string>
#include <algorithm>

using namespace std;

//Construção da Struct :O
struct pessoa{
  int codigo;
  string nome;
  float altura;
};

//Prototipoação de Funções
int menu();
int lerCodigoValido(const string &mensagem); //& serve para armazenar nesse local da memória
void limparBuffer();
void exibirMsgErro(const string &mensagem);
void mostrarArray(pessoa array[], int tamanhoArray);
void esperarEnter();
void zerarArray(pessoa array[], int tamanho);
void preencherArray(pessoa array[], int tamanho);
string lerStringValida(const string &mensagem);
float lerAlturaValida(const string &mensagem);
void editaArray(pessoa array[], int tamanho);
void verificarPessoa(pessoa array[], int tamanho);
void ordernarArray(pessoa array[], int tamanho);

// Função Principal
int main() { 
  const int tamanho =  2; //Define o tamanho do array.
  pessoa pessoaArray[tamanho]; //Declara o array que armazena tamanho. Registros de pessoas.
  int opcao = 0; //Varíavel para armazenar a opção do usuWARIO.

  do{
    opcao = menu();
    switch(opcao){
      case 1: mostrarArray(pessoaArray, tamanho); break;
      case 2: zerarArray(pessoaArray, tamanho); break;
      case 3: preencherArray(pessoaArray, tamanho); break;
      case 4: editaArray(pessoaArray, tamanho); break;
      case 5: verificarPessoa(pessoaArray, tamanho); break;
      case 6: ordernarArray(pessoaArray, tamanho); break;
      case 0: cout << "Sair\n"; break;
      default: exibirMsgErro("Opção Inválida! Escolha uma Opção válida."); break;
    }
  }while(opcao!=0);

};

//Função exibe menu, retorna a escolha do usuário.
int menu() {
  cout << "\nEscolha uma opção: \n";
  cout << "1 - Mostrar array de pessoas\n";
  cout << "2 - Zerar array de pessoas\n";
  cout << "3 - Preenher array de pessoas\n";
  cout << "4 - Editar pessoa no array\n";
  cout << "5 - Verificar pessoa no array\n";
  cout << "6 - Ordernar array de pessoas por código\n";
  cout << "0 - Sair\n";

  return lerCodigoValido("Opção: ");
};

//Função ler número inteiro válido
int lerCodigoValido(const string &mensagem) {
  int numero;
  
  while(true){
    
    cout << mensagem;
    cin >> numero;
    
    if(cin.fail()){
      limparBuffer();
      exibirMsgErro("Entrada inválida! Por favor insira um número inteiro.");
    } else {
      limparBuffer();
      return numero;
    }
  
  };
}

//Função Limpar Buffer
void limparBuffer(){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignora entradas inválidas.
}

//Função para exibir mensagem de Erro
void exibirMsgErro(const string &mensagem){
  cout << mensagem << endl;
}

//Função mostra Array de pessoas
void mostrarArray(pessoa array[], int tamanhoArray) {
  cout << left << setw(10) << "Código" << "\t"
       << left << setw(20) << "Nome" << "\t"
       << left << setw(10) << "Altura" << endl;
  cout << string(50, '-') << endl;
  for(int i = 0; i < tamanhoArray; i++){
    cout << left << setw(10) << array[i].codigo << "\t"
         << left << setw(20) << array[i].nome << "\t"
         << left << setw(10) << array[i].altura << endl;
  }
  esperarEnter();
}

//Função esperar entre
void esperarEnter(){
  cout << "\nPressione Enter para continuar...";
  cin.get();
}

//Função zerar o array de pessoas
void zerarArray(pessoa array[], int tamanho){
  for(int i = 0; i < tamanho; i++){
    array[i].codigo = 0;
    array[i].nome = "";
    array[i].altura = 0.0;
  }

  cout<<"Array de pessoas zerado!";
  esperarEnter();
}

// Função para preencher o array de pessoas
void preencherArray(pessoa array[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        array[i].codigo = lerCodigoValido("Digite o Código da Pessoa ["+to_string(i)+"]: ");
        array[i].nome = lerStringValida("Digite o Nome da Pessoa ["+to_string(i)+"]: ");
        array[i].altura = lerAlturaValida("Digite a Altura da Pessoa ["+to_string(i)+"]: ");
    }
    cout << "Array de pessoas preenchido com Sucesso!";
    esperarEnter();
}

// Função para ler uma String Válida
string lerStringValida(const string &mensagem) {
    string entrada;
    cout << mensagem;
    getline(cin, entrada);

    return entrada;
}

//Função ler altura válida
float lerAlturaValida(const string &mensagem){
  float altura;
  while(true){
    cout << mensagem;
    cin >> altura;
    if (cin.fail() || altura <= 0){
      limparBuffer();
      exibirMsgErro("Entrada inválida! Por favor, insira uma altura válida.");
    }else {
      limparBuffer();
      return altura;
    }
  }
}

//Função edita array
void editaArray(pessoa array[], int tamanho){
  int posicao = lerCodigoValido("Digite a posição que deseja editar: (0 a "+to_string(tamanho-1)+"): ");
  while(posicao < 0 || posicao >= tamanho){
    exibirMsgErro("Posição Inválida! Tente Novamente.");
    posicao = lerCodigoValido("Digite uma posição válida: ");
  };
  
  array[posicao].codigo = lerCodigoValido("Digite o novo Código para a posição ["+to_string(posicao)+"]: ");
  limparBuffer();
  array[posicao].nome = lerStringValida("Digite o novo nome para a posição ["+to_string(posicao)+"]: ");
  limparBuffer();
  array[posicao].altura = lerAlturaValida("Digite a nova Altura da Pessoa ["+to_string(posicao)+"]: ");
  limparBuffer();

  cout<<"Pessoa Editada com Sucesso";
  esperarEnter();
}

//Função Verifica pessoa
void verificarPessoa(pessoa array[], int tamanho){
  int codigo = lerCodigoValido("Digite o código da pessoa que deseja verificar: ");
  bool encontrado = false;
  for(int i = 0; i < tamanho; i++){
    if(array[i].codigo == codigo){
      cout << "Pessoa com o código " << codigo << " encontrada!" << endl;
      cout << "Nome: " << array[i].nome;
      cout << "Altura: " << array[i].altura;
      encontrado = true;
      break;
    }

    if(!encontrado){
      cout << "Pessoa com o código " << codigo << " não encontrada!" << endl;
    }
    esperarEnter();
  }
}

//Função ordernar array por código
void ordernarArray(pessoa array[], int tamanho){
  sort(array, array+tamanho, [](pessoa a, pessoa b){
    return a.codigo < b.codigo;
  });
  cout << "Array de pessoas ordenado por código!";
  esperarEnter();
}
