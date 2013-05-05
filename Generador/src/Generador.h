/*
 * Generador.h
 *
 *	Created on: 28/01/2013
 *	Author: harssed
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
		int nEsp;
		int nPac;
		int slots_disp;
		int slots_dia;
		ofstream guardarArchivo;
		vector <string> bd_names;
		vector <int> esp_profesional_x;
		vector <vector<int> > set_especialidades_profesionales;
		vector <vector<int> > profesionales_esp;
		int distribucion;

		double porcentajeRF; //04-04-2013
		vector <int> esp_porcentajeRF; //04-04-2013
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
		int getNroCitasMaxEsp(int e);

		int calcularNroTotalProfesionales();
		int getCtadEspecialidades();
		int equalsZero(int i, int f); //FALTA IMPLEMENTACIÓN!!
		void arregloEspecialidades(int esp);
		vector <int> especialidadesPaciente(int n, int pac);

		void set_porcentaje_minRF(double p); //04-04-2013
		double get_porcentaje_minRF(); //04-04-2013
		void fill_esp_porcentajeRF();

		void shuffleEspecialidades();
		bool compararElemento(vector <int> elementos, int j);
//		int sumaAleatorios(); //FALTA IMPLEMENTACIÓN!!

		void get_profesionales_especialidades();
		void get_especialidades_profesionales();
		void set_slots_disponibilidad(int slots);
		void set_slots_dia(int slots);

		void leerBD(string nombre_archivo);
		void shuffle_bd();
		void leerBDIds();
		void getListaNombres();
		string getIdBD(int i);
		string getNombreBD(int i);

		void save_nombre_archivo(string nombre_archivo);
		void save_nro_profesionales();
		void save_nro_especialidades();
		void save_nro_pacientes(int nro);
		void save_informacion_especialidades();
		void save_informacion_profesionales();
		void save_informacion_pacientes();

		string generarDispoProf();
		vector <string> generarDispoPac(int);

		void setDistribucion(int);
		int getDistribucion();
		string dispoPacDistNinguna();
		vector <int> dispoPacDistUni();
		vector <int> dispoPacDistNormal();
		vector <int> dispoPacDistExp();

		vector <int> dispoPacDistExp_max(); //04-04-2013

		bool compararStrElemento(vector <string>, string, int);
		vector <int> splitStrDisponibilidad(string cadena);
		vector <int> aleatoriosDistintos(int, int);
		void close_archivo();

		void escribir();
};

#endif
