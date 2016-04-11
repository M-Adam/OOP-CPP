#include <iostream>
#include <string>

using namespace std;

struct Strona
{
public:
	unsigned short strona;
	Strona *nextStrona;

	Strona(unsigned short pierwszaStrona, Strona *kolejnaStrona) : strona(pierwszaStrona), nextStrona(kolejnaStrona) { }
	Strona(unsigned short pierwszaStrona) : strona(pierwszaStrona), nextStrona(NULL) { }
	Strona():strona(65534), nextStrona(NULL){}
};

struct Element
{
public:
	string haslo;
	Strona *pierwszaStrona;
	Element *nextElement;
	bool pierwszaStronaWolna = true;

	Element(string haslo, Element *kolejnyElement) : haslo(haslo), pierwszaStrona(NULL), nextElement(kolejnyElement) {}
	Element(string haslo) : haslo(haslo), pierwszaStrona(NULL), nextElement(NULL){}
	Element() : haslo(""), pierwszaStrona(NULL), nextElement(NULL){}
};

Element pierwszyElement;
bool pierwszyWolny = true;

bool czyJuzJestStrona(Element *element, unsigned short strona)
{
	if (element->pierwszaStronaWolna) return false;

	Strona *tmp;
	tmp = element->pierwszaStrona;
	while(true)	{
		if (tmp->strona == strona)
			return true;
		if (tmp->nextStrona == NULL)
			return false;
		tmp = tmp->nextStrona;
	}
}

void wypiszWszystko()
{
	Element *tmp_e;
	Strona *tmp_s;
	tmp_e = &pierwszyElement;
	tmp_s = tmp_e->pierwszaStrona;
	if (tmp_e == NULL || tmp_s == NULL) return; // w razie jakby nie by³o ¿adnego has³a

	while (true)	{
		cout << tmp_e->haslo << " ";
		while(true)		{
			if(tmp_s->nextStrona != NULL)
				cout << tmp_s->strona << " ";
			if (tmp_s->nextStrona == NULL)	{
				cout << tmp_s->strona;
				break;
			}
			else
				tmp_s = tmp_s->nextStrona;
		}
		cout << endl;

		if (tmp_e->nextElement == NULL)
			return;
		else {
			tmp_e = tmp_e->nextElement;
			tmp_s = tmp_e->pierwszaStrona;
			if (tmp_e == NULL || tmp_s == NULL) return;
		}
	}
}

void dodajStrone(Element *element, unsigned short strona)
{
	if (element->pierwszaStronaWolna)	{
		element->pierwszaStrona = new Strona(strona);
		element->pierwszaStronaWolna = false;
		return;
	}

	Strona *tmp = element->pierwszaStrona;
	if (element->pierwszaStrona->strona > strona)	{
		element->pierwszaStrona = new Strona(strona, tmp);
		return;
	}
	else if (element->pierwszaStrona->strona == strona)
		return;
	else if(element->pierwszaStrona->strona < strona && element->pierwszaStrona->nextStrona == NULL)	{
		element->pierwszaStrona->nextStrona = new Strona(strona);
		return;
	}

	while(true)	{
		if(tmp->nextStrona->strona > strona)		{
			tmp->nextStrona = new Strona(strona, tmp->nextStrona);
			return;
		}
		else if(tmp->nextStrona->strona == strona)
			return;
		else if (tmp->nextStrona->nextStrona == NULL)		{
			tmp->nextStrona->nextStrona = new Strona(strona);
			return;
		}
		else if(tmp->nextStrona->strona < strona)
			tmp = tmp->nextStrona;
	}
}

Element* znajdzMiejsceNaHaslo(string noweHaslo)
{
	Element *tmp = &pierwszyElement;

	if (tmp->haslo > noweHaslo)
	{
		string stareHaslo = tmp->haslo;
		Strona *stareStrony = tmp->pierwszaStrona;
		Element *staryNext = tmp->nextElement;
		bool stareUstawienie = tmp->pierwszaStronaWolna;
		tmp->haslo = noweHaslo;
		tmp->pierwszaStrona = NULL;
		tmp->pierwszaStronaWolna = true;
		tmp->nextElement = new Element(stareHaslo, staryNext);
		tmp->nextElement->pierwszaStrona = stareStrony;
		tmp->nextElement->pierwszaStronaWolna = stareUstawienie;
		return tmp;
	}
	else if (tmp->haslo == noweHaslo)
		return tmp;
	else if (tmp->haslo < noweHaslo && tmp->nextElement == NULL)
	{
		tmp->nextElement = new Element(noweHaslo);
		return tmp->nextElement;
	}

	while(true)
	{
		if (tmp->nextElement->haslo > noweHaslo)
		{
			Strona *stareStrony = tmp->nextElement->pierwszaStrona;
			//bool stareUstawienie = tmp->nextElement->pierwszaStronaWolna;
			tmp->nextElement = new Element(noweHaslo, tmp->nextElement);
			tmp->nextElement->pierwszaStrona = stareStrony;
			//tmp->nextElement->pierwszaStronaWolna = stareUstawienie;
			return tmp->nextElement;
		}
		else if (tmp->nextElement->haslo == noweHaslo)
		{
			return tmp->nextElement;
		}
		else if (tmp->nextElement->nextElement == NULL)
		{
			tmp->nextElement->nextElement = new Element(noweHaslo);
			return tmp->nextElement->nextElement;
		}
		else if (tmp->nextElement->haslo < noweHaslo)
		{
			tmp = tmp->nextElement;
		}
	}
}

