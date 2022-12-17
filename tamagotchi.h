#ifndef TAMAGOTCHI_TAMAGOTCHI_H
#define TAMAGOTCHI_TAMAGOTCHI_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Tamagotchi{

    char name[50];
    int age;
    int hungry;
    int bathroom;
    int happiness;
    bool alive;

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
    printf("My name is %s, and I'm %d years old!\n",tamagotchi->name,tamagotchi->age);

    if (tamagotchi->hungry > 50){
        printf("I am not hungry :) (%d%%)\n",tamagotchi->hungry);
    } else if (tamagotchi->hungry > 25){
        printf("I am hungry (%d%%)\n",tamagotchi->hungry);
    } else{
        printf("I am starving :( (%d%%)\n",tamagotchi->hungry);
    }

    if (tamagotchi->bathroom > 50){
        printf("I don't have to take a bath :) (%d%%)\n",tamagotchi->bathroom);
    } else if (tamagotchi->bathroom > 25){
        printf("I am a bit dirty (%d%%)\n",tamagotchi->bathroom);
    } else{
        printf("I really need to take a bath :( (%d%%)\n",tamagotchi->bathroom);
    }

    if (tamagotchi->happiness > 50){
        printf("I am happy :) (%d%%)\n",tamagotchi->happiness);
    } else if (tamagotchi->happiness > 25){
        printf("I am a okay (%d%%)\n",tamagotchi->happiness);
    } else{
        tamagotchi_sad();
        printf("I am sad :( (%d%%)\n",tamagotchi->happiness);
    }
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
}

#endif //TAMAGOTCHI_TAMAGOTCHI_H
