#ifndef friends_H
#define friends_H

#include "ADTDasar/graph.h"

typedef Graph Friends;

void createPertemanan(Friends *f);
/* I.S. Sembarang */
/* F.S. Mengembalikan graph adjacency matriks dari pertemanan */

void addFriend(Friends *f, int user1, int user2);
/* I.S. Friends terdefinisi */
/* F.S. Mengembalikan friends dengan penambahan relasi antara user 1 dan user 2 */

void removeFriend(Friends*f, int user1, int user2);
/* I.S. Friends terdefinisi */
/* F.S. Mengembalikan friends dengan pengurangan relasi antara user 1 dan user 2 */

boolean isFriend(Friends f, int user1, int user2);
/*Mengembalikan true jika user1 dan user2 berteman*/

#endif