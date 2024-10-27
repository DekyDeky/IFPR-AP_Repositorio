/*
Título: Atividade: Manipulando Struct
Autor: Profe. Berssa
Data: 2024.10.11
*/

/*
Autor: Ricardo Hideki Tsugikava Junior
Data: 2024.10.27
*/

/*
O código a seguir tem a função de manipular um struct de diversas formas e mostrar suas modificações.
*/


#include <iostream>
#include <string>
#include <algorithm>  // Para usar a função sort()
#include <limits>     // Para usar numeric_limits
#include <iomanip>  // Para usar setw e ajustar a largura das colunas
#include <cctype> //Biblioteca usada para manipulação de caractéres únicos, sendo utilizado a função toupper() para tornar maiúscula a primeira letra de cada nome.
#include <vector> //Biblioteca usada para mnipulação de vetores.

using namespace std;

// Definindo a struct Pessoa
struct Pessoa {
    int codigo;
    string nome;
    float altura;
};

// Função para aguardar que o usuário pressione Enter
void esperarEnter() {
    cout << "\nPressione Enter para continuar...";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa qualquer caractere no buffer e aguarda o Enter
    cin.get();  // Aguarda o usuário pressionar Enter
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    cin.clear();  // Limpa o estado de erro
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora entradas inválidas no buffer
}

// Função genérica para exibir mensagens de erro
void exibirMensagemErro(const string &mensagem) {
    cout << mensagem << endl;
}

// Função para ler uma string válida
string lerStringValida(const string &mensagem) {
    string entrada;
    cout << mensagem;
    getline(cin, entrada);  // Usa getline para aceitar entradas com espaços
    return entrada;
}

// Função para ler um número inteiro válido
int lerCodigoValido(const string &mensagem) {
    int numero;
    while (true) {
        cout << mensagem;
        cin >> numero;
        if (cin.fail()) {
            limparBuffer();  // Limpa o estado de erro e o buffer
            exibirMensagemErro("Entrada inválida! Por favor, insira um número inteiro.");
        } else {
            limparBuffer();  // Limpa o buffer após a entrada válida
            return numero;
        }
    }
}

// Função para ler uma altura válida
float lerAlturaValida(const string &mensagem) {
    float altura;
    while (true) {
        cout << mensagem;
        cin >> altura;
        if (cin.fail() || altura <= 0) {
            limparBuffer();  // Limpa o estado de erro e o buffer
            exibirMensagemErro("Entrada inválida! Por favor, insira uma altura válida (acima de 0).");
        } else {
            limparBuffer();  // Limpa o buffer após a entrada válida
            return altura;
        }
    }
}

// Função para zerar o array de pessoas
void zerarArray(Pessoa array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i].codigo = 0;
        array[i].nome = "";
        array[i].altura = 0.0;
    }
    cout << "Array de pessoas zerado!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para mostrar o array de pessoas com alinhamento
void mostrarArray(Pessoa array[], int tamanho) {
    // Título das colunas com alinhamento
    cout << left << setw(10) << "Código" << "\t" 
         << left << setw(20) << "Nome" << "\t"
         << left << setw(10) << "Altura" << endl;

    // Linha divisória
    cout << string(50, '-') << endl;

    // Exibe cada pessoa no array com as colunas alinhadas
    for (int i = 0; i < tamanho; i++) {
        cout << left << setw(10) << array[i].codigo << "\t"
             << left << setw(20) << array[i].nome << "\t"
             << left << setw(10) << array[i].altura << "m" << endl;
    }

    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para preencher o array de pessoas com entradas do usuário
void preencherArray(Pessoa array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i].codigo = lerCodigoValido("Digite o código da pessoa [" + to_string(i) + "]: ");
        //limparBuffer();  // Limpa o buffer antes de capturar a string
        array[i].nome = lerStringValida("Digite o nome da pessoa [" + to_string(i) + "]: ");
        array[i].altura = lerAlturaValida("Digite a altura da pessoa [" + to_string(i) + "] (em metros): ");
    }
    cout << "Array de pessoas preenchido manualmente!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para editar uma pessoa em uma posição específica do array
