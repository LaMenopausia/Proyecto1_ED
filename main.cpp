#include "Struct.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

<<<<<<< HEAD
int main(int argc, char** argv) {
    /*Cola<int> * col = new Cola<int>();
	col->push(1);
	col->push(2);
	col->push(3);
	col->push(4);
	col->push(5);
	col->print();
    int a = col->pull()->data;
    cout << " Eliminado: " << a;

	ListaCircular * lc = new ListaCircular();
	lc->insertar("Paquetico",100);
	lc->insertar("Tubo",250);
	lc->insertar("Paquete",4);
	int galletas = lc->totalGalletas();
    cout << "Total de galletas: " << galletas;
    */
	return 0;
=======
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
>>>>>>> Kenneth
}
