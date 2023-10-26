#include "boolean.h"
#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARK */
    int i = IDX_MIN;
    for(; i<CAPACITY; i++){
        ELMT(*l,i) = MARK;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */
    int i = IDX_MIN;
    while (ELMT(l,i) != MARK && i < CAPACITY){
        i += 1;
    }
    return i;
}
  
/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l){
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    if (listLength(l) == 0){
        return IDX_MIN;
    } else{
        return(listLength(l)-1);
    }
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    if ((i >= IDX_MIN) && (i <= (CAPACITY-1))){
        return true;
    } else{
        return false;
    }
}

boolean isIdxEff(ListStatik l, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
    /* yaitu antara 0..length(l)-1 */
    if ((i >= getFirstIdx(l)) && (i <= (getLastIdx(l)))){
        return true;
    } else{
        return false;
    }
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    /* *** Test List penuh *** */
    return(listLength(l) == 0);
}

boolean isFull(ListStatik l){
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return(listLength(l) == CAPACITY);
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
    /* I.S. l sembarang */
    /* F.S. List l terdefinisi */
    /* Proses: membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
    /*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
    /*    Jika n tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
            Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
    /*    Jika n = 0; hanya terbentuk List kosong */
    int n,i,isi;
    boolean valid = false;
    while (!valid){
        scanf("%d", &n);
        if ((n>=0) && (n<=CAPACITY)){
            valid = true;
        }
    }
    CreateListStatik(l);
    for(i=0; i < n; i++){
        scanf("%d", &isi);
        ELMT(*l, i) = isi;
    }
}

void printList(ListStatik l){
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    int i;
    printf("[");
    for(i = 0; i < listLength(l); i++){
        printf("%d", ELMT(l,i));
        if (i != (listLength(l)-1)){
            printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    /* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
        indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
        elemen l2 pada indeks yang sama */
    int i;
    ListStatik lhasil;
    CreateListStatik(&lhasil);
    if(plus){
        for(i=0; i < listLength(l1); i++){
            ELMT(lhasil, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else{
        for(i=0; i < listLength(l1); i++){
            ELMT(lhasil, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return lhasil;
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
    elemennya sama */
    int i;
    boolean valid = true;
    if(listLength(l1) == listLength(l2)){
        for(i=0; i < listLength(l1); i++){
            if(ELMT(l1,i) != ELMT(l2,i)){
                valid = false;
                break;
            }
        }
        return valid;
    }else{
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
    /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
    /* Skema Searching yang digunakan bebas */
    int i = 0;
    boolean ketemu = false;
    while(i<CAPACITY && ketemu == false){
         if(ELMT(l,i) == val){
            ketemu = true;
        }
        else{
            i++;
        } 
    }
    if(ketemu){
        return i;
    } else{
        return IDX_UNDEF;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
    /* I.S. List l tidak kosong */
    /* F.S. Max berisi nilai terbesar dalam l;
            Min berisi nilai terkecil dalam l */
    int i = IDX_MIN;
    *max = ELMT(l,i);
    *min = ELMT(l,i);
    for(i = IDX_MIN; i < listLength(l); i++){
        if(ELMT(l,i)>*max){
            *max = ELMT(l,i);
        }
        if(ELMT(l,i)<*min){
            *min = ELMT(l,i);
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
    /* Proses: Menambahkan val sebagai elemen pertama List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen pertama l yang baru */
    /* *** Menambahkan elemen pada index tertentu *** */
    int i;
    for(i=listLength(*l); i > 0; i--){
        ELMT(*l,i) =  ELMT(*l,(i-1));
    }
    ELMT(*l,0) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    /* Proses: Menambahkan val sebagai elemen pada index idx List */
    /* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
    /* F.S. val adalah elemen yang disisipkan pada index idx l */
    /* *** Menambahkan elemen terakhir *** */
    int i;
    for(i=listLength(*l); i > idx; i--){
        ELMT(*l,i) =  ELMT(*l,(i-1));
    }
    ELMT(*l,idx) = val;
}

void insertLast(ListStatik *l, ElType val){
    /* Proses: Menambahkan val sebagai elemen terakhir List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    ELMT(*l,(listLength(*l))) = val;
}


/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
    /* Proses : Menghapus elemen pertama List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* *** Menghapus elemen pada index tertentu *** */
    int i;
    *val = ELMT(*l,0);
    for(i=0; i < listLength(*l)-1; i++){
        ELMT(*l,i) =  ELMT(*l,(i+1));
    }
    ELMT(*l,getLastIdx(*l)) =  MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    /* Proses : Menghapus elemen pada index idx List */
    /* I.S. List tidak kosong, idx adalah index yang valid di l */
    /* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* *** Menghapus elemen terakhir *** */
    int i;
    *val = ELMT(*l,idx);
    for(i=idx; i < listLength(*l)-1; i++){
        ELMT(*l,i) =  ELMT(*l,(i+1));
    }
    ELMT(*l,getLastIdx(*l)) =  MARK;
}

void deleteLast(ListStatik *l, ElType *val){
    /* Proses : Menghapus elemen terakhir List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    *val = ELMT(*l,getLastIdx(*l));
    ELMT(*l,getLastIdx(*l)) = MARK;
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
    algoritma bebas */
    int i, j;
    int n = listLength(*l);
    boolean swapped;
    if(asc == true){
        for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (ELMT(*l,j) > ELMT(*l,(j+1))) {
                int temp = ELMT(*l,j);
                ELMT(*l,j) = ELMT(*l,(j+1));
                ELMT(*l,(j+1)) = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
        }
    } else{
        for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (ELMT(*l,j) < ELMT(*l,(j+1))) {
                int temp = ELMT(*l,j);
                ELMT(*l,j) = ELMT(*l,(j+1));
                ELMT(*l,(j+1)) = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
        }
    }
}