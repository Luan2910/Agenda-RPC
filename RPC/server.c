#include <stdio.h>
#include <string.h>
#include "agenda.h"
int * insere_1_svc(operands *argp, struct svc_req *rqstp)
{
   static int result;
   FILE *fp;
   
   if(fp = fopen( "contatos.bin" , "ab" )){
      fwrite(argp->nome, 50, 1, fp);
      fwrite(argp->telefone, 50, 1, fp);
      fwrite(argp->endereco, 50, 1, fp);
      fclose(fp);

      printf ("\nChamado: insere \nUsuario:%s, %s, %s.\n", argp->nome, argp->telefone, argp->endereco);

      result = 1;
   }else{
      printf("Erro ao abrir arquivo binário.\n");
      result = 0;
   }
   return (&result);
}

char **consulta_1_svc(operands *argp, struct svc_req *rqstp)
{
   static char* result;
   result = malloc(sizeof(char)*200);
   int i = 0;
   FILE *fp;
   if(fp = fopen( "contatos.bin" , "rb" )){
      printf ("\nChamado: consulta \nNome: %s.\n",argp->nome);
      
      char nome[50],telefone[50],endereco[50];
      fseek(fp,0,SEEK_SET);
      while(1){
         if(feof(fp))break;
         fread(nome, 50, 1, fp);
         fread(telefone, 50, 1, fp);
         fread(endereco, 50, 1, fp);
         if(feof(fp))break;
         if(strcmp(nome,argp->nome)==0){
            printf("\nRegistro encontrado:\nNome:%s \nTelefone:%s \nEndereco:%s\n", nome, telefone, endereco);
            sprintf(result,"\nRegistro encontrado:\nNome:%s \nTelefone:%s \nEndereco:%s\n", nome, telefone, endereco);
            fclose(fp);
            return (&result);
         }
      }

      printf("Usuario nao encontrado!\n");
      fclose(fp);
      
   }else{
      printf("Erro ao abrir arquivo binário ou agenda ainda não existe.\n");
   }
   sprintf(result,"\nNenhum usuario encontrado! \n");
   return (&result);
} 


int * altera_1_svc (operands *argp, struct svc_req *rqstp)
{
   static int result;
   int i = 0;
   FILE *fp;
   if(fp = fopen( "contatos.bin" , "rb+" )){
      printf ("\nChamado: altera \nNome: %s.\n",argp->aux);
      
      char nome[50],telefone[50],endereco[50];
      fseek(fp,0,SEEK_SET);
      while(1){
         if(feof(fp))break;
         fread(nome, 50, 1, fp);
         fread(telefone, 50, 1, fp);
         fread(endereco, 50, 1, fp);
         
         if(strcmp(nome,argp->aux)==0){
            printf("\nRegistro encontrado!\n");
            fseek(fp, (-1)*sizeof(char)*150, SEEK_CUR);
            fwrite(argp->nome, 50, 1, fp);
            fwrite(argp->telefone, 50, 1, fp);
            fwrite(argp->endereco, 50, 1, fp);
            fclose(fp);
            result = 1;
            printf("\nUsuario alteradocom sucesso.\n");
            return(&result); 
         }
         if(feof(fp))break;
      }

      printf("Usuario nao encontrado!\n");
      fclose(fp);
      result = 2;
      
   }else{
      printf("Erro ao abrir arquivo binário ou agenda ainda não existe.\n");

   }
   return (&result);
} 




int * remover_1_svc (operands *argp, struct svc_req *rqstp)
{
   static int result;
   int i = 0;
   FILE *fp;
   if(fp = fopen( "contatos.bin" , "rb+" )){
      printf ("\nChamado: remover \nNome: %s.\n",argp->nome);
      
      char nome[50],telefone[50],endereco[50];
      fseek(fp,0,SEEK_SET);
      while(1){
         if(feof(fp))break;
         fread(nome, 50, 1, fp);
         fread(telefone, 50, 1, fp);
         fread(endereco, 50, 1, fp);
         
         if(strcmp(nome,argp->nome)==0){
            printf("\nRegistro encontrado!\n");
            fseek(fp, (-1)*sizeof(char)*150, SEEK_CUR);
            fwrite("\0", 1, 1, fp);
            fclose(fp);
            result = 1;
            return(&result); 
         }
         if(feof(fp))break;
      }

      printf("Usuario nao encontrado!\n");
      fclose(fp);
      result = 2;
      
   }else{
      printf("Erro ao abrir arquivo binário ou agenda ainda não existe.\n");
   }
   return (&result);
} 

