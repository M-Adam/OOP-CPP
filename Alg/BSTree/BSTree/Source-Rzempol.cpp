#include <iostream>
#include <string>
using namespace std;

struct NodeStrona
{
public:
	unsigned short strona;
	NodeStrona *lewo, *prawo;

	NodeStrona(unsigned short strona)
	{
		this->strona = strona;
		this->prawo = NULL;
		this->lewo = NULL;
	}
};

struct NodeHaslo
{
public:
	string haslo;
	NodeHaslo *lewo, *prawo;
	NodeStrona* rootStrona;

	NodeHaslo(string haslo)
	{
		this->haslo = haslo;
		this->lewo = NULL;
		this->prawo = NULL;
		this->rootStrona = NULL;
	}
};

NodeHaslo* rootHaslo = NULL;

NodeHaslo* dodajHaslo(string);
NodeHaslo* znajdzHaslo(string);
void wyswietlWszystko(NodeHaslo*);
void wyswietlWszystkieStrony(NodeStrona*);
NodeHaslo* znajdzRodzicaHasla(string);
NodeHaslo* znajdzMinHaslo(NodeHaslo*);
void kasujRootaHaslo();
bool kasujHaslo(string);
NodeStrona* znajdzStrona(NodeHaslo*, unsigned short);
NodeStrona* znajdzMinStrone(NodeStrona*);
NodeStrona* dodajStrone(NodeHaslo*, unsigned short);
NodeStrona* znajdzRodzicaStrony(NodeStrona*, unsigned short);
void wyswietlWszystkieStrony(NodeStrona*);
bool kasujStrone(NodeHaslo*, unsigned short);
void kasujRootaStrone(NodeHaslo*);
char czyHasloWystepujeNaStronie(string, unsigned short);
void jesliIstniejeToWyswietl(string);


NodeHaslo* dodajHaslo(string haslo)
{
	if (rootHaslo == NULL)
	{
		rootHaslo = new NodeHaslo(haslo);
		return rootHaslo;
	}

	NodeHaslo* tmp = rootHaslo;

	while (true)
	{
		if (haslo < tmp->haslo && tmp->lewo == NULL)
		{
			tmp->lewo = new NodeHaslo(haslo);
			return tmp->lewo;
		}
		else if (haslo < tmp->haslo && tmp->lewo != NULL)
		{
			tmp = tmp->lewo;
		}
		else if (haslo > tmp->haslo && tmp->prawo == NULL)
		{
			tmp->prawo = new NodeHaslo(haslo);
			return tmp->prawo;
		}
		else if (haslo > tmp->haslo && tmp->prawo != NULL)
		{
			tmp = tmp->prawo;
		}
		else if (haslo == tmp->haslo)
		{
			return tmp;
		}
	}
}

NodeHaslo* znajdzHaslo(string haslo)
{
	if (rootHaslo == NULL)
		return NULL;
	else if (rootHaslo->haslo == haslo)
		return rootHaslo;

	NodeHaslo* tmp = rootHaslo;

	while (true)
	{
		if (haslo < tmp->haslo && tmp->lewo == NULL)
		{
			return NULL;
		}
		else if (haslo < tmp->haslo && tmp->lewo != NULL)
		{
			tmp = tmp->lewo;
		}
		else if (haslo > tmp->haslo && tmp->prawo == NULL)
		{
			return NULL;
		}
		else if (haslo > tmp->haslo && tmp->prawo != NULL)
		{
			tmp = tmp->prawo;
		}
		else if (haslo == tmp->haslo)
		{
			return tmp;
		}
	}
}

void wyswietlWszystkieStrony(NodeStrona* node)
{
	if (node == NULL)
		return;

	wyswietlWszystkieStrony(node->lewo);

	cout << node->strona << " ";

	wyswietlWszystkieStrony(node->prawo);
}

void wyswietlWszystko(NodeHaslo* node)
{
	if (node == NULL)
		return;

	wyswietlWszystko(node->lewo);

	cout << node->haslo << " ";
	wyswietlWszystkieStrony(node->rootStrona);
	cout << endl;

	wyswietlWszystko(node->prawo);
}

