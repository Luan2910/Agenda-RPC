Agenda RPC

Alunos: Luan Victor de Almeida
        Diogo Machado Zampar
1.Inicialmente estando dentro da pasta do projeto digite no terminal:

make rpc                // compila o codigo do rpc
make client             // compila o codigo do client
make server             // compila o codigo do server

Tudo que é necessário para o programa será compilado a partir desses 3 comandos.

1.1 Caso queira apagar os arquivos que foram criados para iniciar uma nova execução, digite:

make clean

2.1.Para o server utilize o comando:

./server

A partir de então o servidor  estará online.

2.2.Para o cliente, no caso de ser localhost por exemplo, em outro terminal digite:

./cliente localhost

A partir de então todos os comandos estarão visíveis na tela.

3.Para o cliente terão as 5 opções
    1.Inserir
    2.Consultar
    3.Alterar
    4.Remover
    0.Sair

3.1.Digite o numero correspondente a opção desejada e pressione enter.

3.2 Para o inserir será solicitado os 3 parametros de um usuário da lista
    -Nome
    -Telefone
    -Endereço

Digite um de cada vez pressionando entes assim que estiver digitado todos os caracteres desejados.
Uma mensagem de confirmação de gravação será mostrada no cliente como forma de verificação de retorno.

3.3 Para consultar, será solicitado o nome desejado para busca.
Digite normalmente o nome (podendo ter espaço em branco ou não) e pressione enter.

3.3.1 Caso seja encontrado, todas as informações do contato serão mostradas na tela.
3.3.2 Caso não seja encontrado, uma mensagem de retorno será mostrada na tela.

3.4 Para alterar digite o nome de busca primeiramente, para o contato que você deseja anterar.
Em seguida digite as novas informações do contato.
Caso o contato desejado esteja salvo, um mensagem de usuário alterado com sucesso será mostrada na tela.
Caso o contato desejado não esteja salvo, um mensagem de usuário não encontrado será mostrada na tela.

3.5 Para remover um contato, simplesmente digite o nome do contato que deseja ser removido, e este não estará mais apresentável com o comando consulta.

3.6 Digite 0 para sair do programa.


-Tratamento de Perda de Pacote

Para cada funcionalidade do programa, existe um tratamento que executa novamente as funções do RPC responsáveis pelo envio e recebimento de pacotes caso o retorno das funções do RPC indiquem problema de comunicação de rede entre servidor e cliente.