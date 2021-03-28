# metacall-polyglot-cli

## Setup

#### Install MetaCall:
If you face any problems during the install, refer [here](https://github.com/metacall/install/blob/master/README.md)

1. `git clone https://github.com/metacall/core.git`
2. `mkdir core/build && cd core/build`
3. `cmake -DOPTION_BUILD_LOADERS_PY=On -DOPTION_BUILD_DETOURS=Off -DOPTION_BUILD_SCRIPTS=Off -DOPTION_BUILD_TESTS=Off ..`
4. `cmake --build . --target install`

#### Set up:
1. Clone the repository: `git clone https://github.com/akshgpt7/metacall-polyglot-cli && cd metacall-polyglot-cli`
2. Create a virtual env: `python3 -m venv ./venv`
3. Activate the virtual env: `source venv/bin/activate`
4. Install the dependency: `pip install prompt-toolkit`

#### Build and run the CLI:
1. Build the run file: `g++ run.cpp -L/usr/local/lib -lmetacall`
2. Run the REPL: `LD_LIBRARY_PATH=/usr/local/lib ./a.out`

## Usage:
Currently only an `exit` command works since there is no parser to parse the input commands.
