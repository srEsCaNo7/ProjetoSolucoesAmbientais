#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de criptografia simples para a senha
void criptografarSenha(char *senha) {
    for (int i = 0; senha[i] != '\0'; ++i) {
        senha[i] = senha[i] + 3; 
    }
}

// Estrutura para armazenar os dados da indústria
struct Industria {
    char usuario[50];
    char senha[50];
    char nomeDoResponsavel[50];
    char nomeDaEmpresa[50];
    char cnpj[15];
    char razaoSocial[50];
    char telefone[15];
    char rua[50];
    int numero;
    char bairro[50];
    char cidade[50];
    char estado[3];
    char cep[10];
    char email[50];
    char dataDeAbertura[11];
    float quantResiduos;
    float custoEstimado;
};

// Função para realizar o login
int login(struct Industria *industria) {
    char inserirUsuario[50];
    char inserirSenha[50];

    printf("Informe o usuario: ");
    scanf("%s", inserirUsuario);

    printf("Informe a senha: ");
    scanf("%s", inserirSenha);
    criptografarSenha(inserirSenha);

    if (strcmp(inserirUsuario, industria->usuario) == 0 &&
        strcmp(inserirSenha, industria->senha) == 0) {
        return 1; // Login bem-sucedido
    } else {
        return 0; // Login falhou
    }
}

// Função para cadastrar os dados da indústria
void registrarDados(struct Industria *industria) {
    printf("\nInforme os dados da industria:\n");

    printf("Nome do Responsavel: ");
    scanf("%s", industria->nomeDoResponsavel);

    printf("Nome da Empresa: ");
    scanf("%s", industria->nomeDaEmpresa);

    printf("CNPJ: ");
    scanf("%s", industria->cnpj);
    
    printf("Razao Social: ");
    scanf("%s", industria->razaoSocial);

    printf("Telefone: ");
    scanf("%s", industria->telefone);

    printf("Endereço (Rua): ");
    scanf("%s", industria->rua);

    printf("Número: ");
    scanf("%d", &industria->numero);

    printf("Bairro: ");
    scanf("%s", industria->bairro);

    printf("Cidade: ");
    scanf("%s", industria->cidade);

    printf("Estado (Sigla): ");
    scanf("%s", industria->estado);

    printf("CEP: ");
    scanf("%s", industria->cep);

    printf("E-mail: ");
    scanf("%s", industria->email);

    printf("Data de Abertura: ");
    scanf("%s", industria->dataDeAbertura);

    industria->quantResiduos = 0.0;
    industria->custoEstimado = 0.0;
}

int main() {
    struct Industria industria;
    int escolha;

    // Configuração de dados de exemplo
    strcpy(industria.usuario, "usuario");
    strcpy(industria.senha, "senha");
    criptografarSenha(industria.senha);

    do {
        printf("\nEscolha a opçao:\n");
        printf("1 - Login\n");
        printf("2 - Cadastrar Dados da Industria\n");
        printf("3 - Atualizar Quantidades de Resíduos e Valor Estimado\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (login(&industria)) {
                    printf("\nLogin bem-sucedido!\n");
                } else {
                    printf("\nLogin falhou. Verifique usuário e senha.\n");
                }
                break;
            case 2:
                registrarDados(&industria);
                break;
            case 3:
                // Lógica para atualizar quantidades de resíduos e valor estimado
                break;
            case 0:
                printf("Saindo do sistema.\n");
                break;
            default:
                printf("Opçao invalida. Tente novamente.\n");
        }

    } while (escolha != 0);

    return 0;
}
