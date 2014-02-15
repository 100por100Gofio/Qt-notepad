#include "notepadwindow.h"

//Constructor
NotepadWindow::NotepadWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //Establecemos el tamaño inicial de la ventana
    this->setGeometry(30, 30, 800, 600);

    //Establecemos el título de la ventana
    this->setWindowTitle(tr("Editor de texto"));

    txtEditor_= new QTextEdit(this);//"this" indica el padre. toda clase en QT tiene un padre
                                           // que siempre será otro objeto de QT.    

    //Se centra el cuadro de texto
    setCentralWidget(txtEditor_);


    //--------MENÚ PRINCIPAL--------
    //------------------------------

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
    //Teclas de acceso rápido.
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

    //Se puede añadir un icono a cada acción. La imagen se encuentra en la rama de los recursos.
    QIcon* icono = new QIcon(":/iconos/Recursos/iconos/camera-photo.png");
    actEditarCopiar_ = new QAction(*icono, tr("&Copiar"), this);
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
    //--------------------


    //-----BARRA DE HERRAMIENTAS-----
    //-------------------------------

    //Se inicializa la barra de herramientas.
    tlbPrincipal_ = new QToolBar(this);

    //Se añade la barra de herramientas a esta ventana principal.
    this->addToolBar(tlbPrincipal_);
    //
    this->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    //Se añade la acción copiar a la barra de herramientas, que ya se había creado para
    // el menú Editar.
    tlbPrincipal_->addAction(actEditarCopiar_);

    //Se inicializa y se añade la acción "Negrita" a la barra de herramientas.
    //Se usa el mismo icono que para la acción copiar (por que no se han añadido más iconos).
    actTlbNegrita_ = new QAction(*icono, tr("Negrita"), this);
    tlbPrincipal_->addAction(actTlbNegrita_);

    //Se inicializa y se añade la acción "Cursiva" a la barra de herramientas.
    //Se usa el mismo icono que para la acción copiar (por que no se han añadido más iconos).
    actTlbCursiva_ = new QAction(*icono, tr("Cursiva"), this);
    tlbPrincipal_->addAction(actTlbCursiva_);

    //Se inicializa y se añade la acción "Subrayado" a la barra de herramientas.
    //Se usa el mismo icono que para la acción copiar (por que no se han añadido más iconos).
    actTlbSubrayado_ = new QAction(*icono, "Subrayado", this);
    tlbPrincipal_->addAction(actTlbSubrayado_);
    //--------------------
    //--------------------


    //CONEXIONES: conectamos las acciones de los menus con nuestros slots.

    //--------MENÚ PRINCIPAL--------
    //------------------------------

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
    //--------------------
    //--------------------


    //-----BARRA DE HERRAMIENTAS-----
    //-------------------------------

    //Al pinchar sobre "Negrita" se invocará el slot (método) alNegrita().
    connect(actTlbNegrita_, SIGNAL(triggered()), this, SLOT(alNegrita()));

    //Al pinchar sobre "Cursiva" se invocará el slot (método) alCursiva().
    connect(actTlbCursiva_, SIGNAL(triggered()), this, SLOT(alCursiva()));

    //Al pinchar sobre "Subrayado" se invocará el slot (método) alSubrayado().
    connect(actTlbSubrayado_, SIGNAL(triggered()), this, SLOT(alSubrayado()));
    //--------------------
    //--------------------

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
        // Si el usuario hizo click en OK, se establece la fuente escogida.

        //Si hay texto seleccionado, la fuente sólo se aplica a esa selección.
        if (txtEditor_->textCursor().hasSelection())
        {
            QTextCharFormat formatoText;
            formatoText.setFont(font);
            txtEditor_->textCursor().setCharFormat(formatoText);
        }
        else
            txtEditor_->setFont(font);
    }
}

//Se muestra un message box con un mensaje cualquiera.
void NotepadWindow::alAcercade()
{
       QMessageBox messageAcercade;
       messageAcercade.setText("Editor creado en el curso de Qt");
       messageAcercade.exec();       
}

