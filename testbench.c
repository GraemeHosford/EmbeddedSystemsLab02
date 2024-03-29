
#include "Stream.h"
int streamGet(struct Stream *s,int * finished){
    *finished =0;
 //printf("streamGet cnt = %d size =%d\n",s->cnt,s->size);
    if (s->cnt < s->size){
      // printf("streamGet %d\n",s->buffer[s->cnt]);
       return s->buffer[s->cnt++];
    }
    else
       *finished = 1;
return -1;
}

/*
peak examples from
http://sofdem.github.io/gccat/gccat/Cpeak.html
(2,⟨1,1,4,8,6,2,7,1⟩)
(0,⟨1,1,4,4,4,6,7,7⟩)
(4,⟨1,5,4,9,4,6,2,7,6⟩)
*/
main(){

int data1[] = {1,1,4,8,6,2,7,1};
int data2[] ={1,5,4,9,4,6,2,7,6};
int data3[] = {1, 5, 5, 3, 5, 2, 2, 7, 4};
struct Stream s;

s.buffer = data1;
s.size = 8;
s.cnt =0;

int val = peak(&s,2);
printf("result for peak({1,1,4,8,6,2,7,1},2) i.e. are there two peaks in the data? %d\n",val);

s.buffer = data2;
s.size = 9;
s.cnt =0;

val = peak(&s,4);
printf("result for peak({1,5,4,9,4,6,2,7,6},4) i.e. are there 4 peaks in the data? %d\n",val);

val = peak(&s,5);
printf("result for peak({1,5,4,9,4,6,2,7,6},5) i.e. are there 5 peaks in the data? %d\n",val);

s.buffer = data1;
s.size = 8;
s.cnt =0;

val = valley(&s,1);
printf("result for valley({1,1,4,8,6,2,7,1},1) i.e. are there is 1 valleys in the data? %d\n",val);

s.buffer = data2;
s.size = 9;
s.cnt =0;

val = valley(&s,3);
printf("result for valley({1,5,4,9,4,6,2,7,6},3) i.e. are there 3 valleys in the data? %d\n",val);

s.buffer = data2;
s.size = 9;
s.cnt =0;

val = valley(&s,3);
printf("result for valley({1,5,4,9,4,6,2,7,6},3) i.e. are there 3 valleys in the data? %d\n",val);

s.buffer = data1;
s.size = 8;
s.cnt =0;

val = increasing_peak(&s,0);
printf("result for increasing_peak({1,1,4,8,6,2,7,1},0) i.e. are there is 0 increasing peaks in the data? %d\n",val);

s.buffer = data2;
s.size = 9;
s.cnt =0;

val = increasing_peak(&s,0);
printf("result for increasing_peak({1,5,4,9,4,6,2,7,6},0) i.e. are there 0 increasing peaks in the data? %d\n",val);

s.buffer = data3;
s.size = 9;
s.cnt =0;

val = increasing_peak(&s,1);
printf("result for increasing_peak({1, 5, 5, 3, 5, 2, 2, 7, 4}, 1) i.e. are there 1 increasing_peak in the data? %d\n",val);
}

