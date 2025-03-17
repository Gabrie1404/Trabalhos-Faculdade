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

// Vetores globais para armazenar enxovais, fornecedores e funcion�rios
vector<CADenxoval> enxovais;
vector<CADfornecedor> fornecedores;
vector<CADfuncionario> funcionarios;

// Fun��es para cadastro de enxovais
void CadastrarEnxoval() {
    CADenxoval novoEnxoval;
    FILE* arquivo = fopen("enxoval.bin", "ab");
    if (!arquivo){
    	cerr<< "Erro ao abrir o arquivo!"<<endl;
		return; 
	}

    cout << "\n----- Cadastro de Enxoval -----\n";
    cout << "C�digo: ";
    cin >> novoEnxoval.cod;
    cin.ignore(); // Para limpar o buffer de entrada
    cout << "Produto: ";
    getline(cin, novoEnxoval.produto);
    cout << "Descri��o: ";
    getline(cin, novoEnxoval.descricao);
    cout << "Pre�o de Custo: R$";
    cin >> novoEnxoval.precoCusto;
    cout << "Pre�o de Venda: R$";
    cin >> novoEnxoval.precoVenda;
    fwrite(&novoEnxoval, sizeof(CADenxoval),1,arquivo);
    fclose(arquivo);
    cout << "\nEnxoval cadastrado com sucesso!\n";
}

// Fun��o para editar enxoval
void EditarEnxoval() {
    int codBuscado;
    cout << "\n----- Editar Enxoval -----\n";
    cout << "Digite o c�digo do enxoval que deseja editar: ";
    cin >> codBuscado;

    for (size_t i = 0; i < enxovais.size(); i++) {
        if (enxovais[i].cod == codBuscado) {
            cout << "Produto atual: " << enxovais[i].produto << endl;
            cout << "Novo Produto: ";
            cin.ignore(); // Limpa o buffer
            getline(cin, enxovais[i].produto);
            cout << "Descri��o atual: " << enxovais[i].descricao << endl;
            cout << "Nova Descri��o: ";
            getline(cin, enxovais[i].descricao);
            cout << "Pre�o de Custo atual: R$" << enxovais[i].precoCusto << endl;
            cout << "Novo Pre�o de Custo: R$";
            cin >> enxovais[i].precoCusto;
            cout << "Pre�o de Venda atual: R$" << enxovais[i].precoVenda << endl;
            cout << "Novo Pre�o de Venda: R$";
            cin >> enxovais[i].precoVenda;

            cout << "\nEnxoval editado com sucesso!\n";
            return;
        }
    }
    cout << "Enxoval n�o encontrado.\n";
}

// Fun��o para procurar enxoval pelo c�digo
void ProcurarEnxoval() {
    int codBuscado;
    cout << "\n----- Buscar Enxoval -----\n";
    cout << "Digite o c�digo do enxoval: ";
    cin >> codBuscado;

    for (size_t i = 0; i < enxovais.size(); i++) {
        const CADenxoval& enxoval = enxovais[i];
        if (enxoval.cod == codBuscado) {
            cout << "C�digo: " << enxoval.cod 
                 << " | Produto: " << enxoval.produto 
                 << " | Descri��o: " << enxoval.descricao 
                 << " | Pre�o de Custo: R$" << enxoval.precoCusto 
                 << " | Pre�o de Venda: R$" << enxoval.precoVenda << "\n";
            return;
        }
    }
    cout << "Enxoval n�o encontrado.\n";
}

// Fun��es para cadastro de fornecedores
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

// Fun��o para editar fornecedor
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
    cout << "Fornecedor n�o encontrado.\n";
}

// Fun��es para cadastro de funcion�rios
void CadastrarFuncionario() {
    CADfuncionario novoFuncionario;
    FILE* arquivo = fopen("CadFuncionario.bin", "ab");
    if (!arquivo){
    	cerr<< "Erro ao abrir o arquivo!"<<endl;
		return; 
	}

    cout << "\n----- Cadastro de Funcion�rio -----\n";
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
    cout << "\nFuncion�rio cadastrado com sucesso!\n";
    fwrite(&novoFuncionario, sizeof(CADfuncionario),1,arquivo);
    fclose(arquivo);
    cout << "\nEnxoval cadastrado com sucesso!\n";
}

// Fun��o para editar funcion�rio
void EditarFuncionario() {
    int idBuscado;
    cout << "\n----- Editar Funcion�rio -----\n";
    cout << "Digite o ID do funcion�rio que deseja editar: ";
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

            cout << "\nFuncion�rio editado com sucesso!\n";
            return;
        }
    }
    cout << "Funcion�rio n�o encontrado.\n";
}

// Fun��es para remover todas as informa��es
void RemoverTodos() {
    enxovais.clear();
    fornecedores.clear();
    funcionarios.clear();
    cout << "\nTodos os registros foram removidos com sucesso!\n";
}

// Fun��es para exibir relat�rios
void Relatorio() {
    cout << "\n----- Relat�rio de Enxovais -----\n";
    for (size_t i = 0; i < enxovais.size(); i++) {
        const CADenxoval& enxoval = enxovais[i];
        cout << "C�digo: " << enxoval.cod 
             << " | Produto: " << enxoval.produto 
             << " | Descri��o: " << enxoval.descricao 
             << " | Pre�o de Custo: R$" << enxoval.precoCusto 
             << " | Pre�o de Venda: R$" << enxoval.precoVenda << "\n";
    }

    cout << "\n----- Relat�rio de Fornecedores -----\n";
    for (size_t i = 0; i < fornecedores.size(); i++) {
        const CADfornecedor& fornecedor = fornecedores[i];
        cout << "ID: " << fornecedor.id 
             << " | Nome: " << fornecedor.nome 
             << " | Contato: " << fornecedor.contato << "\n";
    }

    cout << "\n----- Relat�rio de Funcion�rios -----\n";
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
        cout << "\n----- HIP�LITO ENXOVAIS -----\n";
        cout << "\n1 - Cadastrar ENXOVAL \n2 - Editar ENXOVAL \n3 - Cadastrar FORNECEDOR \n4 - Editar FORNECEDOR \n5 - Cadastrar FUNCION�RIO \n6 - Editar FUNCION�RIO \n7 - Relat�rio \n8 - Remover Todas as Informa��es \n9 - Buscar ENXOVAL \n0 - SAIR\n";
        cout << "Escolha uma op��o: ";
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
                cout << "Op��o inv�lida! Digite apenas as op��es que est�o acima.\n";
                break;
        }
        system("pause");
    } while (opcao != 0);

    return 0;
}
