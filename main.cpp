#include <iostream>
#include <vector>

using namespace std;

// --------------------
// PONIZEJ ZNAJDUJE SIE 5 HIERARCHII, aż do 4 poziomu -> łącznie 23 klasy
// --------------------

/// 5 przeciazonych operatorow dodanych dla klasy Pojazd
//
/// Klasy generyczne znajduja sie w oddzielnym pliku




/* ---------------------------------------------
Hierarchia związana z Kontem
------------------------------------ */

// Klasa wirtualna

class KontoWirtualne {
	virtual void pokazNazweKonta() = 0;
	virtual void pokazImieKonta() = 0;
	virtual void pokazNazwiskoKonta() = 0;
	virtual void pokazDateDolaczenia() = 0;
	virtual void czyModerator() = 0;
};

// Klasa nadrzędna

class KontoOgolne : public KontoWirtualne {
protected: // do ukazania mechanizmu dziedziczenia
	string nazwa;
	string imie;
	string nazwisko;
	string data_dolaczenia;
	bool czy_moderator;

public: // aby móc uzyc funkcji w mainie
	virtual void pokazNazweKonta() {
		cout << nazwa << endl;
	}
	virtual void pokazImieKonta() {
		cout << imie << endl;
	}
	virtual void pokazNazwiskoKonta() {
		cout << nazwisko << endl;
	}
	virtual void pokazDateDolaczenia() {
		cout << data_dolaczenia << endl;
	}

	virtual void czyModerator() {
		if (czy_moderator==1) {
			cout << "To konto moderatora" << endl;
		}
		else {
			//cout << czy_moderator << endl;
			cout << "To konto normalnego uzytkownika" << endl;
		}
	}



};

// Klasy

class Moderator : public KontoOgolne {
protected:
	friend class KategoriaOgolna;
	friend class PortalOgloszeniowyOgolny;

	friend void friendModeratoraZmienImie(Moderator &moderator, string noweImie);

	void pokazDane() {
		cout << endl << "Wyswietlam dane konta moderatora: " << endl;
		cout << "Nazwa konta: ";
		pokazNazweKonta();
		cout << "Imie: ";
		pokazImieKonta();
		cout << "Nazwisko: ";
		pokazNazwiskoKonta();
		cout << "Data dolaczenia: ";
		pokazDateDolaczenia();
		cout << "Typ konta: ";
		czyModerator();
	}

public:
	Moderator(string nazwa, string imie, string nazwisko, string data_dolaczenia, bool czy_moderator) {
		this->nazwa = nazwa;
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->data_dolaczenia = data_dolaczenia;
		this->czy_moderator = czy_moderator;
	}

	~Moderator() {
		cout << "Obiekt klasy Moderator o nazwie: " << nazwa << " zostal usuniety" << endl;
	}

	void zbanujUzytkownika(string nazwaUzytkownika) {
		cout << "Uzytkownik o nazwie " << nazwaUzytkownika << " zostal zbanowany!" << endl;
	}

};


void friendModeratoraZmienImie(Moderator &moderator, string noweImie) {
	moderator.imie = noweImie;
}


class Uzytkownik : public KontoOgolne {
protected:
	friend class OgloszenieOgolne;
	friend class PrzedmiotOgolny;
	friend class PortalOgloszeniowyOgolny;

	friend void friendUzytkownikZmienNazwe(Uzytkownik &uzytkownik, string nowaNazwa);

	void pokazDane() {
		cout << endl << "Wyswietlam dane konta uzytkownika: " << endl;
		cout << "Nazwa konta: ";
		pokazNazweKonta();
		cout << "Imie: ";
		pokazImieKonta();
		cout << "Nazwisko: ";
		pokazNazwiskoKonta();
		cout << "Data dolaczenia: ";
		pokazDateDolaczenia();
		cout << "Typ konta: ";
		czyModerator();
	}

public:

	Uzytkownik(string nazwa, string imie, string nazwisko, string data_dolaczenia, bool czy_moderator) {
		this->nazwa = nazwa;
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->data_dolaczenia = data_dolaczenia;
		this->czy_moderator = czy_moderator;
	}

	~Uzytkownik() {
		cout << "Obiekt klasy Uzytkownik o nazwie: " << nazwa << " zostal usuniety" << endl;
	}

