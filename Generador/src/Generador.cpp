#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

#include "Generador.h"

/**
 *	Fecha de Creación: Mayo 09 de 2012
 */

Generador::Generador(){
	init();
}


string Generador::itostr(int num){
	stringstream ss;
	ss << num;
	return ss.str();
}


void Generador::init(){
	srand (time(NULL));
	datosEspecialidades();
	nProf_temp = calcularNroTotalProfesionales();
	nEsp = getCtadEspecialidades();
	distribucion = 0;
}


int Generador::numRange(int inf, int sup){
    int var = 0;

    if(inf*sup<0 || inf>sup || sup<inf){
       cout<<"ERROR!!"<<endl;
       cout<<"inf "<<inf<<" sup "<<sup<<endl;
    }
    else
    {
        var = inf + (rand()%(sup+1 - inf));
    }
    return var;
}


void Generador::datosEspecialidades(){

	//Identificador - NombreEspecialidad - DuraciónCita - Capacidad - NroEspecialistas
	/**
	vector <string> especialidad1;
		especialidad1.push_back("1");
		especialidad1.push_back("R. Física");
		especialidad1.push_back("60");	//60 min
		especialidad1.push_back("6");
		especialidad1.push_back("10");

	vector <string> especialidad2;
		especialidad2.push_back("2");
		especialidad2.push_back("R. Cardíaca");
		especialidad2.push_back("60");	//60 min
		especialidad2.push_back("6");
		especialidad2.push_back("1");

	vector <string> especialidad3;
		especialidad3.push_back("3");
		especialidad3.push_back("T. Lenguaje");
		especialidad3.push_back("30");	//30 min
		especialidad3.push_back("4");
		especialidad3.push_back("1");

	vector <string> especialidad4;
		especialidad4.push_back("4");
		especialidad4.push_back("T. Ocupacional");
		especialidad4.push_back("30");	//30 min
		especialidad4.push_back("5");
		especialidad4.push_back("1");

	vector <string> especialidad5;
		especialidad5.push_back("5");
		especialidad5.push_back("T. Respiratoria");
		especialidad5.push_back("20");	//20 min
		especialidad5.push_back("4");
		especialidad5.push_back("1");

	vector <string> especialidad6;
		especialidad6.push_back("6");
		especialidad6.push_back("Nutrición");
		especialidad6.push_back("20");	//20 min
		especialidad6.push_back("1");
		especialidad6.push_back("1");

	vector <string> especialidad7;
		especialidad7.push_back("7");
		especialidad7.push_back("Psicología");
		especialidad7.push_back("20");	//20 min
		especialidad7.push_back("1");
		especialidad7.push_back("1");

	vector <string> especialidad8;
		especialidad8.push_back("8");
		especialidad8.push_back("Audiología");
		especialidad8.push_back("20");	//20 min
		especialidad8.push_back("1");
		especialidad8.push_back("1");

	vector <string> especialidad9;
		especialidad9.push_back("9");
		especialidad9.push_back("Piso Pélvico");
		especialidad9.push_back("60");	//60 min
		especialidad9.push_back("1");
		especialidad9.push_back("1"); //Por definir cantidad de profesionales de esta especialidad

	vector <string> especialidad10;
		especialidad10.push_back("10");
		especialidad10.push_back("Espirometrías");
		especialidad10.push_back("15");	//15 min
		especialidad10.push_back("1");
		especialidad10.push_back("1"); //Por definir cantidad de profesionales de esta especialidad

	informacionEspecialidad.push_back(especialidad1);
	informacionEspecialidad.push_back(especialidad2);
	informacionEspecialidad.push_back(especialidad3);
	informacionEspecialidad.push_back(especialidad4);
	informacionEspecialidad.push_back(especialidad5);
	informacionEspecialidad.push_back(especialidad6);
	informacionEspecialidad.push_back(especialidad7);
	informacionEspecialidad.push_back(especialidad8);
	informacionEspecialidad.push_back(especialidad9);
	informacionEspecialidad.push_back(especialidad10);
	*/
	///////////////////////////////////////////////////

	string datos1[] = {"1","R. Física","60","6","10"};
	vector <string> especialidad1 (datos1, datos1+5);

	string datos2[] = {"2","R. Cardíaca","60","6","1"};
	vector <string> especialidad2 (datos2, datos2+5);

	string datos3[] = {"3","T. Lenguaje","30","4","1"};
	vector <string> especialidad3 (datos3, datos3+5);

	string datos4[] = {"4","T. Ocupacional","30","5","1"};
	vector <string> especialidad4 (datos4, datos4+5);

	string datos5[] = {"5","T. Respiratoria","20","4","1"};
	vector <string> especialidad5 (datos5, datos5+5);

	string datos6[] = {"6","Nutrición","20","1","1"};
	vector <string> especialidad6 (datos6, datos6+5);

	string datos7[] = {"7","Psicología","20","1","1"};
	vector <string> especialidad7 (datos7, datos7+5);

	string datos8[] = {"8","Audiología","20","1","1"};
	vector <string> especialidad8 (datos8, datos8+5);

	string datos9[] = {"9","Piso Pélvico","60","1","1"};
	vector <string> especialidad9 (datos9, datos9+5);

	string datos10[] = {"10","Espirometrías","15","1","1"};
	vector <string> especialidad10 (datos10, datos10+5);

	informacionEspecialidad.push_back(especialidad1);
	informacionEspecialidad.push_back(especialidad2);
	informacionEspecialidad.push_back(especialidad3);
	informacionEspecialidad.push_back(especialidad4);
	informacionEspecialidad.push_back(especialidad5);
	informacionEspecialidad.push_back(especialidad6);
	informacionEspecialidad.push_back(especialidad7);
	informacionEspecialidad.push_back(especialidad8);
	informacionEspecialidad.push_back(especialidad9);
	informacionEspecialidad.push_back(especialidad10);
}

