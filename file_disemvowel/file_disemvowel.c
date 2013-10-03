#include <stdio.h>
#include <stdbool.h>

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
  fseek(inputFile, 0, SEEK_END);
  int num_chars = ftell(inputFile);
  fseek(inputFile, 0, SEEK_SET);
  char in_buf[num_chars];
  fgets(in_buf, num_chars, inputFile);
  char out_buf[num_chars];
  copy_non_vowels(num_chars, in_buf, out_buf);
  fputs(out_buf, outputFile);
}

int main(int argc, char *argv[]) {
  FILE *inputFile = fopen(argv[1], "r");
  FILE *outputFile;

  if ((argc != 2) || (argc != 3)) {
    printf("Incorrect Number of Arguments\n");
  } else if (argc == 2) {
    if (inputFile == 0) {
      fputs(argv[1], inputFile);
    }
  } else {
    if (inputFile == 0) {
      fputs(argv[1], inputFile);
    }
    outputFile = fopen(argv[2], "w");
  }

  disemvowel(inputFile, outputFile);

  return 0;
}
