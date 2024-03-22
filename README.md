# IntroPP2201922

En la carpeta OpenMP se encuentran los archivos "OMP_2201922_PostmanSort.c", "Parelo.c" y "PostmanSort.c". 

# Instrucciones de compilación y ejecución

Para compilar tanto el archivo secuencial como paralelo en GUANE se debe realizar de la siguiente forma:
<code> gcc PostmanSort -o PostmanSort.c
gcc OMP_2201922_PostmanSort -o OMP_2201922_PostmanSort.c
gcc Paralelo -o Paralelo.c </code>
Y para su posterior ejecución con los comandos:
<code>
time /. PostmanSort
time /. OMP_2201922_PostmanSort
time /. Paralelo
</code>
# Comparaciones de tiempos de ejecución al aumentar la escala



Al realizar las ejecuciones con tamaños más grandes de N se nota teóricamente debería ser mejor que la versión con arreglo hasta cierto N, pero debido a la velocidad de la máquina esta mejora no es perceptible, por lo tanto se concluye que aunque la paralelización ayuda a reducir el tiempo de ejecución en este caso no, por ello en este caso es mejor usar la versión con arreglos a pesar de que requiera más memoria.

* este es el tiempo en tocto sin paralelización <br>
  ![image](https://github.com/DarienCas/IntroPP2201922/assets/144241018/5bfd9762-381b-40e2-817d-4725af4b5e6b)
* este es el tiempo desde guane si paralelizacion<br>
    ![image](https://github.com/DarienCas/IntroPP2201922/assets/144241018/02c898b5-d69d-4091-808e-e6e9775fe87e)
* este es el tiempo desde guane paralizado<br>
  ![image](https://github.com/DarienCas/IntroPP2201922/assets/144241018/8ae3d958-a749-4bba-903b-b423be6e1495)



