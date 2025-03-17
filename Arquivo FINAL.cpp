#include <iostream>
#include <string>
#include <locale>
#include <vector>

using namespace std;

// Estruturas
struct CADenxoval {
    int cod;
    string produto;
    string descricao;
    float precoCusto;
    float precoVenda;
};

struct CADfornecedor {
    int id;
    string nome;
    string contato;
};

struct CADfuncionario {
    int id;
    string nome;
    string carroModelo;
    string carroPlaca;
    string diaUso;
};

// Vetores globais para armazenar enxovais, fornecedores e funcionários
vector<CADenxoval> enxovais;
vector<CADfornecedor> fornecedores;
vector<CADfuncionario> funcionarios;

// Funções para cadastro de enxovais
void CadastrarEnxoval() {
    CADenxoval novoEnxoval;
    FILE* arquivo = fopen("enxoval.bin", "ab");
    if (!arquivo){
    	cerr<< "Erro ao abrir o arquivo!"<<endl;
		return; 
	}

    cout << "\n----- Cadastro de Enxoval -----\n";
    cout << "Código: ";
    cin >> novoEnxoval.cod;
    cin.ignore(); // Para limpar o buffer de entrada
    cout << "Produto: ";
    getline(cin, novoEnxoval.produto);
    cout << "Descrição: ";
    getline(cin, novoEnxoval.descricao);
    cout << "Preço de Custo: R$";
    cin >> novoEnxoval.precoCusto;
    cout << "Preço de Venda: R$";
    cin >> novoEnxoval.precoVenda;
    fwrite(&novoEnxoval, sizeof(CADenxoval),1,arquivo);
    fclose(arquivo);
    cout << "\nEnxoval cadastrado com sucesso!\n";
}

// Função para editar enxoval
void EditarEnxoval() {
    int codBuscado;
    cout << "\n----- Editar Enxoval -----\n";
    cout << "Digite o código do enxoval que deseja editar: ";
    cin >> codBuscado;

    for (size_t i = 0; i < enxovais.size(); i++) {
        if (enxovais[i].cod == codBuscado) {
            cout << "Produto atual: " << enxovais[i].produto << endl;
            cout << "Novo Produto: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, enxovais[i].produto);
            cout << "Descrição atual: " << enxovais[i].descricao << endl;
            cout << "Nova Descrição: ";
            getline(cin, enxovais[i].descricao);
            cout << "Preço de Custo atual: R$" << enxovais[i].precoCusto << endl;
            cout << "Novo Preço de Custo: R$";
            cin >> enxovais[i].precoCusto;
            cout << "Preço de Venda atual: R$" << enxovais[i].precoVenda << endl;
            cout << "Novo Preço de Venda: R$";
            cin >> enxovais[i].precoVenda;

            cout << "\nEnxoval editado com sucesso!\n";
            return;
        }
    }
    cout << "Enxoval não encontrado.\n";
}

// Função para procurar enxoval pelo código
void ProcurarEnxoval() {
    int codBuscado;
    cout << "\n----- Buscar Enxoval -----\n";
    cout << "Digite o código do enxoval: ";
    cin >> codBuscado;

    for (size_t i = 0; i < enxovais.size(); i++) {
        const CADenxoval& enxoval = enxovais[i];
        if (enxoval.cod == codBuscado) {
            cout << "Código: " << enxoval.cod 
                 << " | Produto: " << enxoval.produto 
                 << " | Descrição: " << enxoval.descricao 
                 << " | Preço de Custo: R$" << enxoval.precoCusto 
                 << " | Preço de Venda: R$" << enxoval.precoVenda << "\n";
            return;
        }
    }
    cout << "Enxoval não encontrado.\n";
}

// Funções para cadastro de fornecedores
void CadastrarFornecedor() {
    CADfornecedor novoFornecedor;
    FILE* arquivo = fopen("CadFornecedor.bin", "ab");
    if (!arquivo){
    	cerr<< "Erro ao abrir o arquivo!"<<endl;
		return; 
	}

    cout << "\n----- Cadastro de Fornecedor -----\n";
    cout << "ID: ";
    cin >> novoFornecedor.id;
    cin.ignore(); // Para limpar o buffer de entrada
    cout << "Nome: ";
    getline(cin, novoFornecedor.nome);
    cout << "Contato: ";
    getline(cin, novoFornecedor.contato);

    fornecedores.push_back(novoFornecedor);
    cout << "\nFornecedor cadastrado com sucesso!\n";
    
    fwrite(&novoFornecedor, sizeof(CADfornecedor),1,arquivo);
    fclose(arquivo);
    cout << "\nEnxoval cadastrado com sucesso!\n";
}

// Função para editar fornecedor
void EditarFornecedor() {
    int idBuscado;
    cout << "\n----- Editar Fornecedor -----\n";
    cout << "Digite o ID do fornecedor que deseja editar: ";
    cin >> idBuscado;

    for (size_t i = 0; i < fornecedores.size(); i++) {
        if (fornecedores[i].id == idBuscado) {
            cout << "Nome atual: " << fornecedores[i].nome << endl;
            cout << "Novo Nome: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, fornecedores[i].nome);
            cout << "Contato atual: " << fornecedores[i].contato << endl;
            cout << "Novo Contato: ";
            getline(cin, fornecedores[i].contato);

            cout << "\nFornecedor editado com sucesso!\n";
            return;
        }
    }
    cout << "Fornecedor não encontrado.\n";
}

