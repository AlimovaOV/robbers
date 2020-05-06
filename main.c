#include <windows.h>
#include "func_robb.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int item;
    do
    {
        printf("\n\n1 - create\n2 - show\n3 - add\n4 - show alive\n5 - show some\n6 - kill\n7 - dives\n0 - exit\n");
        scanf("%d",&item);
        switch(item)
        {
        case 1:
            printf("crowd = ");
            scanf("%d",&n);
            create();
            break;
        case 2:
            show();
            break;
        case 3:
            add();
            break;
        case 4:
            show_alive();
            break;
        case 5:
            show_some();
            break;
        case 6:
            kill();
            break;
        case 7:
            dives();
            break;
        }
    }
    while (item!=0);
    return 0;
}
