#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <algorithm>
#include "heap.h"
using namespace std;
vector <int> RandomVektor(){
    int RandomVelicina= rand()%50;
    vector<int>vektor(RandomVelicina);
    for (int i=0;i<RandomVelicina;i++){
        vektor[i]=(rand()%500 );
    }
    return vektor;
}
int main() {


  vector<int> v1=RandomVektor();
  Heap h1(v1);
  cout<<"NOVI VEKTOR JE : " <<endl;
  cout<<h1<<endl;

  h1.Izbrisi_Max();
  cout<<endl<< "BEZ MAXIMALNOG : " <<endl;
  cout<<h1<<endl;

  cout <<" ------------------------------------------------------------------------------- "<<endl;



  vector<int> v2=RandomVektor();
  Heap h2(v2);
  cout<<endl;
  cout<<"NOVI VEKTOR JE : " <<endl;
  cout<<h2<<endl;
  h2.Izbrisi_Min();
  cout<<endl<< "BEZ MINIMALNOG : " <<endl;
  cout<<h2<<endl;

  cout <<" ------------------------------------------------------------------------------- "<<endl;



  vector<int> v3=RandomVektor();
  Heap h3(v3);
  cout<<endl;
  cout<<"NOVI VEKTOR JE : " <<endl;
  cout<<h3<<endl;
  h3.Izbrisi_Max();
  cout<<endl<< "BEZ MAXIMALNOG : " <<endl;
  cout<<h3<<endl;
  cout <<" ------------------------------------------------------------------------------- "<<endl;


  vector<int> v4=RandomVektor();
  Heap h4(v4);
  cout<<endl;
  cout<<"NOVI VEKTOR JE : " <<endl;
  cout<<h4<<endl;
  h4.Izbrisi_Min();
  cout<<endl<< "BEZ MINIMALNOG : " <<endl;
  cout<<h4<<endl;

  cout <<" ------------------------------------------------------------------------------- "<<endl;


  vector<int> v5=RandomVektor();
  Heap h5(v5);
  cout<<endl;
  cout<<"NOVI VEKTOR JE : " <<endl;
  cout<<h5<<endl;
  h5.Izbrisi_Max();
  cout<<endl<< "BEZ MAXIMALNOG : " <<endl;
  cout<<h5<<endl;

  cout <<" ------------------------------------------------------------------------------- "<<endl;



  vector<int> v6=RandomVektor();
  Heap h6(v6);
  cout<<endl;
  cout<<"NOVI VEKTOR JE : " <<endl;
  cout<<h6<<endl;
  h6.Izbrisi_Min();
  cout<<endl<< "BEZ MINIMALNOG : " <<endl;
  cout<<h6<<endl;

  cout <<" ------------------------------------------------------------------------------- "<<endl;



  vector<int> v7=RandomVektor();
  Heap h7(v7);
  cout<<endl;
  cout<<"NOVI VEKTOR JE : " <<endl;
  cout<<h7<<endl;
  cout<<endl<< "DODAJ BROJ 999 : " <<endl;
  h7.Dodaj(999);
  cout<<endl<<h7;

  cout <<" ------------------------------------------------------------------------------- "<<endl;


  vector<int> v8=RandomVektor();
  Heap h8(v8);
  cout<<endl;
  cout<<"NOVI VEKTOR JE : " <<endl;
  cout<<h8<<endl;
  cout<<endl<< "DODAJ BROJ 0 : " <<endl;
  h8.Dodaj(0);
  cout<<endl<<h8;

  cout <<" ------------------------------------------------------------------------------- "<<endl;


  vector<int> v9=RandomVektor();
  Heap h9(v9);
  cout<<endl;
  cout<<"NOVI VEKTOR JE : " <<endl;
  cout<<h9<<endl;
  cout<<endl<< "DODAJ BROJ 29 : " <<endl;
  h9.Dodaj(29);
  cout<<endl<<h9;

  cout <<" ------------------------------------------------------------------------------- "<<endl;




}
