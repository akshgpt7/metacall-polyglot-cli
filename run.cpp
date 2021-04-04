#include<metacall/metacall.h>

int main() {

  const char * py_scripts[] =
  {
    "cli.py"
  };

  metacall_initialize();

  metacall_load_from_file(
      "py", py_scripts, sizeof(py_scripts) / sizeof(py_scripts[0]), NULL
      );

  void * ret = NULL;

  void * args[] = {};

  // figure out which function from the MetaCall API will be best
  // to call the function here and to call the callbacks
  ret = metacallv("start", args);

  metacall_destroy();


  return 0;
}