string Generador::getId(int e){
	string id="";
	id = informacionEspecialidad[e][0];
	return id;
}

string Generador::getNombre(int e){
	string nombre="";
	nombre = informacionEspecialidad[e][1];
	return nombre;
}

string Generador::getDuracion(int e){
	string duracion="";
	duracion = informacionEspecialidad[e][2];
	return duracion;
}

int Generador::getCapacidadPacientes(int e){
	int capacidad=0;
	capacidad = atoi(informacionEspecialidad[e][3].c_str());
	return capacidad;
}

int Generador::getNroProfesionales(int e){
	int nroEspecialistas=0;
	nroEspecialistas = atoi(informacionEspecialidad[e][4].c_str());
	return nroEspecialistas;
}


int Generador::getCtadEspecialidades(){

	int esp = 0;
	esp = (int)informacionEspecialidad.size();

	return esp;
}

int Generador::calcularNroTotalProfesionales(){

	int suma = 0;
	int aux = 0;

	for(int i=0;i<(int)informacionEspecialidad.size();i++){
		aux = getNroProfesionales(i);
		suma += aux;
	}
	return suma;
}

void Generador::arregloEspecialidades(int esp){

	int i=0;
	while(getNroProfesionales(esp)>i){
		_espProfesionales.push_back(esp);
		i++;
	}
}

vector <int> Generador::especialidadesPaciente(int nroEsp){

	int n = 0;
	vector <int> especialidades;
	//especialidades.clear();

	for(int i=0; i<nroEsp; i++){

		do{
			n = rand() % nEsp;
	    }
	    while(compararElemento(especialidades, n));

		especialidades.push_back(n);
	    //cout << especialidades.at(i) << " ";
	}

	return especialidades;
}

void Generador::shuffleEspecialidades(){
	random_shuffle(_espProfesionales.begin(),_espProfesionales.end());
	random_shuffle(_espProfesionales.begin(),_espProfesionales.end());
}