// Funções para cadastro de funcionários
void CadastrarFuncionario() {
    CADfuncionario novoFuncionario;
    FILE* arquivo = fopen("CadFuncionario.bin", "ab");
    if (!arquivo){
    	cerr<< "Erro ao abrir o arquivo!"<<endl;
		return; 
	}

    cout << "\n----- Cadastro de Funcionário -----\n";
    cout << "ID: ";
    cin >> novoFuncionario.id;
    cin.ignore(); // Para limpar o buffer de entrada
    cout << "Nome: ";
    getline(cin, novoFuncionario.nome);
    cout << "Modelo do Carro: ";
    getline(cin, novoFuncionario.carroModelo);
    cout << "Placa do Carro: ";
    getline(cin, novoFuncionario.carroPlaca);
    cout << "Dia do Uso: ";
    getline(cin, novoFuncionario.diaUso);

    funcionarios.push_back(novoFuncionario);
    cout << "\nFuncionário cadastrado com sucesso!\n";
    fwrite(&novoFuncionario, sizeof(CADfuncionario),1,arquivo);
    fclose(arquivo);
    cout << "\nEnxoval cadastrado com sucesso!\n";
}

// Função para editar funcionário
void EditarFuncionario() {
    int idBuscado;
    cout << "\n----- Editar Funcionário -----\n";
    cout << "Digite o ID do funcionário que deseja editar: ";
    cin >> idBuscado;

    for (size_t i = 0; i < funcionarios.size(); i++) {
        if (funcionarios[i].id == idBuscado) {
            cout << "Nome atual: " << funcionarios[i].nome << endl;
            cout << "Novo Nome: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, funcionarios[i].nome);
            cout << "Modelo do Carro atual: " << funcionarios[i].carroModelo << endl;
            cout << "Novo Modelo do Carro: ";
            getline(cin, funcionarios[i].carroModelo);
            cout << "Placa do Carro atual: " << funcionarios[i].carroPlaca << endl;
            cout << "Nova Placa do Carro: ";
            getline(cin, funcionarios[i].carroPlaca);
            cout << "Dia do Uso atual: " << funcionarios[i].diaUso << endl;
            cout << "Novo Dia de Uso: ";
            getline(cin, funcionarios[i].diaUso);

            cout << "\nFuncionário editado com sucesso!\n";
            return;
        }
    }
    cout << "Funcionário não encontrado.\n";
}

// Funções para remover todas as informações
void RemoverTodos() {
    enxovais.clear();
    fornecedores.clear();
    funcionarios.clear();
    cout << "\nTodos os registros foram removidos com sucesso!\n";
}

// Funções para exibir relatórios
void Relatorio() {
    cout << "\n----- Relatório de Enxovais -----\n";
    for (size_t i = 0; i < enxovais.size(); i++) {
        const CADenxoval& enxoval = enxovais[i];
        cout << "Código: " << enxoval.cod 
             << " | Produto: " << enxoval.produto 
             << " | Descrição: " << enxoval.descricao 
             << " | Preço de Custo: R$" << enxoval.precoCusto 
             << " | Preço de Venda: R$" << enxoval.precoVenda << "\n";
    }

    cout << "\n----- Relatório de Fornecedores -----\n";
    for (size_t i = 0; i < fornecedores.size(); i++) {
        const CADfornecedor& fornecedor = fornecedores[i];
        cout << "ID: " << fornecedor.id 
             << " | Nome: " << fornecedor.nome 
             << " | Contato: " << fornecedor.contato << "\n";
    }

    cout << "\n----- Relatório de Funcionários -----\n";
    for (size_t i = 0; i < funcionarios.size(); i++) {
        const CADfuncionario& funcionario = funcionarios[i];
        cout << "ID: " << funcionario.id 
             << " | Nome: " << funcionario.nome 
             << " | Carro: " << funcionario.carroModelo 
             << " | Placa: " << funcionario.carroPlaca 
             << " | Dia de Uso: " << funcionario.diaUso << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        system("cls");
        cout << "\n----- HIPÓLITO ENXOVAIS -----\n";
        cout << "\n1 - Cadastrar ENXOVAL \n2 - Editar ENXOVAL \n3 - Cadastrar FORNECEDOR \n4 - Editar FORNECEDOR \n5 - Cadastrar FUNCIONÁRIO \n6 - Editar FUNCIONÁRIO \n7 - Relatório \n8 - Remover Todas as Informações \n9 - Buscar ENXOVAL \n0 - SAIR\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                CadastrarEnxoval();
                break;
            case 2:
                EditarEnxoval();
                break;
            case 3:
                CadastrarFornecedor();
                break;
            case 4:
                EditarFornecedor();
                break;
            case 5:
                CadastrarFuncionario();
                break;
            case 6:
                EditarFuncionario();
                break;
            case 7:
                Relatorio();
                break;
            case 8:
                RemoverTodos();
                break;
            case 9:
                ProcurarEnxoval();
                break;
            case 0:
                cout << "Saindo...\n";
                break;	
            default:
                cout << "Opção inválida! Digite apenas as opções que estão acima.\n";
                break;
        }
        system("pause");
    } while (opcao != 0);

    return 0;
}
