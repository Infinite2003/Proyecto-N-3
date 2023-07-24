En este proyecto se buscaba optimizar algunos aspectos de logica a los juegos "The Guardians" y "The Guardians Jorney", concretamente en los
escenarios donde hubiera: 

	.- Tablero de puntaje
	.- Determinacion de camino entre las aldeas 
	.- Dibujo o renderizado de objetos

Cada una con una cantidad estimada de datos

El objetivo era crear un programa donde se pudieran generar distintos tipos de algoritmos que puedan optimizar estos conjuntos de datos, revisar
cual es el mas optimo para cada ocacion y implementarlo en el juego.

Para esto, yo utilice la creacion de 4 conjuntos de datos con tipos de orden al ser generado cada uno: 

	.- Ordenado
	.- Inversamente Ordenado
	.- Aleatorio
	.- Aleatorio sin Repeticion

y a cada uno le aplique los 7 algoritmos de ordenamiento que ibamos a comprarar: 

	.- QuickSort
	.- ShellSort
	.- SelectionSort
	.- BubbleSort
	.- InsertionSort
	.- MergeSort
	.- HeapSort

En este doy la opcion al usuario si quiere que se ordenen de manera ascendente o descendente, para poder ver la eficacia en ambos casos de cada 
algoritmo.

Primero, realice 4 fucnciones para generar los distintos conjuntos de datos. En los ordenado y Inversamente Ordenado se toma el tamaño de una variable
que seria la cantidad de datos a trabajar dentro de los rangos esperados, y dentro de un for aplico un ciclo para agregar desde el 1 hasta la variable
de cantidad y desde la variable hasta 1 respectivamente. En los aleatorios y aleatorios sin reposicion utilice un for desde 0 hasta la variable 
y mientras se realizaba la recursividad una variable llamada randome obtenia un valor aleatorio, para posteriormente ser ingresado en el arreglo.
En el aleatorio sin repeticion tenia la diferencia de que comprobaba con otro for y un if si ya existia el numero generado dentro del conjunto. 

Despues defini las funciones de los algoritmos de ordenamiento, uno para un orden ascendente y otro para un orden descendente.

Lo siguiente que realice fue generar 7 arreglos vacios para poder igualarlos a cada uno de los 4 conjuntos segun avanzaba la carrera para poder realizar la comparacion de
tiempos de los algoritmos, guardandolos en 7 variables double para guardar los segundos que tardaron. Luego de que termine de realizarce todos los 
algoritmos de ordenamiento llamo una funcion que declaro comparar, que como dicta su nombre, se utiliza para comparar los tiempos de cada algoritmo
En este ingreso los tiempos guardados y los ingreso en un unordered_map, donde relaciono nombres de los algoritmos con sus respectivos tiempos. Despues
genero valores de nombre y de menor para guardar cual es el tiempo mas corto y el nombre del algoritmo respectivo, para despues indicarle al usuario
que este algoritmo se demoro menos con la cantidad de segundos. 

Esto lo realizo por cada conjunto de datos durante las 3 carreras, vasiando los conjuntos originales para despues generar nuevos con una distinta 
cantidad de datos segun el rango de cantidad de datos de cada carrera. 

