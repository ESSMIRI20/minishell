# Minishell

![Language: C](https://img.shields.io/badge/Language-C-red)
![License: MIT](https://img.shields.io/badge/License-MIT-blue)

A small Unix-like shell implemented in C as part of the 1337 / 42 school curriculum.  
Minishell supports command execution, pipelines, redirections, heredoc, and built-in commands. It uses an **Abstract Syntax Tree (AST)** for parsing commands, making it closer to real-world shell behavior.

---

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

---

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
**Usage
Example commands:
```
$ echo "Hello, World!"
Hello, World!
$ ls -la
$ cd ..
$ pwd
$ cat << EOF | grep "main" > result.txt
> line1
> int main() {
> return 0;
> EOF
```
Exit the shell:
```
$ exit
```
AST (Abstract Syntax Tree)
Minishell uses an AST to parse commands before execution. This allows handling complex commands with pipes, redirections, and heredocs in a structured way.

Example command with pipes and redirection:
```
$ ls -l | grep ".c" > output.txt
```
AST representation:

         [REDIRECTION > output.txt]
                    |
                [PIPE |]
               /       \
        [COMMAND ls -l] [COMMAND grep ".c"]
Example command with heredoc:
```
$ cat << EOF | grep "main" > result.txt
> line1
> int main() {
> return 0;
> EOF
```
AST representation:
```
         [REDIRECTION > result.txt]
                    |
                [PIPE |]
               /       \
[HEREDOC << EOF: cat] [COMMAND grep "main"]
```
