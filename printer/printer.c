#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printer.h"

// portable
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#endif

int main(int argc, char** argv)
{
  if (!process(argc, argv))
  {
    print_help();
  }

  return (FALSE); // lol
}

int process(int argc, char** argv)
{
  // setup defaults
  int lim = DEF_LINES;
  int sleep = DEF_TIME;
  char to_print[WORD_MAX];
  zero_char_arr(WORD_MAX, to_print);
  strcpy(to_print, DEF_WORD);

  for (int i = 0; i < argc; i++)
  {
    if ((strcmp(*argv, HELP_PROMPT) == 0))
    {
      return FALSE;
    }
    else if ((strcmp(*argv, WORD_PROMPT) == 0) && i < argc - 1)
    {
      strcpy(to_print, *(++argv));
      i++;
    }
    else if ((strcmp(*argv, LIM_PROMPT) == 0) && i < argc - 1)
    {
      lim = atoi(*(++argv));
      i++;
    }
    else if ((strcmp(*argv, TIME_PROMPT) == 0) && i < argc - 1)
    {
      sleep = atoi(*(++argv));
      i++;
    }
    argv++;
  }

  print_it(to_print, lim, sleep);
  return TRUE;
}

void print_it(char* word, int lim, int sleep)
{
  int up = TRUE;
  int i = 1;

  while (i < lim)
  {
    for (int j = 0; j < i; j++)
    {
      printf("%s%s", word, SPACE);
    }

    printf("\n");

    if (i == lim - 1 || ( !up && i == 1 )) // stupid
    {
      up = !up;
    }

    i = up ? i+1 : i-1;

    msleep(sleep);
  }
}

void print_help()
{
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Copyright Paul Savides 2017\n");
  printf("Use like this-ish\n");
  printf("\tprinter -w hello -s 20\n");
  printf("will print hello pyramids up to 20 in size\n");
  printf("\t-w word to print\n");
  printf("\t-s max size of the line of words (don't put 0 or 1 please)\n");
  printf("\t-t ms before printing next line\n");
  printf("Vvvvvv useful.\n");
}

void zero_char_arr(int size, char* arr)
{
  for (int i = 0; i < size; i++)
  {
    *(arr++) = '\0'; // okay
  }
}

// ty to this friend http://www.cplusplus.com/forum/unices/60161/
void msleep(int milliseconds)
{
  #ifdef __WIN32__
  Sleep(milliseconds);
  #else
  usleep((milliseconds)*1000);
  #endif
}