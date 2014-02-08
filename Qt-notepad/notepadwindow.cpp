#include "notepadwindow.h"

//Constructor
NotepadWindow::NotepadWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //Establecemos el tamaño inicial de la ventana
    this->setGeometry(30, 30, 800, 600);

    //Establecemos el título de la ventana
    this->setWindowTitle(tr("Super editor de texto"));

    txtEditor_= new QPlainTextEdit(this);//this indica el padre. toda clase en QT tiene un padre
                                           // que siempre será otro objeto de QT.

    //Se centra el cuadro de texto
    setCentralWidget(txtEditor_);

    //Inicializamos los menús
    mainMenu_ = new QMenuBar(this);

    //Coloca la barra de menú correctamente.
    setMenuBar(mainMenu_);

    //----ARCHIVO----------
    //La primera opción se llamará "Archivo",
    // y se accederá a ella pulsando Alt + r, porque hemos colocado el & delante de la "r".
    //La función tr traduce desde archivos .po donde hemos establecido los diccionarios.
    //Es decir, la cadena "Archivo" podría ser traducida por "File".
    mnuArchivo_ = new QMenu(tr("A&rchivo"), this);

    //Se añade la opción Archivo a la barra de menú.
    mainMenu_->addMenu(mnuArchivo_);

    //Se inicializa la acción Abrir.
    actArchivoAbrir_ = new QAction(tr("&Abrir"), this);
    actArchivoAbrir_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
    //Se añade la acción Abrir al menú Archivo.
    mnuArchivo_->addAction(actArchivoAbrir_);

    //Se inicializa la acción Guardar.
    actArchivoGuardar_ = new QAction(tr("&Guardar"), this);
    actArchivoGuardar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_G));
    //Se añade la acción Guardar al menú Archivo.
    mnuArchivo_->addAction(actArchivoGuardar_);

    //Se inicializa la acción Cerrar.
    actArchivoCerrar_ = new QAction(tr("&Cerrar"), this);
    actArchivoCerrar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
    //Se añade la acción Cerrar al menú Archivo.
    mnuArchivo_->addAction(actArchivoCerrar_);

    //-------------------


    //----EDITAR----------
    mnuEditar_ = new QMenu(tr("&Editar"), this);
    //Se añade la opción Editar a la barra de menú.
    mainMenu_->addMenu(mnuEditar_);

    actEditarCopiar_ = new QAction(tr("&Copiar"), this);
    actEditarCopiar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    mnuEditar_->addAction(actEditarCopiar_);

    actEditarPegar_ = new QAction(tr("&Pegar"), this);
    actEditarPegar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    mnuEditar_->addAction(actEditarPegar_);

    actEditarCortar_ = new QAction(tr("Cor&tar"), this);
    actEditarCortar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    mnuEditar_->addAction(actEditarCortar_);

    actEditarDeshacer_ = new QAction(tr("&Deshacer"), this);
    actEditarDeshacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
    mnuEditar_->addAction(actEditarDeshacer_);

    actEditarRehacer_ = new QAction(tr("&Rehacer"), this);
    actEditarRehacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
    mnuEditar_->addAction(actEditarRehacer_);
    //--------------------


    //----FORMATO----------
    mnuFormato_ = new QMenu(tr("&Formato"), this);
    //Se añade la opción Formato a la barra de menú.
    mainMenu_->addMenu(mnuFormato_);

    actFormatoFuente_ = new QAction(tr("&Fuente"), this);
    actFormatoFuente_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
    mnuFormato_->addAction(actFormatoFuente_);
    //--------------------

    //----AYUDA----------
    mnuAyuda_ = new QMenu(tr("A&yuda"), this);
    //Se añade la opción Ayuda a la barra de menú.
    mainMenu_->addMenu(mnuAyuda_);

    actAyudaAcercade_ = new QAction(tr("Ac&erca de..."), this);
    actAyudaAcercade_->setShortcut(QKeySequence(Qt::Key_F1));
    mnuAyuda_->addAction(actAyudaAcercade_);
    //--------------------



    //CONEXIONES: conectamos las acciones de los menus con nuestros slots.

    //Al pinchar sobre Abrir se invocará el slot (método) alAbrir().
    connect(actArchivoAbrir_, SIGNAL(triggered()), this, SLOT(alAbrir()));
    //Al pinchar sobre Guardar se invocará el slot (método) alGuardar().
    connect(actArchivoGuardar_, SIGNAL(triggered()), this, SLOT(alGuardar()));
    //Al pinchar sobre Cerrar se invocará el slot close() de esta ventana (this->close()),
    // que es un método predefinido y que podemos invocar.
    connect(actArchivoCerrar_, SIGNAL(triggered()), this, SLOT(close()));

    //Al pinchar sobre Copiar se invocará al slot copy() de txtEditor_,
    // que es un método ya predefinido. Es decir, los cuadros de texto ya tienen
    // un método para copiar y que podemos referenciar.
    connect(actEditarCopiar_, SIGNAL(triggered()), txtEditor_, SLOT(copy()));
    //Al pinchar sobre Pegar se invocará al slot paste() de txtEditor_,
    // que es un método ya predefinido. Es decir, los cuadros de texto ya tienen
    // un método para pegar y que podemos referenciar.
    connect(actEditarPegar_, SIGNAL(triggered()), txtEditor_, SLOT(paste()));
    //Al pinchar sobre Cortar se invocará al slot cut() de txtEditor_,
    // que es un método ya predefinido. Es decir, los cuadros de texto ya tienen
    // un método para cortar y que podemos referenciar.
    connect(actEditarCortar_, SIGNAL(triggered()), txtEditor_, SLOT(cut()));
    //Al pinchar sobre Deshacer se invocará al slot undo() de txtEditor_,
    // que es un método ya predefinido. Es decir, los cuadros de texto ya tienen
    // un método para deshacer y que podemos referenciar.
    connect(actEditarDeshacer_, SIGNAL(triggered()), txtEditor_, SLOT(undo()));
    //Al pinchar sobre Rehacer se invocará al slot redo() de txtEditor_,
    // que es un método ya predefinido. Es decir, los cuadros de texto ya tienen
    // un método para rehacer y que podemos referenciar.
    connect(actEditarRehacer_, SIGNAL(triggered()), txtEditor_, SLOT(redo()));

    //Al pinchar sobre Fuente se invocará el slot (método) alFuente().
    connect(actFormatoFuente_, SIGNAL(triggered()), this, SLOT(alFuente()));

    //Al pinchar sobre "Acerca de" se invocará el slot (método) alAcercade().
    connect(actAyudaAcercade_, SIGNAL(triggered()), this, SLOT(alAcercade()));



}

