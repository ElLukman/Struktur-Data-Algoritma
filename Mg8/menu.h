#ifndef MENU_H
#define MENU_H 

#include "common.h"

// FUNCTION MENU
void MENU_AWAL();
void SUB_MENU_SLL();
void SUB_MENU_DLL();
void SUB_MENU_ARR();

// FUNCTION SUB MENU
// 1. Add Buku
void MENU_TITLE_CREATE_BUKU();

// 2. Edit Buku
void MENU_TITLE_EDIT_BUKU();

// 3. Delete Buku

// 4. Create Anggota
void MENU_TITLE_CREATE_ANGGOTA();
void MENU_INPUT_LEVEL_ANGGOTA();

// 5. Edit Anggota
void MENU_TITLE_EDIT_ANGGOTA();
void MENU_EDIT_LEVEL_ANGGOTA();

// 6. Delete Anggota

// 7. Pinjam Buku 

// 8. Kembalikan Buku 

// 9. Tampilkan Visual 
void TAMPILKAN_VISUAL();

// Other 
void MENU_WARNING();
void PAUSE();
void CLEARBUFFER();


#endif 