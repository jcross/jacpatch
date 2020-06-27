#include <stdio.h>
#if defined(unix) || defined(__unix__) || defined(__unix)
#include <termios.h>
void pause() {
  struct termios oldConf;
  struct termios newConf;
  tcgetattr(0, &oldConf);
  tcgetattr(0, &newConf);
  newConf.c_lflag &= ~ICANON;
  newConf.c_cc[VMIN] = 1;
  newConf.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &newConf);
  getchar();
  tcsetattr(0, TCSANOW, &oldConf);
}
#else
#include <conio.h>
void pause() {
  getch();
}
#endif
