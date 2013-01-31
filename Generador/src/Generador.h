/*
 * Generador.h
 *
 *  Created on: 28/01/2013
 *      Author: harssed
 */

#ifndef GENERADOR_H_
#define GENERADOR_H_

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;

class Generador
{
	private:
		vector <vector <string> > informacionEspecialidad;
		vector <int> _espProfesionales;
		int nProf;
		int nProf_temp;
		int nEsp; //
		int nPac; //
		int slots_disp; //
		ofstream guardarArchivo; //
		vector <string> bd_names; //
		vector <int> esp_profesional_x; //
		vector <vector<int> > set_especialidades_profesionales; //
		vector <vector<int> > profesionales_esp; //
	public:
		Generador();
		void init();
		string itostr(int num);
		int numRange(int inf,int sup);
		void datosEspecialidades();
		string getId(int e);
		string getNombre(int e);
		string getDuracion(int e);
		int getCapacidadPacientes(int e);
		int getNroProfesionales(int e);

		int calcularNroTotalProfesionales();
		int getCtadEspecialidades();
		int equalsZero(int i, int f); //FALTA IMPLEMENTACIÓN!!
		void arregloEspecialidades(int esp);
		vector <int> especialidadesPaciente(int n);

		bool compararElemento(vector <int> elementos, int j);
		void shuffleEspecialidades();
		int sumaAleatorios(); //FALTA IMPLEMENTACIÓN!!

		//string getIdProfesional(int p); //
		void save_nombre_archivo(string nombre_archivo); //
		void get_profesionales_especialidades(); //

		void set_slots_disponibilidad(int slots);  //
		void get_especialidades_profesionales();   //
		void leerBDIds();  //
		void leerBD(string nombre_archivo); //
		void getListaNombres();					   //
		string getNombreBD(int i);
		string getIdBD(int i);
		void shuffle_bd();						   //
		void get_nombres_profesionales(int n);	   //FALTA IMPLEMENACIÓN
		void get_nombres_pacientes(int n);         //FALTA IMPLEMENACIÓN

		void save_nro_profesionales();
		void save_nro_especialidades();
		void save_nro_pacientes(int nro);
		void save_informacion_especialidades();
		void save_informacion_profesionales();
		void save_informacion_pacientes();

		string generarDispoProf();
		vector <int> aleatoriosDistintos(int, int);
		vector <string> generarDispoPac(int ); //FALTA IMPLEMENACIÓN
		bool compararStrElemento(vector <string>, string, int); //FALTA IMPLEMENACIÓN
		vector <int> splitStrDisponibilidad(string cadena);

		vector <int> dispoPacDistNormal(); //FALTA IMPLEMENACIÓN

		vector <int> dispoPacDistUni(); //FALTA IMPLEMENACIÓN

		void escribir();
};

#endif
