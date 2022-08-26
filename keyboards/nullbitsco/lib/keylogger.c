#include <stdio.h>
#include "action.h"
#include "tidbit.h"

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

const char code_to_name[100] = {
 ' ', // 1
 ' ', // 2
 ' ', // 3
 ' ', // 4
 'a', // 5
 'b', // 6
 'c', // 7
 'd', // 8
 'e', // 9
 'f', // 10
 'g', // 11
 'h', // 12
 'i', // 13
 'j', // 14
 'k', // 15
 'l', // 16
 'm', // 17
 'n', // 18
 'o', // 19
 'p', // 20
 'q', // 21
 'r', // 22
 's', // 23
 't', // 24
 'u', // 25
 'v', // 26
 'w', // 27
 'x', // 28
 'y', // 29
 'z', // 30
 '1', // 31
 '2', // 32
 '3', // 33
 '4', // 34
 '5', // 35
 '6', // 36
 '7', // 37
 '8', // 38
 '9', // 39
 '0', // 40
 'R', // 41
 'E', // 42
 'B', // 43
 'T', // 44
 ' ', // 45
 ' ', // 46
 ' ', // 47
 ' ', // 48
 ' ', // 49
 ' ', // 50
 ' ', // 51
 ';', // 52
 '\'', // 53
 ' ', // 54
 ',', // 55
 '.', // 56
 '/', // 57
 ' ', // 58
 ' ', // 59
 ' ', // 60
 ' ', // 61
 ' ', // 62
 ' ', // 63
 ' ', // 64
 ' ', // 65
 ' ', // 66
 ' ', // 67
 ' ', // 68
 ' ', // 69
 ' ', // 70
 ' ', // 71
 ' ', // 72
 ' ', // 73
 ' ', // 74
 ' ', // 75
 ' ', // 76
 ' ', // 77
 ' ', // 78
 ' ', // 79
 ' ', // 80
 ' ', // 81
 ' ', // 82
 ' ', // 83
 ' ',
 '/', // 84
 '*', // 85
 '-', // 86
 '+', // 87
 'E', // 88
 '1', // 89
 '2', // 90
 '3', // 91
 '4', // 92
 '5', // 93
 '6', // 94
 '7', // 95
 '8', // 96
 '9', // 97
 '0', // 98
 '.', // 99
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (keycode < 101) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}
