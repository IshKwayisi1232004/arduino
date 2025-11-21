//Import library for LCD
#include <LiquidCrystal.h>

#define RED_LED 7
#define YELLOW_LED 6
#define GREEN_LED 5

//Variable to store analog pin for Water Sensor
int readPin = A0;

//Varaible to store the water level values
int readValue;

//The constant (unchangeable) values to digital pin values
const int rs = 31, en = 33, d4 = 29, d5 = 27, d6 = 25, d7 = 23;

//Constant value to store the digital pin of the buzzer
const int buzzer = 9;

//Initializes the LCD object using the constant variables
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED_LED, OUTPUT);

  //Configure the water sensor pin to operate as an input
  pinMode(readPin, INPUT);
  
  //Configure the buzzer pin to operate as an output
  pinMode(buzzer, OUTPUT);

  //Initialize LCD by using the its pin dimensions (16x2)
  lcd.begin(16, 2);

  //Initialize the serial monitor port
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  readValue = analogRead(readPin);

  //Clears the LCD display upon startup
  lcd.clear();

  //Set the water level string output on the top row
  lcd.setCursor(0,0);
  lcd.print("Water Level:");

  //Set the water level values and state output on the bottom row
  lcd.setCursor(0, 1);

  //Condition when the water bucket is empty
  if(readValue == 0){
    lcd.print("Empty");

    //Sets the buzzer to turn on for half a second then turn off 
    //the buzzer for 3/4 of a second (i.e. its supposed to be buzzing faster)
    tone(buzzer, 5000, 500);
    delay(750);
  }

  //Condition when the water bucket is at a low level
  else if(readValue < 180){
    lcd.print("Low");
    digitalWrite(RED_LED, HIGH); 
    digitalWrite(GREEN_LED, LOW); 
    digitalWrite(YELLOW_LED, LOW); 

    //Sets the buzzer to turn on for a second then turn off 
    //the buzzer for 1 second (i.e. its supposed to be slower)
    tone(buzzer, 1000, 1000);
    delay(1000);
  }

  //Condition when the water bucket is at a medium level
  else if(readValue < 250){
    lcd.print("Medium");
    digitalWrite(YELLOW_LED, HIGH); 
    digitalWrite(RED_LED, LOW); 
    digitalWrite(GREEN_LED, LOW); 


    noTone(buzzer); 
  }

  //Condition when the water bucket is at a high level
  else{
    lcd.print("High");
    digitalWrite(GREEN_LED, HIGH); 
    digitalWrite(RED_LED, LOW); 
    digitalWrite(YELLOW_LED, LOW); 
    
    noTone(buzzer); 
  }

  //Print the water level state and its value on the serial monitor
  Serial.println(readValue);
  delay(100);
}
