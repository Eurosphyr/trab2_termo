#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#define TAMANHO 5
#define NUM_TENTATIVAS 6
#define LIMPAR_TECLADO (TAMANHO + 32)

#define COR_RESET()            \
    do                         \
    {                          \
        textbackground(BLACK); \
        textcolor(WHITE);      \
    } while (0)
#define COR_VERDE()            \
    do                         \
    {                          \
        textbackground(GREEN); \
        textcolor(BLACK);      \
    } while (0)
#define COR_AMARELO()           \
    do                          \
    {                           \
        textbackground(YELLOW); \
        textcolor(BLACK);       \
    } while (0)
#define COR_CINZA()                \
    do                             \
    {                              \
        textbackground(LIGHTGRAY); \
        textcolor(BLACK);          \
    } while (0)

#define LIMPAR_TELA() clrscr()