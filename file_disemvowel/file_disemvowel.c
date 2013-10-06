#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

bool is_vowel(char c) {
  int i;
  char vowels[] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
  for(i = 0; i < 10; i++){
    if(c == vowels[i]){
      return true;
    }
  }
  return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
  int c;
  int i = 0;
  for (c = 0; c < num_chars; c++) {
    if (!is_vowel(in_buf[c])) {
      out_buf[i] = in_buf[c];
      i++;
    }
  }
  return i + 1;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
  int num_chars = BUF_SIZE;
  char in_buf[num_chars];
  char out_buf[num_chars];
  while (fgets(in_buf, num_chars, inputFile) != NULL) {
    copy_non_vowels(num_chars, in_buf, out_buf);
    if (outputFile == 0) {
      printf("%s\n", out_buf);
    } else {
      fputs(out_buf, outputFile);
    }
  }
}

int main(int argc, char *argv[]) {
  FILE *inputFile;
  FILE *outputFile;

  switch (argc) {
  case 1:
    inputFile = stdin;
    outputFile = stdout;
    break;
  case 2:
    if ((inputFile = fopen(argv[1], "r")) == NULL) {
      puts("Cannot Open Input File\n");
      exit(0);
    }
    outputFile = stdout;
    break;
  case 3:
    if ((inputFile = fopen(argv[1], "r")) == NULL) {
      puts("Cannot Open Input File\n");
      exit(0);
    }
    if ((outputFile = fopen(argv[2], "w")) == NULL) {
      puts("Cannot Open Output File\n");
      exit(0);
    }
    break;
  default:
    puts("Wrong Parameters\n");
    exit(0);
  }

  disemvowel(inputFile, outputFile);

  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
