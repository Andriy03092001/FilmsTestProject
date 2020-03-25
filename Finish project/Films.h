#pragma once
#include<iostream>
#include<string>
using namespace std;


struct Actor
{
	string name;
	int reting;
};

struct Film
{
	string NameFilm;
	Actor* actors;
	int countActors;
};


void addFilm();
void showFilms();