/*
 * Autor: Lucas Rafael Barbosa Lopes
 * Endereço eletronico: lucas7844@gmail.com
 * Descrição: Urna de votação(obs: a urna não é segura para ser usada em votação real);
 */
#include <stdio.h>
#include <stdlib.h>
#include "/home/lucas/Documents/c/bib.h"

// declarar funções
    int login();
	int central();
	int telaconfele();
	int telaconfcand();
	int conf();
	int votacao();
	int addele();
	int listele();
	int excluirele();
	int addcand();
	int lestcand();
	int bloqcand();
	int excluircands();
	
int main(){
        login();

        return 0;
}
int login(){
	FILE *arq = fopen("/home/lucas/Desktop/c.v", "r");
	char id[16], senha[16], idu[16], senhau[16];

		if (arq == NULL){
		conf();
		}else if (fscanf(arq, "%s[^\n]s", id) != EOF && fscanf(arq, "%s", senha) != EOF){

		do{
			printf("\e[H\e[2J");
			printf("  Bem-vindo a Urna eletroica.\n");
			printf("  Faca login.\n");
			printf("  ID:");
			scanf("%s", idu);
			printf("  Senha:");
			scanf("%s", senhau);
			printf("  %s     %s    %s", id, senha, senhau);
		}while(compararstr(id, idu) != 1 || compararstr(senha, senhau) != 1); // a função comparstr foi feita por mim é na minha biblioteca
			printf("\e[H\e[2J");
                        printf("  Longin com sucesso!!!   precione qualquer tecla para continuar.");
                        getchar();
                        central();
        }else conf();

			return 0;
   }
