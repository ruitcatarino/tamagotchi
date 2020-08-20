#ifndef TAMAGOTCHI_TAMAGOTCHI_H
#define TAMAGOTCHI_TAMAGOTCHI_H

#include <stdio.h>
#include <string.h>

struct Tamagotchi{

    char name[50];
    int age;
    int money;
    int hungry;
    int mood;
    int bathroom;
};

void tamagotchi_sad(){
    printf("  .^._.^.\n"
           "  | ; ; |\n"
           " (  ---  )\n"
           " .'     '.\n"
           " |/     \\|\n"
           "  \\ /-\\ /\n"
           "   V   V\n");
}

void tamagotchi_happy(){
    printf("  .^._.^.\n"
           "  | . . |\n"
           " (  \\_/  )\n"
           " .'     '.\n"
           " |/     \\|\n"
           "  \\ /-\\ /\n"
           "   V   V\n");
}

void tamagotchi_status(struct Tamagotchi* tamagotchi){
    printf("I am %d years old\n",tamagotchi->age);
    printf("I am not hungry :) (%d%%)\n",tamagotchi->hungry);
    printf("I don't have to take a bath :) (%d%%)\n",tamagotchi->bathroom);
    printf("I am happy :) (%d%%)\n",tamagotchi->mood);
    printf("You have $%d",tamagotchi->money);
}

void tamagotchi_name(struct Tamagotchi* tamagotchi){
    char name_var[11];

    printf("Hello, my name is ...\n");

    scanf(" %[^\n]s",name_var);

    while (strlen(name_var)>10 || strlen(name_var)<0){
        printf("Please choose another name I wont remember that\nMy name must be between 0 and 10 characters.\n");

        scanf(" %[^\n]s",name_var);
    }

    strcpy(tamagotchi->name,name_var);

    tamagotchi_happy();

    printf("My name is %s!\n",tamagotchi->name);
}

void create(struct Tamagotchi* tamagotchi){

    tamagotchi_name(tamagotchi);

    tamagotchi->age=0;
    tamagotchi->bathroom=100;
    tamagotchi->hungry=100;
    tamagotchi->money=100;
    tamagotchi->mood=100;
}

#endif //TAMAGOTCHI_TAMAGOTCHI_H