	void dodajOgloszenie() {
		cout << "Uzytkownik: " << nazwa << " dodaje ogloszenie!" << endl;
	}

	void usunOgloszenie() {
		cout << "Uzytkownik: " << nazwa << " usuwa ogloszenie!" << endl;
	}

};

void friendUzytkownikZmienNazwe(Uzytkownik &uzytkownik, string nowaNazwa) {
	uzytkownik.nazwa = nowaNazwa;
}




/* ------------------------------------------------------------
Hierarchia związana z Kategorią
------------------------------------------------------------ */

// Klasa wirtualna

class KategoriaWirtualna {
	virtual void pokazNazweKategorii() = 0;
	virtual void pokazOpisKategorii() = 0;
	virtual void pokazDaneModeratoraKtoryDodalKategorie() = 0; // funkcja z klasy Moderator
	virtual void pokazPrzedmiotyKtoreZawieraKategoria() = 0; // funkcja z klasy konkretnej kategorii
	virtual void pokazIloscOgloszenKategorii() = 0; // funkcja z klasy konkretnej kategorii 
};

// Klasa nadrzędna

class KategoriaOgolna : public KategoriaWirtualna {
protected:
	string nazwa;
	string opis;
	Moderator *moderator;

public: 
	virtual void pokazNazweKategorii() {
		cout << nazwa << endl;
	}
	virtual void pokazOpisKategorii() {
		cout << opis << endl;
	}
	virtual void pokazDaneModeratoraKtoryDodalKategorie() {
		moderator->pokazDane();
	}
};

// Klasy

class KategoriaNieruchomosci : public KategoriaOgolna {
protected:
	friend class OgloszenieNieruchomosci;
	friend class Nieruchomosc;


	void wyswietlDane() {
		cout << "Dane kategorii: " << endl;
		cout << "Nazwa: ";
		pokazNazweKategorii();
		cout << "Opis: ";
		pokazOpisKategorii();
		cout << "Dane moderatora, ktory dodal kategorie: " << endl;
		pokazDaneModeratoraKtoryDodalKategorie();
		cout << endl;
	}

public:

	KategoriaNieruchomosci(string nazwa, string opis, Moderator *moderator) {
		this->nazwa = nazwa;
		this->opis = opis;
		this->moderator = moderator;
	}

	~KategoriaNieruchomosci() {
		cout << "Obiekt klasy KategoriaNieruchomosci o nazwie: " << nazwa << " zostal usuniety" << endl;
	}

	virtual void pokazPrzedmiotyKtoreZawieraKategoria() {
		cout << "Wyswietlenie wszystkich przedmiotow przypisanych do tej kategorii" << endl;
	}

	virtual void pokazIloscOgloszenKategorii() {
		cout << "Liczba ogloszen tej kategorii" << endl;
	}
};

class KategoriaPojazdy : public KategoriaOgolna {

protected:
	friend class OgloszeniePojazdu;
	friend class Pojazd;


	friend void friendKategoriaPojazdyZmienOpis(KategoriaPojazdy &kategoriapojazdy, string nowyOpis);

	void wyswietlDane() {
		cout << "Dane kategorii: " << endl;
		cout << "Nazwa: ";
		pokazNazweKategorii();
		cout << "Opis: ";
		pokazOpisKategorii();
		cout << "Dane moderatora, ktory dodal kategorie: " << endl;
		pokazDaneModeratoraKtoryDodalKategorie();
		cout << endl;
	}

public:
	KategoriaPojazdy(string nazwa, string opis, Moderator *moderator) {
		this->nazwa = nazwa;
		this->opis = opis;
		this->moderator = moderator;
	}

	~KategoriaPojazdy() {
		cout << "Obiekt klasy KategoriaPojazdy o nazwie: " << nazwa << " zostal usuniety" << endl;
	}


	virtual void pokazPrzedmiotyKtoreZawieraKategoria() {
		cout << "Wyswietlenie wszystkich przedmiotow przypisanych do tej kategorii" << endl;
	}

	virtual void pokazIloscOgloszenKategorii() {
		cout << "Liczba ogloszen tej kategorii" << endl;
	}




};

void friendKategoriaPojazdyZmienOpis(KategoriaPojazdy &kategoriapojazdy, string nowyOpis) {
	kategoriapojazdy.opis = nowyOpis;
}



class KategoriaPrzedmiot : public KategoriaOgolna {
protected:
	friend class OgloszeniePrzedmiotu;
	friend class Przedmiot;

