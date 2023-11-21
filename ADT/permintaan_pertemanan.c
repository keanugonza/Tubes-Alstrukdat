#include "permintaan_pertemanan.h"
#include "wordmachine.c"

extern self;

void createFriendReqList(Queue *q){
    CreateEmpty(q);
}

boolean hasSentFriendReq(Queue q, Pengguna nama){
    int length =  IDX_TAIL(q) - IDX_HEAD(q) + 1;
    while(length--){
        if(info(HEAD(q)) == nama.nama){
            return true;
        }
        IDX_HEAD(q)++;
    }
    return false;
}

void addFriendReq(Queue *q, Pengguna otherUser){
    printf("\nMasukkan nama pengguna:\n");
    input();
    printf("\n");
    if(!IsEmpty(*q)){
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
    else if(userDoesntExist()){
        printf("Pengguna bernama %s tidak ditemukan.\n", nama());
    }
    else if(isFriends()){
        printf("Anda sudah berteman dengan %s!\n");
    }
    else if(hasSentFriendReq(*q, nama)){
        printf("Anda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.\n");
    }
    else{
        Add(q, otherUser);
        printf("Permintaan pertemanan kepada %s telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
    }
    printf("\n");
}

void displayFriendReqList(Queue q){
    infotype dum;
    int length = IDX_TAIL(q) - IDX_HEAD(q) + 1;
    printf("\n");
    if(length > 0){
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", length);
        while(length--){
            Dequeue(&q, &dum);
            printf("\n| %s\n| Jumlah teman:  %d\n", Info(dum), Prio(dum));
        }
    }
    else
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    printf("\n");
}

void accFriendReq(Queue *q, Graph friendList){
    infotype dum;
    printf("\nPermintaan pertemanan teratas dari %s\n", Info(HEAD(*q)));
    printf("\n| %s\n| Jumlah teman:  %d\n", Info(HEAD(*q)), Prio(HEAD(*q)));

    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
    input();

    if("YA"){
        Dequeue(q, &dum);
        addFriend(friends, u1, u2);
        printf("\nPermintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n");
    }
    else if("TIDAK"){
        Dequeue(q, &dum);
        printf("\nPermintaan pertemanan dari %s telah ditolak.\n", Nama_User());
    }
    printf("\n");
}