#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  if(length == 1){
    return NULL; 
  }
  
  // Filling hash table with weight data key and index as value
  for(int i = 0; i < length; i++){
    hash_table_insert(ht, weights[i], i); 
  }

  Answer *answer = NULL; 

  for(int i = 0; i < length; i++){
    int weight2 = limit - weights[i]; 
    if(hash_table_retrieve(ht, weight2) != NULL){
      answer-> index_1 = i;
      answer-> index_2 = hash_table_retrieve(ht, weight2); 
    }
  }

  destroy_hash_table(ht); 

  if(answer != NULL){
    return answer; 
  }else{
    return NULL;
  }
  
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}