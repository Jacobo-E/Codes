#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define I 20
#define R 340
#include <string.h>
int main()
{
 
     // Primero usa el bucle for para imprimir la forma del corazón
  float y, x, z, f;
  for (y = 1.5f; y > -1.5f; y -= 0.1f)
  {
    for (x = -1.5f; x < 1.5f; x += 0.05f)
    {
      z = x * x + y * y - 1;
      f = z * z * z - x * x * y * y * y;
      putchar(f <= 0.0f ? "*********"[(int)(f * -8.0f)] : ' ');
    }
    putchar('\n');
  }
  
}
