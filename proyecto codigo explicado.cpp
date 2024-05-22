//Libreria para poder compilar
#include <iostream> 
//para crear un archivo
#include <fstream>
//para  cadenas de texto
#include <string>
//permite nos permite trabajar con un string como un stream y asu vez permite y de la misma manera podriamos ahcerlo con un cout y cin
#include <sstream>
// utiliozar la variable pow de elevar 
#include <math.h> 
using namespace std;
///*****************************************************************************////
//Se declaro esta constante para se parar los datos
const char DELIMITADOR = '|';
//Struct del nombre con un espacio de 25 y clave
struct info {
		char nombre[25];
		int clave;
}datos ;	
//struct  de variables a calcular    
struct contenido {
	
};	
///***********************************************************************//////	
//se crea una funcion sin retorno la cual es utilizada para LEER el archivo.bin.

void leer() {
	
//el nombre otro es el nombre del archivo dentro de c++ porque el nombre con el cual sera guardado es inicio2.bin.

//El ifstream es utilizado para poder LEER un archivo.

	ifstream otro("inicio2.bin", ios::binary);
	
//se realiza un condicional if el cual nos dice que si el documento otro esta abierto entonces que  nos permita leerlo.

	if (otro.is_open() ) {
		
// con el read la accion que damos es para poder leer el archivo deacuerdo al tamaño que tenga la variable datos.
                      // con el char lo que hacemos es que lo pasamos lo que hay en datos a caractes del tamaño de datos.
		otro.read((char *) &datos, sizeof (datos));	
		cout<< "ENCONTRE " << datos.nombre << " Con la calve  "<< datos.clave;
		
// un else que si el documento no esta aierto entonces que le diga a usuario que NO EXISTE REGISRTO DE USUAIRO PARA ENTRAR.

	} else {
		cout<< "NO EXISTE REGISRTO DE USUAIRO PARA ENTRAR";
	}
}
//Otra funcion sin retorno que sera utilizada para que el ususuario pueda escribir en el archivo .bin.

void escribir() {	
//solicitamos datos al usuario y los guardamos en el struct.
	cout << "Este proceso elimina el usuario actual y crea uno nuevo" << endl; // esto se solucina en la clase de hoy
	
	cout  << "DIGTE NOMBRE";
	cin >> datos.nombre;
	cout  << "DIGTE CLAVE";
	cin >> datos.clave;
//Utilizamos el ofstream para que el usuario pueda escribir en el.
	ofstream  prueba("inicio2.bin", ios::out);
	
//el char es utilizado para convertir los datos escritos por el usuario a carcter y del tamaño de la variable datos.
	prueba.write((char *) &datos, sizeof(datos) );
	
}
     
// hacemosr la validacion del usuaruario y contraseña.

int valida(info registro) {
	ifstream otro("inicio2.bin", ios::binary);
	
	//aqui hacemos un condicional el caul nos indica que si el archivo (otro) esta abierto entoces.
	
	if (otro.is_open() ) {
		
// esto nos permite leer el lo que tenemos guardado hasta el momento en la variable datos.

		otro.read((char *) &datos, sizeof (datos));	
		
//r
		if((registro.clave==datos.clave))
			return 1;
		else
			return 0;	
	} else {
		cout<< "NO EXISTIA REGISRTO DE USUARIO SE CREO NUEVO";
		ofstream otro2("inicio2.bin", ios::binary);
		otro2.write((char *) &registro, sizeof(registro) );
	}
}

////////**********************************************************///////////////////////

	

