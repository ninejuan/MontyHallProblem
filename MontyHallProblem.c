#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

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

void play_game() {
    int goat_door, chosen_door, revealed_door, final_choice;
    srand(time(NULL)); // 랜덤 시드 설정

    // 염소가 있는 문 랜덤 선택
    goat_door = rand() % 3 + 1;

    // 사용자에게 문 선택 받기
    printf("세 개의 문 중 하나를 선택하세요 (1, 2, 3): ");
    scanf_s("%d", &chosen_door);

    // 사회자가 염소가 없는 문을 열어줌
    do {
        revealed_door = rand() % 3 + 1;
    } while (revealed_door == goat_door || revealed_door == chosen_door);

    printf("사회자가 %d번 문을 열었습니다. 그 문에는 염소가 없습니다.\n", revealed_door);

    // 사용자가 선택을 바꿀지 물어보기
    printf("선택을 바꾸시겠습니까? (1: 예, 0: 아니오): ");
    int change_choice;
    scanf_s("%d", &change_choice);

    if (change_choice) {
        // 남은 문을 최종 선택으로 설정
        for (int i = 1; i <= 3; ++i) {
            if (i != chosen_door && i != revealed_door) {
                final_choice = i;
                break;
            }
        }
    }
    else {
        final_choice = chosen_door;
    }

    // 결과 출력
    if (final_choice == goat_door) {
        printf("축하합니다! 염소를 찾았습니다. 염소는 %d번 문에 있습니다.\n", goat_door);
    }
    else {
        printf("아쉽습니다. 염소는 %d번 문에 있습니다. 당신의 선택은 %d번 문이었습니다.\n", goat_door, final_choice);
    }
}


int main() {
    srand(time(NULL)); 

    printf(" ##  ###  #######  ##  ###  #######  ##  ###           ###  ##   ######   ##       ##               #######  ######   #######  ######    ##      #######  ##  ### \n");
    printf(" #######  ##   ##  ### ###    ###    ##  ###           ###  ##   ##  ##   ##       ##               ##   ##  ##  ##   ##   ##  ##  ##    ##      ##       ####### \n");
    printf(" #######  ##   ##  #######    ###    ##  ###           ###  ##   ##  ##   ##       ##               ##   ##  ##  ##   ##   ##  ##  ##    ##      ##       ####### \n");
    printf(" ### ###  ##  ###  ## ####    ###    #######           #######  #######  ###      ###               #######  #######  ##  ###  #######  ###      #######  ### ### \n");
    printf(" ##  ###  ##  ###  ##  ###    ###      ###             ###  ##  ###  ##  ###      ###               ###      ### ###  ##  ###  ##  ###  ###      ###      ##  ### \n");
    printf(" ##  ###  ##  ###  ##  ###    ###      ###             ###  ##  ###  ##  ###      ###               ###      ### ###  ##  ###  ##  ###  ###      ###      ##  ### \n");
    printf(" ##  ###  #######  ##  ###    ###      ###             ###  ##  ###  ##  ######   ######            ###      ### ###  #######  #######  ######   #######  ##  ### \n");
    
    int choice;
    printf("몬티홀의 역설\n\n");
    printf("1. 몬티홀 체험하기\n");
    printf("2. 몬티홀의 확률 구하기\n\n");
    printf("옵션을 골라주세요 >> ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        play_game();
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
        Sleep(2000);
        main();
    }

    return 0;
}