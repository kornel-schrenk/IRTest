#include <IRremote.h>

int RECV_PIN = 11;
int LED_PIN = 8;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(19200);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    digitalWrite(LED_PIN, HIGH);
    printPress(&results);    
    irrecv.resume(); // Receive the next value
    delay(100);    
    digitalWrite(LED_PIN, LOW);
  }
}

void printPress(decode_results *results){
  if (results->value == 0xFF6897 || results->value == 0xFDB04F) {
    Serial.println("0");
  } else if (results->value == 0xFF30CF || results->value == 0xFD00FF) {
    Serial.println("1");
  } else if (results->value == 0xFF18E7 || results->value == 0xFD807F) {
    Serial.println("2");
  } else if (results->value == 0xFF7A85 || results->value == 0xFD40BF) {
    Serial.println("3");
  } else if (results->value == 0xFF10EF || results->value == 0xFD20DF) {
    Serial.println("4");
  } else if (results->value == 0xFF38C7 || results->value == 0xFDA05F) {
    Serial.println("5");
  } else if (results->value == 0xFF5AA5 || results->value == 0xFD609F) {
    Serial.println("6");
  } else if (results->value == 0xFF42BD || results->value == 0xFD10EF) {
    Serial.println("7");
  } else if (results->value == 0xFF4AB5 || results->value == 0xFD906F) {
    Serial.println("8");
  } else if (results->value == 0xFF52AD || results->value == 0xFD50AF) {
    Serial.println("9");
//Remote control #1
  } else if (results->value == 0xFFA25D) {
    Serial.println("On/Off");
  } else if (results->value == 0xFF629D) {
    Serial.println("Mode");
  } else if (results->value == 0xFFE21D) {
    Serial.println("Sound On/Off");
  } else if (results->value == 0xFF906F) {
    Serial.println("+");
  } else if (results->value == 0xFFA857) {
    Serial.println("-");
  } else if (results->value == 0xFF22DD) {
    Serial.println("Play");
  } else if (results->value == 0xFF02FD) {
    Serial.println("Prev");
  } else if (results->value == 0xFFC23D) {
    Serial.println("Forw");
  } else if (results->value == 0xFFE01F) {
    Serial.println("EQ");
  } else if (results->value == 0xFFB04F) {
    Serial.println("U/SD");
  } else if (results->value == 0xFF9867) {
    Serial.println("Shuffle");
//Remote control #2    
  } else if (results->value == 0xFD30CF) {
    Serial.println("*");
  } else if (results->value == 0xFD708F) {
    Serial.println("#");
  } else if (results->value == 0xFD8877) {
    Serial.println("Up");
  } else if (results->value == 0xFD9867) {
    Serial.println("Down");
  } else if (results->value == 0xFD28D7) {
    Serial.println("Left");
  } else if (results->value == 0xFD6897) {
    Serial.println("Right");
  } else if (results->value == 0xFDA857) {
    Serial.println("OK");
  }
}

