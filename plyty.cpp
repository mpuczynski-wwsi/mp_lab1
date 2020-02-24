#include <iostream>
#include <string>

using namespace std;

struct plyta {
  int idPlyty; 
  string tytul;
  string zespol;
  int rok;
  float cena;
};

plyta plyty[]{
  plyta {.idPlyty=1, .tytul="TEST", .zespol="TEST", .rok=1986, .cena=43.5}
};




void menu();
void dodajPlyte();
void szukajWszystkie();
void szukajZespol();
void szukajRok();

int main(int argc, char const *argv[])
{
  //print_array(plyty);
  cout << plyty[0].tytul << endl;
  menu();
  return 0;

}


void szukajWszystkie(){
  cout  << "SZUKAJ WSZYSTKIE" << endl;
}

void szukajZespol(){
  cout  << "SZUKAJ Zespol" << endl;
}

void szukajRok(){
  cout  << "SZUKAJ Rok" << endl;
}

void dodajPlyte() {
  cout  << "DODAJ PLYTE" << endl;

}


void menu(){
  int wybor = 0;
  do {
    cout << "MENU: " << endl;
    cout << "(1) Wyswietl wszystkie plyty" << endl;
    cout << "(2) Wyswietl wszystkie plyty danego zespolu" << endl;
    cout << "(3) Wyswietl wszystkie plyty z podanego roku" << endl;
    cout << "(4) Dodaj nowa plyte" << endl;
    cout << "(0) Wyjdz" << endl;
    cin >> wybor;
    switch (wybor)
    {
    case 1:
      szukajWszystkie();
      break;
    case 2:
      szukajZespol();
      break;
    case 3:
      szukajRok();
      break;
    case 4:
      dodajPlyte();
      break;
    }
  } while (wybor != 0);
}
