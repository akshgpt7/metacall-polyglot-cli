from prompt_toolkit import prompt
from prompt_toolkit.history import FileHistory
from prompt_toolkit.auto_suggest import AutoSuggestFromHistory
from prompt_toolkit.completion import WordCompleter, PathCompleter

from util import message


def start():

    message()

    path_completer = PathCompleter()

    # Get this list dynamically
    command_completer = WordCompleter(
        ['load', 'clear', 'exit', 'inspect'],
        path_completer,
    )

    while 1:
        user_input = prompt('> ',
                            history=FileHistory('history.txt'),
                            auto_suggest=AutoSuggestFromHistory(),
                            completer=command_completer,
                            complete_while_typing=True
                            )

        if user_input == "exit":
            break

        print(user_input)


