#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>

int main(int argc, char *argv[]){
  (void)argc;
  char buffer[2048];
  int file_descriptor = open(argv[1], O_RDONLY);
  int counter = read(file_descriptor, buffer, 2048);
  write(1, buffer, counter);
  close(file_descriptor);
}