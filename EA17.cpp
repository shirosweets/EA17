/************************************************************
 MATERIA : INFORMATICA
 EXAMEN : Recuperatorio Especificaci?n de Algoritmos - 22 de noviembre de 2012
 NOMBRE : 
 MATRICULA : 
 CARRERA : 
 COMISION : 1.4
 ************************************************************

Realice un programa en C++ para realizar lo siguiente:

1) Dada una matriz cuadrada A de dimensi?n NxN tama?o maximo 100x100, donde N es una constante entera, 
solicitar al usuario el ingreso de la cantidad de filas y columnas.
Luego cargar dicha matriz por teclado de forma tal que TODOS sus valores reales 
sean mayores a cero. Cada vez que se ingrese un nuevo dato a la matriz, deber? 
verificarse que el valor sea mayor a cero. Si no lo fuese, deber? pedirse el ingreso 
de un nuevo valor hasta que lo sea. Todo este procedimiento debe implementarse a 
trav?s de la funci?n con el siguiente prototipo:

void cargarMatriz ( double A[N][N] );

2) Mostrar en pantalla la matriz ingresada a traves del procedimiento con el 
siguiente prototipo:

void mostrarMatriz ( double A[N][N] );

3) Generar el vector C que contenga en cada elemento j el promedio correspondiente
a la columna j de la matriz A. Esto debe implementarse a trav?s de la siguiente
funci?n: 

void promedioColumnas ( double A[N][N], double C[N] );

4) Mostrar en pantalla el vector promedio generado a trav?s del procedimiento con el 
siguiente prototipo:

void mostrarVector ( double C[N] );

5) Generar el vector F que contenga en cada elemento i el promedio correspondiente
a la fila i de la matriz A. Esto debe implementarse a trav?s de la siguiente
funci?n: 

void promedioFilas ( double A[N][N], double F[N] );

6) Mostrar en pantalla el vector promedio generado haciendo uso de la funci?n 4).

7) Modificar los elementos de la matriz A de forma tal que sus elementos sean
el resultado de: duplicar el valor original del elemento (i,j) y restarle la suma 
del promedio de la columna j y de la fila i.

void modificarMatriz ( double A[N][N], double C[N], double F[N] );

8) Mostrar nuevamente la matriz resultante a trav?s de la funci?n implementada en 2).


=========================================================
 EJEMPLO DE EJECUCION O CORRIDA DEL PROGRAMA
		PARA N=2
=========================================================
Inicio de la carga de la matriz:
Ingrese valor mayor a cero:0.5
Ingrese valor mayor a cero:1.5
Ingrese valor mayor a cero:3.5
Ingrese valor mayor a cero:2.5

La matriz ingresada es:

0.5 1.5 
3.5 2.5 

El promedio por columna es:
2 
2 

El promedio por fila es:
1 
3 

La matriz modificada es:

-2 0 
2 0 


=========================================================
Tabla de Correccion
______________________________
Funci?n cargarMatriz       | 20
Funci?n mostrarMatriz      | 10
Funci?n promedioColumnas   | 10
Funci?n promedioFilas      | 10
Funci?n mostrarVector      | 05
Funci?n modificarMatriz    | 25
Programa Principal         | 10
Compilaci?n		           | 10
=========================================================

 Estimado alumno no modifique nada del c?digo que le proveemos, 
 use los procedimientos o funciones que estan definidos y no 
 agregue m?s a la solucion.
************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

const int N=100;
int filas,columnas;
void cargarMatriz ( double[N][N] );
void mostrarMatriz ( double [N][N] );
void promedioColumnas ( double [N][N], double [N] );
void mostrarVector ( double [N] );
void promedioFilas ( double [N][N], double [N] );
void modificarMatriz ( double [N][N], double [N], double [N] );

int main()
{
	double arreglo[N][N];
	double vectorPF[N];
	double vectorPC[N];
	
	cargarMatriz(arreglo);
	cout<<endl;
	mostrarMatriz(arreglo);
	cout<<endl;
	promedioColumnas(arreglo,vectorPC);
	cout<<endl;
	promedioFilas(arreglo,vectorPF);
	cout<<endl;
	modificarMatriz(arreglo,vectorPC,vectorPF);
}

void cargarMatriz (double matriz[N][N])
{
	cout<<"Ingrese el numero de columnas: ";
	cin>>columnas;
	cout<<"Ingrese el numero de filas: ";
	cin>>filas;
	cout<<endl;
	
	for	(int i=0;i<filas;i++)
	{
		for	(int j=0;j<columnas;j++)
		{	
			cout<<"Ingrese valor "<<i<<"."<<j<<" = ";
			cin>>matriz[i][j];
				
			while (matriz[i][j]==0||matriz[i][j]<0)
			{
				cout<<"Numero incorrecto. Reingrese: ";
				cin>>matriz[i][j];
			}
			
			cout<<"Numero ingresado correctamente."<<endl;
			
		}
	}
}
void mostrarMatriz (double matriz[N][N])
{
	cout<<"La matriz ingresada es:";
	for	(int i=0;i<filas;i++)
	{
		cout<<endl;
		for(int j=0;j<columnas;j++)
		{
			cout<<setprecision(2)<<setw(5)<<matriz[i][j];
		}
	}
}

void promedioColumnas (double matriz[N][N],double vectorC[N])
{
	cout<<"El promedio por columnas es:"<<endl;
	
	vectorC[0]=0;
	
	for	(int i=0;i<filas;i++)
	{
		vectorC[i]=0;
		for(int j=0;j<columnas;j++)
		{
			vectorC[i]+=matriz[j][i];
			
		}
		vectorC[i]=vectorC[i]/filas;
		cout<<setprecision(2)<<setw(5)<<vectorC[i]<<endl;
	}
}

void mostrarVector ()
{
	
}

void promedioFilas ( double matriz[N][N], double vectorF[N])
{
	cout<<"El promedio por filas es:"<<endl;
	
	for	(int i=0;i<filas;i++)
	{
		vectorF[i]=0;
		
		for(int j=0;j<columnas;j++)
		{
			vectorF[i]+=matriz[i][j];
			
		}
		vectorF[i]=vectorF[i]/columnas;
		cout<<setprecision(2)<<setw(5)<<vectorF[i]<<endl;
	}
}

void modificarMatriz (double matriz[N][N],double vectorC[N],double vectorF[N])
{
	cout<<"La matriz modificada es: ";
	
	for	(int i=0;i<filas;i++)
	{
		cout<<endl;
		for (int j=0;j<columnas;j++)
		{
			matriz[i][j]=2*matriz[i][j]-(vectorC[i]+vectorF[i]);
			cout<<setprecision(2)<<setw(5)<<matriz[i][j];
		}
	}
}
