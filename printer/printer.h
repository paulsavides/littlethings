// defs
#define TRUE 1
#define FALSE 0
#define WORD_MAX 20

// constants
const char* SPACE       = " ";
const char* WORD_PROMPT = "-w";
const char* LIM_PROMPT  = "-s";
const char* TIME_PROMPT = "-t";
const char* HELP_PROMPT = "-h";

const int   DEF_TIME    = 150;
const int   DEF_LINES   = 30;
const char* DEF_WORD    = "printer";

// forward decs
int process(int argc, char** argv);
void print_help();

void print_it(char* word, int lim, int sleep);

// utils
void zero_char_arr(int size, char* arr);
void msleep(int milliseconds);