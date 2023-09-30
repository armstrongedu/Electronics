/*
based on three row resistors=2.7 Kilo-Ohm and two columns resistors=10 Kilo-Ohm and pull down resistor=10 Kilo-Ohm 
*/

char getKey(){
  int value=analogRead(A0);
  if(value>340&&value<370){
    return '1';
  }
  else if(value>500&&value<580){
    return '2';
  }
  else if(value>1020){
    return '3';
  } 
  else if(value>325&&value<340){
    return '4';
  } 
  else if(value>450&&value<500){
    return '5';
  }  
  else if(value>750&&value<900){
    return '6';
  } 
  else if(value>300&&value<325){
    return '7';
  } 
  else if(value>400&&value<450){
    return '8';
  }
  else if(value>650&&value<750){
    return '9';
  }
  else if(value>200&&value<300){
    return '*';
  }
  else if(value>370&&value<400){
    return '0';
  }
  else if(value>580&&value<650){
    return '#';
  }
  else{
    return '?';
  }
  
}