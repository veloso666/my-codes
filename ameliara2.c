#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *cliente;
typedef struct {
char nome[10];
char sobrenome[10];
char sexo[10];
int cpf[12];
char idade[10];
char pacote[10];
char pontos[10]; 
 } dados_cliente;

dados_cliente dadoscliente[50];
int op, i= 0;

void cadastro();
void lista();
void remover();
void mostre();
int main (){
    
  do{
    

     printf("\n");
        printf ("\t\t\t\t       EMPRESA DE TV     \t\t\t\t\n");
        printf ("\t\t\t===================================\n");
        printf("\t\t\t|\t 1 - Cadastrar Cliente           |\n");
        printf("\t\t\t|\t 2 - Listagem geral              |\n");
        printf("\t\t\t|\t 3 - Relatorio estatistico       |\n");
        printf("\t\t\t|\t 4 - Editar cliente              |\n");
        printf("\t\t\t|\t 5 - Remover cliente             |\n");
        printf("\t\t\t|\t 6 - Listar Clientes Por Pacotes |\n");
        printf("\t\t\t|\t 0 - sair                        |\n");
        printf ("\t\t\t===================================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        scanf("%i", &op);
        switch (op){
        case 1:
           cadastro();
            break;
        case 2:
           lista();
            break;
        case 3:
           
            break;
        case 4:
           
            break;
        case 5:
           remover();
            break;
        case 6:
           
            break;
         case 0:
         system("exit");
            break;
       
        default:
        printf("Opção invalida");
            break;
        }
 } while (op != 6);
 
}
void cadastro(){
cliente = fopen("cliente.dat", "a+b");
if(cliente == NULL)
printf("Erro, nao foi possivel abrir o arquivo\n");
else{
 do{    
        printf("\nDigite o seu primeiro nome: ");
            scanf("%s",&dadoscliente[i].nome);
        printf("\nDigite o seu sobrenome: ");
            scanf("%s",&dadoscliente[i].sobrenome);
         printf("\nDigite o seu cpf: ");
            scanf("%i", &dadoscliente[i].cpf);
         printf("\nDigite o seu sexo[1= feminino][2 = masculino]: ");
            scanf("%s", &dadoscliente[i].sexo);
         printf("\nDigite a sua idade: ");
            scanf("%s", &dadoscliente[i].idade);
         printf("\nDigite qual pacote voce escolheu(1-Premium/2-Ouro/3-Standard): ");
            scanf("%s", &dadoscliente[i].pacote);
         printf("\nDigite a quantidade de pontos que voce ira querer na sua casa: ");
            scanf("%s", &dadoscliente[i].pontos);
         printf("\nDigite 1 para continuar ou outro valor para sair: ");
           scanf("%i", &op);
        fseek(cliente,0,SEEK_SET); 
        fwrite(&dadoscliente, sizeof(dados_cliente),1, cliente);
    }while(op == 1);
       fclose(cliente);

    }
}
    void lista(){
    cliente= fopen("cliente.dat","r+b");
    if(!feof(cliente)){
       while(cliente){
            printf("\n");
            printf("|Nome:%s %s|CPF: %i|Sexo: %s|Idade: %s|Pacote:%s|Pontos:%s|", dadoscliente[i].nome, dadoscliente[i].sobrenome, dadoscliente[i].cpf, dadoscliente[i].sexo, dadoscliente[i].idade,dadoscliente[i].pacote,dadoscliente[i].pontos);
            fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
        
       
        fclose(cliente);

    } 
    else{
        printf("Erro ao abrir arquivo!!");
    }

    }
int procura(int matp){
    int p=0;
    rewind(cliente);
    fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
    while(feof(cliente)==0){
      if(dados_cliente.cpf == matp){
      return p;
      }else{
        fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
        p++;
      }
    }
    return -1;
}
void mostre(int pos){
 fseek(cliente,pos*sizeof(dados_cliente),SEEK_SET);
 printf("|Nome:%s %s|CPF: %i|Sexo: %s|Idade: %s|Pacote:%s|Pontos:%s|", dadoscliente[i].nome, dadoscliente[i].sobrenome, dadoscliente[i].cpf, dadoscliente[i].sexo, dadoscliente[i].idade,dadoscliente[i].pacote,dadoscliente[i].pontos);
 fread(&dadoscliente,sizeof(dados_cliente),1,cliente);
}
 
void remover(){
int matrem,conf,resp,posicao;
dados_cliente.cpf = 0;

 do{
    printf("\nRemover cliente");
    printf("\nCPF: ");
    scanf("&d", &matrem);
    posicao = procura(matrem);
    if(posicao == -1){
    printf("\nCliente não encontrado!");
    } else{(mostre(posicao));
    printf("\nDeseja remover o cliente(1-sim/0-não)?");
    scanf("%d", &conf);
    if(conf == 1){
         fseek(cliente,posicao*sizeof(dados_cliente),SEEK_SET);
         fwrite(&dadoscliente, sizeof(dados_cliente),1, cliente);
         printf("\nCliente removido com sucesso! ");
    }
    else{
        printf("\nRemoção cancelada!");
    }
    printf("\nDeseja remover outro cliente(1-sim/0-não)?");
    scanf("%d", &resp);
    }
}while(resp ==1);
}

