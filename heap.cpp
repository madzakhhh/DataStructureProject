#include "heap.h"
#include <cmath>
#include <ostream>



int Heap::Min_unuk_dijete(int i){
      int Min;
      int index_min;
      if (LijevoDijete(i)!=-1) {  //ako postoji LijevoDijete
        Min=elementi[LijevoDijete(i)];
        index_min=LijevoDijete(i);
        if (DesnoDijete(i)!=-1){ //ako postoji LijevoDijete,mozda postoji i DesnoDijete
            if (Min > elementi[DesnoDijete(i)]){
                Min=elementi[DesnoDijete(i)];
                index_min=DesnoDijete(i);}

            //ako ima desno mozda ima unuke
            if ( LLUnuk(i)!= -1 && Min > elementi[LLUnuk(i)] )
               {
                    Min=elementi[ LLUnuk(i)];
                    index_min=LLUnuk(i);
               }
            if ( LDUnuk(i)!= -1 && Min > elementi[LDUnuk(i)]) //moguce da postoji LDunuk jer postoji LDijete
               {
                    Min = elementi[LDUnuk(i)];
                    index_min=LDUnuk(i);
               }
            if ( DLUnuk(i)!= -1 && Min > elementi[DLUnuk(i)]) //moguce da postoji DLUnuk jer postoji desno dijete
                {
                    Min= elementi[DLUnuk(i)];
                    index_min=DLUnuk(i);

                }
            if ( DDUnuk(i)!=-1  && Min > elementi [DDUnuk(i)]) //moguce da postoji DDUnuk jer postoji desno dijete
               {
                   Min=elementi[DDUnuk(i)];
                   index_min=DDUnuk(i);
               }
        }
        return index_min;
      }
      return -1;
  }
int Heap::Max_unuk_dijete (int i){
      int Max;
      int index_max;
      if (ImaLiDijete(i)) { //ako postoji LijevoDijete,mozda postoji i DesnoDijete
        Max=elementi[LijevoDijete(i)];
        index_max=LijevoDijete(i);
        if (DesnoDijete(i)!=-1){ //ako postoji DesniDijete mozda postoje i unuci
            if (Max<elementi[DesnoDijete(i)]){

                Max=elementi[DesnoDijete(i)];
                index_max=DesnoDijete(i);
            }

            if ( DLUnuk(i)!= -1 && Max < elementi[DLUnuk(i)]) //moguce da postoji DLUnuk jer postoji desno dijete
                {
                    Max= DLUnuk(i);
                    index_max=DLUnuk(i);

                }
            if ( DDUnuk(i)!=-1  && Max < elementi [DDUnuk(i)]) //moguce da postoji DDUnuk jer postoji desno dijete
               {
                   Max=elementi[DDUnuk(i)];
                   index_max=DDUnuk(i);
               }
            if ( LLUnuk(i)!= -1 && Max < elementi[LLUnuk(i)] ) //moguce da postoji LLunuk jer postoji LDijete
                   {
                        Max=elementi[ LLUnuk(i)];
                        index_max=LLUnuk(i);
                   }
            if ( LDUnuk(i)!= -1 && Max < elementi[LDUnuk(i)]) //moguce da postoji LDunuk jer postoji LDijete
                   {
                        Max = elementi[LDUnuk(i)];
                        index_max=LDUnuk(i);
                   }

        }
        return index_max;}
      return -1;
  }

void Heap::Dodaj(int element ){
    elementi.push_back(element);
    UPHeap(elementi.size()-1);
}

