#ifndef TAMAGOTCHI_TAMAGOTCHI_H
#define TAMAGOTCHI_TAMAGOTCHI_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct Tamagotchi{

    char name[50];
    int age;
    int hunger;
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

    if(tamagotchi->hunger > 60 || tamagotchi->happiness <= 25){
        tamagotchi_sad();
    }else {
        tamagotchi_happy();
    }
    printf("My name is %s, and I'm %d years old!\n",tamagotchi->name,tamagotchi->age);

    if (tamagotchi->hunger > 60){
        printf("I am starving :( (%d%%)\n",tamagotchi->hunger);
    } else if (tamagotchi->hunger > 25){
        printf("I am hungry (%d%%)\n",tamagotchi->hunger);
    } else{
        printf("I am not hungry :) (%d%%)\n",tamagotchi->hunger);
    }

    if (tamagotchi->happiness > 50){
        printf("I am happy :) (%d%%)\n",tamagotchi->happiness);
    } else if (tamagotchi->happiness > 25){
        printf("I am a okay (%d%%)\n",tamagotchi->happiness);
    } else{
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
}

void feed(struct Tamagotchi *t) {
  if (t->hunger < 5) {
    t->hunger=8;
  } else{
    t->hunger-=5;
  }
    
}

void play(struct Tamagotchi *t) {
  if (t->happiness > 96) {
    t->happiness=103;
  } else{
    t->happiness+=5;
  }
}

#endif //TAMAGOTCHI_TAMAGOTCHI_H
