
![Banner](https://github.com/byaliego/42-project-badges/blob/main/covers/cover-get_next_line-bonus.png?raw=true)


## Table of Contents
- [Description](#description)
- [Usage](#usage)
- [Function Prototype](#function-prototype)
- [Return Value](#return-value)
- [Example](#example)
- [Notes](#notes)
- [Author](#author)

## Description

`get_next_line` is a function that reads a line from a file descriptor and returns it without the newline character. The function is part of the [42](https://www.42.fr/) curriculum and is designed to enhance your understanding of file manipulation and dynamic memory allocation.

## Usage

To use the `get_next_line` function in your project, follow these steps:

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/YD-S/Get_Next_Line

2. Include the get_next_line.h header file in your project

   ```bash
    #include "get_next_line.h"

3. Compile your project with the get_next_line.c file:

    ```bash
    gcc your_file.c get_next_line.c get_next_line_utils.c -o your_executable

4. Run your executable

## Function prototype

    int get_next_line(int fd, char **line);
## Return Value
The function returns:

1 if a line is read successfully.
0 if the end of the file is reached.
-1 in case of an error.
## Example

    #include "get_next_line.h"
    #include <fcntl.h>
    int main(void)
    {
        int fd;
        char *line;

        fd = open("example.txt", O_RDONLY);
        while (get_next_line(fd, &line) > 0)
        {
            printf("%s\n", line);
            free(line);
        }
        close(fd);
        return 0;
    }

## Notes
Ensure that you free the memory allocated for the line using free() after you're done using it to prevent memory leaks.

The function uses dynamic memory allocation, so make sure to handle errors properly.

You can find additional information and resources on file I/O and dynamic memory allocation to enhance your understanding of the project.

## Author

Yashdev Singh (Ysingh)