//Unos elemenata
Heap::Heap(const vector<int> &niz) {
      for (int i=0;i<niz.size();i++){
        Dodaj(niz[i]);
        }

}
void Heap::UPHeap(int i){
    int level=floor(log(i+1)/log(2)); //izracunava na kojem je nivou
    if (i == 0 ) return;
    if (i!=0){
        if ( level % 2==0){ //ako je na min nivou
            if (elementi[i]>elementi[Roditelj(i)]){ //mora da bude manji od roditelja ako nije
                swap(elementi[i],elementi[Roditelj(i)]); //zamijeni
                UPHeap_Max(Roditelj(i)); //pozove jer je roidtelj na max nivou ako je ovaj na min nivou, i mora da uspostavi dio heapa koji predstavlja MaxHeap da ima trazene osobine koje su narusene
            }
            else{
                UPHeap_Min(i); //ako je u dobrom poretku sada treba da provjerava samo ove na svojim nivoima tj. djedove
            }
        }
        else{ //element je na max nivou
            if (elementi[i]<elementi[Roditelj(i)]){  //moram provjeriti da li je element veci od svog roditelja
                swap(elementi[i],elementi[Roditelj(i)]); //zamijeni
                UPHeap_Min(Roditelj(i)); //pozove UPHeap_Min jer mu je roditelj na min nivou ako je on n amax nivou
            }
            else {
                UPHeap_Max(i); //ako je element u dobrom odnosu sa roditeljima, samo trebam max nivoe da provjeravam
            }
        }

    }
}
void Heap::UPHeap_Min(int i){
    if (Djed(i)!=-1 && elementi[i]<elementi[Djed(i)]){
        swap(elementi[i],elementi[Djed(i)]);
        UPHeap_Min(Djed(i));
}

}
void Heap::UPHeap_Max(int i){
    if (Djed(i)!=-1 && elementi[i] > elementi[Djed(i)]){
        swap(elementi[i],elementi[Djed(i)]);
        UPHeap_Max(Djed(i));
}
}

//Vracaju Min element i Max element iz Heap-a
int Heap::Daj_maximalni(){
     if (max(LijevoDijete(0),DesnoDijete(0)) != -1)
        return max(elementi[LijevoDijete(0)],elementi[DesnoDijete(0)]);
     else {
        return elementi[0];//max je ovo ako je heap samo s jednim elementom
     }

  }
int Heap::Daj_minimalni(){
    if (elementi.size()>0) return elementi[0];
    else {
        cout<<" Heap je prazan ";
    }
}


//vraca index najveceg elmenta , minimalni je uvijek korijen
int Heap::Index_maximalnog(){ //max je uvijek max od djece od korijena
   if (max(LijevoDijete(0),DesnoDijete(0)) != -1){
      int x=max(elementi[LijevoDijete(0)],elementi[DesnoDijete(0)]);
      if (x==elementi[LijevoDijete(0)]) {
        return LijevoDijete(0);
      }
      else{
        return DesnoDijete(0);
      }
   }
   else {
        return 0;//max je ovo ako je heap samo s jednim elementom
   }
}


//pomocna funkcija za brisanje Min/Max elementa
void Heap::DownHeap(int index,bool Parnost){
    if (Parnost){
        int x=Min_unuk_dijete(index);
        if (x==-1) return;
        if (elementi[index]<=elementi[x])
            return;
        else {
            swap(elementi[index],elementi[x]);
            DownHeap(x,Parnost);
        }}
    else{
        int x=Max_unuk_dijete(index);
        if (x==-1) return;
        if (elementi[index]>elementi[x])
            return;
        else {
            swap(elementi[index],elementi[x]);
            DownHeap(x,Parnost);
        }
    }
    return;
}

void Heap::Izbrisi_Min(){
    if (elementi.size()==0) {cout<<"Broj elemenata u heapu je 0" <<endl; return;}
    if (elementi.size()==1) {elementi.pop_back(); cout<< " Izbrisan je jedini element u heapu. " ; return;}
    swap(elementi[0], elementi[elementi.size()-1]);

    elementi.pop_back();

    DownHeap(0,true);

}
void Heap::Izbrisi_Max(){
    if (elementi.size()==0) {cout<<"Broj elemenata u heapu je 0" <<endl; return;}
    if (elementi.size()==1) {elementi.pop_back(); cout<< " Izbrisan je jedini element u heapu. " ; return;}
    int index_maximuma=Index_maximalnog();
    swap(elementi[elementi.size()-1],elementi[index_maximuma]);
    DownHeap(index_maximuma,false);
    elementi.pop_back();
}

ostream& operator<<(ostream& os, const Heap& h){
    int index=0;
    for (int i=0;i<=floor(log(h.elementi.size())/log(2));i++){
        while (floor(log(index+1)/log(2))==i && index<h.elementi.size()){
            os<<h.elementi[index]<<" ";
            index++;
    }
    os<<"\n";
    }
    return os;
}




