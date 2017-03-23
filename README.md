# Laboratorium 3
## Struktura ułamka
>   W dzisiejszym zadaniu tworzymy strukturę, posiadającą zarówno dane, jak funkcje. Uczymy się również, jak testować poprawność programu, wykorzystując funkcję assert().

### Ocena dostateczna
- Zadeklaruj strukturę `fraction`, składającą się z:
    - licznika i mianownika, jako zmiennych typu `int`,
    - funkcji `is_correct()`, typu `bool`.
- W funkcji `is_correct()` zwracaj informację, czy pierwiastek jest poprawny, czyli:
    - mianownik jest różny od zera,
    - wartość bezwzględna licznika jest mniejsza od wartości bezwzględnej mianownika.
- W funkcji `main()`,
    - pobierz liczbę całkowitą `n`, jako argument wiersza poleceń,
    - zadeklaruj dynamiczny `n`-elementowy łańcuch typu `fraction`,
    - wypełnij go losowymi wartościami z przedziału `<-9;9>`

### Ocena dobra
- Przepisz funkcję `is_correct()` tak, aby składała się tylko z jednej linii.
- Używając funkcji `assert()`, przekazując do niej wynik funkcji `is_correct()`, sprawdź, czy wszystkie wylosowane ułamki są poprawne.
- Uzupełnij pętlę, w której losowane były wartości ułamków o zagnieżdżoną pętlę *do while*, sprawdzającą poprawność ułamka po wygenerowaniu, aby wszystkie testy przeszły pomyślnie.

### Ocena bardzo dobra
- Napisz funkcję `gcd()`, odnajdującą największy wspólny dzielnik dwóch liczb całkowitych i użyj jej w napisanej przez Ciebie funkcji `shorten()`, będącej częścią struktury `fraction()`, do skracania ułamka.

## Dokumentacja
- [`abs()`](http://www.cplusplus.com/reference/cmath/abs/)
- [`assert()`](http://www.cplusplus.com/reference/cassert/assert/)
- [`srand()`](http://www.cplusplus.com/reference/cstdlib/srand/)
