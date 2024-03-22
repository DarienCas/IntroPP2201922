# IntroPP2201922

En la carpeta OpenMP se encuentran los archivos "" y "", 

# Instrucciones de compilación y ejecución

Para compilar tanto el archivo secuencial como paralelo en GUANE se debe realizar de la siguiente forma:

Y para su posterior ejecución con los comandos:

# Comparaciones de tiempos de ejecución al aumentar la escala
Se consideraron dos soluciones para abordar el problema. La primera se centró en el uso de un arreglo para calcular todos los números de Fibonacci y, posteriormente, realizar una suma paralelizada de los índices. Esta solución tenía una complejidad tanto temporal como espacial de O(n).

La segunda solución se basó en el empleo de una fórmula matemática que implicaba llamadas a la función "pow". Esta función tiene una complejidad de O(log n), por ello se paralelizaron simultáneamente los dos llamados a la función y, posteriormente, se realizó una suma paralelizada de los índices pares. Esta segunda solución tuvo una complejidad temporal de O(n log n) y una complejidad espacial de O(1).

Al realizar las ejecuciones con tamaños más grandes de N se nota como la solución matemática deja de ser viable, sin embargo teóricamente debería ser mejor que la versión con arreglo hasta cierto N pequeño, pero debido a la velocidad de la máquina esta mejora no es perceptible, por lo tanto se concluye que aunque la paralelización ayuda a reducir el tiempo de ejecución no cambia su tendencia final, por ello en este caso es mejor usar la versión con arreglos a pesar de que requiera más memoria.
