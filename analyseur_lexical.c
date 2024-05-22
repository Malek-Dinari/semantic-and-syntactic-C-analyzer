#include "analyseur_lexical.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Définition des codes pour les unités lexicales
#define PROGRAM 1
#define BEGIN 2
#define END 3
#define IF 4
#define THEN 5
#define ELSE 6
#define WHILE 7
#define DO 8
#define READ 9
#define READLN 10
#define WRITE 11
#define WRITELN 12
#define ID 13
#define SEMICOLON 14
#define COLON 15
#define COMMA 16
#define ASSIGN 17
#define LEFT_PAREN 18
#define RIGHT_PAREN 19
#define OP_REL 20
#define OP_ADD 21
#define OP_MUL 22
#define INTEGER 23
#define CHAR 24
#define EPSILON 25
#define NUMBER 26




// Fonction pour afficher l' unité lexicale avec son type
void printUnite (int unite) {
    switch (unite) {
        case PROGRAM:
            printf("PROGRAM\n");
            break;
        case BEGIN:
            printf("BEGIN\n");
            break;
        case END:
            printf("END\n");
            break;
        case IF:
            printf("IF\n");
            break;
        case THEN:
            printf("THEN\n");
            break;
        case ELSE:
            printf("ELSE\n");
            break;
        case WHILE:
            printf("WHILE\n");
            break;
        case DO:
            printf("DO\n");
            break;
        case READ:
            printf("READ\n");
            break;
        case READLN:
            printf("READLN\n");
            break;
        case WRITE:
            printf("WRITE\n");
            break;
        case WRITELN:
            printf("WRITELN\n");
            break;
        case ID:
            printf("ID\n");
            break;
        case SEMICOLON:
            printf("SEMICOLON\n");
            break;
        case COLON:
            printf("COLON\n");
            break;
        case COMMA:
            printf("COMMA\n");
            break;
        case ASSIGN:
            printf("ASSIGN\n");
            break;
        case LEFT_PAREN:
            printf("LEFT_PAREN\n");
            break;
        case RIGHT_PAREN:
            printf("RIGHT_PAREN\n");
            break;
        case OP_REL:
            printf("OP_REL\n");
            break;
        case OP_ADD:
            printf("OP_ADD\n");
            break;
        case OP_MUL:
            printf("OP_MUL\n");
            break;
        case INTEGER:
            printf("INTEGER\n");
            break;
        case CHAR:
            printf("CHAR\n");
            break;
        case EPSILON:
            printf("EPSILON\n");
            break;
        case NUMBER:
            printf("NUMBER\n");
            break;
        default:
            printf("Unité inconnue\n");
    }
}

// Fonction principale de l'analyseur lexical
void lexicalAnalyzer(char* input) {
    char buffer[50];
    int bufferIndex = 0;

    for (int i = 0; i < strlen(input); ++i) {
        if (isalpha(input[i])) {
            buffer[bufferIndex++] = input[i];
        } else if (isdigit(input[i])) {
            buffer[bufferIndex++] = input[i];
        } else {
            buffer[bufferIndex] = '\0';
            bufferIndex = 0;

            if (buffer[0] != '\0') {
                if (strcmp(buffer, "program") == 0) {
                    printUnite(PROGRAM);
                } else if (strcmp(buffer, "begin") == 0) {
                    printUnite(BEGIN);
                } else if (strcmp(buffer, "end") == 0) {
                    printUnite(END);
                } else if (strcmp(buffer, "if") == 0) {
                    printUnite(IF);
                } else if (strcmp(buffer, "then") == 0) {
                    printUnite(THEN);
                } else if (strcmp(buffer, "else") == 0) {
                    printUnite(ELSE);
                } else if (strcmp(buffer, "while") == 0) {
                    printUnite(WHILE);
                } else if (strcmp(buffer, "do") == 0) {
                    printUnite(DO);
                } else if (strcmp(buffer, "read") == 0) {
                    printUnite(READ);
                } else if (strcmp(buffer, "readln") == 0) {
                    printUnite(READLN);
                } else if (strcmp(buffer, "write") == 0) {
                    printUnite(WRITE);
                } else if (strcmp(buffer, "writeln") == 0) {
                    printUnite(WRITELN);
                } else if (strcmp(buffer, "integer") == 0) {
                    printUnite(INTEGER);
                } else if (strcmp(buffer, "char") == 0) {
                    printUnite(CHAR);
                } else {
                    printUnite(ID);
                }
            }

            //Conditions pour les symboles spéciaux et les opérateurs
            else if (input[i] == ';') {
                printUnite(SEMICOLON);
            } else if (input[i] == ':') {
                printUnite(COLON);
            } else if (input[i] == ',') {
                printUnite(COMMA);
            } else if (input[i] == '=') {
                // Vérifiez si le prochain caractère est aussi '=' pour les opérateurs relationnels
                if (i + 1 < strlen(input) && input[i + 1] == '=') {
                    printUnite(OP_REL);
                    ++i; // Ignorer le caractère '=' déjà lu
                } else {
                    printUnite(ASSIGN);
                }
            } else if (input[i] == '(') {
                printUnite(LEFT_PAREN);
            } else if (input[i] == ')') {
                printUnite(RIGHT_PAREN);
            } else if (input[i] == '+' || input[i] == '-') {
                printUnite(OP_ADD);
            } else if (input[i] == '*' || input[i] == '/') {
                printUnite(OP_MUL);
            }
        }
    }
}

int main() {
    char input[] = "program myProgram ; begin if x then write(y) ; end";
    lexicalAnalyzer(input);

    return 0;
}
