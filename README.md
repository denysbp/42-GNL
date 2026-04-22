*This project has been created as part of the 42 curriculum by deferrei.*

## Description

`get_next_line` is a project from the 42 curriculum whose goal is to implement a function capable of reading a file descriptor line by line.

The main objective is to understand how static storage, file descriptors, dynamic memory allocation, and buffered reading work in C. The function must return one line at a time, including the terminating newline character `\n` when it exists, and return `NULL` when there is nothing left to read or when an error occurs.

This project also helps develop a deeper understanding of memory management, string manipulation, and the behavior of `read()` with different `BUFFER_SIZE` values.

## Instructions

### Compilation

Example with a test main:

```bash
cc get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42 programm.c
```

## Resources

<a href= "https://www.jbiet.edu.in/coursefiles/cse/HO/cse1/CP5.pdf">Artigo 1</a>
<a href= "https://www.freecodecamp.org/portuguese/news/manipulacao-de-arquivos-em-c-como-abrir-e-fechar-arquivos-e-escrever-algo-neles/">Artigo 2</a>

AI Usage

AI was used as a support tool for:

understanding edge cases in memory management
debugging issues found with Valgrind
clarifying the behavior of read()

<b>The implementation logic and debugging process were developed manually. AI was only used to support understanding and improve clarity.</b>

## Algorithm Explanation and Justification

### How it works

A static variable (received) stores leftover data between function calls.
Each call checks if a newline already exists in received.
If not, the function reads from the file descriptor into a buffer of size BUFFER_SIZE.
The buffer is appended to received.
Once a newline is found (or EOF is reached), the function extracts one line.
The remaining content is stored again in received for the next call.
If nothing is left, the memory is freed and NULL is returned.