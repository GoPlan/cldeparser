//
// Created by LE, Duc Anh on 7/29/15.
//

#ifndef CLDEPARSER_TOKEN_H
#define CLDEPARSER_TOKEN_H

typedef struct cldeparser_Token_t cldeparser_Token;
typedef struct cldeparser_TokenContainer_t cldeparser_TokenContainer;
typedef struct cldeparser_TokenContainerCurrent_t cldeparser_ContainerCurrentToken;

struct cldeparser_Token_t {
    int position;
    char *value;
    cldeparser_Token *next;
};

struct cldeparser_TokenContainerCurrent_t {
    int position;
    cldeparser_Token *token;
};

struct cldeparser_TokenContainer_t {
    int count;
    cldeparser_Token *start;
    cldeparser_Token *last;
    cldeparser_ContainerCurrentToken current;
};

// Container functions
void cldeparser_container_add(cldeparser_TokenContainer *container, cldeparser_Token *token);
void cldeparser_container_rem(cldeparser_TokenContainer *container, cldeparser_Token *token);

// Token functions
cldeparser_Token *cldeparser_token_create(const char *value);
void cldeparser_token_destroy(cldeparser_Token *token);

#endif //CLDEPARSER_TOKEN_H
