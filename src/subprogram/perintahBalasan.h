#include "../../ADT/balasan.h"
#include "../../ADT/liststatikpengguna.h"
#include "../../ADT/listdinKicauan.h"
#include "../../ADT/friends.h"


void BALAS(int idkicau, int iddibalas, ListPengguna progListPengguna, ListDinKicauan *progListKicau, int progIdUser,Friends progFriends);
void rekurbalasan(Balasan cnodebal, int progIdUser, int idxKicau, ListDinKicauan progListKicau, ListPengguna progListPengguna, Friends progFriends, int depth);
void BALASAN(int progIdUser, int idxKicau, ListDinKicauan progListKicau, ListPengguna progListPengguna, Friends progFriends);
void HAPUSBALAS(int idkicau, int balasdihapus, ListPengguna progListPengguna, ListDinKicauan *progListKicau, int progIdUser);
void rekurHapusBalas(Balasan par, int idxdihapus);