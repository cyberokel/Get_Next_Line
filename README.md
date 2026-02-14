# Get Next Line

_This project has been created as part of the 42 curriculum by akhalidi._

## Description

`get_next_line` reads and returns one line at a time from a file descriptor. It uses a static variable to store leftover data between calls, enabling efficient line-by-line file reading without re-reading or loading the entire file into memory.

## Compilation
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Different buffer sizes:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10000 get_next_line.c get_next_line_utils.c
```

## Usage
```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm

The implementation uses three helper functions:

1. **read_and_join** - Reads from fd and accumulates data in static variable until '\n' or EOF
2. **extract_line** - Extracts and returns the line (including '\n')
3. **update_stored** - Saves remaining data for next call

**Flow:**
- Read chunks of BUFFER_SIZE bytes
- Store in static variable
- When '\n' found, extract line and save remainder
- Return NULL when nothing left to read

**Why this approach:**
- Efficient: reads only what's needed
- Memory-safe: frees all allocated memory
- Flexible: works with any BUFFER_SIZE (1 to 10000000+)
- Handles edge cases: empty files, no final newline, long lines

## Resources

- `man 2 read`, `man 3 malloc`, `man 3 free`
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)
- [File I/O in C](https://www.tutorialspoint.com/cprogramming/c_file_io.htm)

**AI Usage:** Claude was used only for hints and concept explanations (static variables, read() behavior, pointer arithmetic, edge cases). All code was written independently through learning and debugging.
