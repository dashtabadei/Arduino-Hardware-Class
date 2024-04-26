const int button1= 8;  
const int button2= 9;   
const int button3= 10;    
const int led1 = 12;    
int buttonState1;  
int buttonState2;  
int buttonState3;  
int lastButtonState1 = HIGH; 
int lastButtonState2 = HIGH; 
int lastButtonState3 = HIGH; 
void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  digitalWrite(led1,LOW);
}

void loop() {
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  if (buttonState1 != lastButtonState1) {
    if (buttonState1 == HIGH) {
     
     digitalWrite(led1, !digitalRead(led1));
   

    }
  
  }
   if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
     
     digitalWrite(led1, !digitalRead(led1));
   

    }
  
  }
 
   if (buttonState3 != lastButtonState3) {
    if (buttonState3 == HIGH) {
     
     digitalWrite(led1, !digitalRead(led1));
   

    }
  
  } 

  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;

}
    