void wejscie()
{
	string haslo;
	cin >> haslo;

	unsigned short iloscStron, strona;
	cin >> iloscStron;
	cin >> strona;

	if (pierwszyWolny) {
		pierwszyElement.haslo = haslo;
		pierwszyWolny = false;

		dodajStrone(&pierwszyElement, strona);

		for (unsigned short i = 0; i < iloscStron - 1; i++)
		{
			cin >> strona;
			dodajStrone(&pierwszyElement, strona);
		}
	}
	else {
		Element *gdzieWstawiamy = znajdzMiejsceNaHaslo(haslo);
		
		dodajStrone(gdzieWstawiamy, strona);

		for (unsigned short i = 0; i < iloscStron - 1; i++)
		{
			cin >> strona;
			dodajStrone(gdzieWstawiamy, strona);
		}
	}	
}

Element* znajdzHaslo(string haslo)
{
	if (pierwszyWolny) return NULL;

	

	if (pierwszyElement.haslo == haslo)
		return &pierwszyElement;
	
	Element *tmp = &pierwszyElement;
	while(true)
	{
		if (tmp->nextElement == NULL)
			return NULL;
		if (tmp->nextElement->haslo == haslo)
			return tmp;
		tmp = tmp->nextElement;
	}
}

bool kasujStrone(Element* element, unsigned short strona)     //true - kasujemy ca³e has³o
{
	if (element == NULL) return false; // element zostal skasowany wczesniej
	if (element->pierwszaStronaWolna) return true;
	else if(element->pierwszaStrona->strona == strona && element->pierwszaStrona->nextStrona==NULL)
	{
		delete element->pierwszaStrona;
		element->pierwszaStrona = NULL;
		element->pierwszaStronaWolna = true;
		return true;
	}
	else if(element->pierwszaStrona->strona == strona && element->pierwszaStrona->nextStrona != NULL)
	{
		element->pierwszaStrona = element->pierwszaStrona->nextStrona;
		return false;
	}
	else if(element->pierwszaStrona->strona > strona)
	{
		return false;
	}

	Strona *tmp = element->pierwszaStrona;

	while (true) {
		if (tmp->nextStrona->strona < strona && tmp->nextStrona != NULL) {
			tmp = tmp->nextStrona;
			continue;
		}
		else if (tmp->nextStrona->strona == strona && tmp->nextStrona->nextStrona != NULL)
		{
			tmp->nextStrona = tmp->nextStrona->nextStrona;

			return false;
		}
		else if (tmp->nextStrona->strona == strona && tmp->nextStrona->nextStrona == NULL)
		{
			delete tmp->nextStrona;
			tmp->nextStrona = NULL;

			return false;
		}
		else if (tmp->nextStrona->strona > strona)
			return false;
	}
}

void kasujHaslo(Element* element)
{
	if(element == &pierwszyElement && pierwszyElement.nextElement == NULL) //kasowanie jedynego hasla
	{
		element->pierwszaStrona = NULL;
		element->nextElement = NULL;
		element->pierwszaStronaWolna = true;
		element->haslo = "";
		pierwszyWolny = true;
		return;
	}
	if (element == &pierwszyElement && pierwszyElement.nextElement != NULL) 
	{
		element->nextElement = element->nextElement->nextElement;
		return;
	}

	if(element->nextElement->nextElement==NULL)
	{
		delete element->nextElement;
		element->nextElement = NULL;
		return;
	}
	if(element->nextElement->nextElement != NULL)
	{
		element->nextElement = element->nextElement->nextElement;
	}
}

void kasacja()
{
	string haslo;
	cin >> haslo;

	unsigned short iloscStron, strona;
	cin >> iloscStron;
	
	if (pierwszyElement.haslo == haslo)	{
		for (unsigned short i = 0; i < iloscStron; i++)		{
			cin >> strona;
			if (kasujStrone(&pierwszyElement, strona))
				kasujHaslo(&pierwszyElement);
		}
	}
	else {
		Element *doKasacji = znajdzHaslo(haslo);

		for (unsigned short i = 0; i < iloscStron; i++)		{
			cin >> strona;
			if (doKasacji == NULL)
				continue;
			if (kasujStrone(doKasacji->nextElement, strona))
				kasujHaslo(doKasacji);
		}
	}
}

void find()
{
	string haslo;
	cin >> haslo;
	unsigned short strona;
	cin >> strona;

	Element *szukaneHaslo = znajdzHaslo(haslo);
	if (szukaneHaslo == NULL)
		cout << "0" << endl;
	else	{
		if (czyJuzJestStrona(szukaneHaslo->nextElement, strona))
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
}

void wypiszStrony(Element* el)
{
	Strona *tmp = el->pierwszaStrona;
	cout << el->haslo << " ";
	while (true)	{
		if(tmp->nextStrona != NULL)
			cout << tmp->strona << " ";
		if (tmp->nextStrona == NULL) {
			cout << tmp->strona << endl;
			break;
		}
		else
			tmp = tmp->nextStrona;
	}
}

void findAll()
{
	string haslo;
	cin >> haslo;

	Element *tmp = znajdzHaslo(haslo);
	if (tmp == NULL) {
		cout << "-1" << endl;
		return;
	}
	wypiszStrony(tmp);
}

int main()
{
	unsigned short iloscPolecen;
	cin >> iloscPolecen;

	for (unsigned short i = 0; i < iloscPolecen; i++)
	{
		char rozkaz;
		cin >> rozkaz;
		switch (rozkaz)		{
		case 'I':
			wejscie();
			break;
		case 'D':
			kasacja();
			break;
		case 'F':
			find();
			break;
		case 'A':
			findAll();
			break;
		case 'P':
			wypiszWszystko();
			break;
		default:
			break;
		}
	}

	return 0;
}