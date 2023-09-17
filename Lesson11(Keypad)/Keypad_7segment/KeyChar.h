/*
based on three row resistors=2.7 Kilo-Ohm and two columns resistors=10 Kilo-Ohm and pull down resistor=10 Kilo-Ohm 
*/

char getKey(){
  int value=analogRead(A0);
  if(value>360&&value<370){
    return '1';
  }
  else if(value>540&&value<550){
    return '2';
  }
  else if(value>1023){
    return '3';
  } 
  else if(value>330&&value<340){
    return '4';
  } 
  else if(value>479&&value<489){
    return '5';
  }  
  else if(value>856&&value<866){
    return '6';
  } 
  else if(value>308&&value<318){
    return '7';
  } 
  else if(value>429&&value<439){
    return '8';
  }
  else if(value>709&&value<719){
    return '9';
  }
  else if(value>286&&value<296){
    return '*';
  }
  else if(value>384&&value<394){
    return '0';
  }
  else if(value>600&&value<610){
    return '#';
  }
  else{
    return '?';
  }
}