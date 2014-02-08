#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QFontDialog>
#include <QClipboard>

class NotepadWindow : public QMainWindow
{
    Q_OBJECT

public:
    NotepadWindow(QWidget *parent = 0);
    ~NotepadWindow();

private slots:
    void alAbrir();
    void alGuardar();
    void alFuente();

private:
    //Cuadro de texto.
    QPlainTextEdit* txtEditor_;
    //Barra de menú.
    QMenuBar* mainMenu_;
    //Opción Archivo para la barra de menú. .
    QMenu* mnuArchivo_;
    //Acción Abrir del menú Archivo.
    QAction* actArchivoAbrir_;
    //Acción Guardar del menú Archivo.
    QAction* actArchivoGuardar_;
    //Opción Formato para la barra de menú. .
    QMenu* mnuFormato_;
    //Acción Fuente del menú Formato.
    QAction* actFormatoFuente_;
    //Opción Editar para la barra de menú. .
    QMenu* mnuEditar_;
    //Acción Copiar del menú Editar.
    QAction* actEditarCopiar_;
    //Acción Pegar del menú Editar.
    QAction* actEditarPegar_;
    QClipboard* portapapeles_;

};

#endif // NOTEPADWINDOW_H
