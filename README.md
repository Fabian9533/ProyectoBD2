# ProyectoBD2


<img src="https://upload.wikimedia.org/wikipedia/commons/7/7a/UTEC.jpg" width="200">

### **Integrantes**
* Fabian Martin Alvarado Vargas
* Franco Pacheco Espino
* Johannes Albert Segundo Loayza 
* Nincol Abraham Quiroz Maquin

## **Tabla de contenido**
* [Introducción](#introducción)
* [Técnicas a usar en el proyecto](#técnicas-a-usar)
  * [Extendible Hash](#extendible-hash)
  * [Sequential File](#sequential-file)
* [Resultados](#resultados)
  * [Tiempo de ejecución](#tiempo-de-ejecución)
  * [Acessos a memoria secundaria](#accesos-a-memoria-secundaria)
  * [Discusión y análisis de resultados experimentales](#discusión-y-análisis-de-resultados-experimentales)
* [Pruebas y video del proyecto](#pruebas)
# **Introducción**


## **Objetivo del proyecto**
El objetivo del siguiente proyecto es implementar un Sistema Gestor de Base de Datos (SGBD) en donde se pueda realizar funciones dedicadas al manejo de datos. Para ello, se utilizarán las implementaciones de las estructuras aprendidas en clase.

# **Técnicas a usar**
- [Extendible Hash](#extendible-hash)
- [Sequential File](#sequential-file)
  

## **Extendible Hash**
<!--- >Explicación de la técnica <--->
Se utilizará una tabla hash para almacenar datos, donde la función hash proporcionada por el compilador de C ++ generará cadenas de bits como índices para guardar registros en archivos. Las funciones de inserción, eliminación y búsqueda funcionan de la siguiente manera:
<!--- >Funcionamiento de inserción, eliminación y búsqueda <--->
Dentro de las funciones tales como inserción, eliminación y búsqueda, su funcionamiento es el siguiente.

<!--- >Manejo de memoria secundaria <--->
En el archivo "índice", se encuentran todos los índices de la estructura, que consta de 2^D índices que apuntan a un bucket en el archivo de datos. Los buckets tienen un número máximo de registros y un número de registros insertados. Cada bucket tiene una profundidad local 'D'. Cuando se excede la cantidad máxima de registros en un bucket, se divide el índice, se crea un nuevo bucket y se aumenta en uno la profundidad local. Si su profundidad es igual al valor determinado 'D', entonces se crea un linked bucket. Se consulta al Freelist para verificar si hay buckets eliminados para agregar el linked bucket en dicho espacio. En caso contrario, se escribe al final del archivo linkeando con el bucket correspondiente.

Al eliminar registros, se verifica si se vacía el bucket al eliminar el registro. Además, se comprueba si es posible unir los buckets. En ese caso, se realiza la unión y se disminuye la profundidad local. Los buckets eliminados se registran en un Freelist, que utiliza una estrategia LIFO. Finalmente, la cabecera del Freelist se guarda al inicio del archivo de índices.
 
## **Sequential File**
<!--- >Explicación de la técnica <--->
En esta técnica, los registros se organizan en orden ascendente por una clave dentro del archivo. Si un registro no se encuentra en el archivo principal, se vincula con el siguiente registro correspondiente. Además, hay un archivo auxiliar en el que se ingresan registros que no se pueden escribir al final del archivo principal debido a que está ordenado y no se reconstruye para evitar aumentar la complejidad de la inserción según la cantidad de registros en el archivo principal.
<!--- >Funcionamiento de inserción, eliminación y búsqueda <--->
Dentro de las funciones tales como inserción, eliminación y búsqueda, su funcionamiento es el siguiente.

<!--- >Manejo de memoria secundaria <--->
En las funciones de inserción, eliminación y búsqueda, el archivo principal se mantiene ordenado. Los registros tienen un puntero hacia el siguiente registro, que puede estar en el archivo principal o en el auxiliar. Cuando la cantidad de inserciones en el archivo auxiliar o eliminaciones totales alcanza un límite, se realiza una reorganización para volver a ordenar todos los registros en el archivo principal.

Para la inserción, primero se verifica si hay espacio disponible en el archivo principal para insertar el nuevo registro. Si es así, se agrega el registro. Si no hay espacio libre, se inserta en el archivo auxiliar y se actualizan los punteros. Para la eliminación de un registro, solo se cambian los punteros de los registros, lo que libera espacio para que un nuevo registro se pueda insertar directamente en el archivo principal.


# **Resultados**

## Tiempo de Ejecución
Tiempo medido en segundos

### Inserción de registros
| | | | | | |
| :-------------------: | --- | --- | --- | --- | --- |
| | 500 registros | 1000 registros | 1500 registros | 2000 registros | 2500 registros |
| Sequential | 0.512 | 1.021 | 1.491 | 1.932 | 2.456 | 
| Extendible Hash | 0.484 | 0.888 | 1.687 | 2.442 |  3.261 |

### Búsqueda de un registro
| | | | | | |
| :-------------------: | --- | --- | --- | --- | --- |
| | 500 registros | 1000 registros | 1500 registros | 2000 registros | 2500 registros |
| Sequential | 0.008 | 0.008 | 0.009 | 0.009 | 0.01 | 
| Extendible Hash | 0.008 | 0.008 | 0.008 | 0.008 |  0.008 |

### Búsqueda por rango
| | | | | | |
| :-------------------: | --- | --- | --- | --- | --- |
| | 500 registros | 1000 registros | 1500 registros | 2000 registros | 2500 registros |
| Sequential | 0.436 | 0.443 | 0.445 | 0.445 | 0.447 | 
| Extendible Hash | 0.737 | 0.763 | 0.725 | 0.775 |  0.68 |


## Accesos a memoria secundaria
Para obtener los accesos a memoria secundaria dentro de las funciones especificadas, se contará los "reads" y "writes" que haga la función en su tiempo de ejecución.

### Inserción de registros
| | | | | | |
| :-------------------: | --- | --- | --- | --- | --- |
| | 500 registros | 1000 registros | 1500 registros | 2000 registros | 2500 registros |
| Sequential | 2524 | 5048 | 7572 | 10096 | 12620 | 
| Extendible Hash | 1092 | 2184 | 3854 | 5354 |  6908 |

### Busqueda de un registro
| | | | | | |
| :-------------------: | --- | --- | --- | --- | --- |
| | 500 registros | 1000 registros | 1500 registros | 2000 registros | 2500 registros |
| Sequential | 12 | 12 | 13 | 14 | 15 | 
| Extendible Hash | 2 | 2 | 2 | 2 | 2 |


## Discusión y análisis de resultados experimentales
Los resultados experimentales muestran que entre ambas técnicas de almacenamiento de datos, existen diferencias significativas en sus tiempos de ejecución acorde a la funcionalidad que se requiera.
Por un lado, tenemos que el “Extendible Hash” tiene una diferencia significativa de tiempo de inserción masiva en comparación con el “Sequential File”, esto se debe a que la función hash puede crear “buckets” que no se llenen de datos, cuando se tiene a otros con muchos “linked buckets”, incrementando el tiempo de ejecución mientras más datos se inserten a la vez. Por lo que, el “Sequential File” muestra un mejor rendimiento en este aspecto, porque los archivos son ordenados antes de ser escritos, y no se separan espacios innecesarios al momento de escribir los registros.

Asimismo, cuando es únicamente un solo registro el que se ingresa, la técnica de “Extendible Hash” muestra un mejor rendimiento que el “Sequential File” porque este último, al estar escrito de forma secuencial y ordenada, en el peor de los casos se tiene que ir al final del archivo, que por el contrario dentro de la otra técnica, al generarse la llave, es escrito en los “buckets” creados o por último se inserta uno nuevo, por lo que su complejidad disminuye por su método de acceso. Por lo que, esto mismo se ve reflejado en la búsqueda de un solo registro, porque que tendrían un comportamiento similar en lo que confiere a la lectura del archivo; que para el caso del “Extendible Hash” se va volviendo mucho más eficiente cuando la cantidad de datos incrementa, contrastando con la otra técnica que tiene un comportamiento contrario en cuanto a su tiempo de ejecución.

Por último, encontramos que las búsquedas por rango, son más eficientes dentro del “Sequential File” por su misma organización al momento de escribirse en los archivos, ya que al estar ordenado el acceso es directo. Por el contrario, en la otra técnica se tienen que hacer diversos accesos a distintos “buckets” por lo que ralentiza este tipo de búsqueda.



# **Pruebas**
En el video: [link]([link](https://drive.google.com/drive/folders/1faJ9uAV2EO0ABUXPBB2jaawCxAzAxbSp?usp=sharing))




