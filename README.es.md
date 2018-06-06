# pi
Esto es un sencillo programa que utilizando la libreria GMP y el algoritmo de Chudnovsky saca cifras del número pi.
Puedes leer esto en otras lenguas: [English](README.md), [Català](README.ca.md), [Castellà](README.es.md).
## Empezando
Este programa necesita la libreria GMP antes de compilar.
### Instalar dependències
En Debian GNU/Linux libgmp se instala así:
```
apt install libgmp-dev
```
### Compilar
Se puede compilar con la siguiente orden:
```
gcc -lgmp -W -Wall -Wextra -ansi -pedantic -std=c11 pi_gmp.c -o pi
```
## Utilización
```
./pi cifras
```
Donde "cifras" es el número de decimales que se quieren calcular. Si el número es mayor o igual a 10000 el resultado se escribira en un fichero, en caso contrario en la salida estándar.
### Ejemplo
```
./pi 100
```
Escribira por pantalla:
```
3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068
```
## Referencias
* [GMP](https://gmplib.org/) - La llibreria de precisió multiple utilitzada.
* [Algoritmo de Chudnovsky](https://en.wikipedia.org/wiki/Chudnovsky_algorithm) - Algoritmo de Chudnovsky
## Autores
* **Cosmo Cat**  [cosmogat](https://github.com/cosmogat)
## Licencia
Mirad [LICENSE.md](LICENSE.md)
