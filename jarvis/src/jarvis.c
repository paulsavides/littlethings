#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jarvis.h"

#define true 1
#define false 0


int main (int argc, char** argv)
{
  init();

  int args_given = argc > 1;

  if (args_given)
  {
    process_command(argc-1, argv+1);
  }
  else
  {
    print_help();
  }

  destroy();

  return(0);
}

void init()
{
  num_comms = get_num_lines("jarvis.conf");

  comm_prompt = malloc(num_comms * sizeof(char*));
  comm_action = malloc(num_comms * sizeof(char*));

  for (int i = 0; i < num_comms; i++)
  {
    comm_prompt[i] = malloc(prompt_lim * sizeof(char));
    memset(comm_prompt[i], '\0', prompt_lim);

    comm_action[i] = malloc(comm_lim * sizeof(char));
    memset(comm_action[i], '\0', comm_lim);
  }

  read_comms("jarvis.conf");

}

void destroy()
{
  for (int i = 0; i < num_comms; i++)
  {
    free(comm_prompt[i]);
    free(comm_action[i]);
  }

  free(comm_prompt);
  free(comm_action);
}

int get_num_lines (char* file_path)
{
  int num_lines = 0;

  FILE* fp;
  fp = fopen(file_path, "r");

  // read num lines
  int keep_going = true;
  int c; // store char val in int

  while (keep_going)
  {
    c = fgetc(fp);
    if (c == '\n') { num_lines++; }

    if (feof(fp)) // if end of file
    {
      keep_going = false;
    }
  }

  fclose(fp);


  return num_lines;
}

void read_comms (char* file_path)
{
  FILE* fp;
  fp = fopen(file_path, "r");

  int keep_going = true;

  int cur_line = 0;
  int cur_char = 0;

  int on_prompt = true;

  int c;

  while (keep_going)
  {
    c = fgetc(fp);
    
    if (feof(fp))
    {
      keep_going = false;
      continue;
    }
 
    if (c == ':')
    {
      on_prompt = false;
      cur_char = 0;
      continue;
    } 
    
    if (c == '\n')
    {
      cur_line++;
      cur_char = 0;
      on_prompt = true;
      continue;
    }

    if (on_prompt)
    {
      comm_prompt[cur_line][cur_char] = c;
    }
    else
    {
      comm_action[cur_line][cur_char] = c;
    }
    
    if (cur_char == 0 && c == ' ')
    {
      cur_char--;
    }
 
    cur_char++;
  }

  fclose(fp);
}

void process_command (int argc, char** argv)
{
  for (int i = 0; i < argc; i++)
  {
    for (int j = 0; j < num_comms; j++)
    {
      if (strcmp(comm_prompt[j], argv[i]) == 0)
      {
        printf("%s\n", comm_action[j]);
      }
    }  
  }
}

void print_comms ()
{
  for (int i = 0; i < num_comms; i++)
  {
    printf("%s: %s\n", comm_prompt[i], comm_action[i]);
  }
}

void print_help ()
{
  printf("Please call with one of the following arguments:\n");
  print_comms();
}
