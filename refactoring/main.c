#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "theater.h"

play_t plays[] = {
    { .play_id = "hamlet", .name = "Hamlet", .type = TRAGEDY },
    { .play_id = "as-like", .name = "As You Like it", .type = COMEDY },
    { .play_id = "othello", .name = "Othello", .type = TRAGEDY },
};

invoice_t invoice = {
    .customer = "BigCo",
    .performances = {
        { .play_id = "hamlet", .audience = 55 },
        { .play_id = "as-like", .audience = 35 },
        { .play_id = "othello", .audience = 40 },
    },
};

int main(void)
{
    char result[4096];

    statement(result, &invoice, plays, sizeof(plays) / sizeof(plays[0]));
    puts(result);

    assert(!strcmp(result,
        "Statement for BigCo\n Hamlet: $650.00 (55 seats)\n As You Like it: $580.00 (35 seats)\n Othello: $500.00 (40 seats)\nAmount owed is $1,730.00\nYou earned 47 credits\n"));

    printf("\r\n\033[42;97mSUCCESS!!!\033[0m\r\n\r\n");

    return EXIT_SUCCESS;
}