int central(){
	       int num;

                do{
                        printf("\e[H\e[2J");
                        printf("  Bem-vindo a central.\n");
                        printf("  1- comecar votacao.\n");
                        printf("  2- configurar eleitores.\n");
                        printf("  3- configurar candidatos.\n");
                        printf("  ");
                        scanf("%d", &num);
                }while(num < 1 || num > 3);

        switch(num){
                case 1:
                        votacao();
                        break;
                case 2:
                        telaconfele();
                        break;
                case 3:
                        telaconfcand();
                        break;
                }
     return 0;
}
int votacao(){
                int op;

                 do{
                        printf("\e[H\e[2J");
                        printf("  Infelismente esta parte do programa nao esta pronta!!!");
                        printf("  1- voltar a central.");
                        printf("  2- sair.\n     ");
                        scanf("%d", &op);
                }while(op < 1 || op > 2);

                if(op == 1){
                        central();
                }
        return 0;
}
int telaconfele(){
                int op;

                do{
                        printf("\e[H\e[2J");
                        printf("  Bem-vindo a configurar eleitores.\n");
                        printf("  1- add novos eleitores.\n");
                        printf("  2- listar elitores.\n");
                        printf("  3- excluir todos os eleitores.\n");
                        printf("  ");
                        scanf("%d", &op);
                }while (op < 1 || op > 3);

          switch(op){
                 case 1:
                         addele();
                         break;
                 case 2:
                        listele();
                 case 3:
                        excluirele();
                 break;
         }
         return 0;
}
int telaconfcand(){
                int op;

                do{
                        printf("\e[H\e[2J");
                        printf("  Bem-vindo de candidatos.\n");
                        printf("  1- add novos candidatos.\n");
                        printf("  2- listar candidato.\n");
                        printf("  3- bloquear candidato.\n");
                        printf("  4- excluir todos os candidatos\n");
                        printf("  ");
                        scanf("%d", &op);
                }while (op < 1 || op > 4);

                switch(op){
                        case 1:
                                addcand();
                                break;
                        case 2:
                                lestcand();
                                break;
                        case 3:
                                bloqcand();
                                break;
                        case 4:
                                excluircands();
                                break;
                        }
                return 0;
}
int conf(){
        FILE *confvt = fopen("/home/.conf.vt", "w");
                char id[16], senha[16];

                        printf("\e[H\e[2J");
                        printf("  Bem-vindo ao sistema de cadastro.\n\n");
                        printf("  novo id: ");
                        scanf("%[^\n]s", id);
                        printf("  nova senha: ");
                        scanf("%s[^\n]", senha);

                                fprintf(confvt, "%s\n", id);
                                fprintf(confvt, "%s\n", senha);

                                fclose(confvt);
                                central();
     return 0;
}
int addele(){
		FILE *eleitores = fopen("/home/ele.vt", "a");
		int idade, num;
		char nome[10], sobrenome[10], cod[4], estadocivil[20];

		do{
			printf("\e[H\e[2J");
			printf("  Bem-vindos a pagina de add eleitores.\n");
			printf("  Nome: ");
			scanf("%s", nome);
                        printf("  Sobre nome: ");
                        scanf("%s", sobrenome);
			printf("  Estado civil: ");
			scanf("%s", estadocivil);
			printf("  Codigo de 3 digitos: ");
			scanf("%s", cod);
			printf("  Idade: ");
			scanf("%d", &idade);
			printf("\n  1 para add mais e 2 para voltar.");
			scanf("%d", &num);
			fprintf(eleitores, "%s\n", nome);
                        fprintf(eleitores, "%s\n", sobrenome);
			fprintf(eleitores, "%s\n", estadocivil);
			fprintf(eleitores, "%s\n", cod);
			fprintf(eleitores, "%d\n", idade);
		}while(num == 1);

			//fechar *aquivo e chamar a novamente e voltar a tela anterior
			fclose(eleitores);
			telaconfele();
		return 0;
}
int listele(){
        FILE *eleitores = fopen("/home/ele.vt", "r");
                char nome[10], sobrenome[10], cod[4], estadocivil[20];
                int idade, contador = 1;
                        if (eleitores != NULL){
                                //limpar tela.
                                printf("  Lista de eleitores.\n");
                                while(fscanf(eleitores,"%[^\n]s", nome) != EOF && fscanf(eleitores,"%[^\n]s", sobrenome) != EOF &&
                                        fscanf(eleitores,"%[^\n]s", cod) != EOF && fscanf(eleitores,"%[^\n]s", estadocivil) != EOF &&
                                        fscanf(eleitores,"%d", &idade) != EOF){

                                        printf("\n  Eleitor numero %d\n", contador);
                                        printf("  Nome: %s\n", nome);
                                        printf("  Sobrenome: %s\n", sobrenome);
                                        printf("  Estadocivil:%s\n", estadocivil);
                                        printf("  Idade: %d", idade);
                                        contador+=1;
                                }

                                printf("\n\n  Totalizado %d eleitores.\n", contador-1);
                        }else{
                                        //limpar tela.
                                        printf(" Nao possui eleitores.\n");
                        }

    return 0;
}
int excluirele(){
                // o dever desta função é exluir todos os eleitores.
                   remove("/home/ele.vt");
                int op;

                     do{
                        //limpar tela
                        printf("  Todos os eleitores foram excluidos.\n");
                        printf("  o que deseja fazer agora\n\n");
                        printf("  1- voltar a central.\n");
                        printf("  2- Voltar a configurar eleitores.\n");
                        printf("  3- sair do programa.\n");
                        printf("     ");
                        scanf("%d", &op);
                       }while(op < 1 || op > 3);

                switch(op){
                        case 1:
                                central();
                                break;
                        case 2:
                                telaconfele();
                                break;
                        case 3:
                                return 0;
                                break;
                }
    return 0;
}
int addcand(){
		FILE *candidatos = fopen("/home/can.vt", "a");
                int numero, idade, cargo, partido;
                char nome[10], sobrenome[10], c;
                
                if (candidatos != NULL){
                		do{
                        //limpar tela
                        printf("  Bem-vindo\n");
                        printf("  Para adicionar candidato prencha os campos abaixo.\n\n");
                        printf("  Primeiro Nome: ");
                        scanf("%s", nome);
                        printf("  Sobrenome: ");
                        scanf("%s", sobrenome);
                        printf("  Idade: ");
                        scanf("%d", &idade);
                        printf("  Numero do Partido: ");
                        scanf("%d", &partido);
                        printf("  Numero do candidato: ");
                        scanf("%d", &numero);
                        printf("\n  Cargo politico.\n");
                        printf("  1) Prefeito.\n");
                        printf("  2) Vereador.\n");
                        printf("     ");
                        scanf("%d", &cargo);

                        fprintf(candidatos, "%s\n", nome);
                        fprintf(candidatos, "%s\n", sobrenome);
                        fprintf(candidatos, "%d\n", idade);
                        fprintf(candidatos, "%d\n", partido);
                        fprintf(candidatos, "%d\n", numero);
                        fprintf(candidatos, "%d\n", cargo);

                        printf("\n  Continuar add candidatos ((s/n)): ");
                        scanf("%c", &c);

                    }while(c == 's' || c == 'S');

                    fclose(candidatos);
                    telaconfcand();

			return 0;
}
int lestcand(){
		FILE *candidatos = fopen("/home/can.vt", "r");
                int numero, idade, cargo, partido, contador = 1;
                char nome[10], sobrenome[10];
////****//// continuar daqui
            if (candidatos != NULL){
                		// limpar tela
              			printf("  Lista de candidatos.\n");
                	while (fscanf(candidatos, "%s", nome) != EOF && fscanf(candidatos, "%s", sobrenome) != EOF &&
                        fscanf(candidatos, "%d", &idade) != EOF &&  fscanf(candidatos, "%d", &partido) != EOF &&
                        fscanf(candidatos, "%d", &numero)!= EOF &&  fscanf(candidatos, "%d", &cargo) != EOF){

                     	printf("\n  Candidato numero: %d\n", contador);
                     	printf("  Nome: %s\n", nome);
                        printf("  Sobrenome: %s\n", sobrenome);
                        printf("  Idade: %d\n", idade);
                        printf("  Numero do Partido: %d\n", partido);
                        printf("  Numero do candidato: %d\n", numero);
                        if(cargo == 1){
                        	printf("  Cargo: Prefeito\n");
                        }else printf("  Cargo: Vereador\n");
							contador+=1;
                	}
                		printf("\n  Totalizado %d Candidatos\n", contador-1);
              	}

             		printf("\n  Digite um numero para cntinuar e tecle enter: ");
             		scanf(" %d", &numero);

                    fclose(candidatos);
                    telaconfcand();

			return 0;
}
int bloqcand(){
                int op;

                 do{
                        printf("\e[H\e[2J");
                        printf("  Esta parte do programa nao esta pronta!!!");
                        printf("  1- voltar a central.");
                        printf("  2- sair.\n     ");
                        scanf("%d", &op);
                }while(op < 1 || op > 2);

                if(op == 1){
                        central();
                }
    return 0;
}
int excluircands(){
	// o dever desta função é exluir todos os candidatos
                   remove("/home/.candidatos.vt");
                   
                int op;

                     do{
                        //limpar tela
                        printf("  Todos os candidatos foram excluidos.\n");
                        printf("  o que deseja fazer agora\n\n");
                        printf("  1- voltar a central.\n");
                        printf("  2- Voltar a configurar candidatos.\n");
                        printf("  3- sair do programa.\n");
                        printf("     ");
                        scanf("%d", &op);
                       }while(op < 1 || op > 3);
				 
                 if(op == 1){
					 central();
					 }else {
						 telaconfcand();
					 }
					 
}
	
