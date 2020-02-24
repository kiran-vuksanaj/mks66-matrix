#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *transform;
  
  /*==== TESTING add_edge() ====*/
  printf("==== testing add_edge() ====\n");
  printf("new matrix 4x3 (test growing as well)\nadd (4,2,3),(9,4,4)\n");
  edges = new_matrix(4,3);
  add_edge(edges,4,2,3,9,4,4);
  print_matrix(edges);
  printf("\nadd (7,7,7),(-3,0,2.4)\n");
  add_edge(edges,7,7,7,-3,0,2.4);
  print_matrix(edges);

  /*==== TESTING ident() ====*/
  printf("\n==== testing ident() ====\n");
  transform = new_matrix(4, 2);
  ident(transform);
  print_matrix(transform);

  /*==== TESTING matrix_mult() ====*/
  printf("\n==== testing matrix_mult() ====\n");
  printf("ident * edges (should yield the same)\n");
  matrix_mult(transform,edges);
  print_matrix(edges);
  
  free_matrix( edges );
  free_matrix( transform );
}  
