#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int montyHall_simulation(int switch_doors) {
    int car_door = rand() % 3; 
    int chosen_door = rand() % 3; 

    int revealed_door;
    do {
        revealed_door = rand() % 3;
    } while (revealed_door == car_door || revealed_door == chosen_door);

    if (switch_doors) {
        for (int i = 0; i < 3; ++i) {
            if (i != chosen_door && i != revealed_door) {
                chosen_door = i;
                break;
            }
        }
    }

    return chosen_door == car_door;
}

double get_percentage(int trials) {
    int wins = 0;

    for (int i = 0; i < trials; ++i) {
        wins += montyHall_simulation(1);
    }

    return (double)wins / trials * 100.0;
}

int main() {
    srand(time(NULL)); 

    printf(" ##  ###  #######  ##  ###  #######  ##  ###           ###  ##   ######   ##       ##               #######  ######   #######  ######    ##      #######  ##  ### ");
    printf(" #######  ##   ##  ### ###    ###    ##  ###           ###  ##   ##  ##   ##       ##               ##   ##  ##  ##   ##   ##  ##  ##    ##      ##       ####### ");
    printf(" #######  ##   ##  #######    ###    ##  ###           ###  ##   ##  ##   ##       ##               ##   ##  ##  ##   ##   ##  ##  ##    ##      ##       ####### ");
    printf(" ### ###  ##  ###  ## ####    ###    #######           #######  #######  ###      ###               #######  #######  ##  ###  #######  ###      #######  ### ### ");
    printf(" ##  ###  ##  ###  ##  ###    ###      ###             ###  ##  ###  ##  ###      ###               ###      ### ###  ##  ###  ##  ###  ###      ###      ##  ### ");
    printf(" ##  ###  ##  ###  ##  ###    ###      ###             ###  ##  ###  ##  ###      ###               ###      ### ###  ##  ###  ##  ###  ###      ###      ##  ### ");
    printf(" ##  ###  #######  ##  ###    ###      ###             ###  ##  ###  ##  ######   ######            ###      ### ###  #######  #######  ######   #######  ##  ### ");
    
    int choice;
    printf("몬티홀의 역설\n");
    printf("1. 몬티홀 체험하기\n");
    printf("2. 몬티홀의 확률 구하기\n");
    printf("옵션을 골라주세요 >> ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        int switch_doors;
        printf("Do you want to switch doors? (1 for Yes, 0 for No): ");
        scanf_s("%d", &switch_doors);

        int result = get_percentage(switch_doors);
        if (result) {
            printf("당신은 올바른 문을 골랐습니다!\n");
        }
        else {
            printf("실패!\n");
        }
    }
    else if (choice == 2) {
        int trials;
        printf("시도할 횟수를 입력해주세요(권장 10,000회) >> ");
        scanf_s("%d", &trials);

        double percentage = get_percentage(trials);
        printf("선택을 바꿨을 때의 승률: %.2f%%\n", percentage);
    }
    else {
        printf("올바르지 않은 선택입니다. \n처음으로 돌아갑니다.\n");
        _sleep(2000);
        main();
    }

    return 0;
}