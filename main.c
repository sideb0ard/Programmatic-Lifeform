#include <readline/history.h>
#include <readline/readline.h>

#include "defjams.h"
#include "utils.h"

#include <pthread.h>
#include <stdbool.h>
#include <time.h>


int current_question = 0;

bool chapter1_started = false;
bool phone_answered = false;

void *phone_ringer()
{
    struct timespec ts;
    ts.tv_sec = 3;
    ts.tv_nsec = 0;

    int count = 0;

    while (!phone_answered) {
        printf("BRINNNNG BRINNNG\n");
        if ( count % 10 == 0 ) {
            printf(ANSI_COLOR_WHITE "The phone is ringing, Bertand. Would you like me to answer it?" ANSI_COLOR_RESET "\n" );
        }
        fflush(stdout);
        count++;
        nanosleep(&ts, NULL);
    }

    return NULL;
}

int main()
{
    char *line;
    while ((line = readline(COOL_COLOR_GREEN "$> " ANSI_COLOR_RESET)) !=
           NULL) {

        if (!chapter1_started) {
            pthread_t phone_th;
            if (pthread_create(&phone_th, NULL, phone_ringer, NULL)) {
                fprintf(stderr, "Nae threads, mate\n");
            }
            pthread_detach(phone_th);
            chapter1_started = true;
        }

        if (line[0] != 0) {
            add_history(line);
            interpret(line);
        }

    }

    return 0;
}

