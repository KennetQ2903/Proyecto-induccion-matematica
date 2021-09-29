	/*
	UNIVERSIDAD MARIANO GALVEZ DE GUATEMALA
	INGENIERIA EN SISTEMAS 
	PROYECTO DE MATEMATICA DISCRETA INDUCCION MATEMATICA
	KENNET JORSHOA ORTEGA QUIROZ
	CARNÉ: 6691-21-8308
	*/
	
	#include <iostream> //--> CIN y COUT
	#include <windows.h>// --> CLS
	
	//LIBRERIAS DE FUNCIONES ESPECIALES
	#include <cstdlib> //--> FUNCION GETCH
	#include <conio.h> //--> FUNCION GOTOXY
	#include <string.h> //--> FUNCION CONVERSION DE STRINGS
	
	using namespace std; //--> evitar funciones std de C
	
	//VARIABLE GLOBAL DE MENU
	int op;
	
	//------------------------------------------------------[ ENCABEZADOS ]--------------------------------------------------------------------------------------------------------
	void encabezadoMenu(){
		cout<<"---------------------------------[ MENU INDUCCION MATEMATICA ]-----------------------------------\n"<<endl;
	}
	void encabezadoFactores()
	{
		cout<<"---------------------------------------[ FACTORES PRIMOS ]-----------------------------------\n"<<endl;
	}
	
	void encabezadoMCD()
	{
		cout<<"--------------------------------------------[ MCD ]-----------------------------------\n"<<endl;
	}
	void encabezadoAlgoritmoDeLaDivision()
	{
		cout<<"---------------------------------[ ALGORITMO DE LA DIVISION ]-----------------------------------\n"<<endl;
	}
	void encabezadoAlgoritmoDeEuclides()
	{
		cout<<"----------------------------------[ ALGORITMO DE EUCLIDES ]-----------------------------------\n"<<endl;
	}
	
	//------------------------------PROCEDIMIENTO DE GOTOXY--------------------------------------
	void gotoxy(int x,int y){  
		HANDLE hcon;  
	    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	    COORD dwPos; 
	    dwPos.X = x;  
	    dwPos.Y= y;  
	    SetConsoleCursorPosition(hcon,dwPos);  
	}	
	
	//-----------------------------PROCEDIMIENTO DE NUMERO PRIMO---------------------------------
	
	bool numeroPrimo(int num)
	{
		int i, cont = 0;
		
		 for(i = 1; i <= num; i++)
		 {
		 	if(num % i == 0)
		 	{
		 		cont++;
			}
		 }
		 if(cont > 2)
		 {
		 	return false;
		 }
		 if(cont <= 2)
		 {
		 	return true;
		 }
	}
	
	//-----------------------------------------APARTADO FACTORES PRIMOS----------------------------------------------------------------------------------------------
	
	int productoFactoresPrimos()
	{
		int a = 0;
		int num, res, numTemp, calc;
		bool yesNo;
		int factores[99999];
		
		system("CLS");
		encabezadoFactores();
		cout<<"Ingrese el numero al que desea calcular sus factores primos:"<<endl;
		cin>>num;
		numTemp = num;
		if(num > 1 && num < 1000000 ) //significa que tiene factores primos
		{
			for(int i = 2; i <= num;)
			{
				yesNo = numeroPrimo(i);
				
				if(yesNo == true) //significa que el numero por el cual vamos a dividir es primo
				{
					calc = num % i;
					
					if(calc == 0) //significa que el numero primo dividio exactamente
					{
						num = num / i;
						
						factores[a] = i;
						a++;
						
						i = 2; // reinicio el contador 
					}
				}
				if(calc != 0 || calc < 0 || calc > 0 || yesNo == false)
				{
					i++;
				}
				
			}
			
			cout<<"Los factores primos de "<<numTemp<<" son:\n"<<endl;
			cout<<"\t";
			for(int b = 0; b < a; b++)
			{
				cout<<factores[b];
				if(b != (a - 1))
				{
					cout<<" * ";
				}
			}
			cout<<"\n"<<endl;
			getch();
			return 0;
		}
		
		if(num > 1000000)
		{
			system("CLS");
			cout<<"El numero "<<numTemp<<" es demasiado grande para poder calcular"<<endl;
			getch();
		}
		if(num == 0 || num == 1)
		{
			system("CLS");
			cout<<"El numero "<<numTemp<<" no tiene factores primos posibles"<<endl;
			getch();
		}
	}
	
	
	
	
	//----------------------------APARTADO MCD-----------------------------------------
	
		
	int procedimientoMCD()
	{
		//VARIABLES PARA EL MCD
		int count,  nums, MCD, R;
		int numeros[99999];
		
		//VARIABLES PARA LOS FACTORES
		int a = 0;
		int num, res, numTemp, calc;
		bool yesNo;
		int factores[99999];
		
		system("CLS");
		encabezadoMCD();
		
		do{
			cout<<"Ingrese la cantidad de numeros de los cuales desea saber su MCD: "<<endl;
			cin>>count;
		}while(count <= 0);
		
		for(int i = 0; i < count; i++)
		{
			do{
				system("CLS");
				cout<<"Ingrese el numero "<<i+1<<" del cual desea saber su MCD: "<<endl;
				cin>>nums;
				numeros[i] = nums;
				
			}while(nums < 0);
			
			if(i == 0)
			{
				MCD = nums;
			}
			do{
				R = MCD%nums;
				MCD = nums;
				nums = R;
			}while(R != 0);
		}
		
		num = MCD;
		
		if(num > 1 && num < 1000000 ) //significa que tiene factores primos
		{
			for(int i = 2; i <= num;)
			{
				yesNo = numeroPrimo(i);
				
				if(yesNo == true) //significa que el numero por el cual vamos a dividir es primo
				{
					calc = num % i;
					
					if(calc == 0) //significa que el numero primo dividio exactamente
					{
						num = num / i;
						
						factores[a] = i;
						a++;
						
						i = 2; // reinicio el contador 
					}
				}
				if(calc != 0 || calc < 0 || calc > 0 || yesNo == false)
				{
					i++;
				}
				
			}
		}
		
		system("CLS");
		cout<<"EL MCD de los numeros: ";
		for(int a = 0; a < count; a++)
		{
			cout<<" "<<numeros[a];
			if(a != count-1)
			{
				cout<<",";
			}
		}
		cout<<" es: "<<endl;
		
		for(int b = 0; b < a; b++)
		{
			cout<<factores[b];
			if(b != (a - 1))
			{
				cout<<" * ";
			}
		}
		cout<<" = "<<MCD<<endl;
			
		
		getch();
		return 0;
	}
	
	int algoritmoDelaDivision()
	{
		int div, divsr, a, b, q, r;
		
		system("CLS");
		encabezadoAlgoritmoDeLaDivision();
		cout<<"Ingrese el valor del dividendo"<<endl;
		cin>>div;
		
		
		
		cout<<"Ingrese el valor del divisor"<<endl;
		cin>>divsr;
		
		a = div; //divisor
		
		b = divsr; //dividendo
		
		q = a/b; //cociente
		
		r = a%b; //residuo
		
		system("CLS");
		
		cout<<"La ecuacion del algoritmo de la division es: a = b * q + r\n"<<endl;
		cout<<"Reemplazando datos: "<<endl;
		gotoxy(9, 5);


	// PARA DIBUJAR LAS DIVISIONES
	//VARIABLES PARA MOVER EL CURSOR
		int repeats = -1, x, y, LB, LA;
		
		//VARIABLES PARA CONVERTIR A STRING
		string A, B;
		
		x = 10;
		y = 6;
		int X, Y, X1, Y1, Y2;
		X = x;
		gotoxy(X, y);
		cout<<b;
		cout<<"|";
		cout<<a;
		
		//escribimos la parte de arriba (_)
		B = to_string(b);
		LB = B.length();
		X1 = X+LB+1;
		A = to_string(a);
		LA = A.length();
		Y = y - 1;
		gotoxy(X1, Y);
		for(int l = 0; l < LA; l++)
		{
			cout<<"_";
		}
		//escribimos la parte de arriba (cociente)
		Y1 = Y - 1;
		gotoxy(X1, Y1);
		for(int ll = 0; ll < 1; ll++)
		{
			cout<<a/b;
		}
		//escribimos la parte de abajo (resta)
		Y2 = Y + 2;
		gotoxy(X1, Y2);
		for(int lll = 0; lll < 1; lll++)
		{
			cout<<b*(a/b);
		}
		//escribimos la parte de abajo (--)
		Y2 = Y + 3;
		gotoxy(X1, Y2);
		for(int llll = 0; llll < LA; llll++)
		{
			cout<<"-";
		}
		//escribimos la parte de abajo (--)
		Y2 += 1;
		gotoxy(X1, Y2);
		for(int u = 0; u < 1; u++)
		{
			cout<<a%b;
		}
		
		
		gotoxy(1, 11);
		cout<<"Aplicando la formula 'a = b * q + r': \n"<<endl;
		cout<<"\t"<<a<<" = "<<b<<" * "<<q<<" + "<<r<<"\n"<<endl;
		cout<<"\t"<<a<<" = "<<b*q<<" + "<<r<<"\n"<<endl;
		cout<<"\t"<<a<<" = "<<b*q+r<<"\n"<<endl;
		
		gotoxy(1, 20);
		getch();
		
		return 0;
	}
	
	
	
	
	
	void algoritmoDeEuclides()
	{
		//VARIABLES PARA OPERACIONES
		int div, divsr, a, b, q, r, MCD, nums, R;
		
		//VARIABLES PARA MOVER EL CURSOR
		int repeats = -1, x, y, LB, LA;
		
		//VARIABLES PARA CONVERTIR A STRING
		string A, B;
		
		system("CLS");
		encabezadoAlgoritmoDeEuclides();
		cout<<"Ingrese el valor del dividendo"<<endl;
		cin>>div;
		
		
		
		cout<<"Ingrese el valor del divisor"<<endl;
		cin>>divsr;
		
		
		a = div; //divisor
		
		b = divsr; //dividendo
		
		q = a/b; //cociente
		
		r = a%b; //residuo
		
		system("CLS");
		
		for(int i = 0; i < 2; i++)
		{	
			if(i == 0)
			{
				nums = div;
				MCD = nums;
			}
			if(i > 0)
			{
				nums = divsr;
			}
			do{
				R = MCD%nums;
				MCD = nums;
				nums = R;
				repeats++;

			}while(R != 0);
		}
		//FOR PARA DIBUJAR LAS DIVISIONES
		x = 16;
		y = 4;
		int X, Y, X1, Y1, Y2;
		cout<<"Siguiendo los pasos del algoritmo de Euclides tenemos que: "<<endl;
		for(int s = 1; s <= repeats; s++)
		{
			X = x * s - x;
			gotoxy(X, y);
			cout<<b;
			cout<<"|";
			cout<<a;
			
			//escribimos la parte de arriba (_)
			B = to_string(b);
			LB = B.length();
			X1 = X+LB+1;
			A = to_string(a);
			LA = A.length();
			Y = y - 1;
			gotoxy(X1, Y);
			for(int l = 0; l < LA; l++)
			{
				cout<<"_";
			}
			//escribimos la parte de arriba (cociente)
			Y1 = Y - 1;
			gotoxy(X1, Y1);
			for(int ll = 0; ll < 1; ll++)
			{
				cout<<a/b;
			}
			//escribimos la parte de abajo (resta)
			Y2 = Y + 2;
			gotoxy(X1, Y2);
			for(int lll = 0; lll < 1; lll++)
			{
				cout<<b*(a/b);
			}
			//escribimos la parte de abajo (--)
			Y2 = Y + 3;
			gotoxy(X1, Y2);
			for(int llll = 0; llll < LA; llll++)
			{
				cout<<"-";
			}
			//escribimos la parte de abajo (--)
			Y2 += 1;
			gotoxy(X1, Y2);
			for(int u = 0; u < 1; u++)
			{
				cout<<a%b;
			}
			//intercambio de variables
			r = a%b;
			a = b;
			b = r;
		}
		gotoxy(1, 9);
		cout<<"El MCD es: "<<MCD<<endl;
		getch();
	}
	
	void menu(){
		system("CLS");
		encabezadoMenu();
		cout<<"Que desea realizar?\n"<<endl;
		cout<<"1.Producto de factores primos\n2.Maximo comun divisor\n3.Algoritmo de la division\n4.Algoritmo de euclides\n5.Exit"<<endl;
		cin>>op;
		
		switch(op)
		{
			case 1:
				productoFactoresPrimos();
			break;
			
			case 2:
				procedimientoMCD();
			break;
			
			case 3:
				algoritmoDelaDivision();
			break;
			
			case 4:
				algoritmoDeEuclides();
			break;
			
			case 5:
				//SALIR DEL MENU Y DEL PROGRAMA
			break;
			
			default:
				system("CLS");
				cout<<"Elija una opcion valida!"<<endl;
				getch();
				menu();
			break;
		}
	}
	main(){
		
		do
		{
			system("CLS");
			menu();
		}
		while(op != 5);
		system("CLS");
		cout<<"Nos vemos!"<<endl;
		getch();
	}

