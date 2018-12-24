/*Enter a number in binary in range(0-8) to light one of the diode */


int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

const int bp1 = 13;
const int bp2 = 10;
const int bp3 = 9;
const int bp4 = 7;
const int bp5 = 6;



int bNum;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(bp1, INPUT);
  pinMode(bp2, INPUT);
  pinMode(bp3, INPUT);
  pinMode(bp4, INPUT);
  pinMode(bp5, INPUT);

}

void loop() {
  bNum = 0;
  int buttonState1 = 0;
  int buttonState2 = 0;
  int buttonState3 = 0;
  int buttonState4 = 0;
  
  while (digitalRead(bp5) == LOW) {
    if (buttonState1 == 0) {
      buttonState1 = digitalRead(bp1);
    }
    if (buttonState2 == 0) {
      buttonState2 = digitalRead(bp2);
    }
    if (buttonState3 == 0) {
      buttonState3 = digitalRead(bp3);
    }
    if (buttonState4 == 0) {
      buttonState4 = digitalRead(bp4);
    }

  }
  if (buttonState1 == HIGH) {
    bNum = bNum + 1;
  } 
  if (buttonState2 == HIGH) {
    bNum = bNum + 2;
  } 
  if (buttonState3 == HIGH) {
    bNum = bNum + pow(2, 2);
  } 
  if (buttonState4 == HIGH) {
    bNum = bNum + pow(2, 3);
  }
    

  Serial.print(bNum);

  if (bNum > 8) {
    Serial.print("Enter a new number.");
    loop();
  }

    digitalWrite(latchPin, 0);
    if (bNum==0){
      shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
      
    }else{
      shiftOut(dataPin, clockPin, LSBFIRST, 1<<bNum-1); 
      
    }
    digitalWrite(latchPin, 1);
    
    delay(500);


}
