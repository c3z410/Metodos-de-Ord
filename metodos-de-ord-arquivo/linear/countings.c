#include "countings.h"

// calcula o maior elemento do array.
int maximum(int* arr, int length){
    
      int max = 0;
    
      // itera sobre todos os elementos do array e pega o maior
      for (int current = 0; current < length; current++) {
        if(arr[current] > max) {
          max = arr[current];
        }
      }
    
      return max;
}

//ordena usando o algorítmo counting.
void countings(int* arr, int length) {
    
      // pega o maior valor
      int max = maximum(arr, length);

      // aloca um array de zeros cujo tamanho é igual ao maior elemento do array original
      int* counting = calloc(max, sizeof(int));
    
      // conta o número de ocorrencias de cada valor
      for(int i = 0; i < length; i++){
        counting[arr[i]]++;
      }

      int current = 0;
    
      // itera sobre o array counting que armazena o número de ocorrencias
      for (int i = 0; i <= max; i++) {
        
        // enquanto existir ocorrencias, armazena no array e decrementa o número de ocorrencias.
        while (counting[i] > 0) {
          arr[current++] = i;
          counting[i]--;
        }
      }
    }
    
