#include "radixs.h"

// retorna o maior número, usado para saber o número máximo de casas decimais
int findlargest_num(int *arr, int length)
{

  int largest_num = -1;

  // itera sobre todos os elementos e calcula o maior número
  for (int i = 0; i < length; i++)
  {
    if (arr[i] > largest_num)
      largest_num = arr[i];
  }

  return largest_num;
}

// algoritmo de ordenação radix sort
void radixs(int *arr, int length)
{

  // Usando a base 10.
  int semi_sorted[length];
  int significant_digit = 1;
  int largest_num = findlargest_num(arr, length);

  // repete até chegar no maior dígito significante.
  while (largest_num / significant_digit > 0)
  {

    int bucket[10] = {0};

    // conta o número de elementos em cada bucket
    for (int i = 0; i < length; i++)
      bucket[(arr[i] / significant_digit) % 10]++;

    // adiciona o número do bucket anterior ao atual
    for (int i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];

    // Uso o bucket para criar um array semi ordenado
    for (int i = length - 1; i >= 0; i--)
    {
      // pega o dígito do elemento atual
      int digit = (arr[i] / significant_digit) % 10;

      // coloca o elemento atual no array semi ordenado e decrementa o número de itens no bucket
      semi_sorted[--bucket[digit]] = arr[i];
    }

    // copia o array semi ordenado para o array original
    for (int i = 0; i < length; i++)
      arr[i] = semi_sorted[i];

    // vai para o próximo dígito significante
    significant_digit *= 10;
  }
}
