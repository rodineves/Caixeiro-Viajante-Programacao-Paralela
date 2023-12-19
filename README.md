# Caixeiro Viajante - Programacao Paralela

Códigos que foram feitos durante a disciplina de Programação Paralela do curso de Ciência da Computação, códigos esses que resolvem o problema
do Caixeiro Viajante (Travelling Salesman Problem - TSP) através do algoritmo do vizinho mais próximo. 

## 📮 Problema do Caixeiro Viajante

É um problema que trata de encontrar qual é a menor rota possível passando por todas as cidades, uma única vez e depois voltar para a cidade onde foi iniciado o percurso.

Exemplo:

![caxaro](https://github.com/rodrigoneves927/Caixeiro-Viajante-Programacao-Paralela/assets/105732866/bf530352-eb3a-4407-8076-875f7ed8dd68)

Começando da cidade 1, o caminho que terá menor custo e passará por todas as cidades uma única vez e voltará para a cidade 1 é o caminho: 1 -> 3 -> 2 -> 5 -> 4 -> 1.

## 🏘️ Algoritmo do Vizinho mais Próximo

Esse foi um dos primeiros algoritmo que visavam determinar uma solução para o caixeiro viajante, e um dos mais simples. Ele encontra rapidamente uma solução para o problema, mas geralmente não gera o melhor caminho nem o ideal, pelo motivo de ser um algoritmo guloso (Escolhe o que parece ser o melhor caminho no momento e continua por ele, mesmo no futuro não sendo uma boa escolha). Um pré requisito para que esse algoritmo funcione é que o grafo escolhido precisa ser completo, ou seja, todos os vértices possuem ligação com todos os outros vértices, como a imagem anterior na seção do Problema do Caixeiro Viajante.

![image](https://github.com/rodineves/Caixeiro-Viajante-Programacao-Paralela/assets/105732866/48b5cbe0-daae-4be8-bd04-2298a3afd296)
Exemplo de matriz de grafo completo utilizada para o problema (6 cidades / nós).

Ps.: Sim, eu escolhi esse algoritmo porque é um dos mais fáceis rsrs 😁.

### 👣 Passos do Algoritmo

1. Escolher um vértice para começar
2. Escolher a aresta de menor peso e que vai para um nó que ainda não está na lista dos nós visitados.
3. Coloque este nó como sendo o nó atual.
4. Coloque esse nó escolhido na lista de visitados.
5. Se todos os nós foram visitados, encerrar o algoritmo (voltando para nó inicial).
6. Senão, voltar para o passo 2.

## 🤔 Objetivo do Código
O código objetiva verificar qual é a melhor cidade (nó) para começar, ou seja, o que terá o caminho menos custoso, utilizando o algoritmo do vizinho mais próximo.
Por exemplo, casa haja 6 cidades, o algoritmo será feito 6 vezes, iniciando pelos 6 nós.

## Arquivos

- caixeiro_sequencial.c -> código que resolve o problema normalmente.
- caixeiro_paralelo.c -> código paralelizado
- si6.tsp e si175.tsp -> Arquivos que serão lidos que contém a matriz das cidades onde tem a quantidade de nós e, mais abaixo, a matriz (pode abrir como um txt).

## Como compilar
Não tem segredo para compilar os códigos. Somente foi utilizada a linguagem CApenas Utilizei o DEV C++. Se quiser compilar no terminal, primeiramente precisa instalar o MinGW (Windows) ou o GCC (Linux), depois no terminal:

```bash
gcc -o nome_escolher caixeiro_sequencial.c
```
Clicar o Enter e depois para executar o código:

```bash
./nome_escolher
```
Lembrando que para rodar o código paralelizado, precisa ser um pouco diferente:

```bash
gcc -o nome_escolher caixeiro_paralelo.c -pthread
```
E em seguida somente escrever ./nome_escolher normalmente.

Ps.: Caso queira que os caminho e suas distâncias sejam impressos, basta somente descomentar os trechos dos código que estão na função "caixeiro".


