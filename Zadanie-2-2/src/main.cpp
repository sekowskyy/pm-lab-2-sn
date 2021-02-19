#include <Arduino.h>
#include <avr/io.h>

int main()
{
  uint32_t i;

  DDRB |= (1 << 5); //pinMode(13, OUTPUT);
  while (1)
  {
    PORTB |= (1 << 5); //digitalWrite(13, HIGH);
    i = 0x3FFFF;
    do
    {
      asm volatile("nop");
    } while (i--);
    PORTB &= !(1 << 5); // digitalWrite(13, LOW);
    i = 0x3FFFF;
    do
    {
      asm volatile("nop");
    } while (i--);
  }
}