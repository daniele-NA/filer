#include "txt_file_actions.h"


/**
 *Impl dell'interfaccia
 **/

#define READ_FILE_BUFFER 512


/**
 *Se è diverso da NULL allora è valido
 */
FILE *open_file(char *file_path, char *mode) {
    /**
     *Check se il file è disponibile
     */
    return fopen(file_path, mode);
}

FILE_BOOL read(TxtFileActionParams *params) {
    FILE *f_pt = open_file(params->file_path, "r");
    if (f_pt == NULL) {
        return FILE_ERROR;
    }

    char buffer[READ_FILE_BUFFER];

    while (fgets(buffer, READ_FILE_BUFFER, f_pt) != NULL) {
        printf("%s", buffer);
    }

    fclose(f_pt);
    return FILE_SUCCESS;
}

FILE_BOOL write(TxtFileActionParams *params) {
    FILE *f_pt = open_file(params->file_path, "w");
    if (f_pt == NULL || params->txt == NULL) {
        return FILE_ERROR;
    }
    fputs(params->txt, f_pt);
    fclose(f_pt);
    return FILE_SUCCESS;
}

FILE_BOOL append(TxtFileActionParams *params) {
    if (params->txt == NULL) {
        return FILE_ERROR;
    }

    FILE *f_pt = fopen(params->file_path, "a"); // apertura in append
    if (f_pt == NULL) {
        return FILE_ERROR;
    }

    fputs(params->txt, f_pt);

    fclose(f_pt);
    return FILE_SUCCESS;
}


FILE_BOOL clear(TxtFileActionParams *params) {
    FILE *f_pt = open_file(params->file_path, "w");
    if (f_pt == NULL) {
        return FILE_ERROR;
    }
    fputs("", f_pt);
    fclose(f_pt);
    return FILE_SUCCESS;
}

FILE_BOOL delete(TxtFileActionParams *params) {
    // Attempt to delete the file
    if (remove(params->file_path) == 0) {
        return FILE_SUCCESS;
    }
    return FILE_ERROR;
}
