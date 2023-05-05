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
  * [Gráficos de comparación](#gráficos-de-comparación)
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




