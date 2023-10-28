#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNÇÕES
char* solicitarDadosUsuario();
int logarUsuario(FILE* arq, char valores[]);
void cadastrarUsuario(FILE* arq, char valores[]);
void gerenciarCliente();
void gerenciarAnimais();
void gerenciarAdocao();
void visualizarAnimaisDisponiveis();

#define TAMUSUARIO 5
#define TAMSENHA 5

//FUNÇÃO PRINCIPAL
int main(){

    //VARIÁVEIS
    FILE *arqUsuario, *arqPessoa, *arqDoacao, *arqDepoimento;
    char usuario[5];

    struct Pessoa
    {
        char nome[50];
    };
    
    

    printf("\nBem-vindo(a) ao Patrulha Canina!!!\n");
    
    int opcao;
    // REALIZA O LOGIN
    do
    {
        printf("\nMENU:\n");
        printf("1 - CADASTRAR USUÁRIO\n");
        printf("2 - LOGAR NO SISTEMA\n");
        printf("3 - SAIR\n");
        printf("O que deseja fazer? ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("Para cadastrar um novo usuário é necessário estar logado no sistema. Tente novamente!\n");
                break;

            case 2:
                {
                    arqUsuario = fopen("arquivos/usuarios.txt", "r"); // abre o arquivo
                    if (arqUsuario == NULL)
                    {
                        printf("Erro interno. Tente novamente!\n");
                        opcao = 3;
                        break;
                    }
                    
                    char* dados = (char*) malloc(sizeof(char));
                    dados = solicitarDadosUsuario();
                    int retorno = logarUsuario(arqUsuario, dados);
                    
                    if(retorno == 0)
                        printf("\nUsuário não cadastrado. Tente novamente!\n");
                    else if(retorno == 1)
                    {
                        for (int i=0; i < strlen(dados); i++)
                        {   
                            if (dados[i] == ',')
                                break;

                            usuario[i] = dados[i];
                        }

                        printf("\nUsuário %s logado!\n", usuario);
                        free(dados);   
                    }

                    fclose(arqUsuario);
                    fflush(arqUsuario);
                }
                break;

            case 3:
                break;

            default:
                printf("Opção inválida. Tente novamente!\n");
                break;

        }
    }while(opcao != 3);

    if(opcao = 3)
        return 0;

    // MENU SECUNDÁRIO
    do
    {
        printf("\nMENU:\n");
        printf("1 - GERENCIAR CLIENTE\n");
        printf("2 - GERENCIAR ANIMAIS\n");
        printf("3 - GERENCIAR ADOÇÃO\n");
        printf("4 - VISUALIZAR ANIMAIS DISPONÍVEIS\n");
        printf("5 - SAIR\n");
        printf("O que deseja fazer? ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            default:
                printf("Opção inválida. Tente novamente!\n");
                break;

        }
    }while(opcao != 5);

    
    return 0;
}

//FUNCÕES SECUNDÁRIAS

char* solicitarDadosUsuario()
{
    int tamLinha = TAMUSUARIO + 1 + TAMSENHA + 1; // calcula o tamanho máximo da linha
    char entrada[tamLinha];
    char *linha = (char*) malloc(tamLinha * sizeof(char));

    printf("\nDigite o seu usuário (%d caracteres): ", TAMUSUARIO);
    scanf("%s", entrada);
    while(strlen(entrada) > TAMUSUARIO)
        printf("\nTamanho inválido. Digite o seu usuário (%d caracteres) novamente: ", TAMUSUARIO);

    strcat(linha, entrada);
    strcat(linha, ",");

    printf("Digite a sua senha (%d caracteres): ", TAMSENHA);
    scanf("%s", entrada);
    while(strlen(entrada) > TAMSENHA)
        printf("\nTamanho inválido. Digite a sua senha (%d caracteres) novamente: ", TAMUSUARIO);

    strcat(linha, entrada);
    return linha;
}


int logarUsuario(FILE* arq, char valores[])
{
    rewind(arq); // posiciona o ponteiro no começo do arquivo
    char leitura[19];

    while (!feof(arq)) // indica o fim do arquivo
    {
        //lê uma linha (inclusive com o '\n')
        fgets(leitura, 19, arq);
        
        //remove o '\n' do final da string que acabou de ler
        for (int i=0; i<strlen(leitura); i++)
        {
            if(leitura[i] == '\n')
                leitura[i] = '\0';
        }

        if(strcmp(leitura, valores) == 0) // compara se as strings são iguais
            return 1;
    }

    return 0; // indica que não existe esse perfil cadastrado 
}

void cadastrarUsuario(FILE* arq, char valores[])
{
    fprintf(arq, "%s\n", valores);
}