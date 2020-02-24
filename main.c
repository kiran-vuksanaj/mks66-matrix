#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

#include "time.h"

int main() {

  struct matrix *edges;
  struct matrix *transform;

  srand( time(NULL) );
  
  /*==== TESTING add_edge() ====*/
  printf("==== testing add_edge() ====\n");

  printf("new matrix 4x3 (test growing as well)\nadd (4,2,3),(9,4,4)\n");
  edges = new_matrix(4,3);
  add_edge(edges,4,2,3,9,4,4);
  print_matrix(edges);

  printf("\nadd (7,7,7),(-3,0,2.4)\n");
  add_edge(edges,7,7,7,-3,0,2.4);
  print_matrix(edges);
  
  printf("\nadd (9,0,1),(-0.5,1,1)\n");
  add_edge(edges,9,0,1,-.5,1,1);
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
  printf("switch up transform matrix (random integers 0-3; run multiple times for more unique tests): \n");

  int row,col;
  for( row = 0; row < 4; row++ ){
    for( col = 0; col < 4; col++ ){
      transform->m[row][col] = rand() % 4;
    }
  }
  print_matrix(transform);
  printf("\nnew matrix * edges = \n");
  matrix_mult(transform,edges);
  print_matrix(edges);
  printf("(checked a handful of times against [https://matrix.reshish.com/multCalculation.php], i feel comfortable saying that its functioning)\n");

  free_matrix( edges );
  free_matrix( transform );
  
  printf("\n==== creating image ====\n");

  /* declarations, matrix initializations */
  screen s;
  color c;
  struct matrix *blue = new_matrix(4,5);
  struct matrix *green = new_matrix(4,2);
  struct matrix *white = new_matrix(4,4);

  /* adding edges */

  add_edge(white,50,50,0,150,150,0);

  /* setting colors and drawing for each matrix */
  clear_screen(s);

  c.red = 255;
  c.green = 255;
  c.blue = 255;
  draw_lines(white,s,c);

  c.red = 0;
  c.blue = 0;
  draw_lines(green,s,c);

  c.blue = 255;
  c.green = 0;
  draw_lines(blue,s,c);
  
  save_ppm_ascii(s,"chaos.ppm");
  save_extension(s,"chaos.png");
  
  printf("image file generated: ./chaos.png\n");
  
}  
