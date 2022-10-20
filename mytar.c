#include "inodemap.h"
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>


void errorHandle(char* check) { // should this return something? how to properly handle errors!
  if (check[0] == '\0') {
    printf("Error: No mode specified.\n");
  }
  if (check[1] == 0) {
    printf("Error: No tarfile specified.\n");
  } else {
    printf("found a tarfile\n");
  }

}


int main(int argc, char **argv) {

  int c = 1;
  int z;
  printf("%d\n", argc);
  char check[] = {'\0', 0}; // first value represents the argument found, second value represents if f was found
  char *filename = malloc(sizeof(char*));

  while (c < argc) {
    z= getopt (argc, argv, "ctxf");
    printf("%c is something\n", z);
  switch(z) {
    case 'c':
      if (check[0] == '\0') {
        printf("c found!\n");
        check[0] = z;
      } else {
        printf("Error: Multiple modes specified.\n");
      }
      break;
    case 't':
      if (check[0] == '\0') {
        printf("t found!\n");
        check[0] = z;
      } else {
        printf("Error: Multiple modes specified.\n");
      }
      break;
    case 'x':
      if (check[0] == '\0') {
        printf("x found!\n");
        check[0] = z;
      } else {
        printf("Error: Multiple modes specified.\n");
      }
      break;
    case 'f':
      if (check[0] == '\0') { // should this allow for f to be put before other arguments or naw
        printf("f found!\n");
        filename = optarg;
        check[1] = 1;
      } else {

      }
      break;
    case '?':
      printf("Usage: ppmcvt [-bgirsmtno] [FILE]\n");
    default:
      printf("default\n");
  }
  c++;
}

errorHandle(check);
fopen(filename, O_RDONLY);
fclose((FILE*)filename);

}
