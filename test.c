#include <stdio.h>

typedef struct {
    int red;
    int green;
    int blue;
} Color;

typedef struct {
    int x1, y1;
    int x2, y2;
    Color color;
} Line;

int main() {
    Line line1 = {0, 0, 100, 100, {255, 0, 0}}; 

    
    printf("Line endpoints: (%d, %d) - (%d, %d)\n", line1.x1, line1.y1, line1.x2, line1.y2);
    printf("Line color: RGB(%d, %d, %d)\n", line1.color.red, line1.color.green, line1.color.blue);

    return 0;
}