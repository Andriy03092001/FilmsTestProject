#include "Films.h"
#include<iostream>
#include<string>
#include<fstream>

Film* films;
int countFilms = 0;

void addFilm()
{
	ofstream fout;
	fout.open("Films.txt",fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		Film* temp = new Film[countFilms+1];
		for (int i = 0; i < countFilms; i++) {
			temp[i] = films[i];
		}
	
		int countActors = 0;
		//¬носим дан≥ про новий ф≥льм
		cout << "Enter name for film->_";
		cin >> temp[countFilms].NameFilm;
		cout << "Enter count actors for this film->_";
		cin >> countActors;
		temp[countFilms].countActors = countActors;
		temp[countFilms].actors = new Actor[countActors];
		for (int i = 0; i < countActors; i++)
		{
			cout << "Enter name fot actor->_";
			cin >> temp[countFilms].actors[i].name;
			cout << "Enter rating fot actor (1-5)->_";
			cin >> temp[countFilms].actors[i].reting;
		}

		fout << temp[countFilms].NameFilm << endl;
		fout << temp[countFilms].countActors << endl;
		for (int i = 0; i < temp[countFilms].countActors; i++) {
			fout << temp[countFilms].actors[i].name << endl;
			fout << temp[countFilms].actors[i].reting << endl;
		}

		fout.close();
		countFilms++;
		delete films;
		films = temp;
	}
	else {
		cout << "Error: file not opened!" << endl;
	}
}

void showFilms()
{
	for (int i = 0; i < countFilms; i++) {
		cout << films[i].NameFilm << endl;
		for (int j = 0; j < films[i].countActors; j++) {
			cout << 
				films[i].actors[j].name 
			<< " -> " <<
				films[i].actors[j].reting 
			<< endl;
		}
	}
}
