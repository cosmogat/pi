# pi
Açò és un senzill programa que utilitzant la llibreria GMP i l'algorisme de Chudnovsky trau xifres del nombre pi.
Pots llegir açò en altres llengues: [English](README.md), [Català](README.ca.md), [Castellà](README.es.md).
## Començament
Aquest programa necessita la llibreria GMP abans de compilar.
### Instalar dependències
En Debian GNU/Linux libgmp s'instal·la així
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
On "xifres" és el nombre de decimals que es volen calcular. Si el nombre de decimals es major o igual que 10000 el resultat s'escriura en un fitxer, en cas contrari en l'eixida estàndard.
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
Mireu [LICENSE](LICENSE)
