#include "tamagotchi.h"

void create(struct Tamagotchi* tamagotchi){

    tamagotchi_name(tamagotchi);

    tamagotchi->age=0;
    tamagotchi->bathroom=100;
    tamagotchi->hungry=100;
    tamagotchi->money=100;
    tamagotchi->mood=100;
    tamagotchi->life=100;
    tamagotchi->alive=true;
}

void life(struct Tamagotchi* tamagotchi){
    while(tamagotchi->alive){
        if (tamagotchi->mood==0 || tamagotchi->bathroom==0 || tamagotchi->hungry==0){
            tamagotchi->alive=false;
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