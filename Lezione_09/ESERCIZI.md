# Esercizi per la lezione 9

## Esercizio 9.1

Si scriva un programma che legge i numeri salvati nel file ```dati_esponenziali.txt```
e li scriva in un ```vector<double>```.
  * Si faccia in modo che il nome del file sia passato a linea di comando.
  * Si faccia in modo che il secondo argomneto a linea di comando, opzionale,
    sia il numero massimo di numeri da leggere dal file.  

![linea](../immagini/linea.png)

## Esercizio 9.2 

Si aggiunga al programma precedente il codice sorgente che calcoli la media, il valor minimo ed il valor massimo 
dei numeri inseriti.

![linea](../immagini/linea.png)

## Esercizio 9.3

Si aggiunga al programma precedente il codice sorgente che riempia un istogramma con i numeri presenti nel ```vector```
dove sono stati trasferiti
e che visualizzi l'istogramma a schermo.
 
![linea](../immagini/linea.png)

## Esercizio 9.4

Si scriva una libreria di funzioni per determinare il parametro &tau; della distribuzione esponenziale
utilizzata per generare gli eventi presenti nel file ```dati_esponenziali.txt```,
a partire dal ```vector``` di numeri creato negli esercizi precedenti.
  * Si implementino i prototipi delle funzioni presentate a lezione.
  * Si confronti il risultato ottenuto con la media dei numeri salvati nel ```vector```.
  * Come dipende il risultato dall'intervallo inziale passato alla funzione ```sezione_aurea_max```?

![linea](../immagini/linea.png)

## Esercizio 9.5

Si modifichi la funzione ```sezione_aurea_max```,
aggiungendo la stampa a schermo dei valori degli estremi dell'intevallo considerato ad ogni iterazione,
per osservarne il restringimento durante l'esecuzione del programma.

![linea](../immagini/linea.png)

## Esercizio 9.6

Si modifichi la funzione ```loglikelihood``` in modo che calcoli il logaritmo del prodotto
dei valori della funzione di densita' di probabilita', piuttosto che la somma dei singoli logaritmi.
Come cambia il comportamento dell'algoritmo?

![linea](../immagini/linea.png)

## Esercizio 9.7

Si utilizzi il metodo della bisezione per trovare i due punti 
*&tau; - &sigma;<sub>&tau;</sub>* e *&tau; + &sigma;<sub>&tau;</sub>* 
nel caso dell'esercizio precedente.

