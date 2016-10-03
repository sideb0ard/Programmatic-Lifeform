#include "defjams.h"
#include "utils.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void strim(const char *input, char *result)
{
    int flag = 0;

    while (*input) {
        if (!isspace((unsigned char)*input) && flag == 0) {
            *result++ = *input;
            flag = 1;
        }
        input++;
        if (flag == 1) {
            *result++ = *input;
        }
    }

    while (1) {
        result--;
        if (!isspace((unsigned char)*input) && flag == 0) {
            break;
        }
        flag = 0;
        *result = '\0';
    }
}

void print_help()
{
    printf("Welcome alive, Bertrand!\n");
}

int exxit()
{
    printf(COOL_COLOR_GREEN "\nzzzzzzzzzzzt.n" ANSI_COLOR_RESET);
    exit(0);
}

void interpret(char *line)
{
    char *tok, *last_s;
    char *sep = ",";
    for (tok = strtok_r(line, sep, &last_s); tok;
         tok = strtok_r(NULL, sep, &last_s)) {
        char *trim_tok = calloc(strlen(tok), sizeof(char));
        strim(tok, trim_tok);

        // else if (strcmp(trim_tok, "midi") == 0) {
        //     //// run the MIDI event looprrr...
        //     pthread_t midi_th;
        //     if (pthread_create(&midi_th, NULL, midiman, NULL)) {
        //         fprintf(stderr, "Errrr, wit tha midi..\n");
        //         return;
        //     }
        //     pthread_detach(midi_th);
        // }

        if (strcmp(trim_tok, "exit") == 0) {
            exxit();
        }
        else if (strcmp(trim_tok, "help") == 0) {
            print_help();
        }

        //// SIGNAL START
        //regmatch_t ns_match[3];
        //regex_t ns_cmdtype_rx;
        //regcomp(&ns_cmdtype_rx,
        //        "^(bitwize|sine|sawd|sawu|tri|square) ([[:digit:].]+)$",
        //        REG_EXTENDED | REG_ICASE);
        //if (regexec(&ns_cmdtype_rx, trim_tok, 3, ns_match, 0) == 0) {

        //    float val = 0;
        //    char cmd[20];
        //    SBMSG *msg = new_sbmsg();
        //    sscanf(trim_tok, "%s %f", cmd, &val);
        //    msg->freq = val;

        //    strncpy(msg->cmd, "timed_sig_start", 19);
        //    printf("PARAMZZZ %s", cmd);
        //    strncpy(msg->params, cmd, 10);
        //    thrunner(msg);
        //}
    }
}


