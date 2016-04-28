# Consulta RPC em desenvolvido na linguagem C
Implementação de um serviço de consultas em um Log distribuído. No algoritmo implementado, o comando executado é o grep, mas o mesmo pode ser alterado.

## Projeto criado por:
  * Carlos Augusto Guerra Carneiro - carlosgcarneyro@gmail.com
  
  * Diego Dinarte - diegodxpr@gmail.com
  
  
  
## Como executar o programa:

Para executar o programa, é necessário fazer as seguintes configurações:

1. Dentro da pasta server, existe um arquivo chamado 'rpclog' (é um arquivo contendo erros que serão procurados pelo cliente), este arquivo deve ser salvo nas máquinas, na mesma pasta que o executável do servidor com o seguinte nome <nomedamaquina>rpclog.

2. Dentro da pasta client, existe o arquivo ips, adicione os ips das maquinas que deseja consultar seus respectivos logs, um ip em cada linha.

3. Execute o server, para isto acesse a pasta server e insira o seguinte comando no terminal do linux:
	./msg_server

4. Execute o client, para isto acesse a pasta client e insira o seguinte comando no terminal do linux:
	grep <opção do grep> <palavra a ser procurada no log> rpclog

5. Para verificar os dados recebidos, acesse o arquivo greplist presente dentro da pasta client.
