#include <stdlib.h>
#include <string.h>
#include "Token.h"

void cldeparser_container_add(cldeparser_TokenContainer *container, cldeparser_Token *token) {
    container->last->next = token;
    ++container->count;
}

void cldeparser_container_rem(cldeparser_TokenContainer *container, cldeparser_Token *token) {

}

cldeparser_Token *cldeparser_token_create(const char *value) {
    cldeparser_Token *token = (cldeparser_Token *) calloc(1, sizeof(cldeparser_Token));
    token->next = NULL;
    token->value = strdup(value);
    return token;
}

void cldeparser_token_destroy(cldeparser_Token *token) {
    token->next = NULL;
    free(token->value);
    free(token);
}