	void wyswietlDane() {
		cout << "Dane kategorii: " << endl;
		cout << "Nazwa: ";
		pokazNazweKategorii();
		cout << "Opis: ";
		pokazOpisKategorii();
		cout << "Dane moderatora, ktory dodal kategorie: " << endl;
		pokazDaneModeratoraKtoryDodalKategorie();
		cout << endl;
	}

public:
	KategoriaPrzedmiot(string nazwa, string opis, Moderator *moderator) {
		this->nazwa = nazwa;
		this->opis = opis;
		this->moderator = moderator;
	}

	~KategoriaPrzedmiot() {
		cout << "Obiekt klasy KategoriaPrzedmiot o nazwie: " << nazwa << " zostal usuniety" << endl;
	}

	virtual void pokazPrzedmiotyKtoreZawieraKategoria() {
		cout << "Wyswietlenie wszystkich przedmiotow przypisanych do tej kategorii" << endl;
	}

	virtual void pokazIloscOgloszenKategorii() {
		cout << "Liczba ogloszen tej kategorii" << endl;
	}


 };




/* ------------------------------------------------------------
Hierarchia związana z Przedmiotem
------------------------------------------------------------ */

// Klasa wirtualna

class PrzedmiotWirtualny {
	virtual void pokazNazwePrzedmiotu() = 0;
	virtual void pokazKategoriePrzedmiotu() = 0; // do kategorii odwolanie
	virtual void pokazStanPrzedmiotu() = 0;
	virtual void pokazDateDodaniaPrzedmiotu() = 0;
	virtual void pokazTworcePrzedmiotu() = 0;
};

// Klasa nadrzedna

class PrzedmiotOgolny : public PrzedmiotWirtualny {
protected:
	string nazwa;
	string stan;
	string data_dodania;
	Uzytkownik *tworca;

public:

	virtual void pokazNazwePrzedmiotu() {
		cout << nazwa << endl;
	}
	virtual void pokazStanPrzedmiotu() {
		cout << stan << endl;
	}
	virtual void pokazDateDodaniaPrzedmiotu() {
		cout << data_dodania << endl;
	}
	virtual void pokazTworcePrzedmiotu() {
		tworca->pokazDane();
	}

};

// Klasy

class Nieruchomosc : public PrzedmiotOgolny {

protected:
	friend class KategoriaNieruchomosci;
	friend class OgloszenieNieruchomosci;

	KategoriaNieruchomosci *kategoria;
	int czy_dodana_kategoria;

	string metraz;
	int ilePokojow;

	void pokazDane() {
		pokazNazwePrzedmiotu();
		if (czy_dodana_kategoria==1) {
			kategoria->wyswietlDane();
		}
		pokazStanPrzedmiotu();
		pokazDateDodaniaPrzedmiotu();
		pokazTworcePrzedmiotu();
		cout << metraz << endl;
		cout << ilePokojow << endl;
	}


public:
	Nieruchomosc(string nazwa, string stan, string data_dodania, Uzytkownik *tworca, string metraz, int ilePokojow) {
		this->nazwa = nazwa;
		this->stan = stan;
		this->data_dodania = data_dodania;
		this->tworca = tworca;
		this->metraz = metraz;
		this->ilePokojow = ilePokojow;
		czy_dodana_kategoria = 0;
	}

	void dodajKategorie(KategoriaNieruchomosci *kategoria) {
		this->kategoria = kategoria;
		czy_dodana_kategoria = 1;
	}

	~Nieruchomosc() {
		cout << "Obiekt klasy Nieruchomosc o nazwie: " << nazwa << " zostal usuniety" << endl;
	}


	virtual void pokazKategoriePrzedmiotu() {
		kategoria->wyswietlDane();
	}



};


class Przedmiot : public PrzedmiotOgolny {

protected:
	friend class KategoriaPrzedmiot;
	friend class OgloszeniePrzedmiotu;

	KategoriaPrzedmiot *kategoria;
	int czy_dodana_kategoria;

	void pokazDane() {
		pokazNazwePrzedmiotu();
		if (czy_dodana_kategoria==1) {
			kategoria->wyswietlDane();
		}
		pokazStanPrzedmiotu();
		pokazDateDodaniaPrzedmiotu();
		pokazTworcePrzedmiotu();
	}

public:
	Przedmiot (string nazwa, string stan, string data_dodania, Uzytkownik *tworca) {
		this->nazwa = nazwa;
		this->stan = stan;
		this->data_dodania = data_dodania;
		this->tworca = tworca;
		czy_dodana_kategoria = 0;
	}

