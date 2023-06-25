//
//  main.c
//  trideni_spojak
//
//Na vstupu dostanete zadáno několik čísel (předem neznámý počet). Jednotlivá čísla mohou být oddělena buďto mezerami, nebo konci řádků. Čísla načtěte a setřiďte (dle jejich číselné hodnoty). Konec vstupu tradičně poznáte dle EOF nebo prázndého řádku. Třiďte vzestupně a jednotlivá čísla na výstupu oddělujte mezerami. Kupříkladu na vstup "5 1 3 5 4 6 2" bude výstup "1 2 3 4 5 5 6 ".
//  Created by Natálie Smolíková on 06.11.2021.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct spojovy_seznam{
    int hod;
    struct spojovy_seznam *next;
} spojak;

spojak* init()
{return NULL;}

spojak* insert(int co, spojak* hlava) {
    spojak *pom, *hlava2 = hlava;
    if (hlava == NULL)
{
    hlava = malloc(sizeof(spojak));
    hlava -> hod = co;
    hlava -> next = NULL;
    return hlava;
}
    if ((hlava ->hod ) >=co)
    {
        pom = malloc(sizeof(spojak));
        pom -> hod = co;
        pom -> next = hlava;
        return pom;
    }
    while ((hlava ->next !=NULL) &&((hlava ->next -> hod) < co))
    {
        hlava = hlava -> next;
    }
    pom = malloc(sizeof(spojak));
    pom -> hod = co;
    pom ->next = hlava -> next;
    hlava -> next = pom;
    return hlava2;
}



int main() {
    spojak *posl =init();
    int vstup;
   

   while ((scanf("%d", &vstup)) != EOF)
        posl = insert(vstup, posl);
    
    while(posl !=NULL)
    {printf("%d ", posl -> hod);
        posl = posl -> next;
    }
    
    
    
    return 0;
}
