#ifndef THEATER_H
#define THEATER_H

#include <stdint.h>

#define MAX_ID_LENGTH (32)
#define MAX_NAME_LENGTH (128)
#define MAX_NB_PERFORMANCES (64)

typedef enum {
    COMEDY,
    TRAGEDY,
} play_type_t;

typedef struct {
    char play_id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    play_type_t type;
} play_t;

typedef struct {
    char play_id[MAX_ID_LENGTH];
    uint32_t audience;
} performance_t;

typedef struct {
    char customer[MAX_NAME_LENGTH];
    performance_t performances[MAX_NB_PERFORMANCES];
} invoice_t;

void statement(char* result, invoice_t* invoice, play_t* plays, uint32_t nb_plays);

#endif /* THEATER_H */