NotepadWindow::~NotepadWindow()
{
    //El destructor no hace falta implementarlo.
    //Qt se encargar de liberar la memoria.
    //Al crear un objeto como se ha indicado que su padre sea
    // esta clase (this), al liberar el padre se liberaran los hijos.
}

void NotepadWindow::alAbrir()
{
    QString nombreArchivo;
    //Se invoca un explorador de archivos para buscar el archivo que queremos
    // abrir.
    //El parámetro "" indicaría la ruta donde se inicia la búsqueda.
    //Al seleccionarlo se guardará su nombre en nombreArchivo.
    nombreArchivo = QFileDialog::getOpenFileName(this,
                                                 tr("Abrir archivo de texto plano"),
                                                 "",
                                                 tr("Archivo de texto plano (*.txt)"));
    //Se verifica que no se haya cancelado el
    // cuadro de diálogo.
    if (nombreArchivo != "")
    {
        //Intentamos abrir el archivo.
        QFile archivo;
        //Se inicia la variable archivo con el archivo seleccionado.
        archivo.setFileName(nombreArchivo);
        //Se verifica que se ha abierto correctamente.
        if (archivo.open((QFile::ReadOnly)))
        {
            //Si se pudo abrir el archivo lo leemos y lo colocamos
            // en el cuadro de texto.
            txtEditor_->setPlainText(archivo.readAll());
            //Se cierra el archivo.
            archivo.close();
        }
    }
}


void NotepadWindow::alGuardar()
{
    //Mostramos un diágolo de guardado de ficheros y almacenamos
    QString nombreArchivo;
    //Se invoca un explorador de archivos para buscar el archivo en el
    // que guardaremos los cambios.
    nombreArchivo = QFileDialog::getSaveFileName(this,
                                                 tr("Guardar Archivo"),
                                                 "",
                                                 tr("Archivo de texto plano (*.txt)"));
    //Se verifica que no se haya cancelado el
    // cuadro de diálogo.
    if (nombreArchivo != "")
    {
        //Intentamos abrir el archivo.
        QFile archivo;
        //Se inicia la variable archivo con el archivo seleccionado.
        archivo.setFileName(nombreArchivo);
        //Se abre en modo escritura y si existe se machará el contenido.
        //Se verifica que se ha abierto correctamente.
        if (archivo.open((QFile::WriteOnly | QFile::Truncate)))
        {
            //Si se pudo abrir el archivo, escribimos el contenido
            // en el cuadro de texto.
            archivo.write(txtEditor_->toPlainText().toUtf8());
            //Se cierra el archivo.
            archivo.close();
        }
    }
}

void NotepadWindow::alFuente()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, txtEditor_->font(), this);
    if (ok) {
        // Si el usuario hizo click en OK, se establece la fuente seleccionada
        txtEditor_->setFont(font);
    }
}

void NotepadWindow::alAcercade()
{
       QMessageBox messageAcercade;
       messageAcercade.setText("Editor creado en el curso de Qt");
       messageAcercade.exec();

}
