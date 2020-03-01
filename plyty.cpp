#include <iostream>
#include <string>
#include <vector>
#include <locale> 

using namespace std;

struct plyta {
  int idPlyty; 
  string tytul;
  string zespol;
  int rok;
  float cena;
};

 std::vector<plyta> plyty = {
  plyta {.idPlyty=1, .tytul="The Greatest Hits I, II & III", .zespol="Queen", .rok=2011, .cena=89.99},
  plyta {.idPlyty=2, .tytul="MTV Unplugged: Scorpions", .zespol="Scorpions", .rok=2013, .cena=45.99},
  plyta {.idPlyty=3, .tytul="Ladies And Gentlemen On Acid", .zespol="Acid Drinkers", .rok=2019, .cena=40.99},
  plyta {.idPlyty=4, .tytul="Spirit Box (Deluxe Edition)", .zespol="Depeche Mode", .rok=2017, .cena=76.99},
  plyta {.idPlyty=5, .tytul="Music for the Masses", .zespol="Depeche Mode", .rok=1987, .cena=49.99},
  plyta {.idPlyty=6, .tytul="Construction Time Again", .zespol="Depeche Mode", .rok=1983, .cena=55.99},
  plyta {.idPlyty=7, .tytul="O.R.S.", .zespol="Grubson", .rok=2009, .cena=12.99},
  plyta {.idPlyty=8, .tytul="Zycie po smierci", .zespol="O.S.T.R.", .rok=2016, .cena=44.99},
  plyta {.idPlyty=9, .tytul="Skladam sie z ciaglych powtorzen", .zespol="Rojek Artur", .rok=2013, .cena=33.99},
};




void menu();
void dodajPlyte();
void szukajWszystkie();
void szukajZespol(string nazwa);
void szukajRok(int rok);
void wyswietl(plyta p);

int main(int argc, char const *argv[])
{
  menu();
  return 0;
}



void szukajWszystkie(){
  cout  << "==> Wszystkie plyty <==" << endl;
  for(int i = 0; i < plyty.size(); i++){
    wyswietl(plyty[i]);
  }
  cout  << "=======================" << endl;

}

void szukajZespol(string nazwa){
  cout  << "==> Wszystkie plyty zespolu \"" << nazwa << " <==" << endl;

  for(int i = 0; i < plyty.size(); i++){
    if (plyty[i].zespol.find(nazwa) != -1){
      wyswietl(plyty[i]);
    }
  }
  cout  << "=======================================" << endl;
}

void szukajRok(int rok){
  cout  << "==> Wszystkie plyty wydane w roku \"" << rok << " <==" << endl;

  for(int i = 0; i < plyty.size(); i++){
    if (plyty[i].rok == rok){
      wyswietl(plyty[i]);
    }
  }
  cout  << "=======================================" << endl;

}

void dodajPlyte() {
  cout  << "==> Dodaj nowa plyte: <==" << endl;
  int idPlyty = plyty.size() + 1; 
  string tytul;
  string zespol;
  int rok;
  float cena;
  cout << "Podaj tytul: "; cin >> ws;
  getline(cin, tytul);
  cout << "Podaj nazwe zespolu: "; cin >> ws;
  getline(cin, zespol);
  cout << "Podaj rok wydania: "; cin >> rok;
  cout << "Podaj cene: "; cin >> cena;

  plyty.push_back(
    plyta {.idPlyty=idPlyty, .tytul=tytul, .zespol=zespol, .rok=rok, .cena=cena}
  );

  cout << "==> Dodano nowa plyte! <==" << endl;

  cout  << "=======================" << endl;
}

void wyswietl(plyta p){
  cout << "Id: " << p.idPlyty << ", Nazwa: " << p.tytul << ", Zespol: " << p.zespol << ", Rok: " << p.rok << endl;
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
    string nazwa;
    int rok;
    switch (wybor)
    {
    case 1:
      szukajWszystkie();
      break;
    case 2:
      cout << "Podaj nazwe zespolu ktory chcesz wyszukac" << endl;
      cin >> ws;
      getline(cin, nazwa);
      szukajZespol(nazwa);
      break;
    case 3:
      cout << "Podaj rok ktory chcesz wyszukac" << endl;
      cin >> rok;
      szukajRok(rok);
      break;
    case 4:
      dodajPlyte();
      break;
    }
  } while (wybor != 0);
}
