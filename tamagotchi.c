#include "tamagotchi.h"

void create(struct Tamagotchi* tamagotchi){

    tamagotchi_name(tamagotchi);

    tamagotchi->age=0;
    tamagotchi->hungry=100;
    tamagotchi->bathroom=100;
    tamagotchi->happiness=100;
    tamagotchi->alive=true;
}

void life(struct Tamagotchi* tamagotchi){
    while(tamagotchi->alive){
        if (tamagotchi->happiness==0 || tamagotchi->bathroom==0 || tamagotchi->hungry==0){
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