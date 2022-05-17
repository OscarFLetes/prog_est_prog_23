/* Autor: Oscar Eduardo FLetes Ixta, Realizado 03/03/2022
	Hacer un prgrama que calule la liquidacion de varios empleados 
	Programa en lenguaje c que calcula la liquidacion de varios empleados con el uso del ciclo for, uso de funciones,
	prototipos de funciones y operaciones aritemticas
	Autor: Oscar Eduardo Fletes Ixta
	Escuela: UVM Campus Lomas Verdes
	Materia: Programcion Estructurada
	CICLO: 01/2022

	Programa en lenguaje c que muestra el uso de:
		* Declaracion de variables 
		* Variables del tipo int, float
		* Operaciones aritmeticas 
		* Funciones
		* Prototipos de funciones
		* Uso de parametros para llamar a la funcion 
		* Uso del ciclo for
		* printf para monstrar los valroes de las variables

	Objetivo:
	Mostrar el uso de variables enteras y flotantes, como declararlas, usar funciones, prototipos de funciones, 
	llamar a las funciones con parametros, usar el ciclo for, realizar operaciones aritmeticas e imprimirla.

	Breve descripcion:
	El programa  pide como entrada 2 variables de tipo int y float (cantidad de empleados, saldo actual), 
	luego inicia el ciclo for para insertar los demas datos, conforme a la cantidad de empleados insertados 
	El programa calcula la liquidacion de los empleados
*/

#include<stdio.h>//Cuerpo para lenguaje c
//Prototipos
float liquidacion(float salarioQ, float ant, float isr, float salMinimo);

//Main
int main(){
	//Variables
	int empleados;//variable numero entero
	float liq,salario,antiguedad, impuesto, salarioMinimo;//variable con decimal
	//Entrada
	printf("Introduce la cantidad de empleados: ");//imrpime mensaje
	scanf("%d",&empleados);//lee el numero insertado por el teclado
	printf("Introduce el salario minimo actual: $");//imrpime mensaje
	scanf("%f",&salarioMinimo);//lee el numero insertado por el teclado
	//ciclo for
	for(int i=1;i<=empleados;i++){//se usa para saber la cantidad de empleados 
		printf("empleado #%d \n",i);//imrpime el numero del empleado
		printf("Salario quincenal: $");//imrpime mensaje
		scanf("%f",&salario);//lee el numero insertado por el teclado
		printf("Antiguedad en años: ");//imrpime mensaje
		scanf("%f",&antiguedad);//lee el numero insertado por el teclado
		printf("ISR: ");//imrpime mensaje
		scanf("%f",&impuesto);//lee el numero insertado por el teclado
		//Proceso
		liq=liquidacion(salario,antiguedad,impuesto,salarioMinimo);//Parametros para la funcion
		//Ssalida
		printf("Liquidacion neta: $%.2f\n\n",liq);
	}
	return 0;
}

//Proceso
//Funciones
float liquidacion(float salarioQ, float ant, float isr, float salMinimo){//float(Parametros para la funcion)
	float bonoliquidacion, salarioP,pago20,primaAnt,liqBruto,exento,grabable,impuesto,liqneta;//variable con decimal
	
	bonoliquidacion=salarioQ*6; //Se le paga un bono de loquidacion de 3 meses de salario
	if(salarioQ/15 >salMinimo*2){//Validacion, si salarioQ/15 es mayor que salMinimo
		salarioP=salarioQ/15;//Calcula el salariop
	}
	else{//si no
		salarioP=salMinimo;//salarioP es igual a salMinimo
	}
	pago20=salarioP*20*ant;//Se le paga 20 dias de salario ponderado por cad año de antiguedad
	primaAnt=salarioQ/15*12*ant; //Se le da una prima de antiguedad de 12 años
	liqBruto=bonoliquidacion+pago20+primaAnt;//liquidacion bruta
	exento=90*salMinimo*ant;//Se le exenta la cantidad de 90 salarios minimos por cada año trabajdo
	grabable=liqBruto-exento;//se calcula el brabable
	impuesto=grabable*isr;//se calcula el impuesto
	liqneta=liqBruto-impuesto;//Se calcula la liquidacion neta
	
	return liqneta;
}
