#include <stdio.h>

#include "data/api/api.h"
#include "data/file/txt_file_actions.h"
#include "util/string/methods.h"

#define RAW_STR_LENGTH 256  // Lunghezza stringa raw
#define EXIT_CHARACTER 'z'

#define BOOL int
#define TRUE 1
#define FALSE 0


/**
 *
 * Messaggio Benvenuto con chiamata Api
 * inserimento path
 * apertura file
 * edit
 */
int main(void) {
    print_frr(get_welcome_message());

    printf(", inserisci Path del file .txt\n: ");


    char f_path[RAW_STR_LENGTH];

    scanf_str(f_path);

    printf("Inserisci la scelta: "
        "\n a) Read"
        "\n b) Write"
        "\n c) Append"
        "\n d) Clear"
        "\n e) Delete"
        "\n z) Exit"
    );


    char choice[RAW_STR_LENGTH];
    do {
        printf("\nScelta: ");

        scanf_str(choice);

        switch (choice[0]) {
            //READ
            case 'a': {
                TxtFileActionParams params = {
                    .file_path = f_path,
                    .txt = NULL
                };
                if (read(&params) == FILE_ERROR) {
                    print_err("Errore nell'aprire il file");
                    return -1;
                }
                break;
            }
            //WRITE
            case 'b': {
                char write_file_buffer[RAW_STR_LENGTH];
                printf("Inserisci testo\n :");
                scanf_str(write_file_buffer);
                TxtFileActionParams params = {
                    .file_path = f_path,
                    .txt = write_file_buffer
                };
                if (write(&params) == FILE_ERROR) {
                    print_err("Errore nell'aprire il file");
                    return -1;
                }

                break;
            }

            //APPEND
            case 'c': {
                char write_file_buffer[RAW_STR_LENGTH];
                printf("Inserisci testo\n :");
                scanf_str(write_file_buffer);
                TxtFileActionParams params = {
                    .file_path = f_path,
                    .txt = write_file_buffer
                };
                if (append(&params) == FILE_ERROR) {
                    print_err("Errore nell'aprire il file");
                    return -1;
                }
                break;
            }
            //CLEAR
            case 'd': {
                TxtFileActionParams params = {
                    .file_path = f_path,
                    .txt = NULL
                };
                if (clear(&params) == FILE_ERROR) {
                    print_err("Errore nell'aprire il file");
                    return -1;
                }
                break;
            }

            //DELETE
            case 'e': {
                TxtFileActionParams params = {
                    .file_path = f_path,
                    .txt = NULL
                };
                if (delete(&params) == FILE_ERROR) {
                    print_err("Errore nell'aprire il file");
                    return -1;
                }
                break;
            }
            default: {
                /**
                 *Stampa solo se è diverso dal carattere di uscita
                 *Stampa asincrona
                 **/
                if (choice[0] != EXIT_CHARACTER) print_err("ERROR");
                break;
            }
        }
    } while (choice[0] != EXIT_CHARACTER);

    return 0;
}
