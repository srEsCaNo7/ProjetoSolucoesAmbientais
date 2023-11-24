#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de criptografia simples para a senha
void encryptPassword(char *password) {
    for (int i = 0; password[i] != '\0'; ++i) {
        password[i] = password[i] + 3; // Shift de 3 posições na tabela ASCII
    }
}

// Estrutura para armazenar os dados da indústria
struct Industry {
    char username[50];
    char password[50];
    char responsibleName[50];
    char companyName[50];
    char cnpj[15];
    char socialReason[50];
    char fantasyName[50];
    char phone[15];
    char addressStreet[50];
    int addressNumber;
    char addressNeighborhood[50];
    char addressCity[50];
    char addressState[3];
    char addressZipCode[10];
    char email[50];
    char openingDate[11];
    float wasteQuantity;
    float estimatedCost;
};

// Função para realizar o login
int login(struct Industry *industry) {
    char inputUsername[50];
    char inputPassword[50];

    printf("Informe o usuário: ");
    scanf("%s", inputUsername);

    printf("Informe a senha: ");
    scanf("%s", inputPassword);
    encryptPassword(inputPassword);

    if (strcmp(inputUsername, industry->username) == 0 &&
        strcmp(inputPassword, industry->password) == 0) {
        return 1; // Login bem-sucedido
    } else {
        return 0; // Login falhou
    }
}

// Função para cadastrar os dados da indústria
void registerData(struct Industry *industry) {
    printf("\nInforme os dados da indústria:\n");

    printf("Nome do Responsável: ");
    scanf("%s", industry->responsibleName);

    printf("Nome da Empresa: ");
    scanf("%s", industry->companyName);

    printf("CNPJ: ");
    scanf("%s", industry->cnpj);

    printf("Razão Social: ");
    scanf("%s", industry->socialReason);

    printf("Nome Fantasia: ");
    scanf("%s", industry->fantasyName);

    printf("Telefone: ");
    scanf("%s", industry->phone);

    printf("Endereço (Rua): ");
    scanf("%s", industry->addressStreet);

    printf("Número: ");
    scanf("%d", &industry->addressNumber);

    printf("Bairro: ");
    scanf("%s", industry->addressNeighborhood);

    printf("Cidade: ");
    scanf("%s", industry->addressCity);

    printf("Estado (Sigla): ");
    scanf("%s", industry->addressState);

    printf("CEP: ");
    scanf("%s", industry->addressZipCode);

    printf("E-mail: ");
    scanf("%s", industry->email);

    printf("Data de Abertura: ");
    scanf("%s", industry->openingDate);

    industry->wasteQuantity = 0.0;
    industry->estimatedCost = 0.0;
}

// Função principal
int main() {
    struct Industry industry;
    int choice;

    // Configuração de dados de exemplo
    strcpy(industry.username, "usuario");
    strcpy(industry.password, "senha");
    encryptPassword(industry.password);

    do {
        printf("\nEscolha a opção:\n");
        printf("1 - Login\n");
        printf("2 - Cadastrar Dados da Indústria\n");
        printf("3 - Atualizar Quantidades de Resíduos e Valor Estimado\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (login(&industry)) {
                    printf("\nLogin bem-sucedido!\n");
                } else {
                    printf("\nLogin falhou. Verifique usuário e senha.\n");
                }
                break;
            case 2:
                registerData(&industry);
                break;
            case 3:
                // Lógica para atualizar quantidades de resíduos e valor estimado
                break;
            case 0:
                printf("Saindo do sistema.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (choice != 0);

    return 0;
}