void editarArray(Pessoa array[], int tamanho) {
    int posicao = lerCodigoValido("Digite a posição que deseja editar (0 a " + to_string(tamanho - 1) + "): ");

    // Garante que a posição esteja dentro dos limites do array
    while (posicao < 0 || posicao >= tamanho) {
        exibirMensagemErro("Posição inválida! Tente novamente.");
        posicao = lerCodigoValido("Digite uma posição válida: ");
    }

    array[posicao].codigo = lerCodigoValido("Digite o novo código para a posição [" + to_string(posicao) + "]: ");
    limparBuffer();  // Limpa o buffer antes de capturar a string
    array[posicao].nome = lerStringValida("Digite o novo nome para a posição [" + to_string(posicao) + "]: ");
    array[posicao].altura = lerAlturaValida("Digite a nova altura para a posição [" + to_string(posicao) + "] (em metros): ");
    cout << "Pessoa editada com sucesso!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para verificar se uma pessoa está presente no array por código
void verificarPessoa(Pessoa array[], int tamanho) {
    int codigo = lerCodigoValido("Digite o código da pessoa que deseja verificar: ");
    bool encontrado = false;

    // Verifica se o código está no array
    for (int i = 0; i < tamanho; i++) {
        if (array[i].codigo == codigo) {
            cout << "Pessoa com código '" << codigo << "' encontrada: Nome: " << array[i].nome << ", Altura: " << array[i].altura << "m" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Pessoa com código '" << codigo << "' não encontrada." << endl;
    }

    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para ordenar o array de pessoas pelo código
void ordenarArray(Pessoa array[], int tamanho) {
    sort(array, array + tamanho, [](Pessoa a, Pessoa b) {
        return a.codigo < b.codigo;
    });
    cout << "Array de pessoas ordenado por código!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

//Função adiciona maiúscula na frente dos nomes.
void adicionaMaiuscula(Pessoa array[], int tamanho) { 
  
  for(int i = 0; i < tamanho; i++){ //Para cada item do array...
    array[i].nome[0] = toupper(array[i].nome[0]); //A primeira letra do nome do item selecionado é transformado em maiúscula.
  }
  
}

//Função para Ordenar Registros por Nome
void ordenarArrayNome(Pessoa array[], int tamanho){

  adicionaMaiuscula(array, tamanho); //Transforma a primeira letra em maiúscula para evitar erros com o sort de letras minusculas e maiusculas.
  
  sort(array, array + tamanho, [](Pessoa a, Pessoa b) { //Ordena o array de acordo com o nome do item.
    return a.nome < b.nome;
      
  });

  //Imprime mensagem.
  cout << endl;
  cout << "Array de pessoas ordenado por nome!";

mostrarArray(array, tamanho);
  
  esperarEnter();
}



//Função Exibir a Pessoa com a Maior e Menor Altura
void ExibirMaiorMenorAltura(Pessoa array[], int tamanho){
    float maiorAltura = 0, menorAltura = array[0].altura; //declaração de floats temporários desse escopo.

    vector<string> nomeMaiorAltura, nomeMenorAltura; //vetores temporários do escopo para armazenar diversos nomes caso haja mais de um nome que atenda os requisitos.

    for(int i = 0; i < tamanho; i++){  //Para cada item do array...
        if(array[i].altura > maiorAltura){ //Se a altura do item for maior que a altura atual.
            maiorAltura = array[i].altura; //Maior altura é igual a altura do item.
            nomeMaiorAltura = {array[i].nome}; //Substitui todos os valores do Array pelo nome com altura maior.
        }else if(array[i].altura == maiorAltura){ // Se existir o valor igual a maior altura...
            nomeMaiorAltura.push_back(array[i].nome); //Adiciona esse nome na lista de nomes de maiores alturas
        }

        if(array[i].altura < menorAltura){ //mesma coisa que a explicação de cima só que com a menor altura.
            menorAltura = array[i].altura;
            nomeMenorAltura = {array[i].nome};
        }else if(array[i].altura == menorAltura){
            nomeMenorAltura.push_back(array[i].nome);
        }
             
    }

    //Impressão em forma de lista de todos os nomes que possuem a maior altura.
    cout << endl;
    cout << "A maior altura da lista é de: " << maiorAltura << " m, sendo de: \n";
    for(int i = 0; i < nomeMaiorAltura.size(); i++){
        cout << "-" << nomeMaiorAltura[i] << endl;
    }

    //Impressão em forma de lista de todos os nomes que possuem a menor altura.
    cout << "A menor altura da lista é de: " << menorAltura << " m, sendo de: \n";
    for(int i = 0; i < nomeMenorAltura.size(); i++){
        cout << "-" << nomeMenorAltura[i] << endl;
    }
}

//Função para Contar Quantas Pessoas Têm uma Altura Superior a um Valor Fornecido
void descobrirAlturaSuperior(Pessoa array[], int tamanho){
    float leituraUsuario = lerAlturaValida("Insira uma altura válida: "); //lê uma altura do usuário.
    int quantPessoas = 0; //inteiro usado no escopo.

    for(int i = 0; i < tamanho; i++){ //Para cada item do array...
        if(array[i].altura > leituraUsuario){ //Se o item for maior que a leitura do usuário...
            quantPessoas++; //Adicione um a quantidade de pessoas;
        }
    }

    //Impressão dos valores.
    cout << endl;
    cout << "A quantidade de pessoas com maior a essa altura é de: " << quantPessoas << endl;
}

//Função que organiza altura entre intervalos
void intervaloAlturas(Pessoa array[], int tamanho){
    //(Gambiarra) Vetores que receberão os valores de cada nome de acordo com o que é específicado a baixo. Eles possuem valores inicias para serem reconhecidos futuramente, sem precisar desenvolver diversos if's e for's.
    vector<string> alturasMenores160 = {"menores ou iguais que 1.60."},
    alturasMenores170 = {"menores ou iguais que 1.70."},
    alturasMenores180 = {"menores ou iguais que 1.80."},
    alturasMaiores180 = {"maiores que 1.80."};
    

    //For para distribuir os nomes do array de acordo com suas alturas.
    for(int i = 0; i < tamanho; i++){
        if(array[i].altura <= 1.6){
            alturasMenores160.push_back(array[i].nome);
        }else if(array[i].altura <= 1.7){
            alturasMenores170.push_back(array[i].nome);
        }else if(array[i].altura <= 1.8){
            alturasMenores180.push_back(array[i].nome);
        }else if(array[i].altura > 1.8) {
            alturasMaiores180.push_back(array[i].nome);
        }
    }

    //(Gambiarra parte 2), um vetor de vetores das alutras, para um futuro for, evitando de novo muitos for's e if's.
    vector<vector<string>> gruposAlturas = {alturasMenores160, alturasMenores170, alturasMenores180, alturasMaiores180};

    for(int i = 0; i < gruposAlturas.size(); i++){ //Para cada item no "grupoAlturas"...
        if(gruposAlturas[i].size() == 1){ //Se o tamanho do item atual de "grupoAlturas" for igual a 1...
            cout << "Não existem alturas " << gruposAlturas[i][0] << endl; //É entendido que o grupo atual não recebeu nenhum valor, pois só possui o "valor de localização" atribuído anteriomente.
        }else if(gruposAlturas[i].size() > 1){ //Se não, se o item atul tiver um tamanho maior que 1...
            cout << "As pessoas com a altura " << gruposAlturas[i][0] << " são:\n"; //Imprime todos os nomes que possuem essa caractéristca.
            for(int j = 1; j < gruposAlturas[i].size(); j++){
                cout << "-" << gruposAlturas[i][j] << endl;
            }
        }
    }

    esperarEnter();
}



// Função que exibe o menu e retorna a escolha do usuário
int menu() {
    cout << "\nEscolha uma opção:\n";
    cout << "1 - Mostrar array de pessoas\n";
    cout << "2 - Zerar array de pessoas\n";
    cout << "3 - Preencher array de pessoas\n";
    cout << "4 - Editar pessoa no array\n";
    cout << "5 - Verificar pessoa no array\n";
    cout << "6 - Ordenar array de pessoas por código\n";
    cout << "7 - Ordernar array de pessoas por nome\n";
    cout << "8 - Exibir a maior e menor altura\n";
    cout << "9 - Descobrir quantas pessoas tem certa altura\n";
    cout << "10 - Verficar altura por intervalos\n";
    cout << "0 - Sair\n";
    return lerCodigoValido("Opção: ");
}

int main() {
    const int TAMANHO = 5;  // Define o tamanho do array de pessoas
    Pessoa array[TAMANHO];  // Declara o array para armazenar 5 registros de pessoas

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
                verificarPessoa(array, TAMANHO);
                break;
            case 6:
                ordenarArray(array, TAMANHO);
                break;
            case 7:
                ordenarArrayNome(array, TAMANHO);
                break;
            case 8:
                ExibirMaiorMenorAltura(array, TAMANHO);
                break;
            case 9:
                descobrirAlturaSuperior(array, TAMANHO);
                break;
            case 10:
                intervaloAlturas(array, TAMANHO);
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
