#include <SPI.h>
#include <MFRC522.h>
#define buzzer D3
#define RST_PIN         16           // Configurable, see typical pin layout above
#define SS_PIN          2          // Configurable, see typical pin layout above
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;
void rfid_init(){
  SPI.begin();               // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card
  delay(10);
    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }
}
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}
void update_mode(byte balance){
digitalWrite(buzzer,HIGH);
delay(50);
digitalWrite(buzzer,LOW);
}
void just_added(){
 digitalWrite(buzzer,HIGH);
 delay(700);
 digitalWrite(buzzer,LOW);
}
void already_found(){
 for(int i=0;i<3;i++){
 digitalWrite(buzzer,HIGH);
 delay(200);
 digitalWrite(buzzer,LOW);
 delay(200);
 }
 delay(400);
}
void welcome(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
}
void saved(){
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  delay(500);
}
void success(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
}
void failure(){
  for(int i=0;i<3;i++){
    digitalWrite(buzzer,HIGH);
    delay(300);
    digitalWrite(buzzer,LOW);
    delay(300);
  }
  delay(100);
}
void read_buffer(byte* buffer,int size){
 int index=0;
 while(!Serial.available()){};
 char c=Serial.read();
 while(c!='#'){
   buffer[index++]=c;
    while(!Serial.available()){};
    c=Serial.read();
 }
for(int i=index;i<size;i++) buffer[i]=' ';
}
bool write_block(byte blockAddress,byte* buffer,byte size){
 byte trailerBlock;
    for(int i=1;i<=3;i++){
      if((blockAddress+i)%4 == 3){
        trailerBlock=blockAddress+i;
        break;
      }
    }
   
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("PCD_Authenticate() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return false;
  }
  else Serial.println(F("PCD_Authenticate() success: "));
 
  status = mfrc522.MIFARE_Write(blockAddress, buffer, size);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE_Write() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    //return false;
  }
  else Serial.println(F("MIFARE_Write() success: "));
  
  return true;
}

bool read_block(byte blockAddress,byte* buffer,byte size){
// reset_keys();

  byte trailerBlock;
    for(int i=1;i<=3;i++){
      if((blockAddress+i)%4 == 3){
        trailerBlock=blockAddress+i;
        break;
      }
    }
    
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key, &(mfrc522.uid)); //line 834
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return false;
  }
  else Serial.println(F("PCD_Authenticate() success: "));
  status = mfrc522.MIFARE_Read(blockAddress, buffer, &size);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
   // return false;
  }
  else Serial.println(F("MIFARE_Read() success: "));

  return true;
 
}
bool compatable(){
      Serial.print(F(" PICC type: "));   // Dump PICC type
      MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

    if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
        Serial.println(F("This sample only works with MIFARE Classic cards."));
        return false;
    }
    return true;
}
bool card_detected(){
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return false;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return false;
  }

  return true;
}

void end_loop(){
    mfrc522.PICC_HaltA(); // Halt PICC
  mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
}
String card_UID(){
    String tag="";
    for (byte i = 0; i < 4; i++) {
      tag += mfrc522.uid.uidByte[i];
    }
    return tag;
}
void print_card_info(){
    Serial.print(F("Card UID:"));    //Dump UID
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.print(F(" PICC type: "));   // Dump PICC type
  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  Serial.println(mfrc522.PICC_GetTypeName(piccType));
}
bool print_sector(char Authenticationkey){
   if(Authenticationkey =='A'){
    Serial.println(F("Authenticating using key A..."));
    status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A,7, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PCD_Authenticate() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return false;
    }


    Serial.println(F("Current data in sector:"));
    mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, 1);
    Serial.println();
   }
   else{
    Serial.println(F("Authenticating using key B..."));
    status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B,7, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PCD_Authenticate() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return false;
    }


    Serial.println(F("Current data in sector:"));
    mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, 1);
    Serial.println();
   }
return true;
}
void print_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}
void print_keys(){
    Serial.println(F("Scan a MIFARE Classic PICC to demonstrate read and write."));
    Serial.print(F("Using key (for A and B):"));
    print_byte_array(key.keyByte, MFRC522::MF_KEY_SIZE);
    Serial.println();
}

