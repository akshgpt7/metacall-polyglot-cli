#include<iostream>
#include<string.h>
#include<signal.h>

#include<metacall/metacall.h>
#include <metacall/metacall_value.h>

using namespace std;


// if user wants to exit in between command execution by Ctrl-C
void keyboard_interrupt_handler(int signum) {
   cout << "\nExiting..." << endl;
   exit(signum);
}


int main() {

  const char * py_scripts[] =
  {
    "prompt.py",
    "util.py"
  };

  metacall_initialize();

  metacall_load_from_file(
      "py", py_scripts, sizeof(py_scripts) / sizeof(py_scripts[0]), NULL
      );

  void * ret = NULL;
  void * args[] = {};
  char * user_input = NULL;


  // print welcome message
  void * hello = metacallv("message", args);

  signal(SIGINT, keyboard_interrupt_handler);
  while (true) {

    // figure out which function from the MetaCall API will be best
    // to call the function here and to call the callbacks
    ret = metacallv("take_input", args);

    char *temp = metacall_value_to_string(ret);

    user_input = temp;


    cout << user_input << endl;

    // This is where the input will be interpreted and the
    // callback will actually run 
    if (strcmp(user_input, "exit") == 0) {
      break;
    }
    
  }

  metacall_destroy();

  cout << "Bye! Hope to see you again soon." << endl;


  return 0;
}

