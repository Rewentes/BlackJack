#include "Stack.h"

void print_kard(int sum_player, int sum_dealer, Node player1[10], Node dealer[10], int i_p, int i_d) {
    printf("� ���: %d �窮�. �����: ", sum_player);
    for (int j = 0; j < i_p; j++) {
        printf("%s %s; ", player1[j].name, player1[j].suit);
    }

    printf("\n� ������: %d �窮�. �����: ", sum_dealer);
    for (int j = 0; j < i_d; j++) {
        printf("%s %s; ", dealer[j].name, dealer[j].suit);
    }
}

int main(void) {

    char *name[13] = {"������", "�ன��", "��⢥ઠ", "���ઠ",
                      "����ઠ", "����ઠ", "���쬥ઠ", "����⪠",
                      "����⪠", "�����", "����", "��஫�", "��"};

    char *suit[4] = {"���", "��ࢥ�", "��", "����"};

    int value[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    Node *head = NULL;

    for (int i = 0; i < 13; i++) {
        for (int k = 0; k < 4; k++) {
            push(&head, suit[k], name[i], value[i]);
        }
    }

    Node dealer[10], player1[10];
    char run, run1 = '�';

    printf("����� ����? ([�] - ��; [�] - ���)\n");
    scanf("%s", &run);

    if (run == '�') {
        tusov(&head);
        //printList(head);

        player1[0] = (pop(&head));
        player1[1] = (pop(&head));
        dealer[0] = (pop(&head));
        dealer[1] = (pop(&head));
        int sum_player = player1[0].value + player1[1].value;
        int sum_dealer = dealer[0].value + dealer[1].value;

        printf("� ���: %d �窮�. �����: %s %s � %s %s\n", sum_player,
               player1[0].name, player1[0].suit,
               player1[1].name, player1[1].suit);

        printf("����� ������: %s %s � ***\n", dealer[0].name, dealer[0].suit);

        // ______________�����_______________
        int i_p;
        if (run1 == '�') i_p = 2;
        else i_p = 1;

        while (run1 == '�') {
            printf("\n����� �� ���� �����? ([�] - ��; [�] - ���)\n");
            scanf("%s", &run1);
            if (run1 == '�') break;
            player1[i_p] = (pop(&head));
            sum_player += player1[i_p].value;


            printf("� ���: %d �窮�. �����: ", sum_player);
            for (int j = 0; j < i_p; j++) {
                printf("%s %s; ", player1[j].name, player1[j].suit);
            }
            if (sum_player > 21) {
                return printf("\n�� �ந�ࠫ�.");
            }
            if (sum_player == 21) {
                return printf("\nBlacJack! �� �먣ࠫ�!");
            }
            i_p++;
        }

        // ___________������_____________
        int i_d;
        if (sum_dealer <= 16) i_d = 2;
        else i_d = 1;
        while (sum_dealer <= 16) {
            dealer[i_d] = (pop(&head));
            sum_dealer += dealer[i_d].value;
            i_d++;
            if (sum_player > 21) {
                print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);
                return printf("\n�� �먣ࠫ�, � ������ ����� 21 �窮�.");
            }
        }

        if (sum_dealer < sum_player) {
            print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);
            return printf("\n�� �먣ࠫ�!");
        }
        if (sum_dealer > sum_player) {
            print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);;
            return printf("\n�� �ந�ࠫ�.");
        }

        if (sum_dealer == sum_player) {
            print_kard(sum_player, sum_dealer, player1, dealer, i_p, i_d);
            return printf("\n�����.");
        }
    }
    return 0;
}