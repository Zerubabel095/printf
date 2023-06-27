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
	int _printf(const char *format, ...) {
  int count = 0;
  va_list args;
  va_start(args, format);

  for (; *format; format++) {
    if (*format == '%') {
      format++;
      switch (*format) {
        case 'c': {
          char c = va_arg(args, int);
          count += printf("%c", c);
          break;
        }
        case 's': {
          char *str = va_arg(args, char *);
          count += printf("%s", str);
          break;
        }
        case '%': {
          count += printf("%%");
          break;
        }
        default: {
          printf("Unknown conversion specifier: %c\n", *format);
          count = -1;
          break;
        }
      }
    } else {
      count += printf("%c", *format);
    }
  }

  va_end(args);
  return count;
}
}

