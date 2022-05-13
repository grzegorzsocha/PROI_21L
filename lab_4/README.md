# 21_PROI_lab-4

Wykonał: Grzegorz Socha, nr albumu: 310905 <br/>
Użyte środowisko: Visual Studio 2019 <br/>
Sposób testowania: Native unit test <br/>
 <br/>
Opis: <br/>
Repozytorium zawiera projekt biblioteki zawierającą klasę Queue oraz dziedziczącą po niej klasę Stack. Klasa Queue przechowuje elementy typu T o maksymalnej pojemności N. T i N są parametrami szablonu z domyślną wartością 10 dla N. Do implementacji użyto tablicę. <br/>
 <br/>
Dostępne są publiczne metody: <br/>
 - Dodanie elementu na początek/koniec, <br/>
 - Usunięcie elementu z początku/końca, <br/>
 - Zwrócenie elementu z początku/końca, <br/>
 - Wyczyszczenie kolejki, <br/>
 - Zwrócenie liczby przechowywanych elementów, <br/>
 - Zwrócenie niemodyfikowalnej tablicy elementów. <br/>
 <br/>
Klasa Stack dodatkowo: <br/>
 - Ukrywa możliwość dodawania/usuwania/zwracania elementu z początku, <br/>
 - Posiada metodę pozwalającą odwrócić stos - w ramach obiektu. <br/>
 <br/>
Do implemetacji testów jednostkowych została napisana pomocnicza klasa Person. Samo testowanie poszczególnych metod zostało zrealizowane dla różnych typów 