// esta es una funcio para devolver  de una cadena a un numero.
int DevuelveNumero(string cadena) {
	int control=0;
	int indi=0;
	int numero=0;   		
   		
   	control=cadena.length();   // lenght = Devover la cnatidad de caracteres . Longitud 
	for (indi=0;indi<control;indi++) {         // explicar porfavor
		numero=+(numero*10)+(cadena[indi]-48);
	}
	return numero;
}
// funcion para leer el archivo.txt
void leerarchivo() {
	string cadena;
	int parte=0;
	//contenido entrada;

	cout << "ENTRO A LEECTURA";
	ifstream mirar("datosacargar.txt",ios::in);
	// aqui esta agregando los datos 
	ofstream regis("datos.txt",ios::app);
	if(mirar.is_open()) {
		while (! mirar.eof()) {
			// aqui hacemos es que lo que tiene el txt mirar se va a guardar en cadena 
			getline(mirar,cadena);	
			//va guardar los datos que tiene cadena los pasa a regis.
			regis << cadena << endl;
			parte++;
		}
	}
	    // aqui indica la cantidad de registros que cargo
	cout << endl << "!!!!  CARGO " << parte << " REGISTROS NUEVOS !!!" << endl << endl;
}
//funcion para calcular las temperaturas
void TemperaturaMaxima() {
	string acumtem="";
	string mayortem="";
     // a la menor le declaramos un rango de 200
	string menortem="200";
	string cadena,parte1,temperatura1,condicion,viento,precion,humedad;
	int cuenta=0;
	
	ifstream mirar("datos.txt", ios::in);
	while (getline(mirar,cadena)) {  
		cuenta++;
		stringstream input_stringstream(cadena);
		getline(input_stringstream, parte1, DELIMITADOR);
		getline(input_stringstream, temperatura1, DELIMITADOR);		
		acumtem +=temperatura1;
		// en la variable temp1 se guardann todas las que se leen
		if (temperatura1 > mayortem) {
			mayortem=temperatura1;		
		}
		getline(input_stringstream, condicion, DELIMITADOR);		
		getline(input_stringstream, viento, DELIMITADOR);		
		getline(input_stringstream, precion, DELIMITADOR);	
		getline(input_stringstream, humedad, DELIMITADOR);			
	}
	  // cuenta la cantidad de registros de temperatura que hay
	cout << "SE LEYERON " << cuenta << " REGISTROS " << endl; 
	cout << "Y LA MAYOR  TEMPERURA REGSITRADA ES " << mayortem << " GARDOS CELCIUS "<< endl; 	
}

void TemperaturaMenor() {
	string acumtem="";
	string mayortem="";
	string menortem="200";
	string cadena,parte1,temperatura1,condicion,viento,precion,humedad;
	int cuenta=0;
	// se lee el txt
	ifstream mirar("datos.txt", ios::in);
	while (getline(mirar,cadena)) {  // mientras este cadena en el txt mirar 
		cuenta++;
		stringstream input_stringstream(cadena);
		getline(input_stringstream, parte1, DELIMITADOR);
		getline(input_stringstream, temperatura1, DELIMITADOR);		
		acumtem +=temperatura1;
		if (temperatura1 < menortem) {
			menortem=temperatura1;		
		}
		getline(input_stringstream, condicion, DELIMITADOR);		
		getline(input_stringstream, viento, DELIMITADOR);		
		getline(input_stringstream, precion, DELIMITADOR);	
		getline(input_stringstream, humedad, DELIMITADOR);			
	}
	cout << "SE LEYERON " << cuenta << " REGISTROS " << endl; 
	cout << "Y LA MENOR TEMPERURA REGSITRADA ES " << menortem << " GARDOS CELCIUS "<< endl; 	
}

void TemperaturaPromedio() {
	string acumtem="";
	string mayortem="";
	string menortem="200";
	string cadena,parte1,temperatura1,condicion,viento,precion,humedad;
	int cuenta=0;
	int control=0;
	int indi=0;
	int numero=0;
	int promedia=0;
	
	
	ifstream mirar("datos.txt", ios::in);
	while (getline(mirar,cadena)) {  
		cuenta++;
		stringstream input_stringstream(cadena);
		getline(input_stringstream, parte1, DELIMITADOR);
		getline(input_stringstream, temperatura1, DELIMITADOR);	
		numero=DevuelveNumero(temperatura1);
		/*control=temperatura1.length();
		for (indi=0;indi<control;indi++) {
			numero=+(numero*(10*indi))+(temperatura1[indi]-48);
		}*/
		promedia+=numero;	
		getline(input_stringstream, condicion, DELIMITADOR);		
		getline(input_stringstream, viento, DELIMITADOR);		
		getline(input_stringstream, precion, DELIMITADOR);	
		getline(input_stringstream, humedad, DELIMITADOR);			
	}
	cout << "SE LEYERON " << cuenta << " REGISTROS " << endl; 
	cout << "Y LA TEMPERURA PROMEDIO ES " << (promedia/cuenta) << " GARDOS CELCIUS "<< endl; 	
}


