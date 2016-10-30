#include <stdio.h>
float elevar(float potencia, int espoente);
float raiz(float valor, int quando);


float elevar(float potencia, int espoente){
  /* 
     função que recebe uma potencia do tipo float e um espoente
     do tipo inteiro e returna o resultado do tipo float
  */
  int contador;
  float num1 = potencia * potencia;

  if(espoente > 0){
  for (contador = 2; contador < espoente; contador++){
     num1 = num1 * potencia;
   }
   if(espoente == 1){
    return potencia;
   }else{
   return num1;
  }
 }else{
  return 0;
}
}

float raiz(float valor, int quanto){
   /* 
      função que calcula raiz x = inteiro de valor float
   */
   float x = 0.000001, r = 0.0;
   int y;
   y = quanto%2;
   if(valor > 0 ){
   do{
    r+= x;
    }while(elevar(r, quanto) < valor);
    return r;
    }else if(valor < 0 && y == 1){
      do{ x = - 0.000001;
       r+= x;
    }while(valor < elevar(r, quanto));
    return r;
    }else{
     printf("\n\n....................     Erro 0x001");
    }
    return 0;
}

int compararstr(char str1[], char str2[]){
   int contador=0;
   do{
   if(str1[contador] != str2[contador]){
   return 0;
   }
    contador+=1;
    }while(str1[contador] != '\0' || str2[contador] != '\0');

   return 1;

}
