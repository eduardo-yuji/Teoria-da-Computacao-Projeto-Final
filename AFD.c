/* 
    Automato Finido Deterministico

    Autor: Eduardo Yuji Yoshida Yamada

    Recebe valores 0 e 1

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen


int verificaAlfabeto(char input[200], int max, char E[2]){
    for (int i = 0; i < max; i++){
        if (input[i] != E[0] && input[i] != E[1]){
            printf("\nCaractere %c NAO foi aceito.\n", input[i]);
            return 0; //se não for nenhum das possibilidades do alfabeto, fecha imediatamente pois não é preciso
        }
    }
    return 1;
}



int AFD(char input[200], int max, int init){
    int inputPointer = 0; //primeiro valor de input
    int statePointer = init; //primeiro estado = init
    int sizeInput = strlen(input);
    int cont = 0;
    printf("\nQuantidade de iteracoes a ser realizado: %d\n\n", sizeInput);

    // Q[3] = {'0','01','012'};
    
    while(inputPointer < max){
        printf("Iteracao: %d\nEstado atual: q%d  ----  Caractere atual: %c\n\n", cont, statePointer, input[inputPointer]);
        cont = cont + 1;
        switch(statePointer){ //verifica qual nó está apontando
            case 0:{ //{q0}
                if (input[inputPointer] == '0') //Transição laço
                    break;
                if (input[inputPointer] == '1') //Transição para q1
                    statePointer = 1;
                break;
            }
            case 1:{ //{q0, q1}
                if (input[inputPointer] == '0') //Transição laço
                    break;
                if (input[inputPointer] == '1') //Transição para q2
                    statePointer = 2;
                break;
            }
            case 2:{ //{q0, q1, q2}
                if (input[inputPointer] == '0') //Transição para q1
                    statePointer = 1;
                if (input[inputPointer] == '1') //Transição laço
                    break;
                break;
            }
        }
        inputPointer++; //avança 1 casa na leitura do input
        setbuf(stdin, NULL);
        getchar();

    }
    
    printf("Estado final: q%d\n", statePointer);
    
    if (statePointer == 2) //verifica se o nó é final
        return 1; //caiu em {q0, q1, q2}
    else
        return 0; //caiu em {q0} ou {q0, q1}
}



int main() {
    char input[200]; //string para ser recebido como input

    printf("----------------AUTOMATO FINITO DETERMINISTICO----------------\nAlfabeto: {0,1}\nEstado Inicial: q0\nEstado Final: q2\n\n");
    
    printf("Digite a palavra: ");
    setbuf(stdin, NULL);
    fgets(input, 200, stdin);
    input[strcspn(input, "\n")] = '\0';
    
    int max; //máximo de iterações, que é a quantidade de símbolos no input
    max = strlen(input);
    
    
/*
 * 5-upla: M=({q0,q1,q2},{0,1},δ,q0,q2)
 * δ = Q x Σ -> Q
 */
    //int Q[3] = {0, 1, 2}; //estados, apenas para visualização
    char E[2] = {'0', '1'}; //alfabeto
    int init = 0; //estado inicial
    //int F[1] = {2}; //estado final, apenas para visualização
    
    if (verificaAlfabeto(input, max, E) == 0){ //verifica se input está dentro do alfabeto
        printf("\nERRO: INPUT CONTEM CARACTERE FORA DO ALFABETO\n\n");
        return(2);
    }
    
    if (AFD(input, max, init) == 1){ //executa o AFD
        printf("\nSENTENCA VALIDA\n\n");
    }
    else{
        printf("\nSENTENCA INVALIDA\n\n");
    }
    
    return (EXIT_SUCCESS);
}