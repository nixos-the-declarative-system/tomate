/* tomate — a Pomodoro timer for the terminal. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define VERSION "1.2.0"
#define DEFAULT_MINUTES 25

static void usage(FILE *out)
{
    fputs("usage: tomate [minutes]\n"
          "       tomate --version\n\n"
          "Starts a work timer (25 minutes by default).\n",
          out);
}

int main(int argc, char **argv)
{
    long minutes = DEFAULT_MINUTES;

    if (argc > 2) {
        usage(stderr);
        return 2;
    }
    if (argc == 2) {
        if (strcmp(argv[1], "--version") == 0) {
            puts("tomate " VERSION);
            return 0;
        }
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            usage(stdout);
            return 0;
        }
        char *end = NULL;
        minutes = strtol(argv[1], &end, 10);
        if (*end != '\0' || minutes < 1 || minutes > 999) {
            fprintf(stderr, "tomate: '%s' is not a duration in minutes.\n",
                    argv[1]);
            return 2;
        }
    }

    for (long remaining = minutes * 60; remaining > 0; remaining--) {
        printf("\r🍅  %02ld:%02ld — working.\033[K", remaining / 60, remaining % 60);
        fflush(stdout);
        sleep(1);
    }

    printf("\r🍅  00:00 — break!    \a\n");
    return 0;
}
