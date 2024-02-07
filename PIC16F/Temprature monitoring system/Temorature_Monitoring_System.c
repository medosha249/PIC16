//Define LCD PINS
sbit LCD_EN at RB5_bit;
sbit LCD_RS at RB4_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D4 at RB0_bit;
//
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_D7_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB0_bit;
//
float temprature;
float DisplayTemp;
char temp[4];
void initialization()
{
 LCD_init();
 ADC_init();
 LCD_cmd(_LCD_clear);
 LCD_cmd(_LCD_CURSOR_OFF);
 LCD_out(1,1,"Temp monitoring");
 LCD_out(2,4,"System");
 LCD_OUT(3,1,"By");
 LCD_OUT(4,2,"ENG/Mohamed");
 Delay_ms(3000);
 lcd_cmd(_lcd_clear);
 LCD_OUT(4,0,"    ");
}
void main() {
initialization();
TRISB=0x00;
TRISA=0x0F;
TRISC=0x00;
 while(1)
 {
  temprature=ADC_Read(RA0);
  floattostr(DisplayTemp,temp);
  DisplayTemp=(temprature*50*10)/1023;
  lcd_out(2,12,Ltrim(temp));
  lcd_out(2,16,"C");
  delay_ms(500);
   if(DisplayTemp<22)
   {
   PORTC.F0=1;  //HEATER ON
   PORTC.F1=0;  //FAN OFF
   lcd_out(3,3,"HEATER ON ");
   lcd_out(4,3,"FAN    OFF"); }
   if(DisplayTemp>22&&DisplayTemp<25)
   {
   PORTC.F0=0;  //HEATER OFF
   PORTC.F1=0;  //FAN OFF
   lcd_out(3,3,"HEATER OFF");
   lcd_out(4,3,"FAN    OFF");
   }
   if(DisplayTemp>22&&DisplayTemp>25)
   {
   PORTC.F0=0;  //HEATER OFF
   PORTC.F1=1;  //FAN ON
   lcd_out(3,3,"HEATER OFF");
   lcd_out(4,3,"FAN    ON ");
     }
 }
}