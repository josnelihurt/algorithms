#include "functions.h"
#include <stdlib.h>
#include <ctime>
int getRandomValue()
{
  srand (time(NULL));
  auto value = rand() + 1;
  return value;
}