bool Generador::compararElemento(vector <int> elementos, int j){

	bool siEsta = false;
	for(int i=0; i<(int)elementos.size();i++){
		if(elementos.at(i)==j){
			siEsta = true;
			break;
		}
		else{
			siEsta = false;
		}
	}
	return siEsta;
}

void Generador::get_profesionales_especialidades(){

	int idE = 0;
	int nEP = 0;
	int idE_aux = 0;
	vector <int> aux;

	for(int j=0; j<nEsp; j++){
		idE = atoi(getId(j).c_str());
		aux.push_back(idE);

		for (int i= 0; i < nProf; i++) {

			nEP = (int)set_especialidades_profesionales[i].size()-1;

			for (int k = 0; k < nEP; k++) {

				idE_aux = atoi(getId(set_especialidades_profesionales[i][k+1]).c_str());

				if(idE_aux == idE){
					aux.push_back(atoi(getIdBD(i).c_str()));
				}
			}
		}

		profesionales_esp.push_back(aux);
		aux.clear();
	}

	/*
	int nPE=0;
	for (int i= 0; i < nEsp; i++) {

		nPE = (int)profesionales_esp[i].size()-1;
		for (int j = 0; j < nPE; j++) {
			cout<<"Esp "<<getId(i)<<" "<<profesionales_esp.at(i).at(j+1) <<endl;
		}
	}
	*/
}

void Generador::get_especialidades_profesionales(){

	//int intId;

	for(int e=0; e<nEsp; e++){
		arregloEspecialidades(e);
	}

	shuffleEspecialidades();

	_espProfesionales.push_back(-1);

	int pos=0;

	for(int i=0; i < nProf_temp;i++){

		esp_profesional_x.push_back(_espProfesionales.at(i));

		if(esp_profesional_x.size()<3){

			if(compararElemento(esp_profesional_x, _espProfesionales.at(i+1))){

				sort(esp_profesional_x.begin(), esp_profesional_x.end());
				//cout<<"i: "<<i<<"\tTam: "<<esp_profesional_x.size()<<"\tPos: "<<pos<<endl;
				esp_profesional_x.insert(esp_profesional_x.begin(), atoi(getIdBD(pos).c_str())); //Id del profesional
				set_especialidades_profesionales.push_back(esp_profesional_x);
				esp_profesional_x.clear();

				pos++;
			}
		}
		else{
			sort(esp_profesional_x.begin(), esp_profesional_x.end());
			//cout<<"i:: "<<i<<"\tTam: "<<esp_profesional_x.size()<<"\tPos: "<<pos<<endl;
			esp_profesional_x.insert(esp_profesional_x.begin(), atoi(getIdBD(pos).c_str())); //Id del profesional
			set_especialidades_profesionales.push_back(esp_profesional_x);
			esp_profesional_x.clear();

			pos++;
		}
	}

	if(!esp_profesional_x.empty()){
		sort(esp_profesional_x.begin(), esp_profesional_x.end());
		//cout<<"i::: "<<"\tTam: "<<esp_profesional_x.size()<<"\tPos: "<<pos<<endl;

		esp_profesional_x.insert(esp_profesional_x.begin(), atoi(getIdBD(pos).c_str())); //Id del profesional
		set_especialidades_profesionales.push_back(esp_profesional_x);
	}
}

void Generador::set_slots_disponibilidad(int slots){
	slots_disp = slots;
}

void Generador::leerBD(string nombre_archivo){

	ifstream archivo;
	string linea;

	archivo.open(nombre_archivo.c_str());

	if(archivo.fail()){
		printf("Error al abrir el Archivo \n");
		exit(1);
	}

	while(getline(archivo, linea)){
		bd_names.push_back(linea);
	}
	archivo.close();
}

void Generador::shuffle_bd(){
	random_shuffle(bd_names.begin(),bd_names.end());
}

