#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h> // Para generar números aleatorios

#define WIDTH  30
#define HEIGHT 10

// Requisitos ampliados: Pantalla de presentacion

void pantallaPresentacion() {
    clear();

    mvprintw(1, 1, "P O N G");
    mvprintw(3, 1, "Desarrollado por: Miguel Molinero Martin");
    mvprintw(7, 1, "Controles:");
    mvprintw(8, 3, "Pala izquierda: W (Arriba) y S (Abajo)");
    mvprintw(9, 3, "Pala derecha: ARRIBA y ABAJO");
    mvprintw(11, 1, "Presiona cualquier tecla para comenzar...");

    refresh();
    getch(); // Esperar la entrada del usuario
}

int main(int argc, char *argv[]) {
    int x, y1, y2, i;
    int pelotax, pelotay;
    int maxx, maxy;
    int dir_x, dir_y;
    int jugador1_score, jugador2_score;

    // Inicio de la libreria ncurses
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);


    // Mostrar la pantalla de bienvenida
    pantallaPresentacion();

    // Inicializamos posiciones y puntuaciones
    x = 0;
    y1 = y2 = (LINES - HEIGHT) / 2; //centramos las palas en el medio de la pantalla
    jugador1_score = jugador2_score = 0;
    maxx = getmaxx(stdscr);
    maxy = getmaxy(stdscr);
    pelotax = maxx / 2;
    pelotay = maxy / 2;
    dir_x = 1;
    dir_y = 1;


    while (1) {
        clear();

        // Dibujamos la pelota
        mvprintw(pelotay, pelotax, "O");

        // Dibujamos los jugadores
        for (i = 0; i < HEIGHT; i++) {
            mvprintw(y1 + i, x, "|"); // Paleta izquierda
            mvprintw(y2 + i, maxx - x - 1, "|"); // Paleta derecha
        }

        // Dibujamos los marcadores
        mvprintw(0, 2, "Jugador 1: %d", jugador1_score);
        mvprintw(0, maxx - 15, "Jugador 2: %d", jugador2_score);
        refresh();

        // Inciamos movimiento de la pelota
        pelotax += dir_x;
        pelotay += dir_y;

        // Comprobamos si la pelota toca los limites d ela pantalla
        if (pelotax >= maxx - 1 || pelotax <= 0) {
            dir_x *= -1;
        }
        if (pelotay >= maxy - 1 || pelotay <= 0) {
            dir_y *= -1;
        }

        // Entrada de los jugadores
        int key = getch();
        switch (key) {
            case 'q':
                endwin();
                return 0;
            case 'w':
                if (y1 > 0) y1--;
                break;
            case 's':
                if (y1 < LINES - HEIGHT) y1++;
                break;
            case KEY_UP:
                if (y2 > 0) y2--;
                break;
            case KEY_DOWN:
                if (y2 < LINES - HEIGHT) y2++;
                break;
        }

        // Comprobamos si la bola toca con la pala de los jugadores
        if (pelotax == x + 1 && pelotay >= y1 && pelotay < y1 + HEIGHT) {
            dir_x *= -1;
        } else if (pelotax == maxx - x - 2 && pelotay >= y2 && pelotay < y2 + HEIGHT) {
            dir_x *= -1;
        }

        // Comprobar si la pelota se sale y sumamos puntuacion a los jugadores
        if (pelotax == 0 || pelotax == maxx - 1) {
            if (pelotax == 0) {
                jugador2_score++;
            } else {
                jugador1_score++;
            }
            pelotax = maxx / 2;
            pelotay = maxy / 2;
            // Cambiamos la dirección vertical de forma aleatoria
            dir_y = (rand() % 3) - 1; // Valores aleatorios entre -1, 0, 1
        }
        usleep(50000);
    }

    endwin();
    return 0;
}