	~Przedmiot() {
		cout << "Obiekt klasy Przedmiot o nazwie: " << nazwa << " zostal usuniety" << endl;
	}

	void dodajKategorie(KategoriaPrzedmiot *kategoria) {
		this->kategoria = kategoria;
		czy_dodana_kategoria = 1;
	}


	virtual void pokazKategoriePrzedmiotu() {
		kategoria->wyswietlDane();
	}

	

};


class Pojazd : public PrzedmiotOgolny{

protected:
	friend class KategoriaPojazdy;
	friend class OgloszeniePojazdu;

	KategoriaPojazdy *kategoria;
	int czy_dodana_kategoria;

	string marka;
	string model;
	int rok_produkcji;
	float objetosc_silnika;

	friend void friendPojazduZmienMarke(Pojazd &pojazd, string nowaMarka);

	void pokazDane() {
		cout << "Dane pojazdu: " << endl;
		cout << "Nazwa: ";
		pokazNazwePrzedmiotu();
		cout << "Marka: " << marka << endl;
		cout << "Model: " << model << endl;
		cout << "Rok produkcji: " << rok_produkcji << endl;
		cout << "Objetosc silnika: " << objetosc_silnika << endl;
		cout << "Stan pojazdu: ";
		pokazStanPrzedmiotu();
		cout << "Data dodania pojazdu: ";
		pokazDateDodaniaPrzedmiotu();
		if (czy_dodana_kategoria==1) {
			cout << "- Wyswietlam dane kategorii pojazdu: " << endl;
			kategoria->wyswietlDane();
		}
		
		cout << "- Wyswietlam dane tworcy pojazdu: ";
		pokazTworcePrzedmiotu();
	}


public:
	Pojazd(string nazwa, string stan, string data_dodania, Uzytkownik *tworca, string marka, string model, int rok_produkcji, float objetosc_silnika) {
		this->nazwa = nazwa;
		this->stan = stan;
		this->data_dodania = data_dodania;
		this->tworca = tworca;
		this->marka = marka;
		this->model = model;
		this->rok_produkcji = rok_produkcji;
		this->objetosc_silnika = objetosc_silnika;
		czy_dodana_kategoria = 0;
	}

	~Pojazd() {
		cout << "Obiekt klasy Pojazd o nazwie: " << nazwa << " zostal usuniety" << endl;
	}

	void dodajKategorie(KategoriaPojazdy *kategoria) {
		this->kategoria = kategoria;
		czy_dodana_kategoria = 1;
	}

	void pokazDanePublicznaFunkcjaDoMaina() {
		pokazDane();
	}

	// przeciazone operatory

	void operator+=(float oile) {
		// zwiekszenie objetosci silnika samochodu 
		objetosc_silnika += oile;
	}

	void operator-=(float oile) {
		// zmniejszenie objetosci silnika samochodu 
		objetosc_silnika -= oile;
	}

	void operator*=(float oile) {
		// przemnozenie objetosci silnika przez liczbe
		objetosc_silnika *= oile;
	}

	void operator+(int ile) {
		// zwiekszenie roku produkcji
		rok_produkcji += ile;
	}

	void operator-(float ile) {
		// zmniejszenie roku produkcji
		rok_produkcji -= ile;
	}

	virtual void pokazKategoriePrzedmiotu() {
		kategoria->wyswietlDane();
	}
};


void friendPojazduZmienMarke(Pojazd &pojazd, string nowaMarka) {
	pojazd.marka = nowaMarka;
}








/* ------------------------------------------------------------
Hierarchia zwiazana z Ogłoszeniem
------------------------------------------------------------ */

// Klasa wirtualna

class OgloszenieWirtualne {
	virtual void pokazTytulOgloszenia() = 0; 
	virtual void pokazOpisOgloszenia() = 0; 
	virtual void pokazDateUtworzenia() = 0;
	virtual void pokazDaneSprzedawcy() = 0; // funkcja z klasy Uzytkownik
	virtual void pokazDaneKategorii() = 0; // funkcja z klasy Kategorii
	virtual void pokazDanePrzedmiotu() = 0; // funkcja z klasy Przedmiotu
};

