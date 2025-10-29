#include <LiquidCrystal.h>
#include<string.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define light 3
#define fan 4
#define TV 5

char temp;
char str[10];
char i=0;

void setup() 
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(light, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(TV, OUTPUT);
  lcd.print(" Home Automation ");
  lcd.setCursor(0,1); 
  lcd.print("    Using PC     ");
  delay(2000);
  lcd.clear();
  lcd.print("Keywords For ");
  lcd.setCursor(0,1);
  lcd.print("Controlling");
  delay(2000);
  lcd.clear();
  lcd.print("1. LIGHT ON");
  lcd.setCursor(0,1);
  lcd.print("2. LIGHT OFF");
  delay(2000);
  lcd.clear();
  lcd.print("3. FAN ON");
  lcd.setCursor(0,1);
  lcd.print("4. FAN OFF");
  delay(2000);
  lcd.clear();
  lcd.print("5. TV ON");
  lcd.setCursor(0,1);
  lcd.print("6. TV OFF");
  delay(2000);
  defualt();
  delay(1000);
}

void loop() 
{
   if(temp==1)
   {
    if((strncmp(str,"FAN ON", 6))==0)
    {
     lcd.clear();
     digitalWrite(fan, HIGH);
     lcd.clear();
     lcd.print("Fan Turned On");
     delay(3000);
     defualt();
    }
    
    else if(strncmp(str, "FAN OFF", 7)==0)
    {
     digitalWrite(fan, LOW);
     lcd.clear();
     lcd.print("Fan Turned OFF"); 
     delay(3000);
     defualt();
    }
    
    else if(strncmp(str, "LIGHT ON", 8)==0)
    {
     digitalWrite(light, HIGH);
     lcd.clear();
     lcd.print("Light Turned ON"); 
     delay(3000);
     defualt();
    }
    
    else if(strncmp(str, "LIGHT OFF", 9)==0)
    {
     digitalWrite(light, LOW);
     lcd.clear();
     lcd.print("Light Turned OFF"); 
     delay(3000);
     defualt();
    }
    
     else if(strncmp(str, "TV ON", 5)==0)
    {
     digitalWrite(TV, HIGH);
     lcd.clear();
     lcd.print("TV Turned ON"); 
     delay(3000);
     defualt();
    }
    
    else if(strncmp(str, "TV OFF", 6)==0)
    {
     digitalWrite(TV, LOW);
     lcd.clear();
     lcd.print("TV Turned OFF"); 
     delay(3000);
     defualt();
    }
    
    else 
    {
     lcd.clear();
     lcd.print(" Invalid Input");
     lcd.setCursor(0,1);
     lcd.print("   Try Again  ");
     delay(3000);
     defualt();
     }
   }
}
void serialEvent()
{
   while(Serial.available())
    {
     char Inchar=Serial.read();
     str[i]=Inchar;
     i++;
     lcd.print(Inchar);
     delay(50);
     if(Inchar == 0x0d)
     {
      temp=1;
      //Inchar=0;
     }
    }
}

void defualt()
{
  lcd.clear();
   lcd.print("Enter UR Choise:");
   lcd.setCursor(0,1);
   lcd.cursor();
   i=0;
   temp=0;
}

