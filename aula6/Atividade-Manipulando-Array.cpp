/*
Título: Atividade: Manipulando Array
Autor: Profe. Berssa
Data: 2024.10.11
*/

/*
  Autor: Ricardo Hideki Tsugikava Juniopr
  Data: 2024.10.25

  O código a seguir se trata de um organizador de array de nomes, tendo como funções inicias: Mostrar o Array, Zerar o Array, Preencer o Array Manualmente, Editar um nome do Array, Verificar se um nome está no Array e por fim, Ordenar o Array.
*/


#include <iostream>
#include <string>
#include <algorithm>  // Para usar a função sort()
#include <limits>     // Para usar numeric_limits

using namespace std;

// Função para aguardar que o usuário pressione Enter
void esperarEnter() {
    cout << "\nPressione Enter para continuar...";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa o buffer de entrada - NO CASO DE DAR ERRO DURANTE A EXECUSSÃO DESCOMENTE ESSA LINHA
    cin.get();  // Aguarda o usuário pressionar Enter
}


// Função para limpar o buffer e resetar o estado do `cin`
void limparBuffer() {
    cin.clear();  // Limpa o estado de erro
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora entradas inválidas no buffer
}

// Função genérica para exibir mensagens de erro
void exibirMensagemErro(const string &mensagem) {
    cout << mensagem << endl;
}

// Função para ler uma string válida
string lerEntradaValida(const string &mensagem) {
    string entrada;
    cout << mensagem;
    getline(cin, entrada);  // Usa getline para aceitar entradas com espaços
    return entrada;
}

