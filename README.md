# 2.1.1
 Pakeistos structūros į klases, ir skaičiuojami greičio skirtumai naudojant skirtingus kompiliavimo optimizavimo flags. tačiau neoptimizuotas struktūru paskirstymo metodas buvo vistiek greitesnis, negu klasių.
 
| Vector laikai| | flag | 
|---|---|---|
| 100000 Neopt: 0.083761s| Opt: 0.013155s | -01| 
| 1000000 Neopt: 0.840208s | Opt: 0.138063s | -01| 
| 100000 Neopt: 0.021991s | Opt: 0.001465s | -02|
| 1000000 Neopt:  0.233086s | Opt: 0.015562s | -02| 
| 100000 Neopt: 0.020488s | Opt: 0.001936s | -03|
| 1000000 Neopt: 0.213662s | Opt: 0.015906s | -03|


# 2.1
  Buvo implemetuoti optimizuoti metodai visiem trim kontenriam, vietoj dalyjimo į 2 skirtingus vargšų ir kietų konteinerius buvo ištrinami duomenys iš orginalaus konteinerio ir ištrinti duomenys perkelti į naują konteinerį. Taip pat buvo naudojami visokie optimizavimo algoritmai, taičiau deque nepavyko padaryti greitesnio negu orginalaus skirstymo į 2 konteinerius būdo, taičiau perėjus prie clang kompiliatoriaus ir C++ 17 norint sukurti direktorijas laikyti sukurtus .txt failus deque optimizuotas tapo greitesnis. Gauti rezultatai:
  
  
| Vector laikai | |
| --- | --- |
| 1000 Neoptimizuotas: 0.000057s| Optimizuotas: 0.000018s |
| 10000 Neoptimizuotas: 0.000670s | Optimizuotas: 0.000169s |
| 100000 Neoptimizuotas: 0.004921s | Optimizuotas: 0.001501s |
| 1000000 Neoptimizuotas:  0.042159s | Optimizuotas: 0.012017s |
| 10000000 Neoptimizuotas: 0.441261s | Optimizuotas: 0.122616s |

| List laikai | |
| --- | --- |
| 1000 Neoptimizuotas: 0.000041s | Optimizuotas: 0.000038s |
| 10000 Neoptimizuotas: 0.000354s | Optimizuotas: 0.000236s |
| 100000 Neoptimizuotas: 0.003864s | Optimizuotas: 0.002542s |
| 1000000 Neoptimizuotas: 0.038785s | Optimizuotas: 0.025843s |
| 10000000 Neoptimizuotas: 0.383349s | Optimizuotas: 0.258878s |

| Deque laikai | |
| --- | --- |
| 1000 Neoptimizuotas: 0.000050s | Optimizuotas: 0.000034s |
| 10000 Neoptimizuotas: 0.000453s | Optimizuotas: 0.000199s |
| 100000 Neoptimizuotas: 0.004666s | Optimizuotas: 0.002671s |
| 1000000 Neoptimizuotas: 0.046615s | Optimizuotas: 0.024293s |
| 10000000 Neoptimizuotas: 0.474622s | Optimizuotas: 0.239480s|

# 2.0.5 
yra skirta patikrinti duomenu išsaugojimo spartumo būdus naudojant vector, list bei deque. Vectorius buvo greičiausias.


| list laikai | |
| --- | --- |
| 1000 failo skaitymas: 0.0062024s | studentų rušiavimas: 0.0004345s |
| 10000 failo skaitymas: 0.0543333s  | studentų rušiavimas: 0.0060865s |
| 100000 failo skaitymas: 0.546861s | studentų rušiavimas užtruko: 0.0749402s |
| 1000000 failo skaitymas: 5.29329s | studentų rušiavimas užtruko: 1.00853s |
| 10000000 failo skaitymas: 54.4872s | studentų rušiavimas: 15.1819s |

| Deque laikai | |
| --- | --- |
| 1000 failo skaitymas: 0.006104s | studentų rušiavimas: 0.0004461s |
| 10000 failo skaitymas: 0.0534222s | studentų rušiavimas: 0.0058478s |
| 100000 failo skaitymas užtruko: 0.530247s | studentų rušiavimas: 0.0704389s |
| 1000000 failo skaitymas užtruko: 5.3066s | studentų rušiavimas: 0.889723s |
| 10000000 failo skaitymas užtruko: 53.2172s| studentų rušiavimas: 10.9039s |

| Vector laikai | |
| --- | --- |
| 1000 failo skaitymas: 0.006228s | studentų rušiavimas: 0.0003433s |
| 10000 failo skaitymas: 0.0541851s | studentų rušiavimas: 0.0039269s |
| 100000 failo skaitymas: 0.539999s | studentų rušiavimas: 0.0520185s |
| 1000000 failo skaitymas: 5.29033s | studentų rušiavimas: 0.634036s |
| 10000000 failo skaitymas: 52.7618s | studentų rušiavimas: 7.79611s |

# 2.0.4
  nuskaityti duomenys yra rušiuojami į 2 failus pagal studentų vidurkį ir matuojamas jų laikas.


# 2.0.3
  įdėti keli try catch metodai skirti išvesti patikrinti ar failas iš kurio norima skaityti egzistuoja

# 2.0.2 
  Modifikuota 2.1 versija ir pridėtas pasirinkimas skaityti duomenis iš paruoštų duomenų.
  
# 2.0.1
  Sukurta programa kuri skaito iš įvestų duomenų CLI ir rušiuoja studentus pagal mediana arba vidurkį pasirinktinai. 
