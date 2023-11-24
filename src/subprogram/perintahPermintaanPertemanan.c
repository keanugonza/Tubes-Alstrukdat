#include "../../ADT/permintaan_pertemanan.h"

void createFriendReqList(Queue *q){
    CreateEmpty(q);
}

boolean hasSentFriendReq(Queue q, Word nama){
    int len = length(q);
    while(len--){
        if(isWordEqual(Info(HEAD(q)), nama)){
            return true;
        }
        IDX_HEAD(q)++;
    }
    return false;
}

void addFriendReq(Queue *q, Pengguna currUser, Friends FriendReq, ListPengguna ListPenggunaFriendReq){
    infotype friendReq;
    Word text;
    printf("\nMasukkan nama pengguna:\n");
    ADVWORD();
    text = currentWord;

    Info(friendReq) = text;
    Prio(friendReq) = friendCount(FriendReq, idxPengguna(ListPenggunaFriendReq, text));
    
    printf("\n");
    if(!IsEmpty(*q)){
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
    else if(!isMember(ListPenggunaFriendReq, text)){
        printf("Pengguna bernama ");
        displayWord(text);
        printf("tidak ditemukan.\n");
    }
    else if(isFriend(FriendReq, currUser.id, idxPengguna(ListPenggunaFriendReq, text))){
        printf("Anda sudah berteman dengan ");
        displayWord(text);
        printf("!\n");
    }
    else if(hasSentFriendReq(*q, text)){
        printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
        displayWord(text);
        printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
    }
    else{
        Enqueue(q, friendReq);
        printf("Permintaan pertemanan kepada ");
        displayWord(text);
        printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
    }
    printf("\n");
}

void displayFriendReqList(Queue q){
    infotype dum;
    int len = length(q);
    printf("\n");
    if(length > 0){
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", len);
        while(len--){
            Dequeue(&q, &dum);
            printf("\n| %s\n| Jumlah teman:  %d\n", Info(dum), Prio(dum));
        }
    }
    else
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    printf("\n");
}

void accFriendReq(Queue *q, Pengguna currUser, Friends *FriendReq, ListPengguna ListPenggunaFriendReq){
    infotype dum;
    Word text;

    printf("\nPermintaan pertemanan teratas dari %s\n", Info(HEAD(*q)));
    printf("\n| %s\n| Jumlah teman:  %d\n", Info(HEAD(*q)), Prio(HEAD(*q)));

    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
    ADVWORD();
    text = currentWord;

    if(isWordEqual(text, stringToWord("YA"))){
        Dequeue(q, &dum);
        addFriend(FriendReq, currUser.id, idxPengguna(ListPenggunaFriendReq, Info(HEAD(*q))));
        printf("\nPermintaan pertemanan dari ");
        displayWord(text);
        printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
        displayWord(text);
        printf(".\n");
    }
    else if(!isWordEqual(text, stringToWord("TIDAK"))){
        Dequeue(q, &dum);
        printf("\nPermintaan pertemanan dari ");
        displayWord(text);
        printf(" telah ditolak.\n");
    }
    printf("\n");
}