void Generador::leerBDIds(){

	int tam_bd = bd_names.size();
	//cout<<"TAM "<<tam_bd<<endl;

	for(int i=0; i<tam_bd; i++){
		//bd_names[i]= bd_names[i].substr(0,15);
		cout<<getIdBD(i)<<endl;
	}
}

void Generador::getListaNombres(){

	int tam_bd = bd_names.size();
	//cout<<"TAM "<<tam_bd<<endl;

	for(int i=0; i<tam_bd; i++){
		//bd_names[i]= bd_names[i].substr(0,15);
		cout<<i+1<<" "<<bd_names.at(i)<<endl;
	}
}

string Generador::getIdBD(int i){
	int pos_f = bd_names.at(i).find("-") - 1;
	int pos_i = 0;
	string idPr = bd_names.at(i).substr(pos_i, pos_f);
	return idPr;
}

string Generador::getNombreBD(int i){

	int pos_i = bd_names.at(i).find("-") + 2;
	int pos_f = bd_names.at(i).size() - pos_i -1;
	string nomPr = bd_names.at(i).substr(pos_i, pos_f);
	return nomPr;
}



void Generador::save_nombre_archivo(string nombre_archivo){
	guardarArchivo.open(nombre_archivo.c_str());
}

void Generador::save_nro_profesionales(){
	cout << "No. Profesionales :: ";
	nProf = (int)set_especialidades_profesionales.size();
	cout<<nProf<<endl;
	guardarArchivo <<nProf<<endl;
}


void Generador::save_nro_especialidades(){
	cout << "No. Especialidades :: ";
	cout<<nEsp<<endl;
	guardarArchivo <<nEsp<<endl;
}

void Generador::save_nro_pacientes(int nro = 10){
	int nPac1, nPac2;
	//cout << "Pacientes" << endl;
	//cout << "Lim Inferior :: "; cin >> nPac1;
	//cout << "Lim Superior :: "; cin >> nPac2;
	cout << "No. Pacientes:: ";
	nPac1= nPac2 = nro;
	nPac = numRange(nPac1, nPac2);
	//cin >> nPac;

	cout<<nPac<<endl;
	guardarArchivo <<nPac<<endl;
}

void Generador::save_informacion_especialidades(){

	for(int i=0; i<nEsp; i++){
		cout <<i+1<<") "
			 << getId(i)
			 << " '"<<getNombre(i)<<"' "
			 << getCapacidadPacientes(i)<<" "
			 << getDuracion(i)<<endl;/*" "
			 << getNroProfesionales(i)<<endl;*/
		guardarArchivo << getId(i)
					   << " '"<<getNombre(i)<<"' "
					   << getCapacidadPacientes(i)<<" "
					   << getDuracion(i)<<endl;/*" "
					   << getNroProfesionales(i)<<endl;*/
	}
}


void Generador::save_informacion_profesionales(){

	int nEP = 0; //Número de Especialidades del Profesional
	string strDisp = "";

	for (int i= 0; i < nProf; i++) {

		nEP = (int)set_especialidades_profesionales[i].size()-1;

		cout<<i+1<<") "<<getIdBD(i)<<" '"<<getNombreBD(i)<<"' "<<nEP<<endl;
		guardarArchivo <<getIdBD(i)<<" '"<<getNombreBD(i)<<"' "<<nEP<<endl;

		if(nEP == 1){

			cout<<getId(set_especialidades_profesionales[i][1]) << " - ";
			guardarArchivo<<getId(set_especialidades_profesionales[i][1]) << " - ";

			strDisp = generarDispoProf();

			cout<<strDisp<<endl;
			guardarArchivo<<strDisp<<endl;
		}
		else{

			vector <string> conjunto_dispo(nEP);
			strDisp = generarDispoProf();
			conjunto_dispo.at(0) = strDisp;

			cout<<getId(set_especialidades_profesionales[i][1]) << " - ";
			guardarArchivo<<getId(set_especialidades_profesionales[i][1]) << " - ";

			cout<<strDisp<<endl;
			guardarArchivo<<strDisp<<endl;

			for (int j = 1; j < nEP; j++) {

				cout<<getId(set_especialidades_profesionales[i][j+1]) << " - ";
				guardarArchivo<<getId(set_especialidades_profesionales[i][j+1]) << " - ";

				do{
					strDisp = generarDispoProf();
				}
				while(compararStrElemento(conjunto_dispo, strDisp, j));
				//cout<<"conjunto_dispo.at("<<j<<") == "<<strDisp<<endl;
				conjunto_dispo.at(j) = strDisp;

				cout<<strDisp<<endl;
				guardarArchivo<<strDisp<<endl;

				//break;
			}

			conjunto_dispo.clear();
		}
		//exit(1);
	}
}


