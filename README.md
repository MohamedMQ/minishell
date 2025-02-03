# Minishell
The aims of the project:
- To write a shell (own bash);
- To learn a lot about processes and file descriptors.
## Shell should
- Handle ’ (single quote).
- Handle " (double quote).
- Implement ;.
- Implement redirections (<, >, <<, >>).
- Implement pipes (| character).
- Handle environment variables ($ followed by a sequence of characters).
- Handle $?.
- Handle ctrl-C, ctrl-D and ctrl-\.
- Implement the following builtins:
  - echo -n;
  - cd;
  - pwd;
  - export;
  - unset;
  - env;
  - exit.
## Compilation
```
make readline
```
>To install GNU Readline. GNU Readline is a software library that provides line-editing and history capabilities for interactive programs with a command-line interface, such as Bash. The function readline () prints a prompt and then reads and returns a single line of text from the user.
```
make
```
## Usage
```
./minishell
```
## Output
```
~/minishell$
```
