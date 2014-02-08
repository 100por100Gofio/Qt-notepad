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
#include <QMessageBox>
#include <QToolBar>


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
    void alAcercade();

private:
    //Cuadro de texto.
    QPlainTextEdit* txtEditor_;
    //Barra de menú.
    QMenuBar* mainMenu_;
    //Opción Archivo para la barra de menú.
    QMenu* mnuArchivo_;
    //Acción Abrir del menú Archivo.
    QAction* actArchivoAbrir_;
    //Acción Guardar del menú Archivo.
    QAction* actArchivoGuardar_;
    //Acción Cerrar del menú Archivo.
    QAction* actArchivoCerrar_;

    //Opción Formato para la barra de menú.
    QMenu* mnuFormato_;
    //Acción Fuente del menú Formato.
    QAction* actFormatoFuente_;

    //Opción Editar para la barra de menú.
    QMenu* mnuEditar_;
    //Acción Copiar del menú Editar.
    QAction* actEditarCopiar_;
    //Acción Pegar del menú Editar.
    QAction* actEditarPegar_;
    //Acción Cortar del menú Editar.
    QAction* actEditarCortar_;
    //Acción Deshacer del menú Editar.
    QAction* actEditarDeshacer_;
    //Acción Rehacer del menú Editar.
    QAction* actEditarRehacer_;

    //Opción Ayuda para la barra de menú.
    QMenu* mnuAyuda_;
    //Acción "Acerca de" del menú Ayuda.
    QAction* actAyudaAcercade_;

    QClipboard* portapapeles_;

    //Barra de herramientas.
    QToolBar* tlbPrincipal;

};

#endif // NOTEPADWINDOW_H