void Generador::save_informacion_pacientes(){

	string strDisp = "";
	//int esp_paciente; //Especialidad que requiere el paciente

	int cPac, cPac1, cPac2;//, ePac;
	cPac1 = 1; cPac2 = 5;
	//cout << "Citas paciente" << endl;
	//cout << "Lim Inferior :: "; cin >> cPac1;
	//cout << "Lim Superior :: "; cin >> cPac2;

	int nTrat, nTrat1, nTrat2;
	nTrat1 = 1; nTrat2 = 3;
	//cout << "No. Tratamientos del paciente" << endl;
	//cout << "Lim Inferior :: "; cin >> nTrat1;
	//cout << "Lim Superior :: "; cin >> nTrat2;

	int numPE; 			//Número de Profesionales de una especialidad
	int posProfPref;
	int pPreferencia; 	//Profesional de Preferencia

	vector <int> espPac;

	vector <string> disponibilidadPacientes = generarDispoPac(distribucion);

	for(int i=0; i<nPac; i++){

		nTrat = numRange(nTrat1, nTrat2);

		cout<<i+1<<") "<<getIdBD(nProf+i)<<" '"<<getNombreBD(nProf+i)<<"' "<<nTrat<<" ";
		guardarArchivo<<getIdBD(nProf+i)<<" '"<<getNombreBD(nProf+i)<<"' "<<nTrat<<" ";

		espPac = especialidadesPaciente(nTrat);

		for(int j=0; j<nTrat;j++){

			cPac = numRange(cPac1, cPac2);

			int id1 = 0;
			int pos_e = 0;

			for (int e= 0; e < nEsp; e++) {

				id1 = profesionales_esp[e][0];

				if(id1 == atoi(getId(espPac.at(j)).c_str())){
					numPE = (int)profesionales_esp[e].size()-1;
					pos_e = e;
					break;
				}
			}

			posProfPref = numRange(0, numPE);
			pPreferencia = profesionales_esp[pos_e][posProfPref]; //Obtener elemento que está en la posición posProfPref

			if(posProfPref == 0){
				pPreferencia = 0;
			}

			cout<<"["<<getId(espPac.at(j))<<" "<<cPac<<" "<<pPreferencia<<"]";
			guardarArchivo<<"["<<getId(espPac.at(j))<<" "<<cPac<<" "<<pPreferencia<<"]";
		}

		espPac.clear();

		cout<<endl;
		guardarArchivo<<endl;

		strDisp = disponibilidadPacientes.at(i);

		cout <<strDisp<<endl;
		guardarArchivo<<strDisp<<endl;
	}
}

