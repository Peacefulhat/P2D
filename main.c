#define PMATH_IMP
#define ARENA_IMP
#include "include/arena.h"
#include <time.h>
#define REC_POINTS 4
int main(){
  Arena *rectangle=alloc_arena();
  Region* first= alloc_region(4,VEC2);
  append_region(rectangle, first);
  
  vec2 data[REC_POINTS]={
    {1.0f, 1.0f},
    {4.0f, 1.0f},
    {1.0f, 4.0f},
    {4.0f, 4.0f},
  };
  
  arena_free(rectangle);  
  
  
  
  
  printf("Rectangle Shape:\n");
  
            vec2 *ptr = (vec2 *)region->mem_region;

  for(int i=0;i<REC_POINTS;i++){
    printf("%d: {%f,%f}\n",i, (vec2*)first->mem_region[i].x,(vec2*)first->mem_region[i].y);
  }
  
  return 0;
}