// Klasa nadrzedna

class OgloszenieOgolne : public OgloszenieWirtualne {
protected:
	string tytul;
	string opis;
	string data_utworzenia;
	Uzytkownik *sprzedawca;

	virtual void pokazTytulOgloszenia() {
		cout << tytul << endl;
	}
	virtual void pokazOpisOgloszenia() {
		cout << opis << endl;
	}
	virtual void pokazDateUtworzenia() {
		cout << data_utworzenia << endl;
	}
	virtual void pokazDaneSprzedawcy() {
		sprzedawca->pokazDane();
	}
	
};

// Klasy

class OgloszenieNieruchomosci : public OgloszenieOgolne{
protected:
	friend class KategoriaNieruchomosci;
	friend class PortalOgloszeniowyPrzedmiotyNieruchomosciPojazdy;

	Nieruchomosc *nieruchomosc;
	KategoriaNieruchomosci *kategoria;

	void wyswietlDane() {
		cout << endl;
		cout << "Ogloszenie: " << endl;
		cout << "Tytul: " << tytul << endl;
		cout << "Opis: " << opis << endl;
		cout << "Data utworzenia: " << data_utworzenia << endl;
		cout << "Nazwa sprzedawcy: ";
		sprzedawca->pokazNazweKonta();
		cout << "Nazwa przedmiotu: ";
		nieruchomosc->pokazNazwePrzedmiotu();
		cout << "Nazwa kategorii: ";
		kategoria->pokazNazweKategorii();
		cout << endl;
	}

public:
	virtual void pokazDaneKategorii() {
		kategoria->wyswietlDane();
	}
	virtual void pokazDanePrzedmiotu() {
		nieruchomosc->pokazDane();
	}

	OgloszenieNieruchomosci(string tytul, string opis, string data_utworzenia, Uzytkownik *sprzedawca, Nieruchomosc *nieruchomosc, KategoriaNieruchomosci *kategoria) {
		this->tytul = tytul;
		this->opis = opis;
		this->data_utworzenia = data_utworzenia;
		this->sprzedawca = sprzedawca;
		this->nieruchomosc = nieruchomosc;
		this->kategoria = kategoria;
	}

	~OgloszenieNieruchomosci() {
		cout << "Obiekt klasy OgloszenieNieruchomosci o tytule: " << tytul << " zostal usuniety" << endl;
	}
};


class OgloszeniePrzedmiotu : public OgloszenieOgolne {
protected:
	friend class KategoriaPrzedmiot;
	friend class PortalOgloszeniowyPrzedmiotyNieruchomosciPojazdy;

	Przedmiot *przedmiot;
	KategoriaPrzedmiot *kategoria;

	void wyswietlDane() {
		cout << endl;
		cout << "Ogloszenie: " << endl;
		cout << "Tytul: " << tytul << endl;
		cout << "Opis: " << opis << endl;
		cout << "Data utworzenia: " << data_utworzenia << endl;
		cout << "Nazwa sprzedawcy: ";
		sprzedawca->pokazNazweKonta();
		cout << "Nazwa przedmiotu: ";
		przedmiot->pokazNazwePrzedmiotu();
		cout << "Nazwa kategorii: ";
		kategoria->pokazNazweKategorii();
		cout << endl;
	}

public:
	virtual void pokazDaneKategorii() {
		kategoria->wyswietlDane();
	}
	virtual void pokazDanePrzedmiotu() {
		przedmiot->pokazDane();
	}

	OgloszeniePrzedmiotu(string tytul, string opis, string data_utworzenia, Uzytkownik *sprzedawca, Przedmiot *przedmiot, KategoriaPrzedmiot *kategoria) {
		this->tytul = tytul;
		this->opis = opis;
		this->data_utworzenia = data_utworzenia;
		this->sprzedawca = sprzedawca;
		this->przedmiot = przedmiot;
		this->kategoria = kategoria;
	}

	~OgloszeniePrzedmiotu() {
		cout << "Obiekt klasy OgloszeniePrzedmiotu o tytule: " << tytul << " zostal usuniety" << endl;
	}
};



class OgloszeniePojazdu : public OgloszenieOgolne {
protected:
	friend class KategoriaPojazdy;
	friend class PortalOgloszeniowyPrzedmiotyNieruchomosciPojazdy;

