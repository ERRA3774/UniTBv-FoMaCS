#pragma once
#include <vector>


//var statica
void citire_vect(int &dim, int vect[]);
void afisare_vect(int dim, int vect[]);

//varianta dinamica
void citire_vector(int& dim, int*& vect);
void afisare_vector(int dim, int* vect);

//varianta stl vector
void citire_vect(std::vector<int>& vect); 
void afisare_vect(std::vector<int> vect);