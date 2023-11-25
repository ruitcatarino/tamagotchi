#include "tamagotchi.h"
#include <pthread.h>
#include <unistd.h>

#define SIMULATION_SPEED 1

void *time_thread(void *arg){
    struct Tamagotchi *tamagotchi = (struct Tamagotchi *)arg;

    while (tamagotchi->alive){
        sleep(SIMULATION_SPEED);

        tamagotchi->hunger += 3;
        tamagotchi->happiness -= 3;
        tamagotchi->age++;

        check_status(tamagotchi);
    }

    pthread_exit(NULL);
}

void create(struct Tamagotchi* tamagotchi){

    tamagotchi_name(tamagotchi);

    tamagotchi->age=0;
    tamagotchi->age_of_death=rand() % 61 + 50;
    tamagotchi->hunger=0;
    tamagotchi->happiness=100;
    tamagotchi->alive=true;
}

void life(struct Tamagotchi* tamagotchi){

    int choice;
    
    srand(time(NULL));

    while(tamagotchi->alive){

        scanf("%d", &choice);

        if(tamagotchi->alive == false){
            break;
        }

        if (choice == 1){
            feed(tamagotchi);
        } else if (choice == 2){
            play(tamagotchi);
        } else if (choice == 3){
            break;
        } else{
            printf("I miss you :/ \n");
        }

        check_status(tamagotchi);

    }

}

int main() {

    struct Tamagotchi tamagotchi;

    create(&tamagotchi);

    tamagotchi_status_and_menu(&tamagotchi);

    pthread_t tid;
    if (pthread_create(&tid, NULL, time_thread, (void *)&tamagotchi) != 0){
        perror("Error creating thread");
        return 1;
    }

    life(&tamagotchi);

    pthread_join(tid, NULL);

    return 0;
}