NodeHaslo* znajdzRodzicaHasla(string haslo)
{
	NodeHaslo* tmp = rootHaslo;

	while (true)
	{
		if (tmp->lewo != NULL && tmp->lewo->haslo == haslo)
			return tmp;
		else if (tmp->lewo != NULL && tmp->haslo > haslo){
			tmp = tmp->lewo;
			continue;
		}
		
		if (tmp->prawo != NULL && tmp->prawo->haslo == haslo)
			return tmp;
		if (tmp->prawo != NULL && tmp->haslo < haslo){
			tmp = tmp->prawo;
			continue;
		}
		
	}
}

NodeHaslo* znajdzMinHaslo(NodeHaslo* node)
{
	NodeHaslo* min = node;

	while (min && min->lewo != NULL)
	{
		min = min->lewo;
	}
	return min;
}

void kasujRootaHaslo()
{
	if (rootHaslo == NULL) return;
	if (rootHaslo->lewo == NULL && rootHaslo->prawo == NULL)
	{
		NodeHaslo *tmp = rootHaslo;
		rootHaslo = NULL;
		delete rootHaslo;
		return;
	}
	else if (rootHaslo->lewo == NULL)
	{
		NodeHaslo* tmp = rootHaslo;
		rootHaslo = rootHaslo->prawo;

		delete tmp;
		return;
	}
	else if (rootHaslo->prawo == NULL)
	{
		NodeHaslo* tmp = rootHaslo;
		rootHaslo = rootHaslo->lewo;

		delete tmp;
		return;
	}
	else
	{
		NodeHaslo* prawyMin = znajdzMinHaslo(rootHaslo->prawo);

		string hasloPrzechowane = prawyMin->haslo;
		NodeStrona* sPrzechowane = prawyMin->rootStrona;
		kasujHaslo(prawyMin->haslo);

		rootHaslo->haslo = hasloPrzechowane;
		rootHaslo->rootStrona = sPrzechowane;
		return;
	}
}

bool kasujHaslo(string haslo)
{
	NodeHaslo* doKasacji = znajdzHaslo(haslo);
	if (doKasacji == NULL)
		return false;

	if (doKasacji == rootHaslo)
	{
		kasujRootaHaslo();
		return true;
	}

	NodeHaslo* rodzicSzukanegoHasla = znajdzRodzicaHasla(haslo);

	if (doKasacji->lewo == NULL && doKasacji->prawo == NULL)
	{
		if (rodzicSzukanegoHasla->lewo != NULL && rodzicSzukanegoHasla->lewo == doKasacji)
			rodzicSzukanegoHasla->lewo = NULL;
		else
			rodzicSzukanegoHasla->prawo = NULL;

		delete doKasacji;
		return true;
	}
	else if (doKasacji->lewo == NULL && doKasacji->prawo != NULL)
	{
		NodeHaslo* tmp = doKasacji->prawo;

		if (rodzicSzukanegoHasla->lewo != NULL && rodzicSzukanegoHasla->lewo == doKasacji)
			rodzicSzukanegoHasla->lewo = tmp;
		else
			rodzicSzukanegoHasla->prawo = tmp;


		delete doKasacji;
		return true;
	}
	else if (doKasacji->lewo != NULL && doKasacji->prawo == NULL)
	{
		NodeHaslo* tmp = doKasacji->lewo;

		if (rodzicSzukanegoHasla->lewo != NULL && rodzicSzukanegoHasla->lewo == doKasacji)
			rodzicSzukanegoHasla->lewo = tmp;
		else
			rodzicSzukanegoHasla->prawo = tmp;

		delete doKasacji;
		return true;
	}
	else if (doKasacji->lewo != NULL && doKasacji->prawo != NULL)
	{
		NodeHaslo* prawyMin = znajdzMinHaslo(doKasacji->prawo);

		string hasloPrzechowane = prawyMin->haslo;
		NodeStrona* sPrzechowane = prawyMin->rootStrona;

		kasujHaslo(prawyMin->haslo);

		doKasacji->haslo = hasloPrzechowane;
		doKasacji->rootStrona = sPrzechowane;
		return true;
	}
	return false;
}

