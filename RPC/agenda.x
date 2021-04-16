/*#define PROGRAM_NUMBER 12345678
#define VERSION_NUMBER 1*/

#define PROGRAM_NUMBER 1111111
#define VERSION_NUMBER 1

struct operands
{
        string nome<50>;
        string telefone<50>;
        string endereco<50>;
        string aux<50>;
};

program AGENDA_PROG
{
   version AGENDA_VERSION
   {
     int INSERE (operands) = 1;
     string CONSULTA (operands) = 2;
     int ALTERA (operands) = 3;
     int REMOVER (operands) = 4;
   }
   = VERSION_NUMBER;
}
= PROGRAM_NUMBER;

 
