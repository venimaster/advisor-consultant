#include "mainwindow.h"

MainWindow::MainWindow()
{
     QTextCodec *codec = QTextCodec::codecForName("UTF8");
     QTextCodec::setCodecForTr(codec);

    // actionExit = new QAction(tr("В&ыход"), this);
    // actionExit->setStatusTip(tr("Выход из программы"));
    // actionExit->setShortcut(tr("Ctrl+Q"));
    // connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

     actionAbout = new QAction(tr("About"), this);
     actionAbout->setStatusTip(tr("Program info"));
     connect(actionAbout, SIGNAL(triggered()), this, SLOT(slotAbout()));

  //   menuFile = menuBar()->addMenu(tr("&Файл"));
  //   menuFile->addAction(actionExit);
     menuFile = menuBar()->addMenu(tr("Help"));
     menuFile->addAction(actionAbout);

     labelMenu = new QLabel(statusBar());

     statusBar()->setSizeGripEnabled(true);
     statusBar()->addWidget(labelMenu, 1);

     mainWidget = new QWidget();
     setCentralWidget(mainWidget);

     tableWidget = new QTableWidget();
     tableWidget->setColumnCount(2);
     tableWidget->setColumnWidth(0,200);
     tableWidget->setColumnWidth(1,200);
     //tableWidget->setColumnWidth(2,50);
     tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("ID")));
     tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("State")));
    // tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("String")));
    // tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Integer")));
     tableWidget->setShowGrid(true);
     tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
     tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
     //tableWidget->setColumnHidden(0, true);

     butAdd = new QPushButton(tr("Add"));
     butAdd->setStatusTip(tr("Add data"));
     connect(butAdd, SIGNAL(clicked()), this, SLOT(slotAdd()));

     butDelete = new QPushButton(tr("Delete"));
     butDelete->setStatusTip(tr("Delete data"));
     connect(butDelete, SIGNAL(clicked()), this, SLOT(slotDelete()));

     lineEdit = new QLineEdit();

     spinBox = new QSpinBox();

     vlayout = new QVBoxLayout;
     hlayout = new QHBoxLayout;

     vlayout->addWidget(tableWidget);
     hlayout->addWidget(lineEdit);
     hlayout->addWidget(spinBox);
     hlayout->addStretch(1);
     hlayout->addWidget(butAdd);
     hlayout->addWidget(butDelete);
     vlayout->addLayout(hlayout);
     mainWidget->setLayout(vlayout);

     db = QSqlDatabase::addDatabase("QMYSQL");
     db.setDatabaseName("inputdb");
     db.setHostName("localhost");

     db.setUserName("root");

    //db.setPassword("123");


     if (!db.open())
     {
         QMessageBox::warning( 0 , "Ошибка!", db.lastError().databaseText());
     }

     RefreshTable();
}

MainWindow::~MainWindow()
{
     db.close();
     db.removeDatabase(db.connectionName());

     delete(hlayout);
     delete(vlayout);
     delete(spinBox);
     delete(lineEdit);
     delete(butDelete);
     delete(butAdd);
     delete(tableWidget);
     delete(mainWidget);
     delete(labelMenu);
     delete(actionAbout);
     delete(actionExit);
}

void MainWindow::RefreshTable()
{
     int n = tableWidget->rowCount();
     for( int i = 0; i < n; i++ ) tableWidget->removeRow( 0 );

     QSqlQuery query;
     query.exec("SELECT * FROM `table`;");

     while (query.next())
     {
          tableWidget->insertRow(0);
          tableWidget->setItem(0, 0, new QTableWidgetItem(query.value(0).toString()));
          tableWidget->setItem(0, 1, new QTableWidgetItem(query.value(1).toString()));
          //tableWidget->setItem(0, 2, new QTableWidgetItem(query.value(2).toString()));
         // tableWidget->setItem(0, 3, new QTableWidgetItem(query.value(3).toString()));
          tableWidget->setRowHeight(0, 20);
     }
}

void MainWindow::slotAdd()
{
     QSqlQuery query;
     query.prepare("INSERT INTO `table` VALUES (:identifier, :st);");
     query.bindValue(":identifier", spinBox->value());
     query.bindValue(":st", lineEdit->text());
     query.exec();
     RefreshTable();
}

void MainWindow::slotDelete()
{
     if(tableWidget->currentIndex().row() >= 0)
     {
          QSqlQuery query;
          query.prepare("DELETE FROM `table` WHERE ID = :id;");
          query.bindValue(":id", tableWidget->item(tableWidget->currentIndex().row(), 0)->text());
          query.exec();
          RefreshTable();
     }
}

void MainWindow::slotAbout()
{
     QMessageBox::about( 0 , tr("About"), tr("Info"));
}