string Generador::generarDispoProf(){

	string strDisp = "";
	vector <int> disponibilidad (slots_disp,0);

	int nDias = 6;
	int nDiasDispo = numRange(1,nDias);
	vector <int> diasDispo (aleatoriosDistintos(nDiasDispo, nDias));

	vector <int> jornadaDispo (nDiasDispo);
	int nJornadaDispo = 0;

	int slots_dia = 12;
	int hrs_jr_man = 5;
	int hrs_jr_tar = 7;
	int hrs_descanso = 0;
	//Jornada en la cual está disponible el profesional
	int dispo_jornada = 0;
	//Define el inicio a partir del cual está disponible el profesional en una jornada determinada
	int begin_count = 0;

	int dia = 0;

//	cout<<"No. Días "<<nDiasDispo<<endl;

	for(int i=0; i<nDiasDispo; i++){

		dia = diasDispo.at(i);

		if(dia == 5) nJornadaDispo = 0;
		else nJornadaDispo = numRange(0,2);

		jornadaDispo.at(i) = nJornadaDispo;
	}

//	for(int i=0; i < nDiasDispo; i++){
//		cout << "Día " << diasDispo.at(i)
//			 << " Jornada " << jornadaDispo.at(i) << endl;
//	}

	//cout<<strDisp<<endl;

	for(int i=0; i<slots_disp; i++){

		for(int j=0; j<nDiasDispo; j++){

			dia = diasDispo.at(j);
			nJornadaDispo = jornadaDispo.at(j);

			if(dia != 5){

				switch(nJornadaDispo){
					case 0:
						dispo_jornada = hrs_jr_man;
						begin_count = slots_dia*dia;
					break;
					case 1:
						dispo_jornada = hrs_jr_tar;
						begin_count = slots_dia*dia + hrs_jr_man + hrs_descanso;
					break;
					case 2:
						dispo_jornada = slots_dia;
						begin_count = slots_dia*dia;
					break;
				}

				for(int k=0; k<dispo_jornada; k++){
					disponibilidad.at(begin_count+k) = 1;
				}
			}
			else{
				for(int k=0; k < hrs_jr_man; k++){
					disponibilidad.at((slots_disp - hrs_jr_man)+k) = 1;
				}
			}
		}
	}

	//Se establecen las horas de descanso que corresponden al medio día.
	/*
	for(int i=0; i < (nDias-1); i++){
		disponibilidad.at(6+12*i) = 0;
		disponibilidad.at(7+12*i) = 0;
	}
	*/


	for(int i=0; i<slots_disp; i++){
		strDisp += itostr(disponibilidad.at(i)) + " ";
	}

	return strDisp;
}

vector <string> Generador::generarDispoPac(int distrib){

	vector <string> strDispoPac(nPac);
	string strDisp = "";

	if(distrib == 0){

		for(int i = 0; i < nPac; i++){
			strDispoPac.at(i) = dispoPacDistAleatoria();
		}
	}
	else{

		vector <int> disponibilidad;
		int nslots = slots_disp;//11; //6 - //slots_disp;
		vector <vector <int> > dispoVsPac (nPac, vector<int> (nslots));

		vector <int> temporal(nslots);


		switch(distrib){
			case 1:
				disponibilidad = dispoPacDistUni();
			break;
			case 2:
				disponibilidad = dispoPacDistNormal();
			break;
			default:
				cout<<"La Distribución de la Disponibilidad de los Pacientes es Incorrecta."<<endl;
				exit(1);
			break;
		}


		for(int i = 0; i < nPac; i++) {
			for(int j = 0; j < nslots; j++){
				dispoVsPac.at(i).at(j) = -1;
			}
		}

		//vector <int> temporal(nslots);

		for(int j=0; j<nslots; j++){

			if(disponibilidad.at(j) == 0){
				for(int i=0; i<nPac; i++){
					dispoVsPac.at(i).at(j) = 0;
				}
			}
			else
			if(disponibilidad.at(j) == nPac){
				for(int i=0; i<nPac; i++){
					dispoVsPac.at(i).at(j) = 1;
				}
			}
			else
			if(disponibilidad.at(j) > 0 && disponibilidad.at(j) < nPac){
				int nPacDisp = 0;
				int temp = 0;
				nPacDisp = disponibilidad.at(j);

				cout <<"slot["<<j<<"] :=> nPacDisp:=> " << nPacDisp <<" :=> ";

				for(int k=0; k<nPacDisp; k++){
					do{
						temp = numRange(1,nPac);
					}while(compararElemento(temporal, temp));

					cout<<"Pac: "<<temp<<" ";
					temporal.push_back(temp);

					dispoVsPac.at(temp-1).at(j) = 1;
				}
				cout<<endl;
			}

			temporal.clear();
		}


		for(int i = 0; i < nPac; i++) {
			for(int j = 0; j < nslots; j++){
				if(dispoVsPac.at(i).at(j) == -1)
					dispoVsPac.at(i).at(j) = 0;
			}
		}

//				Método: Imprimir

//				for ( int i = 0; i < nPac; i++ ) {
//					for ( int j = 0; j < nslots; j++ ){
//						cout<<dispoVsPac.at(i).at(j)<<" ";
//					}
//					cout<<endl;
//				}


		for(int i = 0; i < nPac; i++){
			for(int j = 0; j < nslots; j++){
				strDisp += itostr(dispoVsPac.at(i).at(j)) + " ";
			}
			strDispoPac.at(i) = strDisp;
			strDisp = "";
		}

	}

	return strDispoPac;
}