void Calcular() {
	int mayortem=0;
	int menortem=200;
	int acumtem=0;
	string cadena,parte1,temperatura1,condicion,viento,precion,humedad;
	string incendio="NO HAY PROBABILIDAD DE INCENDIO";
	string tormenta="NO HAY PROBABILIDAD DE TORMENTA";
	int cuenta=0;
	
	cout << "Los Datos Cual Dato desea calcular" << endl;
	ifstream mirar("datos.txt", ios::in);
	while (getline(mirar,cadena)) {  
		cuenta++;
		stringstream input_stringstream(cadena);
		getline(input_stringstream, parte1, DELIMITADOR);
		getline(input_stringstream, temperatura1, DELIMITADOR);		
		acumtem +=DevuelveNumero(temperatura1);
		if (DevuelveNumero(temperatura1) > mayortem) {
			mayortem=DevuelveNumero(temperatura1);
			
		}
		if (DevuelveNumero(temperatura1) < menortem) {
			menortem=DevuelveNumero(temperatura1);		
		}
		getline(input_stringstream, condicion, DELIMITADOR);		
		getline(input_stringstream, viento, DELIMITADOR);		
		getline(input_stringstream, precion, DELIMITADOR);	
		getline(input_stringstream, humedad, DELIMITADOR);		
		if ((DevuelveNumero(temperatura1) >= 35) && (condicion=="2") && ((DevuelveNumero(viento) >= 7) )) {
				incendio="PROBABILIDAD DE INCENDIO ALTA Temperatura "+temperatura1+" Y viento de "+viento;	
		}
		if ((DevuelveNumero(precion) < 1010) && (DevuelveNumero(humedad) > 70) && (condicion == "1") ) {
				tormenta="ALTA PROBABILIDAD DE TORMENTA percion atmosferica "+precion+" Y humedad de " + humedad+"%";	
		}
	}
	cout << "SE REGISTRARON " << cuenta << " REGISTROS " << endl; 
	cout << "MAYOR " << mayortem << endl; 
	cout << "MENOR " << menortem << endl; 
	//cout << acumtem << endl;
	cout << incendio << endl;
	cout << tormenta << endl;
	
	ofstream salida("informe.txt" , ios::out);
	salida << "Se recibieron " << cuenta << " Registros " << endl; 
	salida << "La temperatura mayor fue " << mayortem << " Grado Celsius "<< endl; 
	salida << "La temperatura menor fue " << menortem << " Grados Celsius"<< endl; 
	//salida << acumtem << endl;
	salida << incendio << endl;
	salida << tormenta << endl;
	
}


void MayorHumedad () {
	int mayortem=0;
	//string menortem="200";
	string acumtem="";
	string cadena,parte1,temperatura1,condicion,viento,precion,humedad;
	string incendio="NO HAY PROBABILIDAD DE INCENDIO";
	string tormenta="NO HAY PROBABILIDAD DE TORMENTA";
	int cuenta=0;
	int numero=0;
	
	cout << "Los Datos Cual Dato desea calcular" << endl;
	ifstream mirar("datos.txt", ios::in);
	while (getline(mirar,cadena)) {  
		cuenta++;
		stringstream input_stringstream(cadena);
		getline(input_stringstream, parte1, DELIMITADOR);
		getline(input_stringstream, temperatura1, DELIMITADOR);		
		getline(input_stringstream, condicion, DELIMITADOR);
		getline(input_stringstream, viento, DELIMITADOR);		
		getline(input_stringstream, precion, DELIMITADOR);	
		getline(input_stringstream, humedad, DELIMITADOR);		
		numero=DevuelveNumero(humedad);
		if (numero > mayortem) {
			mayortem=numero;		
		}
	}
	cout << "SE LEYERON " << cuenta << " REGISTROS " << endl; 
	cout << "Y LA MAYOR PORCENTAJE DE HUMEDAD PROMEDIO  ES " << mayortem << " % "<< endl; 	
}

