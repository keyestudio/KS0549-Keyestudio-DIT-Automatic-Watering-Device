## 5.4 Control an LCD1602 display

You can view values detected by the soil sensor on the Arduino IDE serial monitor.

We can add an LCD1602 display to show humidity values.

**Description**

The LCD1602 display is used for showing character strings.

**Test Code**

The LCD1602 displays character strings and values

```C
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("keyestudio");
}


void loop()
{
}
```

**Test Result：**

You can view the display show Hello World! on the first line and keyestudio on the second line.