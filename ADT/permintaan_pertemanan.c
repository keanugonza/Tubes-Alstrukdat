#include "permintaan_pertemanan.h"

#include "./ADTDasar/prioqueue.c"
#include "friends.c"
#include "pengguna.c"
#include "wordmachine.c"
#include "liststatikpengguna.c"

extern ListPengguna LP;
extern Word self;
extern friends;

void createFriendReqList(Queue *q){
    CreateEmpty(q);
}

boolean hasSentFriendReq(Queue q, Word nama){
    int length =  IDX_TAIL(q) - IDX_HEAD(q) + 1;
    while(length--){
        if(isWordEqual(Info(HEAD(q)), nama)){
            return true;
        }
        IDX_HEAD(q)++;
    }
    return false;
}

void addFriendReq(Queue *q, Word nama){
    printf("\nMasukkan nama pengguna:\n");
    input();

    printf("\n");
    if(!IsEmpty(*q)){
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
    else if(!isMember(LP, currentWord)){
        printf("Pengguna bernama %s tidak ditemukan.\n", currentWord);
    }
    else if(isFriends()){
        printf("Anda sudah berteman dengan %s!\n");
    }
    else if(hasSentFriendReq(*q, nama)){
        printf("Anda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.\n");
    }
    else{
        Add(q, currentWord);
        printf("Permintaan pertemanan kepada %s telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
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

void accFriendReq(Queue *q, int id){
    infotype dum;
    printf("\nPermintaan pertemanan teratas dari %s\n", Info(HEAD(*q)));
    printf("\n| %s\n| Jumlah teman:  %d\n", Info(HEAD(*q)), Prio(HEAD(*q)));

    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
    input();

    if("YA"){
        Dequeue(q, &dum);
        addFriend(friends, id, id);
        printf("\nPermintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n");
    }
    else if("TIDAK"){
        Dequeue(q, &dum);
        printf("\nPermintaan pertemanan dari %s telah ditolak.\n", Nama_User());
    }
    printf("\n");
}