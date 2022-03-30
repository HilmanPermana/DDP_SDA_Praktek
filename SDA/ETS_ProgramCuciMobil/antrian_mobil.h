
#ifndef ANTRIAN_MOBIL_H
#define ANTRIAN_MOBIL_H
#include "waktu.h"
#include "queue.h"
#include "tempatcuci.h"

//Procedure dan fungsi
waktu WaktuBerjalan(waktu sebelumnya);
void Menu(tempatcuci loketCuci[JML_TEMPATCUCI], waktu berjalan);
void CheckAntrian(tempatcuci loketCuci[JML_TEMPATCUCI], waktu berjalan);
waktu GetWaktuPelayananMulai(int idxLoketCuci, waktu WaktuKedatangan, tempatcuci loketCuci[JML_TEMPATCUCI], waktu WaktuSebelumya[JML_TEMPATCUCI]);
char GetWaktuPencucian(waktu &lamaPencucian);
waktu WaktuSelesai(waktu lamaPencucian, waktu WaktuDilayani);
void InputMerkMobil(DinamisChar &MerkMobil);
void TampilkanData(tempatcuci loketCuci[JML_TEMPATCUCI]);
void SimpanKeFile( DinamisChar, waktu kedatangan, waktu dilayani, waktu selesai, char jenis, int loket);
void HapusFile();



#endif
