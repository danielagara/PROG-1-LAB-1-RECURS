#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED
typedef struct
{
    int R;
    int G;
    int B;
}pixel;


pixel* pixel_getRGB(pixel* pPixel, int index);
int pixel_setRGB(pixel* arraypixel, int index, int R, int G, int B);
pixel* pixel_newPixel(int qty);
pixel pixel_getPixel(pixel* pPixel, int index);
void pixel_deletePixel(pixel* pPixel);
#endif // PIXEL_H_INCLUDED
