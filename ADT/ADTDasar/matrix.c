#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
   ROW_EFF(*m) = nRows;
   COL_EFF(*m) = nCols;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */


/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
   return (i>=0 && i<ROW_CAP && j>=0 && j<COL_CAP);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
   return (ROW_EFF(m)-1);
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m){
   return (COL_EFF(m)-1);

}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
   return (i>=0 && i<ROW_EFF(m) && j>=0 && j<COL_EFF(m));

}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i){
   return (ELMT(m,i,i));
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
   createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
   int i,j;
   for(i=0;i<ROW_EFF(mIn);i++){
      for(j=0;j<COL_EFF(mIn);j++){
         ELMT(*mOut,i,j) = ELMT(mIn,i,j); 
      }
   }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
   int i,j,input;
   createMatrix(nRow, nCol,m );
   for(i=0;i<nRow;i++){
      for(j=0;j<nCol;j++){
         scanf("%d", &input); 
         ELMT(*m,i,j) = input;
      }
   }

}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
   int i,j,input;
   for(i=0;i<ROW_EFF(m);i++){
      for(j=0;j<COL_EFF(m);j++){ 
         if (j==COL_EFF(m)-1){
            printf("%d\n",ELMT(m,i,j));
         }
         else{
         printf("%d ",ELMT(m,i,j));
         }
      }
   }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
   Matrix hasil;
   int i,j;

   createMatrix(ROW_EFF(m1), COL_EFF(m1),&hasil);
   for(i=0;i<ROW_EFF(m1);i++){
      for(j=0;j<COL_EFF(m1);j++){
         ELMT(hasil,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
      }
   }
   return hasil;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2){
   Matrix hasil;
   int i,j;

   createMatrix(ROW_EFF(m1), COL_EFF(m1),&hasil);
   for(i=0;i<ROW_EFF(m1);i++){
      for(j=0;j<COL_EFF(m1);j++){
         ELMT(hasil,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
      }
   }
   return hasil;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2){
   Matrix hasil;
   int i,j,k;

   createMatrix(ROW_EFF(m1), COL_EFF(m2),&hasil);

   for(i=0; i<ROW_EFF(m1); i++){
      for(j=0; j<COL_EFF(m2); j++){
         ELMT(hasil,i,j) = 0;
         for (k=0; k<COL_EFF(m1); k++){
            ELMT(hasil,i,j) += ELMT(m1,i,k) * ELMT(m2,k,j);
         }
      }
   }
   return hasil;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod){
   Matrix m3;
   int i,j;

   createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
   m3 = multiplyMatrix(m1,m2);
   for(i=0;i<ROW_EFF(m3);i++){
      for(j=0;j<COL_EFF(m3);j++){
         ELMT(m3,i,j) =  ELMT(m3,i,j) % mod;
      }
   }
   return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
Matrix multiplyByConst(Matrix m, ElType x){
   int i,j;
   Matrix hasil;
   createMatrix(ROW_EFF(m), COL_EFF(m), &hasil);
   for(i=0;i<ROW_EFF(m);i++){
      for(j=0;j<COL_EFF(m);j++){
         ELMT(hasil,i,j) = x * ELMT(m,i,j);
      }
   }
   return hasil;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k){
   int i,j;

   for(i=0;i<ROW_EFF(*m);i++){
      for(j=0;j<COL_EFF(*m);j++){
         ELMT(*m,i,j) = k * ELMT(*m,i,j);
      }
   }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
   int i,j;
   if ( (ROW_EFF(m1)!=ROW_EFF(m2)) || (COL_EFF(m1)!=COL_EFF(m2)) ){
      return false;
   }
   else{
      for(i=0;i<ROW_EFF(m1);i++){
         for(j=0;j<COL_EFF(m1);j++){
            if (ELMT(m1,i,j) != ELMT(m2,i,j)){
               return false;
            }
         }
      }
      return true;
   }
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
   return (!isMatrixEqual(m1,m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
   return ((ROW_EFF(m1)==ROW_EFF(m2)) && (COL_EFF(m1)==COL_EFF(m2)));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
   int hasil;
   hasil = ROW_EFF(m) * COL_EFF(m);
   return hasil;
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
   return (ROW_EFF(m) == COL_EFF(m));
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m){
   int i,j;
   if (!isSquare(m)){
      return false;
   }
   else{
      for(i=0;i<ROW_EFF(m);i++){
         for(j=0;j<COL_EFF(m);j++){
            if (ELMT(m,i,j) != ELMT(m,j,i)){
               return false;
            }
         }
      }
      return true;
   }
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m){
   int i,j;
   if (!isSquare(m)){
      return false;
   }
   else{
      for(i=0;i<ROW_EFF(m);i++){
         for(j=0;j<COL_EFF(m);j++){
            if (i==j){
               if (ELMT(m,i,j) != 1){
                  return false;
               }
            }
            else{
               if (ELMT(m,i,j) != 0){
                  return false;
               }
            }
         }
      }
      return true;
   } 
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m){
   int i,j;
   double persen;
   double hitung0 = 0;
   for(i=0;i<ROW_EFF(m);i++){
      for(j=0;j<COL_EFF(m);j++){
         if (ELMT(m,i,j) == 0){
            hitung0 ++;
         }
      }
   }
   persen = (countElmt(m)-hitung0) / countElmt(m);

   if (persen > 0.05){
      return false;
   }
   else{
      return true;
   }
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m){
   return multiplyByConst(m,-1);
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m){
   pMultiplyByConst(m,-1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
Matrix minorr(Matrix m, int row, int col){
   Matrix minor;
   int i,j;
   createMatrix(ROW_EFF(m)-1,COL_EFF(m)-1,&minor);
   for(i=0; i<ROW_EFF(minor);i++){
      for(j=0; j<COL_EFF(minor);j++){
         if (i>=row && j<col){
            ELMT(minor,i,j) = ELMT(m,i+1,j);
         }
         else if (i>=row && j>=col){
            ELMT(minor,i,j) = ELMT(m,i+1,j+1);
         }
         else if (i<row && j>=col){
            ELMT(minor,i,j) = ELMT(m,i,j+1);
         }
         else if (i<row && j<col){
            ELMT(minor,i,j) = ELMT(m,i,j);
         }
      }
   }
   return minor;
}

float determinant(Matrix m){
   if (ROW_EFF(m)==1){
      return ELMT(m,0,0);
   }
   else if (ROW_EFF(m)==2) {
      return ((ELMT(m,0,0)*ELMT(m,1,1))-(ELMT(m,0,1)*ELMT(m,1,0)));
   }
   int i;
   float hasil =0;
   int sign =1 ;

   for (i=0; i<COL_EFF(m);i++){
      hasil += sign * ELMT(m,0,i) * determinant(minorr(m,0,i));
      sign = -sign;
   }
   return hasil;
}

/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m){
   Matrix hasil;
   int i,j;
   createMatrix(ROW_EFF(m),COL_EFF(m),&hasil);
   for(i=0;i<ROW_EFF(m);i++){
      for (j=0;j<COL_EFF(m);j++){
         ELMT(hasil,i,j) = ELMT(m,j,i);
      }
   }
   return hasil;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m){
   Matrix temp;
   int i,j;
   createMatrix(ROW_EFF(*m),COL_EFF(*m),&temp);
   for(i=0;i<ROW_EFF(*m);i++){
      for (j=0;j<COL_EFF(*m);j++){
         ELMT(temp,i,j) = ELMT(*m,j,i);
      }
   }
   copyMatrix(temp,m);

}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
