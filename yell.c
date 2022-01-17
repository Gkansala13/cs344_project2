#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	char buffer[2048];
  if (argc < 2) {
		int counter = 1;
		while(counter > 0) {
			counter = read(0, buffer, sizeof buffer);
      for (int i = 0; i < counter; ++i) {
				buffer[i] = toupper(buffer[i]);
      }
			write(1, buffer, counter);
		}
	}

	for (int i = 1; i < argc; ++i) {
		int file_descriptor = open(argv[i], O_RDONLY);	
		int counter = 1;
		while(counter > 0) {
			counter = read(file_descriptor, buffer, sizeof buffer);
      for (int i = 0; i < counter; ++i) {
				buffer[i] = toupper(buffer[i]);
      }
			write(1, buffer, counter);
		}
	}
}