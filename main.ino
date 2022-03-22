#include <LiquidCrystal.h> 
LiquidCrystal lcd(2,3,4,5,6,7);
int BTN_UP = 8;
int BTN_DOWN = 9;
int LS_UP, LS_DOWN, CS_UP, CS_DOWN;
int index = 0;
int string_leng = 9;
String str[string_leng] = {
  "LINE 1",
  "LINE 2",
  "LINE 3",
  "LINE 4",
  "LINE 5",
  "LINE 6",
  "LINE 7",
  "LINE 8",
  "LINE 9"
  }; 

void trigger_once_up(){
  LS_UP = CS_UP;
  CS_UP = digitalRead(BTN_UP);
  if ((LS_UP == LOW && CS_UP == HIGH) && index <= string_leng-3){
    index++;
    lcd.clear();
    }
  }
void trigger_once_down(){
  LS_DOWN = CS_DOWN;
  CS_DOWN = digitalRead(BTN_DOWN);
  if ((LS_DOWN == LOW && CS_DOWN == HIGH) && index >= 0){
    index--;
    lcd.clear();
    }
  }

void setup() {
  lcd.begin(16, 2); 
  Serial.begin(9600);
  pinMode(BTN_UP, INPUT);
  pinMode(BTN_DOWN, INPUT);
}
void loop() {
  trigger_once_up();
  trigger_once_down();
  lcd.setCursor(0,0);

  lcd.print(str[index]);
  lcd.setCursor(0,1);
  
  lcd.print(str[index+1]);
  Serial.print(index);
}
