/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : Overview of C Language
*Percobaan        : -
*Hari dan Tanggal : Selasa, 15 Februari 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <math.h>

int main() {
	double x1, y1;	// koordinat router
	double x2, y2;	// koordinat komputer
	double length;	// panjang kabel ethernet
	
	// Input koordinat router dan komputer
	printf("Koordinat router (x,y): ");
	scanf("%lf,%lf", &x1, &y1);
	printf("Koordinat komputer (x,y): ");
	scanf("%lf,%lf", &x2, &y2);
	
	/* // Pengecekan input jika diperlukan (comment jika asumsi input pasti valid)
	if (((x1 < 0 || x1 > 4 || y1 < 0 || y1 > 3) || ((x1 != 0 && x1 != 4) && (y1 != 0 && y1 != 3)))  ||
	((x2 < 0 || x2 > 4 || y2 < 0 || y2 > 3) || ((x2 != 0 && x2 != 4) && (y2 != 0 && y2 != 3))))  {
		printf("Input tidak valid");
		return -1;
	}
	*/

	// Kondisi router yang berseberangan merupakan kasus khusus dimana perhitungan
	// panjang kabel tidak dapat dilakukan hanya dengan menggunakan selisih x dan y
	// Kondisi router dan komputer bersebrangan (salah satu pada sumbu x)
	if (((x1 == 0 && x2 == 4) || (x1 == 4 && x2 == 0)) && (y1 !=0 && y1 != 3 && y2 != 0 && y2 != 3)) {
		if ((y1 + y2) < (3 - y1 + 3 - y2)) {
			length = y1 + 4 + y2;
		}
		else {
			length = 3 - y1 + 4 + 3 - y2;
		}
	}
	// Kondisi router dan komputer bersebrangan (salah satu pada sumbu y)
	else if (((y1 == 0 && y2 == 3) || (y1 == 3 && y2 == 0)) && (x1 != 0 && x1 != 4 && x2 != 0 && x2 != 4)) {
		if ((x1 + x2) < (4 - x1 + 4 - x2)) {
			length = x1 + 3 + x2;
		}
		else {
			length = 4 - x1 + 3 + 4 - x2;
		}
	}
	// Kondisi umum (dapat dihitung dengan menggunakan selisih x dan y)
	else {
		length = fabs(x1 - x2) + fabs(y1 - y2);
	}
	
	// Output panjang kabel ethernet minimal
	printf("Panjang kabel Ethernet minimal: %lf", length);
	
	return 0;
}
