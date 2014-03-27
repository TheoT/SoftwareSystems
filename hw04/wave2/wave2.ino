/*
  

 Author: Allen Downey 
 
 Based on http://arduino.cc/en/Tutorial/AnalogInput
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 License: Public Domain
 
 */
 
 
int ledPin = 5;       // select the pin for the LED
int buttonPin1 = 2;
int buttonPin2 = 3;

void setup() {
  Serial.begin(9600);
  
  pinMode(buttonPin1, INPUT_PULLUP);  
  pinMode(buttonPin2, INPUT_PULLUP);  

  pinMode(ledPin, OUTPUT);
  
  pinMode(13, OUTPUT);  
  pinMode(12, OUTPUT);  
  pinMode(11, OUTPUT);  
  pinMode(10, OUTPUT);  
  pinMode(9, OUTPUT);  
  pinMode(8, OUTPUT);  
  pinMode(7, OUTPUT);  
  pinMode(6, OUTPUT);
  
  // interupts setup based on code from http://www.instructables.com/id/Arduino-Timer-Interrupts/?ALLSTEPS
  cli();//stop interrupts

  //set timer1 interrupt at ~2kHz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0;
  // set timer count for 1khz increments
  OCR1A = 1000;
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS11 bit for 8 prescaler
  TCCR1B |= (1 << CS11);   
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  sei();//allow interrupts
  //END TIMER SETUP
    
}

void writeByte(int x) {
  int pin;
  x = ~x;
  PORTD = (x<<6) & B00000011;   
  PORTB = x>>2;   // turns on 13,12,11; turns off 10,9,8
  for (pin=13; pin>=6; pin--) {
    digitalWrite(pin, x&1);
    x >>= 1;
  }
}


int low = 36;
int high = 255;
int stride = 5;
int counter = low;
int play_flag = 0;

void loop() {
  int button1 = digitalRead(buttonPin1);
  if (button1){ 
    play_flag = !play_flag;
  }
  
}

ISR(TIMER1_COMPA_vect) {//Interrupt at freq of 1kHz to measure reed switch
  counter += stride;
  if (counter > high) {
    counter = low;
    //Serial.println(counter);
  }

  // write to the digital pins  
  writeByte(counter);
}
