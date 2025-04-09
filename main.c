#define PMATH_IMP
#define ARENA_IMP
#include "include/arena.h"
#include <time.h>

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}
void fill_region_with_dummy_data(Arena* arena, Types type) {
    size_t count = random_int(3, 10);

    switch (type) {
        case CHAR: {
            char *data = malloc(count * sizeof(char));
            for (size_t i = 0; i < count; i++) data[i] = 'A' + (rand() % 26);
            append_data(arena, CHAR, data, count);
            free(data);
        } break;

        case INT: {
            int *data = malloc(count * sizeof(int));
            for (size_t i = 0; i < count; i++) data[i] = random_int(1, 100);
            append_data(arena, INT, data, count);
            free(data);
        } break;

        case FLOAT: {
            float *data = malloc(count * sizeof(float));
            for (size_t i = 0; i < count; i++) data[i] = (float)rand() / RAND_MAX * 100.0f;
            append_data(arena, FLOAT, data, count);
            free(data);
        } break;

        case DOUBLE: {
            double *data = malloc(count * sizeof(double));
            for (size_t i = 0; i < count; i++) data[i] = (double)rand() / RAND_MAX * 100.0;
            append_data(arena, DOUBLE, data, count);
            free(data);
        } break;

        case UINT: {
            unsigned int *data = malloc(count * sizeof(unsigned int));
            for (size_t i = 0; i < count; i++) data[i] = (unsigned int)random_int(1, 200);
            append_data(arena, UINT, data, count);
            free(data);
        } break;
	  
        case VEC2: {
            vec2 *data = malloc(count * sizeof(vec2));
            for (size_t i = 0; i < count; i++){
	      data[i].x = (real)random_int(1, 200);
	      data[i].y = (real)random_int(1, 200);
	    }
            append_data(arena, VEC2, data, count);
            free(data);
        } break;
       
    }
}


int main() {
    srand((unsigned int)time(NULL));
    Arena* arenas[100];

    printf("Creating 100 arenas and filling them...\n");

    for (int i = 0; i < 100; i++) {
        arenas[i] = alloc_arena();
        for (int j = 0; j < 100; j++) {
            Types t = (Types)(rand() % 6);
            fill_region_with_dummy_data(arenas[i], t);
        }
        printf("Arena #%d filled with 100 regions.\n", i);
    }

    printf("\nPrinting first 100 arenas as sample:\n\n");
    for (int i = 0; i < 100; i++) {
        printf("----- Arena #%d -----\n", i);
        arena_print(arenas[i]);
        printf("---------------------\n\n");
    }

    printf("Freeing all arenas...\n{");
    for (int i = 0; i < 100; i++) {
        printf("%d,", i);
        arena_free(arenas[i]);
    }
    
    printf("}\n");
    printf("Done. All arenas cleaned.\n");
    return 0;
}
