#ifndef METHODS_H
#define METHODS_H
#include <string.h>


/**
 * @param path [Inserito con fgets]
 */
void trim_str(char *path) {
    // Rimuovi newline
    path[strcspn(path, "\n")] = '\0';

    unsigned int len = strlen(path);
    if (path[0] == '"') {
        memmove(path, path + 1, len); // shift a sinistra
        len--;
    }
    if (len > 0 && path[len - 1] == '"') {
        path[len - 1] = '\0';
    }
}

/**
 * Macro che ricava automaticamente la lunghezza dell'array
 */
#define scanf_str(str) _scanf_str(str, sizeof(str))

/**
 * Versione privata: non usare direttamente
 */
static void _scanf_str(char *str, unsigned long long max_len) {
    fgets(str, max_len, stdin);
    str[strcspn(str, "\n")] = '\0';
    trim_str(str);
}



void print_err(const char *txt) {
    fprintf(stderr, "%s", txt);
    Sleep(10);
}


/**
 * Stampa e pulisce
 */
void print_frr(char *txt_to_free) {
    printf("%s", txt_to_free);
    free(txt_to_free);
}

#endif
