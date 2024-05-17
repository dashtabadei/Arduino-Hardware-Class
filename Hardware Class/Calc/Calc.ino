#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
const byte ROW_NUM = 4;
const byte COL_NUM = 4;

char keys[ROW_NUM][COL_NUM] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'c', '0', '=', '+'}
};

byte pin_rows[ROW_NUM] = {7, 6, 5, 4};
byte pin_column[COL_NUM] = {3, 2, 1, 0};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COL_NUM);

float value = 0;
float result = 0;
char operatorSymbol = ' ';
bool equalsPressed = false;
char key;
void setup() {
  lcd.begin(16, 2);
}

void loop() {
   key = keypad.getKey();

  if (key) {
    if (key == 'c') {
      lcd.clear();
      value = 0;
      result = 0;
      operatorSymbol = ' ';
      equalsPressed = false;
    } 

    else if (key == '=') {
      if (operatorSymbol != ' ' && !equalsPressed) {
        if (operatorSymbol == '+') {
          result += value;
        }

         else if (operatorSymbol == '-') {
          result -= value;
        }

         else if (operatorSymbol == '*') {
          result *= value;
        }

         else if (operatorSymbol == '/') {
          if (value != 0) {
            result /= value;
          }
           else {
            lcd.clear();
            lcd.print("تقسیم بر 0 ");
            delay(2000);
          }
        }

        lcd.clear();
        lcd.print("حاصل=");
        lcd.print(result);
        value = 0;
        equalsPressed = true;
      }
    }
     else if (isdigit(key)) {
      value = value * 10 + (key - '0');
      lcd.write(key);
    }
     else {
      operatorSymbol = key;
      result = value;
      value = 0;
      lcd.write(key);
    }
  }
}