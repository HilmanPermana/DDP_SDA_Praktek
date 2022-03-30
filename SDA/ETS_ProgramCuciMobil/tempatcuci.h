
#ifndef TEMPATCUCI_H
#define TEMPATCUCI_H
#define JML_TEMPATCUCI 2
#include "queue.h"

struct tempatcuci{
	
	DinamisChar nama;
	List antrian;
	
};

void CreateTempatCuci(tempatcuci loketCuci[JML_TEMPATCUCI]);
int GetTempatCuci(tempatcuci loketCuci[JML_TEMPATCUCI], waktu prevFinishTime[JML_TEMPATCUCI]);
bool WaktuIstirahat(waktu T);
bool WaktuBuka(waktu T);
void gotoxy(int x, int y);

#endif
