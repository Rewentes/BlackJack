#include "Stack.h"

int main(void) {

    char *name[13] = {"������", "�ன��", "��⢥ઠ", "���ઠ",
                      "����ઠ", "����ઠ", "���쬥ઠ", "����⪠",
                      "����⪠", "�����", "����", "��஫�", "��" };

    char *suit[4] = { "���", "��ࢥ�", "��", "����" };

    int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

    Node *head = NULL;

    for (int i = 0; i < 13; i++) {
        for (int k = 0; k < 4; k++) {
            push(&head, suit[k], name[i], value[i]);
        }
    }

    Node dealer[2], player1[2];
    char run[20], da[20] = "��", nzh[20] = "�����";
    int flag1 = 1, flag2= 1;

    printf("����� ����?\n");
    scanf("%s", &run);
    for (int i = 0; i < 20; i++) {

        if (run[i] != da[i]){
            flag1 = 0;
        }
        else if (run[i] != nzh[i]) {
            flag2 = 0;
        }
    }

    if (flag2 == 1) {
        tusov(&head);

            player1[1] = (pop(&head));
            player1[2] = (pop(&head));
            dealer[1] = (pop(&head));
            dealer[2] = (pop(&head));

        int sum_player = player1[1].value + player1[2].value;
        int sum_dealer = dealer[1].value + dealer[2].value;

        printf("� ���: %d �窮�. �����: %s %s � %s %s\n", sum_player,
               player1[1].name, player1[1].suit,
               player1[2].name, player1[2].suit);

        printf("� �����: %d �窮�. �����: %s %s � %s %s\n", sum_dealer,
               dealer[1].name, dealer[1].suit,
               dealer[2].name, dealer[2].suit);

    }
        //printList(head);
        //printf("___________________________\n");
/*
    Node pops;
    pops = (pop(&head));
    printf("�������: %s %s\n", pops.name, pops.suit);

    pops = delete_N(&head,  3);
    printf("�������: %s %s\n", pops.name, pops.suit);

    pops = *LAST_element(head);
    printf("��᫥���� �����: %s %s\n", pops.name, pops.suit);

    printf("___________________________\n");

  //  pushBack(head, suit[0], name[0]);

  //  insert(head, 1, suit[2], name[3]);
 */

    return 0;
}