NodeStrona* znajdzStrona(NodeHaslo *nodeHaslo, unsigned short strona)
{
	if (nodeHaslo == NULL)
		return NULL;
	if (nodeHaslo->rootStrona == NULL)
		return NULL;
	else if (nodeHaslo->rootStrona->strona == strona)
		return nodeHaslo->rootStrona;

	NodeStrona* tmp = nodeHaslo->rootStrona;

	while (true)
	{
		if (strona < tmp->strona && tmp->lewo == NULL)
		{
			return NULL;
		}
		else if (strona < tmp->strona && tmp->lewo != NULL)
		{
			tmp = tmp->lewo;
		}
		else if (strona > tmp->strona && tmp->prawo == NULL)
		{
			return NULL;
		}
		else if (strona > tmp->strona && tmp->prawo != NULL)
		{
			tmp = tmp->prawo;
		}
		else if (strona == tmp->strona)
		{
			return tmp;
		}
	}
}

NodeStrona* znajdzMinStrone(NodeStrona* node)
{
	NodeStrona* min = node;

	while (min && min->lewo != NULL)
	{
		min = min->lewo;
	}
	return min;
}

void kasujRootaStrone(NodeHaslo* node_haslo)
{
	if (node_haslo == NULL) return;
	if (node_haslo->rootStrona == NULL) return;

	if (node_haslo->rootStrona->lewo == NULL && node_haslo->rootStrona->prawo == NULL)
	{
		NodeStrona *tmp = node_haslo->rootStrona;
		node_haslo->rootStrona = NULL;
		delete tmp;
		return;
	}
	else if (rootHaslo->lewo == NULL)
	{
		NodeStrona* tmp = node_haslo->rootStrona;
		node_haslo->rootStrona = node_haslo->rootStrona->prawo;

		delete tmp;
		return;
	}
	else if (rootHaslo->prawo == NULL)
	{
		NodeStrona* tmp = node_haslo->rootStrona;
		node_haslo->rootStrona = node_haslo->rootStrona->prawo;

		delete tmp;
		return;
	}
	else if (node_haslo->rootStrona->lewo != NULL && node_haslo->rootStrona->prawo != NULL)
	{
		NodeStrona* prawyMin = znajdzMinStrone(node_haslo->rootStrona->prawo);

		unsigned short stronaPrzechowane = prawyMin->strona;
		kasujStrone(node_haslo, prawyMin->strona);

		node_haslo->rootStrona->strona = stronaPrzechowane;
		return;
	}
}

NodeStrona* znajdzRodzicaStrony(NodeStrona* node_strona, unsigned short strona)
{
	NodeStrona* tmp = node_strona;

	while (true)
	{
		if (tmp->lewo != NULL){
			if (tmp->lewo->strona == strona)
				return tmp;
			else if (tmp->strona > strona)
				tmp = tmp->lewo;
		}
		else if (tmp->prawo != NULL){
			if (tmp->prawo->strona == strona)
				return tmp;
			else if (tmp->strona < strona)
				tmp = tmp->prawo;
		}
	}
}

bool kasujStrone(NodeHaslo *nodeHaslo, unsigned short strona)
{
	if (nodeHaslo == NULL) return false;

	NodeStrona* doKasacji = znajdzStrona(nodeHaslo, strona);
	if (doKasacji == NULL)
		return false;

	if (doKasacji == nodeHaslo->rootStrona)
	{
		kasujRootaStrone(nodeHaslo);
		return true;
	}

	NodeStrona* rodzicSzukanejStrony = znajdzRodzicaStrony(nodeHaslo->rootStrona, strona);

	if (doKasacji->lewo == NULL && doKasacji->prawo == NULL)
	{
		if (rodzicSzukanejStrony->lewo != NULL && rodzicSzukanejStrony->lewo == doKasacji)
			rodzicSzukanejStrony->lewo = NULL;
		else
			rodzicSzukanejStrony->prawo = NULL;
		

		delete doKasacji;
	}
	else if (doKasacji->lewo == NULL && doKasacji->prawo != NULL)
	{
		NodeStrona* tmp = doKasacji->prawo;

		if (rodzicSzukanejStrony->lewo != NULL && rodzicSzukanejStrony->lewo == doKasacji)
			rodzicSzukanejStrony->lewo = tmp;
		else 
			rodzicSzukanejStrony->prawo = tmp;

		delete doKasacji;
	}
	else if (doKasacji->lewo != NULL && doKasacji->prawo == NULL)
	{
		NodeStrona* tmp = doKasacji->lewo;

		if (rodzicSzukanejStrony->lewo != NULL && rodzicSzukanejStrony->lewo == doKasacji)
			rodzicSzukanejStrony->lewo = tmp;
		else
			rodzicSzukanejStrony->prawo = tmp;

		delete doKasacji;
	}
	else if (doKasacji->lewo != NULL && doKasacji->prawo != NULL)
	{
		NodeStrona* prawyMin = znajdzMinStrone(doKasacji->prawo);

		unsigned short stronaPrzechowana = prawyMin->strona;

		kasujStrone(nodeHaslo, prawyMin->strona);

		doKasacji->strona = stronaPrzechowana;
	}
	return true;
}

