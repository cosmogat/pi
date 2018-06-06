# pi
This is a simple program for compute the digits of pi number.
You can read this in other languages: [English](README.md), [Català](README.ca.md), [Castellà](README.es.md).
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
