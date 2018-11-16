#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));
  
  // create a hash table that holds the source as the key and the destination as the value;
  for(int i = 0; i < length; i++){
    hash_table_insert(hash, tickets[i]-> source, tickets[i]-> destination); 
  }
  // populate routes array
  //first find the first element in the array by locating the key which value is NULL
  route[0] = hash_table_retrieve(hash, NULL); 
  // to find second value and other remaining values, save destination of first, then search hash for the first array value
  for(int i = 1; i < length; i++){
    route[i] = hash_table_retrieve(hash, route[i-1]); 
  }
  //destroy hash table and clear memory when done
  destroy_hash_table(hash); 
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}