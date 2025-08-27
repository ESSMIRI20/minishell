# Minishell

![Language: C](https://img.shields.io/badge/Language-C-red) ![License: MIT](https://img.shields.io/badge/License-MIT-blue)

A small Unix-like shell implemented in C as part of the 1337 / 42 school curriculum.  
Minishell supports command execution, pipelines, redirections, heredoc, and built-in commands. It uses an **Abstract Syntax Tree (AST)** for parsing commands, making it closer to real-world shell behavior.

## Features

- Execute external commands (`/bin/ls`, `/bin/echo`, etc.)
- Built-in commands:
  - `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`
- Input/output redirections: `>`, `>>`, `<`
- Heredoc support: `<<`
- Pipe support: `|`
- AST-based command parsing for structured execution
- Signal handling:
  - Ctrl+C (SIGINT) — interrupts the current command
  - Ctrl+D — exits the shell
  - Ctrl+\ (SIGQUIT) — handled gracefully
- Minimal error handling similar to real shells

## Installation

Clone the repository:

```bash
git clone https://github.com/<your-username>/minishell.git
cd minishell
```

Compile:
```
make
```
Run the shell:
```
./minishell
```