	Pojazd *pojazd;
	KategoriaPojazdy *kategoria;

	friend void friendOgloszeniePojazduZmienTytul(OgloszeniePojazdu &ogloszeniepojazdu, string nowyTytul);

	void wyswietlDane() {
		cout << endl;
		cout << "Ogloszenie: " << endl;
		cout << "Tytul: " << tytul << endl;
		cout << "Opis: " << opis << endl;
		cout << "Data utworzenia: " << data_utworzenia << endl;
		cout << "Nazwa sprzedawcy: ";
		sprzedawca->pokazNazweKonta();
		cout << "Nazwa przedmiotu: ";
		pojazd->pokazNazwePrzedmiotu();
		cout << "Nazwa kategorii: ";
		kategoria->pokazNazweKategorii();
		cout << endl;
	}

public:
	virtual void pokazDaneKategorii() {
		kategoria->wyswietlDane();
	}
	virtual void pokazDanePrzedmiotu() {
		pojazd->pokazDane();
	}

	OgloszeniePojazdu(string tytul, string opis, string data_utworzenia, Uzytkownik *sprzedawca, Pojazd *pojazd, KategoriaPojazdy *kategoria) {
		this->tytul = tytul;
		this->opis = opis;
		this->data_utworzenia = data_utworzenia;
		this->sprzedawca = sprzedawca;
		this->pojazd = pojazd;
		this->kategoria = kategoria;
	}

	~OgloszeniePojazdu() {
		cout << "Obiekt klasy OgloszeniePojazdu o tytule: " << tytul << " zostal usuniety" << endl;
	}
};

void friendOgloszeniePojazduZmienTytul(OgloszeniePojazdu &ogloszeniepojazdu, string nowyTytul) {
	ogloszeniepojazdu.tytul = nowyTytul;
}






/* --------------------------------------------
Hierarchia związana z Portalem
------------------------------------ */

// Klasa wirtualna

class PortalWirtualny {
	virtual void wyswietlWszystkichUzytkownikow() = 0;
	virtual void wyswietlWszystkichModeratorow() = 0;
	virtual void wyswietlWszystkieOgloszenia() = 0;
	virtual void wyswietlNazwe() = 0;
	virtual void wyswietlWlasciciela() = 0;
};


// Klasa nadrzedna, ogolny portal

class PortalOgloszeniowyOgolny : public PortalWirtualny {
protected:
	string nazwa;
	string data_utworzenia;

	vector<Uzytkownik*> uzytkownicy;
	vector<Moderator*> moderatorzy;
	
public:
	virtual void wyswietlNazwe() {
		cout << nazwa << endl;
	}

	virtual void wyswietlWszystkichUzytkownikow() {
		cout << endl << "----- Wyswietlam wszystkich uzytkownikow portalu: " << endl;
		for (int i = 0; i<uzytkownicy.size(); ++i) {
			uzytkownicy[i]->pokazDane();
		}
		cout << endl;
	}

	virtual void wyswietlWszystkichModeratorow() {
		cout << endl << "----- Wyswietlam wszystkich moderatorow portalu: " << endl;
		for (int i = 0; i<moderatorzy.size(); ++i) {
			moderatorzy[i]->pokazDane();
		}
		cout << endl;
	}

	void dodajModeratoraDoPortalu(Moderator* mod) {
		moderatorzy.push_back(mod);
	}

	void dodajUzytkownikaDoPortalu(Uzytkownik* uzyt) {
		uzytkownicy.push_back(uzyt);
	}
};


// Klasy dziedziczace, portal o konkretnym przeznaczeniu

class PortalOgloszeniowyPrzedmiotyNieruchomosciPojazdy : public PortalOgloszeniowyOgolny {
protected:
	vector<OgloszenieNieruchomosci*> ogloszenianieruchomosci;
	vector<OgloszeniePrzedmiotu*> ogloszeniaprzedmiotu;
	vector<OgloszeniePojazdu*> ogloszeniapojazdow;

public:
	virtual void wyswietlWszystkieOgloszenia() {
		cout << endl << "----- Wyswietlam wszystkie ogloszenia portalu: " << endl;
		for (int i = 0; i<ogloszenianieruchomosci.size(); ++i) {
			ogloszenianieruchomosci[i]->wyswietlDane();
		}
		for (int i = 0; i<ogloszeniaprzedmiotu.size(); ++i) {
			ogloszeniaprzedmiotu[i]->wyswietlDane();
		}
		for (int i = 0; i<ogloszeniapojazdow.size(); ++i) {
			ogloszeniapojazdow[i]->wyswietlDane();
		}
		cout << endl;
	}

