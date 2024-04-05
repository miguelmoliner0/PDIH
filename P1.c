#include <stdio.h>
#include <dos.h>

//autor: Miguel Molinero Martin

#define BYTE unsigned char
BYTE MODOTEXTO = 3;
BYTE MODOGRAFICO = 4;


int mi_getchar(){
    union REGS inregs, outregs;
    int caracter;
    inregs.h.ah = 1;
    int86(0x21, &inregs, &outregs);
    caracter = outregs.h.al;
    return caracter;
}
void mi_putchar(char c){
    union REGS inregs, outregs;
    inregs.h.ah = 2;
    inregs.h.dl = c;
    int86(0x21, &inregs, &outregs);
}

void pausa(){
    union REGS inregs, outregs;
    inregs.h.ah = 0x00;
    int86(0x16, &inregs, &outregs);
}

//coloca el cursor en una posición determinada
void gotoxy(int x, int y) {
    union REGS inregs, outregs;

    inregs.h.ah = 0x02;  // Función para mover el cursor
    inregs.h.bh = 0x00;  // Página de pantalla
    inregs.h.dh = y; // Fila y 
    inregs.h.dl = x; // Columna x

    int86(0x10, &inregs, &outregs);
}

//fija el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.
void setcursortype(int tipo_cursor){
    union REGS inregs, outregs;
    inregs.h.ah = 0x01;
    switch(tipo_cursor){
        case 0: //invisible
            inregs.h.ch = 010;
            inregs.h.cl = 000;
            break;
        case 1: //normal
            inregs.h.ch = 010;
            inregs.h.cl = 010;
            break;
        case 2: //grueso
            inregs.h.ch = 000;
            inregs.h.cl = 010;
            break;
    }
    int86(0x10, &inregs, &outregs);
}

// establece el modo de vídeo: 3-texto, 4-gráfico
void setvideomode(BYTE modo){
    union REGS inregs, outregs;
    inregs.h.al = modo;
    inregs.h.ah = 0x00;
    int86(0x10, &inregs, &outregs);
}

//obtiene el modo de video actual
BYTE getvideomode() {
    union REGS inregs, outregs;
    inregs.h.ah = 0x0F; // funcion para obtener el modo de vídeo actual
    int86(0x10, &inregs, &outregs);

    return outregs.h.al; // Retorna el modo de vídeo actual
}

static unsigned char colorTexto = 0x07; //letras gris default
static unsigned char colorFondo = 0x00; //ponemos fondo negro 

//modifica el color de primer plano con que se mostrarán los caracteres
void textcolor(unsigned char color) {
    
    colorTexto = color; //cambiamos color
} 

//modifica el color de fondo con que se mostrarán los caracteres
void textbackground(unsigned char color) {
    colorFondo = color << 4; //para actualizar los ultimos 4 bits
}

//borra toda la pantalla
void clrscr() {
	setvideomode(0x04); //en el modo grafico
	setvideomode(0x02); //en el modo de texto
}

//escribe un carácter en pantalla con el color indicado actualmente
void cputchar(char c) {
    union REGS regs, outregs;
    regs.h.ah = 0x09; //funcion para escribir en pantalla
    regs.h.al = c;    // toma el argumento del caracter c a escribir
    regs.h.bl = colorTexto | colorFondo << 4; //color de texto y fondo introducidos anteriormente
    regs.h.bh = 0x00; 
    regs.x.cx = 1;    // ponemos el caracter n veces
    int86(0x10, &regs, &outregs); 
    return;
}

//obtiene un carácter de teclado y lo muestra en pantalla
int getche() {
    union REGS inregs, outregs;
    inregs.h.ah = 0x00; // funcion para leer un caracter por teclado
    int86(0x16, &inregs, &outregs); 
    cputchar(outregs.h.al); // utilizamos la funcion anterior para mostrar por pantalla el caracter
    return outregs.h.al;
}

// pone un pixel en la coordenada X,Y de color C
void pixel(int x, int y, BYTE C){
    union REGS inregs, outregs;
    inregs.x.cx = x;
    inregs.x.dx = y;
    inregs.h.al = C;
    inregs.h.ah = 0x0C;
    int86(0x10, &inregs, &outregs);
}

void asciiart() {
    gotoxy(1, 1);
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar('o');
    cputchar('\'');
    cputchar('}');
    cputchar('}');
    cputchar(')');
    cputchar('_');
    cputchar('_');
    cputchar('_');
    cputchar('_');
    cputchar('/');
    cputchar('/');
    printf("\n");

    gotoxy(1, 2);
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar('`');
    cputchar('_');
    cputchar('/');
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar(')');
    printf("\n");

    gotoxy(1, 3);
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar(' ');
    cputchar('(');
    cputchar('_');
    cputchar('(');
    cputchar('/');
    cputchar('-');
    cputchar('(');
    cputchar('_');
    cputchar('/');
}




int main() {
    

    //prueba de gotoxy();
    /*
    printf("Moviendo cursor a la posicion (x:10, y:10)\n");
    gotoxy(10,10);
    */
    //prueba de setcursortype()
    /*   clrscr();
    printf("Cambiado el tipo de cursor a NORMAL\n");
    setcursortype(1);*/

    /*
    //prueba de setvideomode() y getvideomode()
    clrscr();
    printf("El modo de video actual es: %d\n", getvideomode());
    printf("Cambio de modo a modo grafico...\n");
    setvideomode(MODOGRAFICO);
    printf("El modo de video actual es: %d\n", getvideomode());

    //prueba de textcolor() y textbackground()
    printf("Cambio color de texto a rojo y fondo azul.\n");
    textcolor(4);
    textbackground(1);
    /*

    //prueba de clrscr() y cputchar()
    printf("Borrando pantalla\n");
    //clrscr();

    printf("Escribiendo por pantalla 'PDIH' \n");
    cputchar('P');
    cputchar('D');
    cputchar('I');
    cputchar('H');

    //prueba de getche()
    printf("Presiona una tecla para continuar...\n");
    getche();

    */

   asciiart();

    return 0;
}