#include "Stack.h"

void print_kard(int sum_player, int sum_dealer, Node player1[10], Node dealer[10], int i_p, int i_d) {
    printf("У Вас: %d очков. Карты: ", sum_player);
    for (int j = 0; j < i_p; j++) {
        printf("%s %s; ", player1[j].name, player1[j].suit);
    }

    printf("\nУ Диллера: %d очков. Карты: ", sum_dealer);
    for (int j = 0; j < i_d; j++) {
        printf("%s %s; ", dealer[j].name, dealer[j].suit);
    }
}

int main(void) {

    char *name[13] = {"Двойка", "Тройка", "Четверка", "Пятерка",
                      "Шестерка", "Семерка", "Восьмерка", "Девятка",
                      "Десятка", "Валет", "Дама", "Король", "Туз"};

    char *suit[4] = {"Пик", "Червей", "Буб", "Крести"};

    int value[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    Node *head = NULL;

    for (int i = 0; i < 13; i++) {
        for (int k = 0; k < 4; k++) {
            push(&head, suit[k], name[i], value[i]);
        }
    }

    Node dealer[10], player1[10];
    char run, run1 = 'Д';

    printf("Начать игру? ([Д] - Да; [Н] - Нет)\n");
    scanf("%s", &run);

    if (run == 'Д') {
        tusov(&head);
        //printList(head);

        player1[0] = (pop(&head));
        player1[1] = (pop(&head));
        dealer[0] = (pop(&head));
        dealer[1] = (pop(&head));
        int sum_player = player1[0].value + player1[1].value;
        int sum_dealer = dealer[0].value + dealer[1].value;

        printf("У Вас: %d очков. Карты: %s %s и %s %s\n", sum_player,
               player1[0].name, player1[0].suit,
               player1[1].name, player1[1].suit);

        printf("Карты Диллера: %s %s и ***\n", dealer[0].name, dealer[0].suit);

        // ______________ИГРОК_______________
        int i_p;
        if (run1 == 'Д') i_p = 2;
        else i_p = 1;

        while (run1 == 'Д') {
            printf("\nВзять еще одну карту? ([Д] - Да; [Н] - Нет)\n");
            scanf("%s", &run1);
            if (run1 == 'Н') break;
            player1[i_p] = (pop(&head));
            sum_player += player1[i_p].value;


            printf("У Вас: %d очков. Карты: ", sum_player);
            for (int j = 0; j < i_p; j++) {
                printf("%s %s; ", player1[j].name, player1[j].suit);
            }
            if (sum_player > 21) {
                return printf("\nВы проиграли.");
            }
            if (sum_player == 21) {
                return printf("\nBlacJack! Вы выиграли!");
            }
            i_p++;
        }

        // ___________ДИЛЛЕР_____________
        int i_d;
        if (sum_dealer <= 16) i_d = 2;
        else i_d = 1;
        while (sum_dealer <= 16) {
            dealer[i_d] = (pop(&head));
            sum_dealer += dealer[i_d].value;
            i_d++;
            if (sum_player > 21) {
                print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);
                return printf("\nВы выиграли, у диллера больше 21 очков.");
            }
        }

        if (sum_dealer < sum_player) {
            print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);
            return printf("\nВы выиграли!");
        }
        if (sum_dealer > sum_player) {
            print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);;
            return printf("\nВы проиграли.");
        }

        if (sum_dealer == sum_player) {
            print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);
            return printf("\nНичья.");
        }
    }
    return 0;
}