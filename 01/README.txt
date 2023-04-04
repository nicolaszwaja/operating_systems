========================================================================
Autor: Nicola Szwaja                              Krakow, 23.03.2022
========================================================================

Katalog programy zawiera programy stworzone wg poleceń ćwiczenia 1 dotyczącego procesów:

*podpunkt a ćwiczenia, czyli wypisywane w terminalu są numery identyfikacyjne
danego procesu.

*podpunkt b ćwiczenia, czyli trzykrotnie wywołuje funkcję fork oraz identyfikatory 
dla procesu macierzystego oraz powstałych procesów

*podpunkt c ćwiczenia, czyli trzykrotnie wywołuje funkcję fork oraz identyfikatory 
dla procesu macierzystego oraz powstałych procesów, przy użyciu funkcji sleep 
osieracane są procesy potomne, przez co muszą one zostać zaadoptowane, dzięki 
poleceniu pstree -p dowiadujemy się czy procesem adoptującym je jest init czy 
systemd.

*podpunkt d ćwiczenia, czyli trzykrotnie wywołuje funkcję fork oraz identyfikatory 
dla procesu macierzystego oraz powstałych procesów potomnych, dzięki funkcji sleep 
i prawidłowemu dobraniu ilości sekund oczekiwania procesy na ekranie wypisywane są 
pokoleniami w kolejności chronologicznej powstania.
powstaje również "drzewo genealogiczne" w pliku tekstowym "drzewo.txt"

*podpunkt e ćwiczenia, czyli trzykrotnie wywołuje funkcję fork oraz identyfikatory 
dla procesu macierzystego oraz powstałych procesów potomnych, użyta funkcja setpgid 
sprawia, że każdy proces potomny straje się liderem własnej grupy procesów
Przy n-krotnym wykonaniu funkcji fork() powstaje 2^n procesów(licząc macierzysty), 
ponieważ funkcja ta tworzy proces potomny dla każdego istniejącego procesu, czyli podwaja ich ilość

* Jak uruchomic programy:
=========================

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.
-> Aby uruchomic 1-szy program, nalezy wykonac komende:
       make runA
-> Aby uruchomic drugi program, nalezy wykonac komende:
       make runB
-> Aby uruchomic trzeci program, nalezy wykonac komende:
       make runC   
-> Aby uruchomic czwarty program, nalezy wykonac komende:
       make runD
-> Aby uruchomic piąty program, nalezy wykonac komende:
       make runE
       
-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
       make clean

-> W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
       make tar
       
========================================================================