void Generador::setDistribucion(int d){
	distribucion = d;
}

int Generador::getDistribucion(){
	return distribucion;
}

string Generador::dispoPacDistAleatoria(){
	string strDisp = "";
	for(int d=0; d<slots_disp; d++){
		strDisp += itostr(numRange(0,1)) + " ";
	}
	return strDisp;
}

vector <int> Generador::dispoPacDistUni(){

	gsl_rng * r;
	// select random number generator
	r = gsl_rng_alloc (gsl_rng_mt19937);

	long seed;
	seed = time (NULL)*getpid();
	gsl_rng_set (r, seed);

	int slots_dia = 12;
	double slots_ini = 0.0;
	double slots_fin = 12.0;

	vector <int> arreglo(slots_disp);

	const int nrolls = 1200;	//Number of experiments
	const int nstars = 120;		//Maximum number of stars to distribute

	double number;

	for(int a = 0; a < 6; a++){

		for (int i=0; i<nrolls; i++) {
			number = gsl_rng_uniform (r);
			number = number*slots_dia + slots_dia*a;

			if ((number >= (slots_ini+slots_dia*a)) && (number <= (slots_fin+slots_dia*a))){
				if(arreglo[int(number)] < 100) //numPac)
					++arreglo[int(number)];
			}
		}
	}

	gsl_rng_free (r);

	int suma = 0;
	int temp = 0;

	for (int i=0; i<slots_disp; i++) {
		temp = arreglo[i]*nstars/nrolls;
		arreglo[i] = temp;
		suma += arreglo[i];
		cout << "slot[" << i << "]: " << arreglo[i] << " \t = " << " \t";
		cout << string(temp,'*') << endl;
	}


	cout << endl << "Suma \t= " << suma << endl;

	double porcentaje = 0;
	int totalPacientes = nPac;
	int numeroPacientes = 0;

	for (int i=0; i<slots_disp; i++) {
		porcentaje = (double)arreglo[i]/10;
		numeroPacientes = floor((double)totalPacientes*porcentaje);
		arreglo[i] = numeroPacientes;
		cout<<numeroPacientes<<endl;
	}
//	exit(1);
	return arreglo;
}

