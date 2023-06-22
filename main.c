#include <stdio.h>
#include <math.h>

float calcularArea(float a, float b, float c);
float calcularPerimetro(float puntos[5][3], float *a, float *b, float *c, float *d, float *e, float *f, float *h);
float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularVolumen(float h, float area);

int main(int argc, char *argv[])
{

    float puntos[5][3] = {{0, 0, 0}, {3, 0, 0}, {0, 0, 3}, {1, 7, 1}, {1, 0, 1}};

    float a, b, c, d, e, f, h;

    float perimetro = calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f, &h);
    float area = calcularArea(a, b, c);
    float area2 = calcularArea(b, d, e);
    float area3 = calcularArea(a, e, f);
    float area4 = calcularArea(d, f, c);
    float areasuper = area + area2 + area3 + area4;
    float volumen = calcularVolumen(h, area);
    printf("El area superficial es: %.2f\n", areasuper);
    printf("La altura es: %.2f \n", h);
    printf("El volúmen es: %.2f \n", volumen);
    return 0;
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2)
{

    float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));

    return dist;
}

float calcularPerimetro(float puntos[5][3], float *a, float *b, float *c, float *d, float *e, float *f, float *h)
{

    *a = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *b = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *c = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *d = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *f = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *e = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *h = calcularDistancia(puntos[3][0], puntos[3][1], puntos[3][2], puntos[4][0], puntos[4][1], puntos[4][2]);

    float super = 0;

    return super;
}

float calcularArea(float a, float b, float c)
{
    float s = 0;
    s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}
float calcularVolumen(float h, float area1)
{
    float volumen = (h * (area1)) / 3;
    return volumen;
}