//Se establece o se quita la Negrita.
void NotepadWindow::alNegrita()
{
    QTextCharFormat formatoText;

    //Si hay texto seleccionado, el cambio sólo se aplica a dicha selección.
    if (txtEditor_->textCursor().hasSelection())
    {
        //Si la fuente ya está en negrita se quita.
        //Si no está en negrita se establece como tal.
        formatoText.setFontWeight((txtEditor_->textCursor().charFormat().fontWeight() == QFont::Bold) ? QFont::Normal : QFont::Bold);

        //Se usa "mergeCharFormat" en lugar de "setCharFormat" para combinar con otras opciones
        // que ya pueden estar establecidas como cursiva o subrayado.
        txtEditor_->textCursor().mergeCharFormat(formatoText);
    }
    //Si no hay texto seleccionado, el cambio afectará a lo que se escriba a partir de ahora.
    else
    {
        //Si la fuente ya está en negrita se quita.
        //Si no está en negrita se establece como tal.
        formatoText.setFontWeight((txtEditor_->currentCharFormat().fontWeight() == QFont::Bold) ? QFont::Normal : QFont::Bold);

        //Se usa "mergeCharFormat" en lugar de "setCharFormat" para combinar con otras opciones
        // que ya pueden estar establecidas como cursiva o subrayado.
        txtEditor_->mergeCurrentCharFormat(formatoText);
    }
}


//Se establece o se quita la Cursiva.
void NotepadWindow::alCursiva()
{
    QTextCharFormat formatoText;

    //Si hay texto seleccionado, el cambio sólo se aplica a dicha selección.
    if (txtEditor_->textCursor().hasSelection())
    {
        //Si la fuente ya está en cursiva se quita.
        //Si no está en cursiva se establece como tal.
        formatoText.setFontItalic(txtEditor_->textCursor().charFormat().fontItalic() ? false : true);

        //Se usa "mergeCharFormat" en lugar de "setCharFormat" para combinar con otras opciones
        // que ya pueden estar establecidas como negrita o subrayado.
        txtEditor_->textCursor().mergeCharFormat(formatoText);
    }
    //Si no hay texto seleccionado, el cambio afectará a lo que se escriba a partir de ahora.
    else
    {
        //Si la fuente ya está en cursiva se quita.
        //Si no está en cursiva se establece como tal.
        formatoText.setFontItalic(txtEditor_->currentCharFormat().fontItalic() ? false : true);

        //Se usa "mergeCharFormat" en lugar de "setCharFormat" para combinar con otras opciones
        // que ya pueden estar establecidas como negrita o subrayado.
        txtEditor_->mergeCurrentCharFormat(formatoText);
    }
}


//Se establece o se quita el Subrayado.
void NotepadWindow::alSubrayado()
{
    QTextCharFormat formatoText;

    //Si hay texto seleccionado, el cambio sólo se aplica a dicha selección.
    if (txtEditor_->textCursor().hasSelection())
    {
        //Si la fuente ya está subrayada se quita.
        //Si no está subrayada se establece como tal.
        formatoText.setFontUnderline(txtEditor_->textCursor().charFormat().fontUnderline() ? false : true);

        //Se usa "mergeCharFormat" en lugar de "setCharFormat" para combinar con otras opciones
        // que ya pueden estar establecidas como negrita o cursiva.
        txtEditor_->textCursor().mergeCharFormat(formatoText);
    }
    //Si no hay texto seleccionado, el cambio afectará a lo que se escriba a partir de ahora.
    else
    {
        //Si la fuente ya está subrayada se quita.
        //Si no está subrayada se establece como tal.
        formatoText.setFontUnderline(txtEditor_->currentCharFormat().fontUnderline() ? false : true);

        //Se usa "mergeCharFormat" en lugar de "setCharFormat" para combinar con otras opciones
        // que ya pueden estar establecidas como negrita o cursiva.
        txtEditor_->mergeCurrentCharFormat(formatoText);
    }
}
