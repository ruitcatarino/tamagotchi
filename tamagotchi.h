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
    int age_of_death;
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

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void print_menu(){
    printf("What would you like to do?\n");
    printf("1. Feed\n");
    printf("2. Play\n");
    printf("3. Quit\n");
    printf("(Any onther number) Do nothing\n");
}

void tamagotchi_status_and_menu(struct Tamagotchi* tamagotchi){

    if(tamagotchi->hunger > 60 || tamagotchi->happiness <= 25){
        tamagotchi_sad();
    }else {
        tamagotchi_happy();
    }
    printf("My name is %s, and I'm %d years old!\n",tamagotchi->name,tamagotchi->age);

    if (tamagotchi->hunger > 60){
        printf("Hunger: (%d%%)\n\tI am starving :( \n",tamagotchi->hunger);
    } else if (tamagotchi->hunger > 25){
        printf("Hunger: (%d%%)\n\tI am hungry \n",tamagotchi->hunger);
    } else{
        printf("Hunger: (%d%%)\n\tI am not hungry :)\n",tamagotchi->hunger);
    }

    if (tamagotchi->happiness > 50){
        printf("Happiness: (%d%%)\n\tI am happy :) \n",tamagotchi->happiness);
    } else if (tamagotchi->happiness > 25){
        printf("Happiness: (%d%%)\n\tI am a okay \n",tamagotchi->happiness);
    } else{
        printf("Happiness: (%d%%)\n\tI am sad :( \n",tamagotchi->happiness);
    }

    print_menu();
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

void feed(struct Tamagotchi *tamagotchi){
  if (tamagotchi->hunger < 5){
    tamagotchi->hunger=0;
  } else{
    tamagotchi->hunger-=5;
  }
    
}

void play(struct Tamagotchi *tamagotchi){
  if (tamagotchi->happiness > 96){
    tamagotchi->happiness=100;
  } else{
    tamagotchi->happiness+=5;
  }
}

void check_status(struct Tamagotchi *tamagotchi){
    clearScreen();
    
    if (tamagotchi->happiness <= 0){
        tamagotchi_sad();
        printf("I died from being unhappy!\n");
        tamagotchi->alive = false;
    } else if (tamagotchi->hunger >= 100){
        tamagotchi_sad();
        printf("I died from being too hungry!\n");
        tamagotchi->alive = false;
    } else if (tamagotchi->age >= tamagotchi->age_of_death){
        tamagotchi_sad();
        printf("I died from old age!\n");
        tamagotchi->alive = false;
    } else {
        tamagotchi_status_and_menu(tamagotchi);
    }
}

#endif //TAMAGOTCHI_TAMAGOTCHI_H
