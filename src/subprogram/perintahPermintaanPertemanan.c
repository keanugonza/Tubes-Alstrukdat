#include "../../ADT/permintaan_pertemanan.h"

extern Queue progQueue[20];

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

void addFriendReq(Pengguna currUser, Friends FriendReq, ListPengguna ListPenggunaFriendReq){
    infotype friendReq;
    Word text;
    printf("\nMasukkan nama pengguna:\n");
    ADVWORD();
    text = currentWord;

    Info(friendReq) = currUser.nama;
    Prio(friendReq) = friendCount(FriendReq, currUser.id);
    
    printf("\n");
    if(!IsEmpty(progQueue[currUser.id])){
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
    else if(!isMember(ListPenggunaFriendReq, text)){
        printf("Pengguna bernama ");
        displayWord(text);
        printf(" tidak ditemukan.\n");
    }
    else if(isFriend(FriendReq, currUser.id, idxPengguna(ListPenggunaFriendReq, text))){
        printf("Anda sudah berteman dengan ");
        displayWord(text);
        printf("!\n");
    }
    else if(hasSentFriendReq(progQueue[idxPengguna(ListPenggunaFriendReq, text)], currUser.nama)){
        printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
        displayWord(text);
        printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
    }
    else{
        Enqueue(&progQueue[idxPengguna(ListPenggunaFriendReq, text)], friendReq);
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
        for(int i = 0; i < len; i++){
            printf("\n| ");
            displayWord(Info(q.buffer[i]));
            printf("\n| Jumlah teman:  %d\n", Prio(q.buffer[i]));
        }
    }
    else
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    printf("\n");
}

void accFriendReq(Pengguna currUser, Friends *FriendReq, ListPengguna ListPenggunaFriendReq){
    infotype dum;
    Word text;

    printf("\nPermintaan pertemanan teratas dari ");
    displayWord(Info(HEAD(progQueue[currUser.id])));
    printf("\n\n| ");
    displayWord(Info(HEAD(progQueue[currUser.id])));
    printf("\n| Jumlah teman:  %d\n", Prio(HEAD(progQueue[currUser.id])));

    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
    ADVWORD();
    text = currentWord;

    if(isWordEqual(text, stringToWord("YA"))){
        addFriend(FriendReq, currUser.id, idxPengguna(ListPenggunaFriendReq, Info(HEAD(progQueue[currUser.id]))));
        printf("\nPermintaan pertemanan dari ");
        displayWord(Info(HEAD(progQueue[currUser.id])));
        printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
        displayWord(Info(HEAD(progQueue[currUser.id])));
        printf(".\n");
        Dequeue(&progQueue[currUser.id], &dum);
    }
    else if(!isWordEqual(text, stringToWord("TIDAK"))){
        Dequeue(&progQueue[currUser.id], &dum);
        printf("\nPermintaan pertemanan dari ");
        displayWord(Info(HEAD(progQueue[currUser.id])));
        printf(" telah ditolak.\n");
    }
    printf("\n");
}