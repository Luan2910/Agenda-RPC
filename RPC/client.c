/* Cliente RPC simples */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

int insere(CLIENT *clnt, char* nome, char* telefone, char* endereco)
{
   operands ops;
   int *result;

   ops.nome = nome;
   ops.telefone = telefone;
   ops.endereco = endereco;
   int count=0;
   
   do{
     result = insere_1(&ops,clnt);
     if(count>0) printf ("Problemas ao chamar a funcao remota, reenviando pacotes.\n");
     count++;
     if(count>10) exit (1);
   }while(result == 0 || result == NULL);
   
   printf("Usuário inserido com sucesso!\n");

   return (*result);
}

char* consulta(CLIENT *clnt, char* nome)
{
   operands ops;
   char **result;
   ops.nome = nome;
   
   int count=0;
   do{
      result = consulta_1(&ops,clnt);
      if(count > 0) printf("\nProblemas ao chamar a funcao remota, reenviando pacotes.\n");
      count++;
      if(count > 10) exit(1);
   }while((result == 0 || result == NULL));
   printf("\n%s",*result);
   return (*result);
}


int altera(CLIENT *clnt, char *nomeAnterior,char* nome, char* telefone, char* endereco)
{
   operands ops;
   int *result;
   ops.nome = nome;
   ops.telefone = telefone;
   ops.endereco = endereco;
   ops.aux = nomeAnterior;
   int count=0;

   do{
      result = altera_1(&ops,clnt);
      if(count>0) printf("\nProblemas ao chamar a funcao remota, reenviando pacotes.\n");
      count++;
      if(count>10) exit(1);
   }while(result == 0 || result == NULL);
   
   if(*result == 1){ 
      printf("\nUsuario alterado com sucesso.\n");
   }else{
      printf("\nUsuario nao encontrado.\n");
   }

   return (*result);
}

int remover(CLIENT *clnt, char* nome)
{
   operands ops;
   int *result;
   ops.nome = nome;
   int count=0;

   do{
      result = remover_1(&ops,clnt);
      if(count>0) printf ("Problemas ao chamar a fun��o remota\n");
      count++;
      if(count>10) exit (1);
   }while(result == NULL);
   
   if(*result == 1){ 
      printf("\nUsuario removido com sucesso.\n");
   }else{
      printf("\nUsuario nao encontrado.\n");
   }
   return (*result);

}



int main( int argc, char *argv[])
{
   CLIENT *clnt;
   char comando[50], nome[50], nomeAnterior[50], endereco[50], telefone[50];
   int escolha;
   if (argc>2)
   {
      fprintf (stderr,"Usage: %s hostname command\n",argv[0]);
      exit (1);
   }

   clnt = clnt_create (argv[1], AGENDA_PROG, AGENDA_VERSION, "udp");

   if (clnt == (CLIENT *) NULL)
   {
      clnt_pcreateerror (argv[1]);
      exit(1);
   }
   
   while(1){
      printf("\n\n\tMENU PRINCIPAL\n\tEscolha uma opção:\n");
      printf("\t[1] inserir contato\n");
      printf("\t[2] consultar contato\n");
      printf("\t[3] alterar um contato\n");
      printf("\t[4] remover um contato\n");
      printf("\t[0] sair do programa\n");
      scanf("%d",&escolha);
      switch(escolha){
         case 1:
            printf("\nInsira o nome:");
            scanf(" %[^\n]s", nome);
            fflush(stdin);
            printf("\nInsira o telefone:");
            scanf(" %s", telefone);
            printf("\nInsira o endereco:");
            scanf(" %[^\n]s", endereco);
            printf ("%d\n", insere(clnt, nome, telefone, endereco));
            break;

         case 2:
      
            printf("\nInsira o nome do contato para busca:");
            scanf(" %[^\n]s", nome);
            consulta(clnt, nome);
            break;
         
         case 3:
            printf("\nInsira o nome do contato a ser alterado:");
            scanf(" %[^\n]s", nomeAnterior);
            printf("\nInsira o novo nome do contato:");
            scanf(" %[^\n]s", nome);
            printf("\nInsira o novo telefone do contato:");
            scanf("%s", telefone);
            printf("\nInsira o novo endereco do contato:");
            scanf(" %[^\n]s", endereco);
            altera(clnt, nomeAnterior, nome, telefone, endereco);
            break;
            
         case 4:
            printf("\nInsira o nome do contato a ser removido:");
            scanf(" %[^\n]s", nome);
            remover(clnt, nome);
            break;
         case 0:
            exit(1);
      }
   }
   
   return (0);
} 
