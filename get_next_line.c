#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char *line;
    static char *stash;
    char buff[BUFFER_SIZE + 1];
    char *temp;

    stash = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || > 1024)
        return (NULL);
    

    return (line);
}