void MenorHumedad () {
	int menortem=250;
	//string menortem="200";
	string acumtem="";
	string cadena,parte1,temperatura1,condicion,viento,precion,humedad;
	string incendio="NO HAY PROBABILIDAD DE INCENDIO";
	string tormenta="NO HAY PROBABILIDAD DE TORMENTA";
	int cuenta=0;
	int numero=0;
	
	cout << "Los Datos Cual Dato desea calcular" << endl;
	ifstream mirar("datos.txt", ios::in);
	while (getline(mirar,cadena)) {  
		cuenta++;
		stringstream input_stringstream(cadena);
		getline(input_stringstream, parte1, DELIMITADOR);
		getline(input_stringstream, temperatura1, DELIMITADOR);		
		getline(input_stringstream, condicion, DELIMITADOR);
		getline(input_stringstream, viento, DELIMITADOR);		
		getline(input_stringstream, precion, DELIMITADOR);	
		getline(input_stringstream, humedad, DELIMITADOR);		
		numero=DevuelveNumero(humedad);
		if (numero < menortem) {
			menortem=numero;		
		}
	}
	cout << "SE LEYERON " << cuenta << " REGISTROS " << endl; 
	cout << "Y LA MENOR PORCENTAJE DE HUMEDAD PROMEDIO  ES " << menortem << " % "<< endl; 	
}

void verarchivo() {
	string cadena,parte1;
	
	cout << "DATOS REGISTRADOS ACTUALMENBTE" << endl;
	
	ifstream mirar("datos.txt", ios::in);
	while (getline(mirar,cadena)) {  
		stringstream input_stringstream(cadena);
		getline(input_stringstream, parte1, DELIMITADOR);
		cout << "FECHA :" << parte1 ;
		getline(input_stringstream, parte1, DELIMITADOR);		
		cout << "TEMPERATIURA " << parte1;
		getline(input_stringstream, parte1, DELIMITADOR);		
		cout << "COIDCION ATMOSFERICA " << parte1;
		getline(input_stringstream, parte1, DELIMITADOR);		
		cout << "VELOCIDAD DEL VIENTO " << parte1;
		getline(input_stringstream, parte1, DELIMITADOR);		
		cout << "PRECION ATMOSFERICA " << parte1;
		getline(input_stringstream, parte1, DELIMITADOR);		
		cout << "HUMEDAD " << parte1 << endl;
	}	
}

void regusu() {
	
}

int entrada() {
//se declararon variables.
    info  usuario;
    int opcion;

    cout  << "DIGTE NOMBRE";
	cin >>usuario.nombre;
	cout  << "DIGTE CLAVE";
	cin >>usuario.clave;
	opcion=valida(usuario);
	if (opcion != 1) {
		cout << "LA INFORMCAION NO ES CORRECTA.VUELVA A INTERTARLO" << endl;
		return 0;
	}
	return 2;	
}

void Incendio() {
	string mayortem="";
	string menortem="200";
	string acumtem="";
	string cadena,parte1,temperatura1,condicion,viento,precion,humedad;
	string incendio="NO HAY PROBABILIDAD DE INCENDIO";
	string tormenta="NO HAY PROBABILIDAD DE TORMENTA";
	int cuenta=0;
	
	cout << "Los Datos Cual Dato desea calcular" << endl;
	ifstream mirar("datos.txt", ios::in);
	while (getline(mirar,cadena)) {  
		cuenta++;
		stringstream input_stringstream(cadena);
		getline(input_stringstream, parte1, DELIMITADOR);
		getline(input_stringstream, temperatura1, DELIMITADOR);		
		getline(input_stringstream, condicion, DELIMITADOR);		
		getline(input_stringstream, viento, DELIMITADOR);		
		getline(input_stringstream, precion, DELIMITADOR);	
		getline(input_stringstream, humedad, DELIMITADOR);		
			
		if ((DevuelveNumero(temperatura1) >= 35) && (condicion=="2") && ((DevuelveNumero(viento) >= 7) )) {
				incendio="PROBABILIDAD DE INCENDIO ES ALTA Temperatura "+temperatura1+" Y viento de "+viento;	
		}
//		if ((precion < "1010") && (humedad > "70") && (condicion == "1") ) {
				//tormenta="ALTA PROBABILIDAD DE TORMENTA percion atmosferica "+precion+" Y humedad de " + humedad+"%";	
	//	}
			
	}
	cout << "SE REGISTRARON " << cuenta << " REGISTROS " << endl; 
	cout << incendio << endl;
	
}