NodeStrona* dodajStrone(NodeHaslo* node_haslo, unsigned short strona)
{
	if (node_haslo->rootStrona == NULL)
	{
		node_haslo->rootStrona = new NodeStrona(strona);
		return node_haslo->rootStrona;
	}

	NodeStrona *tmp = node_haslo->rootStrona;

	while (true)
	{
		if (strona < tmp->strona && tmp->lewo == NULL)
		{
			tmp->lewo = new NodeStrona(strona);
			return tmp->lewo;
		}
		else if (strona < tmp->strona && tmp->lewo != NULL)
		{
			tmp = tmp->lewo;
		}
		else if (strona > tmp->strona && tmp->prawo == NULL)
		{
			tmp->prawo = new NodeStrona(strona);
			return tmp->prawo;
		}
		else if (strona > tmp->strona && tmp->prawo != NULL)
		{
			tmp = tmp->prawo;
		}
		else if (strona == tmp->strona)
		{
			return tmp;
		}
	}
}

char czyHasloWystepujeNaStronie(string haslo, unsigned short strona)
{
	NodeHaslo *tmp = znajdzHaslo(haslo);

	if (tmp == NULL)
		return '0';

	NodeStrona *wsk = znajdzStrona(tmp, strona);

	if (wsk == NULL)
		return '0';

	return '1';
}

void jesliIstniejeToWyswietl(string haslo)
{
	NodeHaslo *tmp = znajdzHaslo(haslo);
	if (tmp == NULL)
	{
		cout << "-1" << endl;
		return;
	}
	cout << haslo << " ";
	wyswietlWszystkieStrony(tmp->rootStrona);
	cout << endl;
}

int main()
{
	unsigned int iloscPolecen;
	char polecenie;
	cin >> iloscPolecen;
	for (unsigned int i = 0; i < iloscPolecen; i++)
	{
		cin >> polecenie;

		switch (polecenie)
		{
		case 'I':{
			string hasloDoDodania;
			cin >> hasloDoDodania;
			NodeHaslo *tmp = dodajHaslo(hasloDoDodania);
			unsigned int iloscStronDoDodania;
			cin >> iloscStronDoDodania;
			unsigned short stronaDoDodania;
			for (unsigned int j = 0; j < iloscStronDoDodania; j++)
			{
				cin >> stronaDoDodania;
				dodajStrone(tmp, stronaDoDodania);
			}
			break;
		}
		case 'D':{
			string hasloDoUsuniecia;
			cin >> hasloDoUsuniecia;
			NodeHaslo *wsk = znajdzHaslo(hasloDoUsuniecia);
			unsigned int iloscStronDoKasacji;
			cin >> iloscStronDoKasacji;
			unsigned short stronaDoKasacji;
			for (unsigned int j = 0; j < iloscStronDoKasacji; j++)
			{
				cin >> stronaDoKasacji;
				kasujStrone(wsk, stronaDoKasacji);
			}
			if (wsk->rootStrona == NULL)
				kasujHaslo(hasloDoUsuniecia);
			break;
		}
		case 'F':{
			string hasloDoSprawdzenia;
			cin >> hasloDoSprawdzenia;
			unsigned short stronaDoSprawdzenia;
			cin >> stronaDoSprawdzenia;
			cout << czyHasloWystepujeNaStronie(hasloDoSprawdzenia, stronaDoSprawdzenia) << endl;
			break;
		}
		case 'A':{
			string hasloDoWyswietlenia;
			cin >> hasloDoWyswietlenia;
			jesliIstniejeToWyswietl(hasloDoWyswietlenia);
			break;
		}
		case 'P':{
			if (rootHaslo == NULL)
				cout << endl;
			else
				wyswietlWszystko(rootHaslo);
			break;
		}
		default:
		{break; }
		}

	}
	return 0;
}