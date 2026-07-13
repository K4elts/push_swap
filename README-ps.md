# *Este proyecto ha sido creado como parte del currículo de 42 por jgilaber y aliao-tr.*

# push_swap

## 📖 Descripción

**push_swap** es un proyecto del currículo de 42 cuyo objetivo consiste en ordenar una secuencia de números enteros utilizando únicamente un conjunto limitado de operaciones sobre dos pilas.

El programa recibe una lista de números como argumentos, los almacena en dos pilas denominadas **A** y **B**, y debe generar la secuencia de instrucciones necesaria para ordenar los elementos en orden ascendente utilizando el menor número posible de movimientos.

Este proyecto permite profundizar en conceptos fundamentales de la programación en C, como la implementación de estructuras de datos dinámicas, el diseño y análisis de algoritmos, la optimización de operaciones y el tratamiento eficiente de la memoria.

Además, constituye una primera aproximación al estudio de la complejidad algorítmica y al desarrollo de soluciones orientadas al rendimiento.

---

## ✨ Características

### Funcionalidad principal

* Recepción de números enteros mediante argumentos de línea de comandos.
* Validación de la entrada y detección de errores.
* Gestión de números negativos y positivos.
* Detección de valores duplicados.
* Ordenación utilizando exclusivamente las operaciones permitidas.
* Generación de una secuencia optimizada de instrucciones.

---

### Operaciones permitidas

#### Intercambio

* `sa` → Intercambia los dos primeros elementos del stack a.
    No hace nada si hay solo uno o ningún elemento.
* `sb` → Intercambia los dos primeros elementos del stack b.
    No hace nada si hay solo uno o ningún elemento.
* `ss` → Ejecuta `sa` y `sb` simultáneamente.

#### Inserción

* `pa` → Toma el primer elemento del stack b y lo coloca el primero en el stack a.
    No hace nada si b está vacío.
* `pb` → Toma el primer elemento del stack a y lo coloca el primero en el stack b.
    No hace nada si a está vacío.

#### Rotación

* `ra` → Desplaza hacia arriba todos los elementos del stack a una posición, convirtiendo el primer elemento en el último.
* `rb` → Desplaza hacia arriba todos los elementos del stack b una posición, convirtiendo el primer elemento en el último.
* `rr` → Ejecuta `ra` y `rb` simultáneamente.

#### Rotación inversa

* `rra` → Desplaza hacia abajo todos los elementos del stack a una posición, convirtiendo el último elemento en el primero.
* `rrb` → Desplaza hacia abajo todos los elementos del stack b una posición, convirtiendo el último elemento en el primero
* `rrr` → Ejecuta `rra` y `rrb` simultáneamente.

---

## 🛠️ Instrucciones

### Requisitos

* Sistema operativo Linux o macOS.
* Compilador compatible con C (`gcc` o `clang`).
* `make`.

### Compilación

Para generar el ejecutable:

```bash
make
```

Esto creará el archivo:

```text
push_swap
```

### Limpiar archivos objeto

```bash
make clean
```

### Eliminar todos los archivos generados

```bash
make fclean
```

### Recompilar completamente

```bash
make re
```

---

## 🚀 Ejemplo de uso

Ordenar una pequeña secuencia:

```bash
./push_swap 2 1 3
```

Salida:

```text
sa
```

Otro ejemplo:

```bash
./push_swap 3 2 5 1 4
```

Salida posible:

```text
pb
ra
pb
sa
pa
pa
ra
ra
```

Comprobar el resultado utilizando el programa `checker`:

```bash
ARG="3 2 5 1 4"
./push_swap $ARG | ./checker $ARG
```

Salida:

```text
OK
```

---

## 🏗️ Decisiones técnicas

* Todas las funciones siguen la **Norminette** de 42.
* La memoria dinámica se gestiona mediante `malloc` y `free`, evitando fugas de memoria.
* La entrada se valida completamente antes de iniciar el proceso de ordenación.
* Los números se almacenan en estructuras dinámicas para facilitar las operaciones de inserción y rotación.
* Se emplean algoritmos diferentes según el tamaño del conjunto de datos.

---

## ⚙️ Algoritmos seleccionados

La estrategia de ordenación se divide en dos partes.

### Conjuntos pequeños

Para secuencias reducidas (entre 2 y 5 elementos) se utilizan algoritmos específicos construidos manualmente.

Estos algoritmos:

* Analizan la posición relativa de cada elemento.
* Seleccionan directamente la combinación mínima o casi mínima de operaciones.
* Reducen considerablemente el número de movimientos.

Por ejemplo:

* 2 elementos → máximo 1 operación.
* 3 elementos → máximo 2 o 3 operaciones.
* 5 elementos → utilización temporal de la pila B para simplificar la ordenación.

