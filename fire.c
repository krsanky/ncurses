/*
 * ncurses-fire.c
 * ---------------------------
 * This C function adapted from python cfire by Matthew Simpson (https://gist.github.com/msimpson/1096950)
 *
 * Email from Matthew Simpson (Jan 31, 2016):
 * Thanks for the complements, but I didn't invent the effect. I too adapted it from someone else's work.
 * Originally it was written in JavaScript by Thiemo Mättig, found here: http://maettig.com/code/javascript/asciifire.html
 * ---------------------------
 * 
 * Copyright 2016 Frank Cox <theatre@melvilletheatre.com>
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided
 * that the following conditions are met:
 * 
 *     Redistributions of source code must retain the above copyright notice, this list of conditions and
 *     the following disclaimer.
 *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions
 *     and the following disclaimer in the documentation and/or other materials provided with the
 *     distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void flames(void);

int main(int argc, char** argv)
 {
 initscr();
 start_color();

 flames();

 endwin();
 return 0;
 }

void flames(void)
 {
 int width, height, size, *b, i;
 const char characters[] = {' ', '.', ':', '^', '*', 'x', 's', 'S', '#', '$'};
 
 getmaxyx(stdscr,height,width);
 size=width*height;
 init_pair(1,0,0);
 init_pair(2,1,0);
 init_pair(3,3,0);
 init_pair(4,4,0);
 clear();
 
 b=calloc((size+width+1),sizeof(int));
 nodelay(stdscr,TRUE);
 srand(time(NULL));

 for (;;)
  {
  for (i =0; i < width/9; i++)
   b[(int)(((float)rand()/(float)RAND_MAX)*width+width*(height-1))]=65;
  for (i=0; i < size; i++)
   {
   b[i]=(b[i]+b[i+1]+b[i+width]+b[i+width+1])/4;
   if (b[i] > 15)
    attrset(COLOR_PAIR(4)|A_BOLD);
   else if (b[i] > 9)
    attrset(COLOR_PAIR(3)|A_BOLD);
   else if (b[i] > 4)
    attrset(COLOR_PAIR(2)|A_BOLD);
   else
    attrset(COLOR_PAIR(1)|A_BOLD);
   if (i < size-1)
    {
    move(i/width, i%width);
    if (b[i] > 9)
     addch(characters[9]);
    else
     addch(characters[b[i]]);
    }
   }
  refresh();
  timeout(30);
  if (getch() != ERR)
   break;
  }
 
 free(b);
 return;
 }


