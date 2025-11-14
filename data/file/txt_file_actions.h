#ifndef TXT_FILE_ACTIONS_H
#define TXT_FILE_ACTIONS_H
#include <stdio.h>


#define FILE_BOOL int
#define FILE_SUCCESS 1
#define FILE_ERROR 0

/**
 *Interfaccia per definire azioni sui file .txt
*/


typedef struct {
    char *file_path;

    /**
     * Per le operazioni che non lo richiedono sarà NULL
     */
    char *txt;
} TxtFileActionParams;

FILE *open_file(char *file_path, char *mode);

FILE_BOOL read(TxtFileActionParams *params);

FILE_BOOL write(TxtFileActionParams *params);

FILE_BOOL append(TxtFileActionParams *params);

FILE_BOOL clear(TxtFileActionParams *params);

FILE_BOOL delete(TxtFileActionParams *params);

FILE_BOOL rewrite(TxtFileActionParams *params);


#endif