	void dodajOgloszenieNieruchomosciDoPortalu(OgloszenieNieruchomosci* ogl) {
		ogloszenianieruchomosci.push_back(ogl);
	}

	void dodajOgloszeniePrzedmiotuDoPortalu(OgloszeniePrzedmiotu* ogl) {
		ogloszeniaprzedmiotu.push_back(ogl);
	}

	void dodajOgloszeniePojazduDoPortalu(OgloszeniePojazdu* ogl) {
		ogloszeniapojazdow.push_back(ogl);
	}
};


// Czwarty poziom hierarchii, konkretna strona z portalem dziedziczaca z klasy portalu o konkretnym przeznaczeniu

class NajlepszyPortalOgloszeniowyPL : public PortalOgloszeniowyPrzedmiotyNieruchomosciPojazdy {
protected:
	string domena;
	string wlasciciel;

public:
	NajlepszyPortalOgloszeniowyPL(string nazwa, string data_utworzenia, string domena, string wlasciciel) {
		this->nazwa = nazwa;
		this->data_utworzenia = data_utworzenia;
		this->domena = domena;
		this->wlasciciel = wlasciciel;
	}

	~NajlepszyPortalOgloszeniowyPL() {
		cout << "Obiekt klasy NajlepszyPortalOgloszeniowyPL o nazwie: " << nazwa << " zostal usuniety" << endl;
	}

	virtual void wyswietlWlasciciela() {
		cout << wlasciciel << endl;
	}
};













/*  -------------------------------------
Funkcja glowna 
----------------------------- */

