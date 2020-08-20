#include "tamagotchi.h"

void life(struct Tamagotchi* tamagotchi){

}

int main() {
    struct Tamagotchi tamagotchi;

    create(&tamagotchi);

    tamagotchi_status(&tamagotchi);

    life(&tamagotchi);

    return 0;
}