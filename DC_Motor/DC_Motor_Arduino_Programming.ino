/************************
Exercise the motor using the L293D chip
************************/

#define ENABLE 7                // makes ENABLE and 7 the same thing - makes the MEGA read 7 each time the word ENABLE is printed in the code
#define DIRA 5                    // similar to the previous command (think what this one does!!!)
#define DIRB 3                    // you should know what this command do by now...:)

int i;
 
void setup() {
                                             //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}

void loop() {
                                        //---back and forth example
    Serial.println("One way, then reverse");
    digitalWrite(ENABLE,HIGH); // enable on
    for (i=0;i<5;i++) {
      digitalWrite(DIRA,HIGH); //one way
      digitalWrite(DIRB,LOW);
      delay(2000);
      digitalWrite(DIRA,128); 
      delay(3000);
      digitalWrite(DIRA,LOW);  //reverse
      delay(1000);
      digitalWrite(DIRB,HIGH);
      delay(2000);
      digitalWrite(DIRB,128);
      delay(3000);
      digitalWrite(DIRB,LOW);
      delay(1000);
    }
}
   
