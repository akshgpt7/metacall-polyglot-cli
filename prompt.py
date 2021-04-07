from prompt_toolkit import prompt
from prompt_toolkit.history import FileHistory
from prompt_toolkit.auto_suggest import AutoSuggestFromHistory
from prompt_toolkit.completion import WordCompleter, PathCompleter


def take_input():

    path_completer = PathCompleter()

    # Get this list dynamically for completion
    command_completer = WordCompleter(
        ['load', 'clear', 'exit', 'inspect'],
        path_completer,
    )

    try:
        user_input = prompt('> ',
                            history=FileHistory('history.txt'),
                            auto_suggest=AutoSuggestFromHistory(),
                            completer=command_completer,
                            complete_while_typing=True
                            )

    except (EOFError, KeyboardInterrupt):
       return "exit"

    return user_input



