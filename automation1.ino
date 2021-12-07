#include <LiquidCrystal.h>
#include <IRremote.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#define pin A3
#define NUMPIXELS 1
Servo motor;
IRrecv irrecv(9);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS,pin,NEO_GRB+NEO_KHZ800);
decode_results results;
LiquidCrystal lcd(2,3,4,5,6,7);
int toggleState_1 = 0; 
int toggleState_2 = 0; 
int toggleState_3 = 0; 
int toggleState_4 = 0;
int toggleState_5 = 0;
int toggleState_6 = 0;
int toggleState_7 = 0; 
int toggleState_8 = 0;
int toggleState_9 = 0;
int toggleState_10 = 0;
int toggleState_11 = 0;
int pos;
byte customChar[] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup()
{
  lcd.begin(16,2); 
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
 irrecv.enableIRIn();
  pixels.begin();
 //Serial.begin(9600);
  lcd.createChar(0, customChar);
  lcd.setCursor(2,0);
  lcd.print("Automation.....");
  delay(400);
}
void loop()
{
  float reading,voltage,tempreading,fernite,temp;
  tempreading = analogRead(A4);
  voltage=tempreading*5;
 voltage/=1024.0;
 temp = (voltage - 0.5)*100;
 
  if(temp > 0 & temp < 25)
  {
   
  lcd.setCursor(0,0);
  lcd.print("Room Temperature ");
   lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.write(byte(0));
  lcd.print("C ");
  
  }
  
  else if(temp < 0)
  {
    lcd.setCursor(0,0);
    lcd.print("Room Temperature ");
     lcd.setCursor(0,1);
    lcd.print("Temp:");
    lcd.print(temp);
    lcd.write(byte(0)); 
    lcd.print("C ");
  
  }
   else if(temp > 25 & temp < 75)
  {
    lcd.setCursor(0,0);
    lcd.print("Room Temperature ");
     lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(temp);
     lcd.write(byte(0));
    lcd.print("C ");
   
  }
  
   else if(temp > 75)
  {
     lcd.setCursor(0,0);
     lcd.print("Room Temperature ");
     lcd.setCursor(0,1);
     lcd.print("Temp: ");
     lcd.print(temp);
     lcd.write(byte(0));
     lcd.print("C ");
    
  }
  if(irrecv.decode(&results))
    {
            switch(results.value)
            {
                case 16619623: //bulb 2
                    if(toggleState_1 == 0)
                    {
                       pixels.setPixelColor(0,0,255,0);
                       pixels.show();
                    digitalWrite(12,HIGH);
                    toggleState_1 = 1;
                    toggleState_11 = 1;
                      lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("BULB 2 - ON");
                      delay(400);
                      lcd.clear();
                      pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                     pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                    digitalWrite(12,LOW);
                    toggleState_1 = 0;
                    toggleState_11 = 0;
                    lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("BULB 2 - OFF");
                      delay(400);
                      lcd.clear();
                      pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    
                }
                break;
                // bulb 1
                case 16609423: 
                    if(toggleState_2 == 0)
                    {
                      pixels.setPixelColor(0,0,255,0);
                       pixels.show();
                    digitalWrite(8,HIGH);
                    toggleState_2 = 1;
                    toggleState_11 = 1;  
                      lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("BULB 1 - ON");
                      delay(400);
                      lcd.clear();
                      pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                 pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                    digitalWrite(8,LOW);
                    toggleState_2 = 0;
                    toggleState_11 = 0;
                      lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("BULB 1 - OFF");
                      delay(400);
                      lcd.clear();
                     pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                }
                break; 
               // fan 1
                case 16591063: 
                    if(toggleState_3 == 0)
                    {
                     pixels.setPixelColor(0,0,255,0);
                     pixels.show();
                    digitalWrite(10,HIGH);
                    toggleState_3 = 1;
                    toggleState_11 = 1;  
                      lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("FAN 1 - ON");
                      delay(400);
                      lcd.clear();
                      pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                  pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                    digitalWrite(10,LOW);
                    toggleState_3 = 0;
                    toggleState_11 = 0;
                  	  lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("FAN 1 - OFF");
                      delay(400);
                       lcd.clear();
                     pixels.setPixelColor(0,0,0,0);
                      pixels.show(); 
                }
                break;
              // fan 2
                case 16586983: 
                    if(toggleState_4 == 0)
                    {
                     pixels.setPixelColor(0,0,255,0);
                       pixels.show(); 
                    digitalWrite(11,HIGH);
                    toggleState_4 = 1;
                      toggleState_11 = 1;
                       lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("FAN 2 - ON");
                      delay(400);
                      lcd.clear();
                       pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                  pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                    digitalWrite(11,LOW);
                    toggleState_4 = 0;
                    toggleState_11 = 0;
                     lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("FAN 2 - OFF");
                      delay(400);
                       lcd.clear();
                      pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                }
                break;
              // gate 1
                case 16599223:
                    motor.attach(A1); 
                       
                    if(toggleState_5 == 0)
                    {
                     pixels.setPixelColor(0,0,255,0);
                     pixels.show();
                    for(pos = 0;pos<=90;pos++)
                   {
                      motor.write(pos);
                      delay(5);
                    }
                    toggleState_5 = 1;
                       lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("GATE 1 - ON");
                      delay(400);
                      lcd.clear();
                      pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                 pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                    for(pos = 90 ;pos >= 0;pos--)
                    {
                     motor.write(pos);
                      delay(5);
                    }
                    toggleState_5 = 0;
                  
                  	  lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("GATE 1 - OFF");
                      delay(400);
                      lcd.clear();
                     pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                }
                break;
               // gate 2
                case 16607383:
                     motor.attach(A0);
                     
                    if(toggleState_6 == 0)
                    {
                    pixels.setPixelColor(0,0,255,0);
                    pixels.show();
                    for(pos = 0;pos <= 90;pos++)
                    {
                      motor.write(pos);
                      delay(5);
                    }
                    toggleState_6 = 1;
                      lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("GATE 2 - ON");
                      delay(400);
                      lcd.clear();
                     pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                  pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                    for(pos = 90 ;pos >= 0;pos--)
                    {
                     motor.write(pos);
                     delay(5);
                    }
                    toggleState_6 = 0;
                  lcd.clear();
                  lcd.setCursor(2,0);
              
                      lcd.print("GATE 2 - OFF");
                      delay(400);
                      lcd.clear();
                  pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                }
                break;
              // fan 1 + fan 2
                case 16603303:
                    if(toggleState_7 == 0 & toggleState_3 == 0 &
                    toggleState_4 == 0 )
                    {
                      pixels.setPixelColor(0,0,255,0);
                       pixels.show();
                      digitalWrite(10,HIGH);
                      digitalWrite(11,HIGH);
                    toggleState_7 = 1;
                    toggleState_3 = 1;
                    toggleState_4 = 1;  
                    toggleState_11 = 1;  
                      lcd.clear();
                      lcd.setCursor(0,0);
                      lcd.print("Fan1 - ON");
                      lcd.setCursor(0,1);
                      lcd.print("FAN2 - ON");
                      delay(400);
                      lcd.clear();
                      pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                 pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                   digitalWrite(10,LOW);
                    digitalWrite(11,LOW);  
                    toggleState_7 = 0;
                     toggleState_3 = 0;
                    toggleState_4 = 0; 
                  	toggleState_11 = 0;
                      lcd.clear();
                      lcd.setCursor(0,0);
                      lcd.print("Fan1 - OFF");
                      lcd.setCursor(0,1);
                      lcd.print("FAN2 - OFF");
                      delay(400);
                   		lcd.clear();
                 pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                }
              break;
              // bulb 1 + bulb 2
                case 16601263:
                    if(toggleState_8 == 0 & toggleState_2 == 0 
                         & toggleState_1 == 0)
                    {
                    pixels.setPixelColor(0,0,255,0);
                       pixels.show();
                      digitalWrite(8,HIGH);
                      digitalWrite(12,HIGH);
                    toggleState_8 = 1;
                    toggleState_2 = 1;
                    toggleState_1 = 1; 
                     toggleState_11 = 1; 
                       lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("BULB 1 - ON");
                      lcd.setCursor(2,1);
                      lcd.print("BULB 2 - ON");
                      delay(400);
                      lcd.clear();
                      pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                   pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                   digitalWrite(8,LOW);
                    digitalWrite(12,LOW);  
                    toggleState_8 = 0;
                    toggleState_2 = 0;
                    toggleState_1 = 0;
                    toggleState_11 = 0;
                     lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("BULB 1 - OFF");
                      lcd.setCursor(2,1);
                      lcd.print("BULB 2 - OFF");
                      delay(400);
                  lcd.clear();
                  pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                }
              break;
              //fan 2 + bulb 2
                case 16582903:
                    if(toggleState_9 == 0& toggleState_4 == 0 
                         & toggleState_1 == 0)
                    {
                    pixels.setPixelColor(0,0,255,0);
                       pixels.show();
                      digitalWrite(12,HIGH);
                      digitalWrite(11,HIGH);
                    toggleState_9 = 1;
                    toggleState_4 = 1;
                    toggleState_1 = 1; 
                    toggleState_11 = 1;  
                      lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("FAN 2 - ON");
                      lcd.setCursor(2,1);
                      lcd.print("BULB 2 - ON");
                      delay(400);
                      lcd.clear();
                       pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                    pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                   digitalWrite(11,LOW);
                    digitalWrite(12,LOW);  
                    toggleState_9 = 0;
                    toggleState_4 = 0;
                    toggleState_1 = 0;
                    toggleState_11 = 0;
                  lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("FAN 2 - OFF");
                      lcd.setCursor(2,1);
                      lcd.print("BULB 2 - OFF");
                      delay(400);
                  lcd.clear();
               pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                }
              break;
              //fan 1 + bulb 1
                case 16605343:
                    if(toggleState_10 == 0 & toggleState_2 == 0 
                         & toggleState_3 == 0)
                    {
                      pixels.setPixelColor(0,0,255,0);
                       pixels.show();
                      digitalWrite(10,HIGH);
                      digitalWrite(8,HIGH);
                    toggleState_10 = 1;
                    toggleState_3 = 1;
                    toggleState_2 = 1;  
                    toggleState_11 = 1;  
                      lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("FAN 1 - ON");
                      lcd.setCursor(2,1);
                      lcd.print("BULB 1 - ON");
                      delay(400);
                      lcd.clear();
                     pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                   pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                   digitalWrite(10,LOW);
                    digitalWrite(8,LOW);  
                    toggleState_10 = 0;
                    toggleState_3 = 0;
                    toggleState_2 = 0;
                    toggleState_11 = 0;
                   lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("FAN 1 - OFF");
                      lcd.setCursor(2,1);
                      lcd.print("BULB 1 - OFF");
                      delay(400);
                  lcd.clear();
                   pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                }
              break;
               //power
                case 16580863:
                    if(toggleState_11 == 0  & toggleState_3 == 0
                   & toggleState_2 == 0
                    & toggleState_4 == 0
                    & toggleState_1 == 0
                    & toggleState_7 == 0
                    & toggleState_8 == 0
                    & toggleState_9 == 0
                    & toggleState_10 == 0)
                    {
                     pixels.setPixelColor(0,0,255,0);
                       pixels.show();
                      digitalWrite(10,HIGH);
                      digitalWrite(8,HIGH);
                      digitalWrite(11,HIGH);
                      digitalWrite(12,HIGH);
                      
                    toggleState_11 = 1;
                    toggleState_3 = 1;
                    toggleState_2 = 1;
                    toggleState_4 = 1;
                    toggleState_1 = 1;
                    toggleState_7 = 1;
                    toggleState_8 = 1;
                    toggleState_9 = 1;
                    toggleState_10 = 1;
                      lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("Power - ON");
                      delay(400);
                      lcd.clear();
                    pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                    }
                else
                {
                    pixels.setPixelColor(0,255,0,0);
                     pixels.show();
                   digitalWrite(10,LOW);
                    digitalWrite(8,LOW);
                    digitalWrite(11,LOW);
                     digitalWrite(12,LOW);
                     
                    toggleState_11 = 0;
                    toggleState_3 = 0;
                    toggleState_2 = 0;
                    toggleState_4 = 0;
                    toggleState_1 = 0;
                    toggleState_7 = 0;
                    toggleState_8 = 0;
                     toggleState_9 = 0;
                    toggleState_10 = 0;
                  lcd.clear();
                      lcd.setCursor(2,0);
                      lcd.print("Power - OFF");
                      delay(400);
                      lcd.clear();
                    pixels.setPixelColor(0,0,0,0);
                      pixels.show();
                }
              break;
              
              default:
              {
                pixels.setPixelColor(0,0,0,255);
                pixels.show();
               lcd.clear();
                 lcd.setCursor(0,0);
                lcd.print("No Such Command");
                lcd.setCursor(2,1);
                lcd.print("Available");
                delay(400);
                lcd.clear();
                 pixels.setPixelColor(0,0,0,0);
                 pixels.show();
                
                
              }
            }
        irrecv.resume();
         
    
    
    }
  
}


