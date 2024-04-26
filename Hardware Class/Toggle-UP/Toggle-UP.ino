const int button= 10;   
const int led1 = 12;    
int buttonState;  
int lastButtonState = HIGH; 
void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  digitalWrite(led1,LOW);
}

void loop() {
  buttonState = digitalRead(button);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
     
     digitalWrite(led1, !digitalRead(led1));
   

    }
  
  }
 
   

  lastButtonState = buttonState;
}
    