int main() {
	cout << "-----------------------------------------------------" << endl;
	cout << "		DEMONSTRACJA DZIALANIA PROGRAMU" << endl;
	cout << "-----------------------------------------------------" << endl << endl;

	// tworzenie obiektu portalu
	NajlepszyPortalOgloszeniowyPL *portal1 = new NajlepszyPortalOgloszeniowyPL("Najlepszy portal ogloszeniowy", "1.01.2023 r.", "najlepszyportal.pl", "Michał Błaszczykowski");

	// tworze moderatora
	Moderator *moderator1 = new Moderator("mod1", "Jakub", "Cabacki", "5.12.2022", 1);
	portal1->dodajModeratoraDoPortalu(moderator1);

	// moderator tworzy kategorie ogloszen
	KategoriaPojazdy *kategoriapojazdy1 = new KategoriaPojazdy("Pojazdy", "W tej kategorii znajdziesz zarowno nowe jak i uzywane pojazdy", moderator1);
	KategoriaPrzedmiot *kategoriaprzedmiot1 = new KategoriaPrzedmiot("Przedmioty", "W tej kategorii znajdziesz zarowno nowe jak i uzywane przedmioty", moderator1);
	KategoriaNieruchomosci *kategorianieruchomosci1 = new KategoriaNieruchomosci("Nieruchomosci", "W tej kategorii znajdziesz najlepsze nieruchomosci w miescie", moderator1);

	// tworze uzytkownikow
	Uzytkownik *uzytkownik1 = new Uzytkownik("uzytkownik1", "Jan", "Kowalski", "14.12.2022", 0);
	portal1->dodajUzytkownikaDoPortalu(uzytkownik1);
	Uzytkownik *uzytkownik2 = new Uzytkownik("uzytkownik2", "Bartosz", "Abacki", "18.12.2022", 0);
	portal1->dodajUzytkownikaDoPortalu(uzytkownik2);
	Uzytkownik *uzytkownik3 = new Uzytkownik("uzytkownik3", "Grzegorz", "Babacki", "23.12.2022", 0);
	portal1->dodajUzytkownikaDoPortalu(uzytkownik3);

	// uzytkownicy tworza przedmioty i ogloszenia
	Pojazd *pojazd1 = new Pojazd("Nowy Mercedes", "Jak nowy", "15.12.2022", uzytkownik1, "Mercedes", "CLA200", 2022, 1.8);
	OgloszeniePojazdu *ogloszeniepojazdu1 = new OgloszeniePojazdu("Sprzedam auto", "Świetny samochód polecam", "23.12.2002", uzytkownik1, pojazd1, kategoriapojazdy1);
	portal1->dodajOgloszeniePojazduDoPortalu(ogloszeniepojazdu1);

	Nieruchomosc *nieruchomosc1 = new Nieruchomosc("Piekne mieszkanie 60m2", "Nowe", "19.12.2022", uzytkownik2, "60m2", 3);
	OgloszenieNieruchomosci *ogloszenienieruchomosci1 = new OgloszenieNieruchomosci("Sprzedam piekne mieszkanie w centrum", "60m2, blisko metro, park", "19.12.2022", uzytkownik2, nieruchomosc1, kategorianieruchomosci1);
	portal1->dodajOgloszenieNieruchomosciDoPortalu(ogloszenienieruchomosci1);

	Przedmiot *przedmiot1 = new Przedmiot("Laptop DELL XPS15", "Jak nowy", "23.12.2022", uzytkownik3);
	OgloszeniePrzedmiotu *ogloszenieprzedmiotu1 = new OgloszeniePrzedmiotu("Sprzedam jak nowego laptopa DELL XPS15", "Laptop wydajny, uzywany tydzien", "23.12.2022", uzytkownik3, przedmiot1, kategoriaprzedmiot1);
	portal1->dodajOgloszeniePrzedmiotuDoPortalu(ogloszenieprzedmiotu1);



	cout << endl << "----- Dane pojazdu1 przed uzyciem przeciazonych operatorow: -----" << endl;
	pojazd1->pokazDanePublicznaFunkcjaDoMaina();

	// wykorzystanie przeciazonych operatorow do zwiekszenia badz zmniejszenia objetosci silnika samochodu o wartosc float a potem przemnozenie 
	*pojazd1 += 0.3;
	*pojazd1 -= 0.1;
	*pojazd1 *= 2;

	// do zwiekszenia i zmniejszenia roku produkcji 
	*pojazd1 + 3;
	*pojazd1 - 1;

	cout << endl << "----- Dane pojazdu1 po uzyciu przeciazonych operatorow: -----" << endl;
	pojazd1->pokazDanePublicznaFunkcjaDoMaina();



	// wywolanie 5 funkcji zaprzyjaznionych dla 5 roznych klas do zmiany wartosci atrybutow obiektow

	friendPojazduZmienMarke(*pojazd1, "zmieniona_marka Mercedes-AMG");
	//pojazd1->pokazDane();

	friendModeratoraZmienImie(*moderator1, "zmienione_imie Waldek");
	//moderator1->pokazDane();

	friendKategoriaPojazdyZmienOpis(*kategoriapojazdy1, "zmieniony_opis W tej kategorii znajdziesz zarowno nowe jak i uzywane pojazdy");
	//kategoriapojazdy1->wyswietlDane();

	friendUzytkownikZmienNazwe(*uzytkownik1, "zmieniona_nazwa_uzytkownik1");
	//uzytkownik1->pokazDane();

	friendOgloszeniePojazduZmienTytul(*ogloszeniepojazdu1, "zmieniony_tytul Sprzedam Mercedesa-AMG");
	//ogloszeniepojazdu1->wyswietlDane();
	



	// wyswietlamy dane portalu wszystkie na koniec po dodaniu i jednoczesnie ich funkcje opisujace te obiekty
	cout << endl << endl << endl << "------------ Podsumowanie portalu: " << endl << endl;
	portal1->wyswietlWszystkichModeratorow();
	portal1->wyswietlWszystkichUzytkownikow();
	portal1->wyswietlWszystkieOgloszenia();




	// zwalnianie pamieci, usuwanie i wywolywanie destruktorow wszystkich powolanych obiektow
	cout << endl;
	cout << "	[Konczenie dzialania progamu] " << endl << endl;

	delete pojazd1;
	delete nieruchomosc1;
	delete przedmiot1;

	delete ogloszeniepojazdu1;
	delete ogloszenienieruchomosci1;
	delete ogloszenieprzedmiotu1;
	
	delete kategoriapojazdy1;
	delete kategoriaprzedmiot1;
	delete kategorianieruchomosci1;

	delete uzytkownik1;
	delete uzytkownik2;
	delete uzytkownik3;

	delete moderator1;

	delete portal1;

	cout << endl;

	return 0;
}






