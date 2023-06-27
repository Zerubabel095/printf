#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 *_printf - it prints characters and strings
 *format - it takes characters and string as argument
 *Return - integer i 
 */

int _printf(const char *format, ...) 
{
  va_list args;
  int i;

  va_start(args, format);
  for (i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%') {
      i++;
      switch (format[i]) {
        case 'd':
          putchar((int)va_arg(args, int));
          break;
        case 's':
          puts((char *)va_arg(args, char *));
          break;
        default:
          putchar(format[i]);
          break;
      }
    } else {
      putchar(format[i]);
    }
  }

  va_end(args);
  return i;
}

