# pi (català)
Açò és un senzill programa que utilitzant la llibreria GMP i l'algorisme de Chudnovsky trau xifres del nombre pi.
## Començament
Aquest programa necessita la llibreria GMP abans de compilar.
### Instalar dependències
En Debian GNU/Linux libgmp s'instala així
```
apt install libgmp-dev
```
### Compilar
Es pot compilar aquest codi amb la següent ordre:
```
gcc -lgmp -W -Wall -Wextra -ansi -pedantic -std=c11 pi_gmp.c -o pi
```
## Utilització
```
./pi xifres
```
On "xifres" és el nombre de decimals que es volen calcular. Si el nombre de decimals es major o igual que 10000 el resultat s'escriura en un fitxer, en cas contrari en l'eixida estandard.
### Exemple
```
./pi 100
```
Escriura per pantalla el següent:
```
3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068
```
## Referències
* [GMP](https://gmplib.org/) - La llibreria de precisió multiple utilitzada.
* [Algorisme de Chudnovsky](https://en.wikipedia.org/wiki/Chudnovsky_algorithm) - L'algorisme de Chudnovsky
## Autors
* **Cosmo Cat**  [cosmogat](https://github.com/cosmogat)
## Llicència
Mireu [LICENSE.md](LICENSE.md)


# pi (english)
This is a simple program for compute the digits of pi number.
## Getting started
This program needs GMP library before compile it.
### Install dependences
In Debian GNU/Linux libgmp:
```
apt install libgmp-dev
```
### Compile
We can compile this code with:
```
gcc -lgmp -W -Wall -Wextra -ansi -pedantic -std=c11 pi_gmp.c -o pi
```
## Running
```
./pi digits
```
Where "digits" is the number of digits that we want to compute. If the number is major or equal than 10000 the result will be written in a file, in other case in the standard output.
### Example
```
./pi 100
```
Write on screen:
```
3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068
```
## References
* [GMP](https://gmplib.org/) - GMP library.
* [Algorisme de Chudnovsky](https://en.wikipedia.org/wiki/Chudnovsky_algorithm) - Chudnovsky's algorithm
## Autors
* **Cosmo Cat**  [cosmogat](https://github.com/cosmogat)
## License
See the [LICENSE.md](LICENSE.md)
