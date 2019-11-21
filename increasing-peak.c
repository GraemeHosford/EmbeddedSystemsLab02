#include "Stream.h"
int increasing_peak(struct Stream *s, int n){

int prev;
int c =0;
int state =0;
int finish =0;
int lastPeak = -1;
prev = streamGet(s,&finish);
//printf("peak2 cnt = %d size =%d\n",s->cnt,s->size);
if (finish ) return 0;
int curr = streamGet(s,&finish);
while (!finish && c<n ){
//printf("here1 state = %d\n",state);
//printf("peak3 c=%d cnt = %d size =%d\n",c,s->cnt,s->size);
   switch (state){
      case 0:
         if (prev < curr)
            state = 1;
         break;
      case 1:
         if (prev >= curr && prev >= lastPeak){
            lastPeak = prev;
            state = 0;
            c++; // found a peak 
         } else {
                return 0;
         }
        break;
      }
prev = curr;
curr = streamGet(s,&finish);
}
if (c==n) return 1;
return 0;
}
 
