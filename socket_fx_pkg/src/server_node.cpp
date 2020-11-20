#include "socket_fx.h"

int main(int argc, char **argv)
{
  Server *Sr = new Server(80);

  while(1)
  {
  	Sr -> socketloop();
    
    
  }
  delete Sr; 
  return 0;
}