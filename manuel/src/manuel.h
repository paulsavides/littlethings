void init       ();
void destroy    ();

void read_comms   (char* file_path);
int get_num_lines (char* file_path);


static int    num_comms;
static char** comm_prompt;
static char** comm_action;

const int prompt_lim = 10;
const int comm_lim = 100;


void process_command (int argc, char** argv);

void print_comms();
void print_help ();
