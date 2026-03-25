# Planetų valdymo sistema (C++)

Šis projektas yra bazinis objektinio programavimo (OOP) pavyzdys C++ kalboje. Jame realizuota `Planet` klasė, kuri leidžia kurti planetų objektus, valdyti jų duomenis ir užtikrinti duomenų vientisumą naudojant išimčių valdymą (exceptions).

## Funkcionalumas

* **Duomenų saugojimas:** Kiekviena planeta turi pavadinimą (`name`), gravitacijos jėgą (`gravity`) ir palydovų skaičių (`moons`).
* **Unikalus identifikavimas:** Automatinis unikalaus `id` priskyrimas kiekvienam naujam objektui naudojant statinius kintamuosius.
* **Objektų sekimas:** Programoje realizuotas statinis skaitliukas `count`, kuris seka, kiek šiuo metu atmintyje yra aktyvių objektų.
* **Validacija:** Sistema neleis sukurti planetos su neigiama gravitacija ar neigiamu palydovų skaičiumi.

## Techniniai sprendimai

Projekte panaudotos šios C++ koncepcijos:
* **Encapsulation (Inkapsuliacija):** Privatūs laukai pasiekiami tik per *getter* ir *setter* metodus.
* **Exceptions (Išimtys):** Naudojamas `std::invalid_argument` klaidoms apdoroti, jei įvedami neteisingi duomenys.
* **Static nariai:** `lastId` ir `count` naudojami globaliai klasės būsenai stebėti.
* **Destruktoriai:** Automatinis `count` mažinimas, kai objektas pašalinamas iš atminties.
* **Unit Testing:** `main()` funkcijoje realizuoti testai naudojant `assert()` biblioteką, užtikrinantys kodo teisingumą.

## Testavimo pavyzdžiai

Programa automatiškai patikrina penkis esminius scenarijus:
1.  **Test1:** Objekto sukūrimas ir duomenų gavimas per `toString`.
2.  **Test2:** Reikšmių keitimas naudojant *setter* metodus.
3.  **Test3:** Išimčių metimas, kai įvedami neigiami parametrai.
4.  **Test4:** Unikalių ID sekos generavimas.
5.  **Test5:** Dinaminis atminties valdymas (rodyklių masyvas) ir objektų skaitliuko tikslumas.

## Kaip paleisti

Norėdami sukompiliuoti ir paleisti programą, naudokite bet kurį C++ kompiliatorių:

```bash
g++ main.cpp -o planetos
./planetos