void Tormenta() {
	string mayortem="";
	string menortem="200";
	string acumtem="";
	string cadena,parte1,temperatura1,condicion,viento,precion,humedad;
	string tormenta="NO HAY PROBABILIDAD DE TORMENTA";
	int cuenta=0;
	
	cout << "Los Datos Cual Dato desea calcular" << endl;
	ifstream mirar("datos.txt", ios::in);
	while (getline(mirar,cadena)) {  
		cuenta++;
		stringstream input_stringstream(cadena);
		getline(input_stringstream, parte1, DELIMITADOR);
		getline(input_stringstream, temperatura1, DELIMITADOR);		
		getline(input_stringstream, condicion, DELIMITADOR);		
		getline(input_stringstream, viento, DELIMITADOR);		
		getline(input_stringstream, precion, DELIMITADOR);	
		getline(input_stringstream, humedad, DELIMITADOR);		
			
		if ((DevuelveNumero(precion) < 1010) && (DevuelveNumero(humedad) > 70) && (condicion == "1") ) {
			tormenta="ALTA PROBABILIDAD DE TORMENTA percion atmosferica "+precion+" Y humedad de " + humedad+"%";	
		}
			
	}
	cout << "SE REGISTRARON " << cuenta << " REGISTROS " << endl; 
	cout << tormenta << endl;
	
}


int main () {
	int opcion;
	
	do 
	{
		cout << "BIENVENIDO AL SISTEMA DE CONTROL Y PROBABILIDAD DE MEDIO AMBIENTE" << endl;
		cout << "Digite una opcion" << endl << "1. Registro de Usuario" << endl << "2. Iniciar Sistema"   << endl;
		cin >> opcion;		
		if(opcion==1) {
			escribir();
		}
		if(opcion==2) {
			opcion=entrada();
		}
	} while (opcion != 2);
	
// este bucle es utilizado para la interfaz del menu siempre y cuando sea diferente de 3 ya que el numero 3 en el menu significa la saida del programa.

	do 
	{
		cout << "Digite una opcion" << endl << "1. Mostrar Temperatura Maxima" << endl << "2. Mostrar Temperatura Minima"  << endl << "3. Calcular Promedio de Temperatura"  << endl ;
		cout << "4. Calcular Mayor Promedio de Humedad" << endl << "5. Calcular Menor Promedio de Humedad" << endl << "6. Calcular probabilidad de incendio" << endl << "7. Calcular Probabilidad de tormenta" << endl ; 
		cout << "8. Agregar registros desde un archivo " << endl << "9. Generar Archivo Informe" << endl << "0. Temrinar " << endl;
		cin >> opcion;
		
		if(opcion==1) {
			TemperaturaMaxima();
		}
// que si el usuario dijita el numero 1 entonces el progrograma lo que hace es remitir al usuario hacia la funcion escribir para crear un registro.		

		if(opcion==2) {		
			TemperaturaMenor();
		}
// que si el usuario dijita el numero 1 entonces el progrograma lo que hace es remitir al usuario hacia la funcion LEER para que este pueda leer sus datos.	
		if(opcion==3)  {
			TemperaturaPromedio();
		}
		if (opcion==4) {
			MayorHumedad ();
		}
		if (opcion==5) {
			MenorHumedad ();
		}
		if(opcion==6)  {
			Incendio();
		}
		if(opcion==7)  {
			Tormenta();
		}
		if(opcion==8)  {
			leerarchivo();
		}
		if(opcion==9)  {
			Calcular();
		}
	} while (opcion != 0);
			
}
