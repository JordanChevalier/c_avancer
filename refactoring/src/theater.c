
#include "theater.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) (((x) >= (y)) ? (x) : (y))
#define GROUP_SIZE (3)

char *format_currency_number(float value)
{
    static char buffer[128];
    char temp[128];

    uint64_t integer_part = (uint64_t)value;
    double fractional = fabs(value - (double)integer_part);

    /* Format fractional part */
    int frac = (int)round(fractional * 100);

    /* Build integer part with grouping */
    char *p = temp + sizeof(temp) - 1;
    *p = '\0';

    int digit_count = 0;

    do
    {
        if (digit_count == GROUP_SIZE)
        {
            *--p = ',';
            digit_count = 0;
        }

        *--p = '0' + (integer_part % 10);
        integer_part /= 10;
        digit_count++;

    } while (integer_part > 0);

    snprintf(buffer, sizeof(buffer), "%s.%02d", p, frac);

    return buffer;
}
play_t *play_for(performance_t *performance, play_t *plays, uint32_t nb_plays)
{
    play_t *result;
    for (int j = 0; j < nb_plays; j++)
    {
        if (strcmp(plays[j].play_id, performance->play_id) == 0)
        {
            result = &plays[j];
        }
    }
    return result;
}

float amount_for(play_t *play, performance_t *performance, play_t *plays, uint32_t nb_plays)
{

    float this_amount = 0;
    switch (play_for(performance, plays, nb_plays)->type)
    {
    case TRAGEDY:
        this_amount = 40000;
        if (performance->audience > 30)
        {
            this_amount += 1000 * (performance->audience - 30);
        }
        break;
    case COMEDY:
        this_amount = 30000;
        if (performance->audience > 20)
        {
            this_amount += 10000 + 500 * (performance->audience - 20);
        }
        this_amount += 300 * performance->audience;
        break;
    }

    return this_amount;
}

void statement(char *result, invoice_t *invoice, play_t *plays, uint32_t nb_plays)
{
    float total_amount = 0;
    int volume_credits = 0;
    float this_amount = 0;
    performance_t *performance;

    sprintf(result, "Statement for %s\n", invoice->customer);

    for (int i = 0; i < MAX_NB_PERFORMANCES; i++)
    {
        performance = &invoice->performances[i];

        if (!performance->audience)
            continue;

        this_amount = 0;
        this_amount = amount_for(play_for(performance, plays, nb_plays), performance, plays, nb_plays);

        // add volume credits
        volume_credits += MAX(performance->audience - 30, 0);

        // add extra credit for every five comedy attendees
        if (play_for(performance, plays, nb_plays)->type == COMEDY)
            volume_credits += performance->audience / 5;

        // print line for this order
        sprintf(result, "%s %s: $%s (%d seats)\n", result, play_for(performance, plays, nb_plays)->name,
                format_currency_number(this_amount / 100), performance->audience);
        total_amount += this_amount;
    }

    sprintf(result, "%sAmount owed is $%s\n", result, format_currency_number(total_amount / 100));
    sprintf(result, "%sYou earned %d credits\n", result, volume_credits);
}
