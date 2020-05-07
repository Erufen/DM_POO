#include <iostream>
//#include "ListeOrd.h"

using namespace std;

struct Element
{
	int data;
	Element* suivant;
};

Element* liste = NULL;

void InsertInPlace(int data)
{
	Element* element = new Element; // on fixe la valeur de l'élément
	element->data = data; // on place le nouvel élément en début de liste
	element->suivant = liste; // déplacement du pointeur vers la tête de la liste
	liste = element;
}

Element* Rechercher(int data)
{
	Element* element = liste;
	while (element != NULL && element->data != data)
		element = element->suivant;
	return element;
}

void popFirst(Element* element)
{
	Element* precedent = liste;
	if (element == liste) {
		liste = NULL;
		delete element;
		return;
	}
	while (precedent != NULL && precedent->suivant != element)
		precedent = precedent->suivant;

	if (precedent == NULL) return;
	precedent->suivant = element->suivant;
	delete element;
}

void display()
{
	Element* element = liste;
	while (element != NULL) {
		cout << element->data << "\t";
		element = element->suivant;
	}
	cout << endl;
}

int main(void)
{
	Element* e;

	InsertInPlace(10);
	InsertInPlace(5);
	InsertInPlace(13);

	display();

	e = Rechercher(5);
	popFirst(e);
	//e = Rechercher(13); // ne fonctionne pas si je veux supprimer 2 éléments à la suite
	//popFirst(e);

	display();

	return 0;
}