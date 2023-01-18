<h1 align="center">
:woman_technologist:
      Programa de compressão e descompressão de texto
</h1>

## :computer: HOWTO
  Para rodar o projeto:
  1. Coloque o input que deseja comprimir no arquivo `data/file`.*
  2. Rode o comando `make` na pasta raiz do projeto.
  3. Rode o binario `./labs` na pasta raiz.
  4. Ao rodar o programa se exibirão na tela:
   - Texto descomprimido
   - Tempo da operações de descompressão.
   - Quantidade de bytes totais.
   - Quantidade de bytes comprimidos.
   
*Nota: O programa suporta max 755 caracteres.

## :label: SOBRE O PROJETO

Este projeto foi desenvolvido para a edição 4º do Labs da 42 sp.

O programa deve comprimir e descomprimir textos, retornando informações sobre o processo.

Para desenvolver essa utilidade foi usado o algoritmo de huffman.

## :clipboard: FLUXO E DESENVOLVIMENTO

Como já citado, o algoritmo de huffman é usado aqui para codificar e decodificar o input, veremos aqui visualmente o passo a passo que o programa faz, usando como exemplo o input "hello world":

  1. Criar lista de frecuencia ordenada dos caracteres
 
    O programa processa o input retornardo a quantidade de vezes que uma letra esta presente nele, ordenando ded forma accendente en relação a frecuencia de cada caracter, com o objetivo de agrupar e reducir o que seriam varios chars em diferentes possições a apenas  dois dados, o char e a sua frecuencia:
    
![image](https://user-images.githubusercontent.com/53455663/212553883-a229f526-932b-4668-bed4-84faaec07ea3.png)



  2. Criar a arvora de huffman

    A arvore ded huffman é uma arvore binaria, o que quer dizer que cada nodo podera ter apenas maximo dois filhos, o que permite percorrer a arvore com zeros e uns, zero seria para esquerda e 1 para a direita.
    Nese paso se percorre a lista para poder cria a arvore, enquanto mais aparições determinadao caracter fizer no input mas perto da cabeça da arvore ele estara e enquando menor a frecuencia mais distante estará.
    Nessa imagem podemos ver um output com as folhas da arvore apenas, indicando se está a direita ou esquer e qual a altura da arvore na qual se encontra:
    
![image](https://user-images.githubusercontent.com/53455663/212554391-ea65403e-9603-4ecb-9f2e-e4d09bcc17c2.png)

  3. Percorrer arvore e gerar dicionário

      Ao percorrer a arvore se acha qual é a posição dos chars, o que retornará as cordenadas de zeros e uns para chegar nele apartir da cabeça da arvore.
      A continução as cordenada de cada caracter:
      
![image](https://user-images.githubusercontent.com/53455663/212554843-51855b90-eb09-4eb2-82e2-b4754a809a1f.png)

      Obs. A arvore deve ser percorrida de forma recursiva, para poder percorrer tanto o lado esquerdo quanto o direito e obter a altura das folhas na arvore.
      
   4. Codificar texto com dicionario

      Aqui se percorre cada char do texto original e se concatena os codigos correspondentes do dicionario, criando uma string de zeros e ums que depois será exposta a operações bit wise agrupando de 8 em 8 para representar o 8 bits que formam um byte e finalmente teremos apenas os bytes que reprentam o texto comprimido.
      
       
        |h   | e  |l  |l  |o   |     |w   |o   |r   |l  |d   |
        |--  |--  |-- |-- |--  |---  |--  |--  |--  |-- |--  |
        |110 |111 |01 |01 |001 |0001 |100 |001 |101 |01 |0000 |
        
        
  Resultado da compressão:
    
  | 11011101 | 01001000 | 11000011 | 01010000 |
  |---       |---       |---       |---       |
  |    221   |    72    |    195   |    80    |
  
---- 11 byte foram comprmidos em apenas 4 bytes ----
   
   ![image](https://user-images.githubusercontent.com/53455663/212557027-54022aba-dbb7-4141-a9a1-08b7b19e8e16.png)
   

  
  5. Para desccodificar o caminho é mais simple, apenas precisamos da tabela e os dados comprimidos:
      - Faz operações bitwise inversas que retornar string de zeros e uns
        
        `11011101 | 01001000 | 11000011 | 01010000`
        
      - Compara com a tabela e retorna os chars.
                    
        |110 |111 |01 |01 |001 |0001 |100 |001 |101 |01 |0000 |
        |--  |--  |-- |-- |--  |---  |--  |--  |--  |-- |--  |
        |h   | e  |l  |l  |o   |     |w   |o   |r   |l  |d   |
        
 
   ## :hammer_and_wrench: WORK IN PROGRESS
   
   Idealmente o programa deve usar recursos como gerenciamento de processos, rodando paralelamente os processos de compressão e descompressão e recebendo e entregando dados através de operações de memória compartilhada, alcançando maior desenpenho em geral e uma usabilidade mais interessante.
   
## :gem: CONCLUSÕES
  - Otimizar o uso de recursos de memoria em um programa de compressão é fundamental pois incluso é a basse do conceito.
  - Colaborando chegamos mais longe.
  

      
## :eyes: De uma olhada nas ferramentas usadas para planejar o projeto
 - [Notion(Rascunhos)](https://www.notion.so/Huffman-Algorithm-8880a28c061649729f614456454cc72a)
 - [Github Canvan Board](https://github.com/users/angelasoler/projects/6/views/1)
