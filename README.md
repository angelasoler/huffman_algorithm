<h1 align="center">
:woman_technologist:
      Programa de compressão e descompressão de string
</h1>

## :computer: HOWTO
  Para rodar o projeto:
  1. Coloque o input que deseja comprimir no arquivo `data/file`.*
  2. Rode o comando `make` na pasta raiz do projeto.
  3. Rode o binario `./labs` na pasta raiz.
  4. Ao rodar o programa se exibiram na tela:
   - Texto descomprimido
   - Tempo da operações de dedscompressão.
   - Quantidade de bytes totais.
   - Quantidade de bytes comprimidos.
   
*Nota: O programa suporta max 755 caracteres.

## :hammer_and_wrench: SOBRE O PROJETO

Este projeto foi desenvolvido para a edição 4º do Labs da 42 sp.

O programa deve comprimir e descomprimir textos, retornando informações sobre o processo.

Para desenvolver essa utilidaded foi usado o algoritmo de huffman.

## :clipboard: FLUXO E DESENVOLVIMENTO

Como já citado, o algoritmo de huffman é usado aqui para codificar e dedcodificar o input, veremos aqui visualmente o passo a passo que o programa faz, usando como exemplo o input "hello world":

  1. Criar lista de frecuencia dos caracteres
    O programa processa o input retornardo a quantidade de vezes que uma letra esta presente nele, com o objetivo de agrupar e reducir o que seriam varios chars em diferentes possições a apenas  dois dados, o char e a sua frecuencia:
    
![image](https://user-images.githubusercontent.com/53455663/212553883-a229f526-932b-4668-bed4-84faaec07ea3.png)



  2. Cria a arvora de huffman
    A arvore ded huffman é uma arvore binaria, o que quer dizer que cada nodo podera ter apenas maximo dois filhos, o que permite percorrer a arvore com zeros e uns, zero seria para esquerda e 1 para a direita.
    Nese paso se percorre a lista para poder cria a arvore, enquanto mais aparições determinadao caracter fizer no input mas perto da cabeça da arvore ele estara e enquando menor a frecuencia mais distante estará.
    Nessa imagem podemos ver um output com as folhas da arvore apenas, indicando se está a direita ou esquer e qual a altura da arvore na qual se encontra:
    
![image](https://user-images.githubusercontent.com/53455663/212554391-ea65403e-9603-4ecb-9f2e-e4d09bcc17c2.png)

  3. Percorrer arvore e gerar dicionario
  
  



## :gem: Acesse ferramentas usadas para planejar o projeto:
 - [Notion(Rascunhos)](https://www.notion.so/Huffman-Algorithm-8880a28c061649729f614456454cc72a)
 - [Github Canvan Board](https://github.com/users/angelasoler/projects/6/views/1)
