const int button= 10;   
const int led1 = 12;    
const int led2 = 11; 

int buttonState = HIGH;  
int lastButtonState = HIGH; 
int counter = 0; 
int counter2=0;
void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1,HIGH);
   digitalWrite(led2,LOW);
}

void loop() {
  buttonState = digitalRead(button);
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      counter++;
    }
    delay(50); 
  }
  if (counter == 2) {
    counter = 0; 
    
     digitalWrite(led1, !digitalRead(led1));
    digitalWrite(led2, !digitalRead(led2));
   
  }
  

  lastButtonState = buttonState;
}
    