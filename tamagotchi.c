#include "tamagotchi.h"

void create(struct Tamagotchi* tamagotchi){

    tamagotchi_name(tamagotchi);

    tamagotchi->age=0;
    tamagotchi->hunger=0;
    tamagotchi->happiness=100;
    tamagotchi->alive=true;
}

void life(struct Tamagotchi* tamagotchi){

    int choice;

    srand(time(0));

    int ageofdeath = rand() % 61 + 50;

    while(tamagotchi->alive){

        printf("What would you like to do?\n");
        printf("1. Feed\n");
        printf("2. Play\n");
        printf("3. Quit\n");
        printf("(Any onther number) Do nothing\n");

        scanf("%d", &choice);

        if (choice == 1) {
            feed(tamagotchi);
        } else if (choice == 2) {
            play(tamagotchi);
        } else if (choice == 3) {
            break;
        } else{
            printf("I miss you :/ \n");
        }

        if(tamagotchi->age != 0){
            tamagotchi->hunger+=3;
            tamagotchi->happiness-=3;
            tamagotchi->age++;
        }else{
            tamagotchi->age++;
        }

        if (tamagotchi->happiness <= 0){
            tamagotchi_sad();
            printf("I died from being unhappy!\n");
            tamagotchi->alive=false;
        } else if (tamagotchi->hunger >= 100){
            tamagotchi_sad();
            printf("I died from being too hungry!\n");
            tamagotchi->alive=false;
        } else if (tamagotchi->age >= ageofdeath){
            tamagotchi_sad();
            printf("I died from old age!\n");
            tamagotchi->alive=false;
        } else{
            tamagotchi_status(tamagotchi);
        }

    }

}

int main() {

    struct Tamagotchi tamagotchi;

    create(&tamagotchi);

    tamagotchi_status(&tamagotchi);

    life(&tamagotchi);

    return 0;
}