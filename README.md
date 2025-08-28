# Minishell

![Language: C](https://img.shields.io/badge/Language-C-red)
![License: MIT](https://img.shields.io/badge/License-MIT-blue)

A part of the 1337 / 42 education program, a Unix-like shell developed in C.  

Minishell enables the execution of commands, supports pipelines, redirections, heredoc, and includes built-in commands. It utilizes an **Abstract Syntax Tree (AST)** for command parsing, which improves its fidelity to genuine shell functionality.

---

## Features

Fighter (your script) <--[execute]-- [external command] : /bin/ls /bin/echo 등등
- Built-in commands:
- `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`
- Input/output redirections: `>`, `>>`, <`.
- Heredoc support: `<<`
- Pipe support: `|`
- command parsing, based on AST, for structured execution.
- Signal handling:
- Ctrl+C (SIGINT) — interrupt (kill) the current command(InitializedTypeInfo)
  - Ctrl+D — exits the shell
- Ctrl+\ (SIGQUIT) — handled in an clean way
- Very little error handling a la real shells

---

## Installation

Clone the repository:

```bash
git clone https://github.com/ESSMIRI20/minishell.git
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
$ cd..
$ pwd
$ cat << EOF | grep "main" > result EOF a_main b_main c_main d_eof e_main EOF $ diff -u result input --- result 2009-10-07 17:19:27.000000000 +0200 +++ input 2009-10-07 17:15:00.000000000 +0200 @@ -1,3 +1,3 @@ -a_main -b_main -e_main +a_main e_main +b_main c_main txt
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
Minishell abstract syntax tree for parsing commands and not doing this. This permits a structured way to deal with complex commands which use pipes, redirections and heredocs. 

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
