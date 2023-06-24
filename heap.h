#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Heap {

  vector<int> elementi;

   bool ImaLiDijete(int indeks) {if (LijevoDijete(indeks)!=-1 || DesnoDijete(indeks)!=-1) return true; return false;}

  //vracaju odgovarajuci index za trazeno, ako je van opsegag elemenata onda vracaju -1

  int Djed (int indeks){ if (Roditelj(indeks) !=-1 && (Roditelj(indeks))>=0) return Roditelj(Roditelj(indeks)); return -1;}
  int Roditelj(int indeks) { if (indeks <= 0) return -1; else{return (indeks-1)/2; }}

  int LijevoDijete(int indeks) { if ( 2*indeks + 1 < int(elementi.size())) return  2*indeks + 1 ; else return -1;}
  int DesnoDijete (int indeks) { if ( 2*indeks + 2 < int(elementi.size())) return  2*indeks + 2 ; else return -1;}

  int LLUnuk (int indeks ){ if (LijevoDijete(indeks) != -1 && LijevoDijete(LijevoDijete(indeks)) != -1 ) return LijevoDijete(LijevoDijete(indeks)); else return -1;}
  int LDUnuk (int indeks ){ if (LijevoDijete(indeks) != -1 && DesnoDijete(LijevoDijete(indeks))  != -1 ) return DesnoDijete(LijevoDijete(indeks)); else return -1;}
  int DLUnuk (int indeks ){ if (DesnoDijete(indeks)  != -1 && LijevoDijete(DesnoDijete(indeks))  != -1 ) return LijevoDijete(DesnoDijete(indeks)); else return -1;}
  int DDUnuk (int indeks ){ if (DesnoDijete(indeks)  != -1 && DesnoDijete(DesnoDijete(indeks))   != -1 ) return DesnoDijete(DesnoDijete(indeks)); else return -1;}

  //Pomocne za brisanje MIN i MAX elementa
  int Min_unuk_dijete(int i);
  int Max_unuk_dijete (int i);

  //Pomocne za Upheap
  void UPHeap_Min(int i);
  void UPHeap_Max(int i);

  //Pomocne za brisanje MIN i MAX elementa
  int Daj_maximalni();
  int Daj_minimalni();

  //int Index_minimalnog(); -uvijek korijen
  int Index_maximalnog();
  void DownHeap(int index,bool parnost);

  //Pomocne za konstruktor
  void UPHeap(int i);

  public:

  Heap(const vector<int> &niz);

  //Za brisanje MIN i MAX elementa
  void Izbrisi_Min();
  void Izbrisi_Max();

  //Za dodavanjeelemenata u heap
  void Dodaj( int element);
  //Operator ispisa
  friend ostream& operator<<(ostream& os, const Heap& h);


};



#endif // HEAP_H
