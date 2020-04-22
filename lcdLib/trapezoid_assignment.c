#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

int main()
{

    configureClocks();
    lcd_init();
    u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLACK);
    int x,y;
    int x_origin = 10, y_origin = 10;

    //Rectangle
    for(y=0; y<=10; y++){
      for(x=0; x<=20; x++){
        drawPixel(x+x_origin,y+y_origin,COLOR_WHITE);
      }
    }

    //Right-Most Triangle
    for(y=0;y<=10;y++){
      for(x=0;x<=y;x++){
        drawPixel(x+x_origin+20,y+y_origin+20,COLOR_WHITE);
      }
    }

    //Left-Most Triangle
    for(y=0;y<=10;y++){
      for(x=0;x<=y;x++){
        drawPixel(x+x_origin,-y+y_origin,COLOR_WHITE);
      }
    }


    return 0;
}
