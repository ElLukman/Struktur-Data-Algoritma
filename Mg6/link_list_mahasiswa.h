#ifndef link_list_mahasiswa_H

#define link_list_mahasiswa_H
#define bool unsigned char // 0 - 255 integer

typedef struct Node *address;
typedef struct Mahasiswa {
    char *Nama;
    int Nilai;
} Mhs;

typedef struct Node {
    Mhs Info;
    address Next;
} Node;

//Validator 
bool IsEmpty (address p);
bool CheckName (Mhs *Nama);

//Getter and Setter 
char *getNama (Mhs Info);
int getNilai (Mhs *Info);
void setNama (Mhs *Info, char *NewName);
void setNilai (Mhs *Info, int nilai);

//Konstruktor
void CreateNode (address *p);
void FillNode (address *p, Mhs info);
void InsertFirst (address *p, address NewNode);
void InsertLast (address *p, address NewNode);
void InsertAfter (address *p, address NewNode);

//Destruktor 
void DeleteFirst(address *p, int *X);
void DeleteLast(address *p, int *X);
void DeleteAfter(address *p, int *X);

//PrintObject and Counting
void PrintList (address p);
int CountElements (address p);

//Sorting and Filtering
void SortingAscendingName (address p, Node);
void SortingAscendValue (address p, Node);
void SortingDescendName (address p, Node);
void SortingDescendValue (address p, Node);
void FilterValue(address p, Node);



#endif