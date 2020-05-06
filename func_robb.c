#include <string.h>
#include "func_robb.h"



void create()
{
    int i;
    rezult.horse = 0;
    rezult.sword = 0;
    rezult.necklace = 0;
    rezult.wife = 0;
    rezult.money = 0;
    rezult.rich = 0;
    FILE *fn = fopen("name.txt", "r");
    for (i=0; i<n; i++)
    {
        fgets(gang[i].name, 100, fn);
        gang[i].live = 1;
        gang[i].horse = rand()%10;
        gang[i].sword = rand()%15;
        gang[i].necklace = rand()%20;
        gang[i].wife = rand()%5;
        gang[i].money = rand()%1000;
        gang[i].rich = 500*gang[i].horse+50*gang[i].sword+100*gang[i].necklace-200*gang[i].wife+gang[i].money;
        rezult.horse += gang[i].horse;
        rezult.sword += gang[i].sword;
        rezult.necklace += gang[i].necklace;
        rezult.wife += gang[i].wife;
        rezult.money += gang[i].money;
        rezult.rich += gang[i].rich;
    }
    return;
};
void show()
{
    int i, c = 0;
    char *ll;
    for (i=0; i<n; i++)
    {
        if (gang[i].live == 1)
        {
            ll="yes";
            c++;
        }
        else ll="no";
        printf("%s%12s%4d%4d%4d%3d%6d%6d\n",gang[i].name, ll, gang[i].horse,gang[i].sword,gang[i].necklace,gang[i].wife,gang[i].money, gang[i].rich );
    }
    printf("\n%s%12d%4d%4d%4d%3d%6d%6d\n","", c, rezult.horse,rezult.sword,rezult.necklace,rezult.wife,rezult.money, rezult.rich );
    return;
};
void add()
{
    if (n < nn)
    {
        printf("Name: ");
        scanf("%s",gang[n].name);
        strcat(gang[n].name,"\n");
        gang[n].live = 1;
        printf("horse: ");
        scanf("%d",&gang[n].horse);
        printf("sword: ");
        scanf("%d",&gang[n].sword);
        printf("necklace: ");
        scanf("%d",&gang[n].necklace);
        printf("wife: ");
        scanf("%d",&gang[n].wife);
        printf("money: ");
        scanf("%d",&gang[n].money);
        gang[n].rich = 500*gang[n].horse+50*gang[n].sword+100*gang[n].necklace-200*gang[n].wife+gang[n].money;
        rezult.horse += gang[n].horse;
        rezult.sword += gang[n].sword;
        rezult.necklace += gang[n].necklace;
        rezult.wife += gang[n].wife;
        rezult.money += gang[n].money;
        rezult.rich += gang[n].rich;
        n++;
    }
    else  printf("gang set is closed");
    return;
};
void show_alive()
{
    int i;
    for(i=0; i<n; i++)
        if (gang[i].live == 1)
            printf("%s%12s%4d%4d%4d%3d%6d%6d\n",gang[i].name, "yes", gang[i].horse,gang[i].sword,gang[i].necklace,gang[i].wife,gang[i].money, gang[i].rich );
    return;
};
void show_some()
{
    char str[100];
    int i;
    char *ll;
    printf("Name: ");
    scanf("%s",str);
    strcat(str,"\n");
    for(i=0; i<n; i++)
        if (strcmp(gang[i].name,str) == 0)
        {
            if (gang[i].live == 1) ll="yes";
            else ll="no";
            printf("%s%12s%4d%4d%4d%3d%6d%6d\n",gang[i].name, ll, gang[i].horse,gang[i].sword,gang[i].necklace,gang[i].wife,gang[i].money, gang[i].rich );
        }
    return;
};
void kill()
{
    char str[100];
    int i;
    printf("Name: ");
    scanf("%s",str);
    strcat(str,"\n");
    for(i=0; i<n; i++)
        if (strcmp(gang[i].name,str) == 0)
        {
            gang[i].live = 0;
            rezult.horse -= gang[i].horse;
            rezult.sword -= gang[i].sword;
            rezult.necklace -= gang[i].necklace;
            rezult.wife -= gang[i].wife;
            rezult.money -= gang[i].money;
            rezult.rich -= gang[i].rich;
            break;
        }
    return;
};
void dives()
{
    int i;
    int max=0;
    for(i=0; i<n; i++)
        if (gang[i].rich > max && gang[i].live == 1) max=gang[i].rich;
    for(i=0; i<n; i++)
        if (gang[i].rich == max && gang[i].live == 1)
            printf("%s%12s%4d%4d%4d%3d%6d%6d\n",gang[i].name, "yes", gang[i].horse,gang[i].sword,gang[i].necklace,gang[i].wife,gang[i].money, gang[i].rich );
    return;
};

