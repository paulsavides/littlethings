#include <stdio.h>
#include <windows.h> // needed for Sleep() (unistd.h on *nix)

#define TRUE 1
#define FALSE 0

int main(int argc, char** argv)
{
  const char* SPACE = " ";
  char* fuck = "fuck";

  int lim = 30;
  int up = TRUE;

  int i = 1;
  int sleep_time = 150;


  while (i < lim)
  {
    for (int j = 0; j < i; j++)
    {
      printf("%s%s", fuck, SPACE);
    }

    printf("\n");

    if (i == lim - 1 || ( !up && i == 1 )) // stupid
    {
      up = !up;
    }

    i = up ? i+1 : i-1;

    Sleep(sleep_time);
  }

  // lol infinite loops are trash
}