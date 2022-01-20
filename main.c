#include "Stack.h"
#include <windows.h>

void print_kard(int sum_player, int sum_dealer, Node player1[10], Node dealer[10], int i_p, int i_d) {
    printf("Player: %d points. Cards: ", sum_player);
    for (int j = 0; j < i_p; j++) {
        printf("%s %s; ", player1[j].name, player1[j].suit);
    }

    printf("\nDiler: %d points. Cards: ", sum_dealer);
    for (int j = 0; j < i_d; j++) {
        printf("%s %s; ", dealer[j].name, dealer[j].suit);
    }
}

int main(void) {

    char *name[13] = {"Two", "Three", "Four", "Five",
                      "Six", "Seven", "Eight", "Nine",
                      "Ten", "Jack", "Queen", "King", "Ace"};
    // пики (spades), червы (hearts), бубны (diamonds), трефы (clubs)
    char *suit[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};

    int value[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    Node *head = NULL;

    for (int i = 0; i < 13; i++) {
        for (int k = 0; k < 4; k++) {
            push(&head, suit[k], name[i], value[i]);
        }
    }

    Node dealer[10], player1[10];
    char run, run1 = 'Y';

    printf("Start the game? ([Y] - Yes; [N] - No)\n");
    scanf("%s", &run);

    if (run == 'Y') {
        tusov(&head);
        //printList(head);

        player1[0] = (pop(&head)); player1[1] = (pop(&head));
        dealer[0] = (pop(&head)); dealer[1] = (pop(&head));
        int sum_player = 0, sum_p = player1[0].value + player1[1].value;
        int sum_dealer = 0, sum_d = dealer[0].value + dealer[1].value;

        for (int i = 0; i < 2; ++i) {

            if ((sum_p > 21) && (player1[i].value == 11)) {
                sum_player += 1;
            } else sum_player += player1[i].value;

            if ((sum_d > 21) && (dealer[i].value == 11)) {
                sum_dealer += 1;
            } else sum_dealer += dealer[i].value;

        }

        printf("Player: %d points. Cards: %s %s and %s %s\n", sum_player,
               player1[0].name, player1[0].suit,
               player1[1].name, player1[1].suit);

        printf("Diler cards: %s %s and ***\n", dealer[0].name, dealer[0].suit);

        if (sum_player == 21) return printf("\nBlacJack! Player are winner!");

        // ______________ИГРОК_______________
        int i_p;
        if (run1 == 'Y') i_p = 2;
        else i_p = 1;

        while (run1 == 'Y') {
            printf("\nTake another card? ([Y] - Yes; [N] - No)\n");
            scanf("%s", &run1);

            if (run1 == 'N') break;
            player1[i_p] = (pop(&head));

            if ((sum_player+player1[i_p].value) > 21 && player1[i_p].value == 11) {
                sum_player += 1;
            } else sum_player += player1[i_p].value;

            printf("Player: %d points. Cards: ", sum_player);
            for (int j = 0; j < (i_p + 1); j++) {
                printf("%s %s; ", player1[j].name, player1[j].suit);
            }
            if (sum_player == 21) {
                return printf("\nBlacJack! Player are winner!");

            }
            if (sum_player > 21) {
                return printf("\nPlayer are loser!");
            }
            i_p++;
        }

        // ___________ДИЛЛЕР______________
        int i_d;
        if (sum_dealer <= 16) i_d = 2;
        else i_d = 1;
        while (sum_dealer <= 16) {
            dealer[i_d] = (pop(&head));

            if ((sum_dealer + dealer[i_d].value) > 21 && dealer[i_d].value == 11) {
                sum_dealer += 1;
            } else sum_dealer += dealer[i_d].value;

            i_d++;
            if (sum_dealer > 21) {
                print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);
                return printf("\nPlayer are winner, the dealer has more than 21 points.");
            }
        }
        // _______________________________
        if (sum_dealer < sum_player) {
            print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);
            return printf("\nPlayer are loser!");
        }
        if (sum_dealer > sum_player) {
            print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);
            return printf("\nPlayer are winner!");
        }

        if (sum_dealer == sum_player) {
            print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);
            return printf("\nDraw.");
        }
    }

    return 0;
}