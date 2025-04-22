# minishell

## 1. Initial Setup & Project Structure
### Task 1: Set up a GitHub repository and organize the project structure.

#### Create a src/ folder for source code.

#### Create an include/ folder for header files.

#### Set up Makefile for compiling the project.

#### Add .gitignore to exclude unnecessary files.

#### Assigned to: Team Lead (if applicable) or a couple of members to set up the project framework.

## 2. Core Components of Minishell
  ## 2.1 Input Handling
### Task 2: Implement a basic loop to read user input.

Create a function that continuously waits for user input.

Display a prompt (e.g., $ or minishell$).

Handle special cases like empty input or entering exit.

Assigned to: Team member focused on input/output handling.

2.2 Tokenization (Parsing)
Task 3: Parse the input into tokens.

Tokenize the input based on spaces, handling quoted strings (e.g., "Hello World").

Consider escape characters for special handling (e.g., \n, \t).

Assigned to: Member focused on parsing and string handling.

2.3 Executing Commands
Task 4: Implement command execution.

Use fork() to create child processes for each command.

Use execvp() or execve() to execute the parsed command in the child process.

Assigned to: Member with experience in process management and system calls.

3. Built-In Commands Implementation
3.1 Built-in cd Command
Task 5: Implement cd to change the current working directory.

Handle relative and absolute paths.

Handle ~ (home directory) and .. (parent directory).

Update the environment variables (PWD, OLDPWD).

Assigned to: Member focused on implementing shell features and environment handling.

3.2 Built-in echo Command
Task 6: Implement echo to print text to the terminal.

Handle flags like -n to suppress the newline.

Assigned to: Same member as cd or someone working on output handling.

3.3 Built-in env Command
Task 7: Implement env to print environment variables.

Print the environment variables in the current shell.

Assigned to: Same member as cd or another member working on environment variables.

3.4 Built-in exit Command
Task 8: Implement exit to terminate the shell.

Handle an optional exit status (e.g., exit 1 for error).

Ensure proper cleanup before exiting.

Assigned to: Member responsible for exit conditions and overall program termination.

4. Advanced Shell Features
4.1 Piping
Task 9: Implement piping between commands.

Use pipe() and dup2() for redirecting output from one command to another.

Handle multiple commands in a single line (e.g., ls | grep "test").

Assigned to: Member experienced with system calls and inter-process communication.

4.2 Redirection (>, <, >>)
Task 10: Implement input and output redirection.

Handle redirection to files (> and >> for output, < for input).

Handle multiple redirections in the same command.

Assigned to: Member familiar with file handling and redirection.

4.3 Environment Variables
Task 11: Implement environment variable handling.

Set and get environment variables with setenv() and getenv().

Update environment variables when running commands like cd.

Assigned to: Member focused on environment handling and system calls.

4.4 Signal Handling
Task 12: Implement signal handling for interrupts (Ctrl+C) and background processes.

Use signal() or sigaction() to handle signals.

Make sure the shell doesn't terminate unexpectedly when pressing Ctrl+C.

Assigned to: Member experienced with signal handling in C.

5. Testing & Debugging
5.1 Unit Tests for Commands
Task 13: Write test cases for each built-in command (cd, echo, env, exit).

Use simple test cases (e.g., cd /home, echo "Hello World").

Ensure proper behavior with edge cases (e.g., invalid arguments).

Assigned to: QA or testing-focused team member.

5.2 Test Shell with Different Inputs
Task 14: Test the shell with various scenarios (pipes, redirections, commands, edge cases).

Check for correct output, error handling, and robustness.

Assigned to: All team members (for thorough testing).

5.3 Bug Fixing and Polishing
Task 15: Review and fix bugs.

Test edge cases (e.g., invalid command arguments, empty inputs).

Optimize code and clean up any unused variables or functions.

Assigned to: Entire team for a final review and bug fixing.

6. Documentation & Finalization
6.1 Write Documentation
Task 16: Document the project, explaining the design choices and how to use the shell.

Provide a README.md with setup instructions, usage examples, and a description of the shell's features.

Assigned to: Member responsible for documentation.

6.2 Code Review and Merge
Task 17: Conduct a final code review.

Ensure all code is consistent, well-documented, and adheres to coding standards.

Merge the final code into the main branch for submission.

Assigned to: All team members for code review.

7. Final Testing & Submission
Task 18: Final round of testing and submission.

Ensure everything works as expected before submission.

Verify that the shell is compliant with any requirements set by your instructors.

Assigned to: QA team or team lead for final testing.

Project Timeline Example (Assuming 2 Weeks Deadline):
Week 1:

Day 1-2: Project setup, core input handling, and tokenization.

Day 3-4: Implement cd, echo, env, exit commands.

Day 5-7: Implement piping and redirection.

Week 2:

Day 8-10: Handle environment variables, signal handling, and advanced features.

Day 11-12: Testing, debugging, and writing documentation.

Day 13-14: Code review, merge, final testing, and submission.
