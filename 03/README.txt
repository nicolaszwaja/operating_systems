===================================================================================
Autor: Nicola Szwaja                              Krakow, 7.04.2022
===================================================================================

Katalog zawiera program stworzony wg poleceń ćwiczenia 3 dotyczącego sygnałów:

*w podpunkcie a powstał program do obsługi sygnałów, należy wybrać jedną z opcji 
 (ignoruj,domyslna,przechwyc) oraz podać numer sygnału. Dzięki funkcji pause()
  program oczekuje na sygnały wysyłane z konsoli lub za pomocą sekwencji klawiszy
  oraz reaguje na nie zgodnie z naszym wyborem.
 
*w podpunkcie b powyższy program wywoływany jet przez funkcję execl w procesie
 potomnym,do którego wysyłane są sygnały z procesu macierzystego poprzez funkcję kill
 
*w podpunkcie c tworzy się proces potomny stający się jednocześnie liderem nowej grupy
 procesów oraz uruchamiane w nim zostają procesy potomne, które wykonują program,
 który obsługuje sygnały(podpunkt a ćwiczenia)
 z procesu macierzystego wysyłam sygnały do całej grupy procesów potomnych, lider grupy
 procesów ignoruje wysyłane sygnały oraz czeka na zakończenie swoich procesów potomnych
 i wypisuje ich status zakończenia zwracany przez wait.
 
=====================================================================================
* Jak uruchomic programy:
=====================================================================================

Katalog zawiera program Makefile do kompilacji, linkowania
i uruchamiania powyzszych programow, a takze czyszczenia katalogu 
i jego archiwizacji.

-> Aby uruchomic program, nalezy wykonac komende:

       make SYGNAL=nr_sygnału OPCJA=nazwa_opcji runA
       nazwę opcji wybieramy spośród: domyslna,ignoruj,przechwyc
       
-> Aby uruchomic program, nalezy wykonac komende:

       make SYGNAL=nr_sygnału OPCJA=nazwa_opcji runB
       nazwę opcji wybieramy spośród: domyslna,ignoruj,przechwyc  
       
-> Aby uruchomic program, nalezy wykonac komende:

       make SYGNAL=nr_sygnału OPCJA=nazwa_opcji runC
       nazwę opcji wybieramy spośród: domyslna,ignoruj,przechwyc            
       
-> Aby wyczyscic zawartosc katalogu (usunac zbedne pliki), nalezy wykonac:
       make clean

-> W celu archiwizacji oraz kompresji katalogu nalezy wykonac:
       make tar
       
======================================================================================= 