---

### Conjuntos grandes: Radix Sort sobre índices normalizados

Para conjuntos de mayor tamaño se utiliza una variante de **Radix Sort binario**.

Antes de comenzar la ordenación:

1. Los números se copian y se ordenan.
2. Cada valor recibe un índice correspondiente a su posición en el conjunto ordenado.
3. Los valores originales se sustituyen por dichos índices.

Por ejemplo:

Entrada:

```text
40 10 -2 100
```

Índices:

```text
2 1 0 3
```

Una vez normalizados los datos:

1. Se procesa cada bit del índice comenzando por el menos significativo.
2. Si el bit actual es `0`, el elemento se envía a la pila B mediante `pb`.
3. Si el bit actual es `1`, se realiza una rotación de la pila A mediante `ra`.
4. Cuando todos los elementos han sido examinados, los elementos almacenados en B se devuelven a A mediante `pa`.
5. El proceso se repite para todos los bits necesarios.

Al finalizar el último recorrido, la pila A queda completamente ordenada.

---

## 📈 Justificación del algoritmo

La elección de **Radix Sort binario** está motivada por varias razones.

### Rendimiento predecible

El número de operaciones crece de manera aproximadamente lineal respecto al número de elementos:

```text
O(n · k)
```

donde:

* `n` es el número de elementos.
* `k` es el número de bits necesarios para representar el índice máximo.

Dado que `k` es pequeño incluso para conjuntos grandes, el rendimiento resulta muy estable.

### Adaptación a las operaciones permitidas

Las operaciones de `push_swap` encajan de forma natural con el funcionamiento de Radix Sort:

* `pb` permite separar los elementos cuyo bit es `0`.
* `ra` conserva el orden relativo de los elementos cuyo bit es `1`.
* `pa` reconstruye la pila principal para la siguiente iteración.

Por este motivo, el algoritmo puede implementarse utilizando exclusivamente las operaciones autorizadas por el subject.

### Simplicidad y robustez

La normalización de índices elimina problemas asociados a:

* Números negativos.
* Valores extremadamente grandes.
* Comparaciones complejas entre enteros.

El algoritmo trabaja únicamente con índices consecutivos:

```text
0 ... n - 1
```

lo que simplifica notablemente la implementación y reduce la posibilidad de errores.

---

## 🗂️ Estructura de datos

Las pilas se implementan mediante listas enlazadas.

Cada nodo almacena:

* El valor original.
* El índice normalizado.
* Un puntero al siguiente elemento.

La utilización de listas enlazadas ofrece varias ventajas:

* Inserción y extracción en tiempo constante.
* Rotaciones eficientes.
* Gestión dinámica de la memoria.
* Ausencia de límites fijos de capacidad.

Estas características hacen que las listas enlazadas sean especialmente adecuadas para representar las pilas de `push_swap`.

---

## 📚 Descripción detallada del proyecto

`push_swap` es un programa orientado al estudio de la eficiencia algorítmica bajo restricciones operacionales.

A diferencia de los algoritmos de ordenación tradicionales, el objetivo no consiste únicamente en obtener una secuencia ordenada, sino en minimizar el número de operaciones disponibles sobre dos pilas.

La combinación de estructuras dinámicas, algoritmos especializados para conjuntos pequeños y Radix Sort para conjuntos grandes permite obtener soluciones eficientes y escalables respetando todas las limitaciones impuestas por el proyecto.

---

## 📚 Recursos

### Documentación y referencias

* The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie.
* Introduction to Algorithms — Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest & Clifford Stein.
* Algorithms — Robert Sedgewick & Kevin Wayne.
* The Linux Manual Pages Project (`man atoi`, `man malloc`, `man free`).
* Documentación oficial del currículo de 42.
* Documentación sobre Radix Sort y análisis de complejidad algorítmica.

### Uso de Inteligencia Artificial

Durante el desarrollo de este proyecto se ha utilizado IA únicamente como herramienta de apoyo para:

* Revisión y mejora de la documentación.
* Generación y corrección del archivo `README.md`.
* Consulta de explicaciones teóricas sobre estructuras de datos, análisis de complejidad y funcionamiento de Radix Sort.

La implementación, diseño y codificación del programa `push_swap` han sido realizados manualmente siguiendo los requisitos del proyecto y las normas académicas de 42.

---

## 📊 Rendimiento

* 100 números aleatorios: menos de 700 operaciones.
* 500 números aleatorios: menos de 5500 operaciones.

---

## 👤 Autor

**Login 42:** `jgilaber`

Proyecto realizado como parte del programa de formación de **42 Madrid**.
