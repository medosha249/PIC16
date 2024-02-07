
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;



sbit LED1 at RC0_bit;
sbit LED2 at RC1_bit;
sbit LED3 at RC2_bit;
sbit LED4 at RC3_bit;


sbit Button1 at RD0_bit;
sbit Button2 at RD1_bit;
sbit Button3 at RD2_bit;
sbit Button4 at RD3_bit;
  
  int button1State = 0;
  int button2State = 0;
  int button3State = 0;
  int button4State = 0;

void Initialize() {
  
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);

  
  TRISC = 0x00;

  
  TRISD = 0xFF;

  LED1 = 0;
  LED2 = 0;
  LED3 = 0;
  LED4 = 0;

   Lcd_Out(1, 1, "Lighting system");
  Lcd_Out(2, 1, "Prees Buttons");
  Delay_ms(1000);
  Lcd_Out(1, 1, "Led1:OFFLed2:OFF");
  Lcd_Out(2, 1, "Led3:OFFLed4:OFF");


  Delay_ms(1000);
}

void main() {
  Initialize();

  while (1) {
    
    if (Button1 != button1State) {
      button1State = Button1;
      LED1 = button1State;  
      Lcd_Out(1, 6, button1State ? "ON " : "OFF");  
    }

  
    if (Button2 != button2State) {
      button2State = Button2;
      LED2 = button2State;  
      Lcd_Out(1,14,button2State ? "ON " : "OFF");  
    }

    
    if (Button3 != button3State) {
      button3State = Button3;
      LED3 = button3State;  
      Lcd_Out(2,6,button3State ? "ON " : "OFF"); 
    }

    
    if (Button4 != button4State) {
      button4State = Button4;
      LED4 = button4State; 
      Lcd_Out(2,14, button4State ? "ON " : "OFF");  
    }

  
    Delay_ms(100);
  }
}