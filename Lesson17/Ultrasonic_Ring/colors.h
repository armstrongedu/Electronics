#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        2 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24
  Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void clear_face(){
    pixels.clear();
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
  }
}
void TurnOn_pixel(int pixel_number,int red,int green,int blue){
  pixels.setPixelColor(pixel_number, pixels.Color(red,green,blue));
  pixels.show();
}

void set(){

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  pixels.begin();
  pixels.clear();
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
  }
}
void show_levels(int level,int red,int green,int blue){
  if(level<1){
    pixels.clear();
      for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();
    return;
  }
  if(level>NUMPIXELS/2+1){
pixels.clear();
      for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(red,green,blue));
  }
  pixels.show();
    return;
  }
  bool removed[NUMPIXELS];
  for(int i=0;i<NUMPIXELS;i++){
    removed[i]=false;
  }
     
      pixels.setPixelColor(0, pixels.Color(red,green,blue));
      removed[0]=true;
      pixels.show();
  if(level<=9&&level>1){    
  
  for(int i=1;i<level;i++){
    pixels.setPixelColor(i, pixels.Color(red,green,blue));
    pixels.setPixelColor(16-i, pixels.Color(red,green,blue)); 
    removed[i]=true;
    removed[16-i]=true;
    pixels.show();
  }
}

  if(level>9){

    for(int i=1;i<16;i++){
    pixels.setPixelColor(i, pixels.Color(red,green,blue));   
    removed[i]=true;
    pixels.show();

  }

    pixels.setPixelColor(16, pixels.Color(red,green,blue));
    pixels.setPixelColor(17, pixels.Color(red,green,blue)); 
    removed[16]=true;
    removed[17]=true;  
    pixels.show();     
  }
  if(level>=11){
    pixels.setPixelColor(18, pixels.Color(red,green,blue));
    pixels.setPixelColor(23, pixels.Color(red,green,blue));
    removed[18]=true;
    removed[23]=true;   
    pixels.show();   
  }
  if(level>=12){
    pixels.setPixelColor(19, pixels.Color(red,green,blue));
    pixels.setPixelColor(22, pixels.Color(red,green,blue));
    removed[19]=true;
    removed[22]=true;   
    pixels.show();   
  }
    if(level==13){
    pixels.setPixelColor(20, pixels.Color(red,green,blue));
    pixels.setPixelColor(21, pixels.Color(red,green,blue));
    removed[20]=true;
    removed[21]=true;   
    pixels.show();   
  }
  for(int i=0;i<NUMPIXELS;i++){
    if(removed[i]==false){
      pixels.setPixelColor(i,0,0,0);
    }
  }
  pixels.show();
}
void show_rainbow(char direction,int cycles){
      for(int i=16;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(10,10,10));
        pixels.show();
  }
  pixels.updateLength(16);
  if(direction=='a'){
  for(long firstPixelHue = 0; firstPixelHue < cycles*65536; firstPixelHue += 256) {
    pixels.rainbow(firstPixelHue);
    pixels.show(); 
    delay(1);  
  }
 
}
else if(direction=='c'){
  for(long firstPixelHue = cycles*65536-1; firstPixelHue >=0; firstPixelHue -= 256) {
    pixels.rainbow(firstPixelHue);
    pixels.show(); 
    delay(1);  
     }   
   }
    pixels.updateLength(NUMPIXELS);
 }
void dance(){
  
    pixels.clear();
  for(int i=0;i<NUMPIXELS;i++){
   pixels.setPixelColor(i,0,0,0);
 }
 pixels.show();

  for(int j=1;j<4;j++){
      int color=j;
  for(int i=0;i<NUMPIXELS;i++){
    if(color==1){
    pixels.setPixelColor(i,85*j,0,0);
    }
    else if(color==2){
      pixels.setPixelColor(i,0,85*j,0);
    }
    else if(color==3){
      pixels.setPixelColor(i,0,0,85*j);
    }
    else if(color==4){
      pixels.setPixelColor(i,85*j,85*j,0);
    }
    pixels.show();
    color++;
    if(color>4){color=1;}
  }
  delay(30);
  pixels.clear();
  for(int i=0;i<NUMPIXELS;i++){
   pixels.setPixelColor(i,0,0,0);
 }
 pixels.show();
 delay(10);
 pixels.clear();  
  }
  
}