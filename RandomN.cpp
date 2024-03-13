#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include<stdio.h>
#include <windows.h>
const int PopulationSize = 20;
const int ArraySize = 19;

int main(){

  int population[ PopulationSize ];
  for ( int i=0; i < PopulationSize; i++ )
    population[ i ] = i+1;

   int arreglo[ ArraySize ];

   srand(time(0));

   for(int i = 0; i < PopulationSize; i++)
   {
     int j = rand() % PopulationSize;

     if ( i == j )
       j = ( i + 1 ) % PopulationSize;

     std::swap( population[i], population[j]);
   }

   for ( int i = 0; i < ArraySize; ++i )
   {
     arreglo[ i ] = population[ i ];
     std::cout << arreglo[ i ] << std::endl;
   }

   return 0;
}
