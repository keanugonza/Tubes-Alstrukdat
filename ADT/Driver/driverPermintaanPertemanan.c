#include "../permintaan_pertemanan.c"
#include "../charmachine.c"

Friends f;
Pengguna user;
ListPengguna LP;

int main(){
    Queue q;
    Matrix m;
    Word text;

    STARTWORD();
    text = currentWord;
    createPengguna(&user, 1, text, text, text, text, text, 0, m);

    createListPengguna(&LP);
    insertPengguna(&LP, user);
    
    createFriendReqList(&q);
    addFriendReq(&q, text);
    displayFriendReqList(q);
}