vector <int> Generador::dispoPacDistNormal(){

	gsl_rng * r;
	// select random number generator
	r = gsl_rng_alloc (gsl_rng_mt19937);

	//Seed: http://www.cs.unc.edu/~jeffay/dirt/FAQ/gsl.html
	long seed;
	seed = time (NULL);// * getpid();
	gsl_rng_set (r, seed);

	const int nrolls = 10000;  // number of experiments
	const int nstars = 100;    // maximum number of stars to distribute

	int slots = slots_disp;
	int slots_dia = 12;
	vector <int> arreglo (slots);
	double sigma = 1.5;
	double mean = 2;

	double sigma2 = 1.5;
	double mean2 = 9;

	double ini_jr1 = 0.0, fin_jr1 = 6.0, ini_jr2 = fin_jr1, fin_jr2 = slots;
	double number = 0.0, number2 = 0.0;

	for(int a = 0; a < 6; a++){

		for (int i=0; i<nrolls; i++) {

			number = mean + slots_dia*a + gsl_ran_gaussian(r, sigma);
			if ((number >= (ini_jr1+slots_dia*a))&&(number <= (fin_jr1+slots_dia*a))){
				if(number < 65) ++arreglo[int(number)];
			}
//			cout<<"number "<<int(number)<<endl;
			number2 = mean2 + slots_dia*a + gsl_ran_gaussian(r, sigma2);
			if ((number2 >= (ini_jr2+slots_dia*a))&&(number2 <= (fin_jr2+slots_dia*a))){
				if(number2 < 65) ++arreglo[int(number2)];
			}
//			cout<<"number2 "<<int(number)<<endl;
		}
	}
//	cout<<"arreglo.size() "<<arreglo.size()<<endl;
	gsl_rng_free (r);

	//	int suma = 0;
	double aux = 0;
	int aux1 = 0;

	for (int i=0; i<slots; i++) {
		std::cout << "slot [" << i << "] :\t";
		aux = (double)arreglo[i]*nstars/(nrolls*2);
		aux1 = rint(aux);
//		suma += aux1;
		arreglo[i] = aux1;
		std::cout << std::string(aux1,'*') << std::endl;
		arreglo[i] = rint((double)aux1*nPac/100);
	}
//	cout<<"Suma "<<suma<<endl;

//		for (int i=0; i<slots_disp; i++) {
//			cout << "arreglo["<<i<<"] "<<arreglo[i]<<endl;
//		}
//	exit(1);
	return arreglo;
}

bool Generador::compararStrElemento(vector <string> elementos, string elemento, int limit){

	vector <int> dispoActual;
	vector <int> temporal;

	dispoActual = splitStrDisponibilidad(elemento);

//	cout<<"Tamano DispoActual "<<dispoActual.size()<<endl;


	for(int i=0; i<limit; i++){
		temporal = splitStrDisponibilidad(elementos.at(i));

		for(int j=0; j<(int)dispoActual.size();j++){
			if( (temporal.at(j) == dispoActual.at(j)) && (temporal.at(j) == 1) ){
				return true;
			}
		}
		//temporal.clear();
	}

	return false;
}

vector <int> Generador::splitStrDisponibilidad(string cadena){

	vector <int> vectorAux;
	string buf;
	stringstream ss(cadena);
	vector<string> tokens;

	while(getline(ss, buf, ' ')) {
		vectorAux.push_back(atoi(buf.c_str()));
	}

	return vectorAux;
}

vector <int> Generador::aleatoriosDistintos(int nro, int max){

	int n = 0;
	vector <int> vector;

	for(int i=0; i<nro; i++){

		do{
			n = rand() % max;
	    }
	    while(compararElemento(vector, n));

		vector.push_back(n);
	    //cout << vector.at(i) << " ";
	}

	sort(vector.begin(), vector.end());

	return vector;
}

void Generador::close_archivo(){
	guardarArchivo.close();
}

void Generador::escribir(){
	save_nombre_archivo("test3.0.0.txt");
	set_slots_disponibilidad(65);
	leerBD("bd_new.txt");
	get_especialidades_profesionales();
	shuffle_bd();
	save_nro_profesionales();
	save_nro_especialidades();
	save_nro_pacientes(100);
	cout<<endl<<"ESPECIALIDADES"<<endl<<endl;
	save_informacion_especialidades();
	cout<<endl<<"PROFESIONALES"<<endl<<endl;
	save_informacion_profesionales();
	get_profesionales_especialidades();
	cout<<endl<<"PACIENTES"<<endl<<endl;
	setDistribucion(1);
	save_informacion_pacientes();
	close_archivo();
}
