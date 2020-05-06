#ifndef FUNC_ROBB_H_INCLUDED
#define FUNC_ROBB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define nn 40
int n;

typedef struct
{
    char name[100];
    int live;
    int horse;
    int sword;
    int necklace;
    int wife;
    int money;
    int rich;
} Robber;

Robber gang[nn], rezult;

void create();
void show();
void add();
void show_alive();
void show_some();
void kill();
void dives();

#endif // FUNC_ROBB_H_INCLUDED

