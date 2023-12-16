#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int **cidades;
int **caminho;
int *distancia;
int max;
FILE *file;

void inserir_valor() {
    int n;
	for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            
			fscanf(file, "%d", &n);
            cidades[i][j] = n;
        }
    }
}

void print_matriz() {
	
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {	
            printf("%d   ", cidades[i][j]);
        }
        printf("\n");
    }
}

int verificar(int n, int no_atual) {
    for (int i = 0; i < max; i++) {
        if (caminho[no_atual][i] == -1) {
            break;
        }
        if (n == caminho[no_atual][i]) {
            return 0;
        }
    }
    return 1;
}

void caixeiro(){
	int observar, contagem, menor, proximo_no;
	
	for (int i = 0; i < max; i++) {
        caminho[i][0] = i;
        observar = caminho[i][0];
        contagem = 0;
        distancia[i] = 0;

        while (contagem != max-1) {
            menor = INT_MAX;
            for (int j = 0; j < max; j++) {
                
          		if(verificar(j, i)){
          			
          			if (cidades[observar][j] <= menor && cidades[observar][j] != 0) {
						menor = cidades[observar][j];
	            		proximo_no = j;
          			}
				}
	            
            }
            
            contagem++;
            caminho[i][contagem] = proximo_no;
            distancia[i] += menor;
            observar = proximo_no;
        }

        caminho[i][max] = caminho[i][0];
        distancia[i] += cidades[caminho[i][0]][caminho[i][max-1]];
		
		/*
        for (int j = 0; j < max+1; j++) {
            printf("%d", caminho[i][j]);
            if (j != max) {
                printf(" -> ");
            }
        }
        printf("\nDistancia total: %d\n", distancia[i]);
        */
        //system("pause");
    }
}

int main() {
    int i, j;
    int melhor_no_distancia = INT_MAX, melhor_no;

    file = fopen("si175.tsp", "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo texto.tsp\n");
        return 1;
    }
    
    fscanf(file, "%d", &max);
    printf("%d\n", max);
    
    cidades = malloc(max * sizeof (int*));
    caminho = malloc(max * sizeof (int*));
    distancia = malloc(max * sizeof (int));
	
	for(i=0 ; i<max ; i++){
		cidades[i] = malloc(max * sizeof (int));
		caminho[i] = malloc((max+1) * sizeof (int));
	}
	
    for (i = 0; i < max; i++) {
        for (j = 0; j < max + 1; j++) {
            caminho[i][j] = -1;
        }
    }

    inserir_valor();
    //print_matriz();
    
	fclose(file);
       
	caixeiro();
	
	
    for (i = 0; i < max; i++) {
        if (distancia[i] < melhor_no_distancia) {
            melhor_no_distancia = distancia[i];
            melhor_no = i;
        }
    }

    printf("\n\n\nMelhor noh para comecar: %d\n", melhor_no);
    printf("Com distancia: %d", melhor_no_distancia);
    
    return 0;
}
