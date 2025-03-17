// Felix, 18.02.2024
// This code snipped will check if the arduino and the board work correctly


// In this setup only input pin 1 will be used.
// If no input is transmitted, the pin will return 0. Otherwise about [800;2200]
// for 0 a stock LED sequence is returned with the RGB colors.
// with a connected input, there are two different ouput options





// Pins Definition

// LEDs

// stripe 1         // pwm pins
#define redLed_1    5   
#define greenLed_1  3
#define blueLed_1   6

// stripe 2         // pwm pins
#define redLed_2    10  
#define greenLed_2  9
#define blueLed_2   11

// stripe 3         // digital pins
#define redLed_3    7   
#define greenLed_3  4
#define blueLed_3   8


// input
#define rxIN_1 13
#define rxIN_2 12
#define rxIN_3 2
 

// parameters for LED functions
int flashDelay1 = 500;



// Setup
void setup(){

analogWrite(redLed_1, 0);
analogWrite(greenLed_1, 100);
analogWrite(blueLed_1, 0);

analogWrite(redLed_2, 0);
analogWrite(greenLed_2, 0);
analogWrite(blueLed_2, 111);

analogWrite(redLed_3, 255);
analogWrite(greenLed_3, 0);
analogWrite(blueLed_3, 0);

Serial.begin(9600);
}

// Loop
void loop(){

  // store current stick position, ca. [860,2100]
  int input_1 = pulseIn(rxIN_1, HIGH); 
  int input_2 = pulseIn(rxIN_2, HIGH); 
  int input_3 = pulseIn(rxIN_3, HIGH); 

  // print output: control shift M
  Serial.println(input_1);          
  Serial.println(input_2);
  Serial.println(input_3);        
  delay(500);  

  if (input_1 < 800) {  // no input at input 1    
    stockRGBcolors();

  } else if (input_1 > 800 && input_1 < 1500) {  // input option 1 
    fullWhite();

  } else if (input_1 > 1500) {  // input option 2 
    greenRedFlash();

  }


}  // loop Ende


void stockRGBcolors() {
   // stripe 1 
  analogWrite(redLed_1, 255);
  analogWrite(greenLed_1, 0);
  analogWrite(blueLed_1, 0);

  // stripe 2
  analogWrite(redLed_2, 0);
  analogWrite(greenLed_2, 255);
  analogWrite(blueLed_2, 0);

  // stripe 3 
  analogWrite(redLed_3, 0);
  analogWrite(greenLed_3, 0);
  analogWrite(blueLed_3, 255);
}


void fullWhite() {
  // stripe 1
  analogWrite(redLed_1, 255);
  analogWrite(greenLed_1, 255);
  analogWrite(blueLed_1, 255);

  // stripe 2
  analogWrite(redLed_2, 255);
  analogWrite(greenLed_2, 255);
  analogWrite(blueLed_2, 255);
  
  // stripe 3
  analogWrite(redLed_3, 255);
  analogWrite(greenLed_3, 255);
  analogWrite(blueLed_3, 255);

}


void greenRedFlash() {
  
  // stripe 1
  analogWrite(redLed_1, 255);
  analogWrite(greenLed_1, 0);
  analogWrite(blueLed_1, 0);

  // stripe 2
  analogWrite(redLed_2, 0);
  analogWrite(greenLed_2, 255);
  analogWrite(blueLed_2, 0);
  
  // stripe 3
  analogWrite(redLed_3, 0);
  analogWrite(greenLed_3, 0);
  analogWrite(blueLed_3, 255);

  // red Flash
  analogWrite(redLed_1, 0);
  delay(flashDelay1);
  analogWrite(redLed_1, 255);
  delay(flashDelay1);
  analogWrite(redLed_1, 0);
  delay(flashDelay1);
  analogWrite(redLed_1, 255);
  delay(flashDelay1);

  // Green Flash
  analogWrite(greenLed_2, 0);
  delay(flashDelay1);
  analogWrite(greenLed_2, 255);
  delay(flashDelay1);
  analogWrite(greenLed_2, 0);
  delay(flashDelay1);
  analogWrite(greenLed_2, 255);
  delay(flashDelay1);

}




// end