// Função para zerar o array de nomes
void zerarArray(string array[], int tamanho) {
    fill(array, array + tamanho, "");  // Usa a função fill para preencher o array com strings vazias
    cout << "Array de nomes zerado!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para mostrar o array de nomes
void mostrarArray(string array[], int tamanho) {
    cout << "Conteúdo do array de nomes:\n";
    for (int i = 0; i < tamanho; i++) {
        cout << "Posição [" << i << "]: " << array[i] << endl;  // Exibe o índice e o nome
    }
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para preencher o array de nomes com entradas do usuário
void preencherArray(string array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = lerEntradaValida("Digite um nome para a posição [" + to_string(i) + "]: ");
    }
    cout << "Array de nomes preenchido manualmente!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para editar um nome em uma posição específica do array
void editarArray(string array[], int tamanho) {
    int posicao = stoi(lerEntradaValida("Digite a posição que deseja editar (0 a " + to_string(tamanho - 1) + "): "));

    // Garante que a posição esteja dentro dos limites do array
    while (posicao < 0 || posicao >= tamanho) {
        exibirMensagemErro("Posição inválida! Tente novamente.");
        posicao = stoi(lerEntradaValida("Digite uma posição válida: "));
    }

    string nome = lerEntradaValida("Digite o novo nome para a posição [" + to_string(posicao) + "]: ");
    array[posicao] = nome;  // Atualiza o nome na posição escolhida
    cout << "Nome alterado com sucesso!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para verificar se um nome está presente no array
void verificarNome(string array[], int tamanho) {
    string nome = lerEntradaValida("Digite o nome que deseja verificar: ");
    bool encontrado = false;

    // Verifica se o nome está no array
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == nome) {
            cout << "Nome '" << nome << "' encontrado na posição [" << i << "]" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Nome '" << nome << "' não encontrado no array." << endl;
    }

    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para ordenar o array de nomes em ordem alfabética
void ordenarArray(string array[], int tamanho) {
    sort(array, array + tamanho);  // Usa a função sort() para ordenar o array
    cout << "Array de nomes ordenado com sucesso!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para Mostrar a Quantidade de Nomes Vazios e Preenchidos
void mostraNomesVazioPreenchidos(string array[], int tamanho){
  int vazios = 0, preenchidos = 0; //Declaração das variáveis do escopo.
  
    for(int i = 0; i < tamanho; i++){ //Loop em for para cada elemento do array.
      if(array[i] == ""){ vazios++; } //Se o array estiver vazio, adiciona um na variável vazio. Se estiver preenchido, adiciona 1 na variável preenchido.
      else { preenchidos++; }
    }

  cout << "Número de Nomes Vazios: " << vazios << endl;
  cout << "Número de Nomes Preenchidos: " << preenchidos << endl;

  esperarEnter();
}

//Função para Contar a Quantidade de Ocorrências de um Nome
void contaNomes(string array[], int tamanho){
  string nome = lerEntradaValida("Insira o nome desejado: "); //Lê uma entrada do usuário
  bool encontrado = false; //Declara variáveis que serão utilizadas no escopo
  int quantidade = 0;

  for(int i = 0; i < tamanho; i++){ //Para cada item do array...
    if(nome == array[i]){ //Se o nome dado pelo usuário for igual ao item da posição i...
      encontrado = true; //Encontrado igual a verdadeiro
      quantidade++; //Adiciona 1 para quantidade.
    }
  }

  if(!encontrado){ //Se encontrado não é verdadeiro...
    exibirMensagemErro("O nome desejado não foi encontrado no Array!"); //Imprime mensagem de erro.
  } else { //Caso contrário...
    cout << "O nome " << nome << " se repete " << quantidade << " no array.\n"; //Exibe a quantidade de vezes que o nome aparece o array.
  }

  esperarEnter();
}

//Função para Exibir o Nome Mais Curto e o Nome Mais Longo
void nomeMaisCurtoLongo(string array[], int tamanho){
  string maiorString, menorString; //Strings usadas no escopo
  int numMaiorString = array[0].length(), numMenorString = array[0].length(); //Inteiros com valores padrão usados no escopo (para não haver erro de memória)

  for(int i = 0; i < tamanho; i++){ //Para cada item no array...
      
    if(array[i].length() > numMaiorString){ //Se o tamanho do item for maior que o tamanho da maior String...
        numMaiorString = array[i].length(); //numMaiorString igual ao tamanho do array.
        maiorString = array[i]; //maiorString igual a String.
    }
      
    if (array[i].length() < numMenorString){ //Se o tamanho do array for menor que o tamanho da menor string...
        numMenorString = array[i].length(); //O tamanho da menor string é igual ao tamanho da string.
        menorString = array[i]; //a menorString igual ao item do array.
    }
  }

    //Imprime os valores necessários para o usuário.
    cout << endl;
    cout << "A maior String é: " << maiorString << " com " << numMaiorString << " caractéres.\n";
    cout << "A menor String é: " << menorString << " com " << numMenorString << " caractéres.\n";  

    esperarEnter();
}

void removerVogais(string array[], int tamanho){
    string itemResultado;  //String usada temporáriamente no escopo
    
    for (int i = 0; i < tamanho; i++){ //Para cada item do array...
        for (char letra : array[i]){ //Para cada letra de uma string do array...
            
            if(letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u' && //Se não for nenhuma vogal minuscula ou maiscula...
                letra != 'A' && letra != 'E' && letra != 'I' && letra != 'O' && letra != 'U'){itemResultado += letra;} //Adicionar letra na variável temporária.
         
        }
        
        array[i] = itemResultado; //A string atual do array é igual a variável temporária.
        itemResultado = ""; //Limpa a variável temporária para o próximo uso.
            
    }

    //Imprime as informações
    cout << endl;
    cout << "Vogais removidas do Array!\n";
}

// Função que exibe o menu e retorna a escolha do usuário
int menu() {
    cout << "\nEscolha uma opção:\n";
    cout << "1 - Mostrar array de nomes\n";
    cout << "2 - Zerar array de nomes\n";
    cout << "3 - Preencher array de nomes\n";
    cout << "4 - Editar nome no array\n";
    cout << "5 - Verificar se o nome está no array\n";
    cout << "6 - Ordenar array de nomes\n";
    cout << "7 - Quantidade de nomes vazios e preenchidos\n";
    cout << "8 - Contar a Quantidade de Ocorrências de um Nome\n";
    cout << "9 - Exibir o nome mais longo e mais curto do Array\n";
    cout << "10 - Remover vogais\n";
    cout << "0 - Sair\n";
    return stoi(lerEntradaValida("Opção: "));
}

int main() {
    const int TAMANHO = 3;  // Define o tamanho do array de nomes
    string array[TAMANHO];   // Declara o array para armazenar 10 nomes

    int opcao;

    do {
        opcao = menu();  // Mostra o menu e lê a opção do usuário

        switch (opcao) {
            case 1:
                mostrarArray(array, TAMANHO);
                break;
            case 2:
                zerarArray(array, TAMANHO);
                break;
            case 3:
                preencherArray(array, TAMANHO);
                break;
            case 4:
                editarArray(array, TAMANHO);
                break;
            case 5:
                verificarNome(array, TAMANHO);
                break;
            case 6:
                ordenarArray(array, TAMANHO);
                break;
            case 7: 
                mostraNomesVazioPreenchidos(array, TAMANHO);
                break;
            case 8: 
                contaNomes(array, TAMANHO);
                break;
            case 9: 
                nomeMaisCurtoLongo(array, TAMANHO);
                break;
            case 10: 
                removerVogais(array, TAMANHO);
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                exibirMensagemErro("Opção inválida! Escolha uma opção válida.");
                break;
        }
    } while (opcao != 0);  // O programa continua executando até que o usuário escolha sair

    return 0;
}
