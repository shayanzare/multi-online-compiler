#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "highlight.h"

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>
#include <QEventLoop>
#include <QByteArray>
#include <QVariant>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }

    Highlighter *highlighter = new Highlighter(ui->textEdit->document());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->radioButton_2->isChecked()) {
        QEventLoop eventLoop;
        QNetworkAccessManager manager;
        QUrl url("http://ide.geeksforgeeks.org/main.php");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        //send request with header
        QNetworkReply *reply = manager.post(request, "lang=Cpp&code=" + ui->textEdit->toPlainText().toUtf8() + "&input=&save=false");
        eventLoop.exec();

        QString output = reply->readAll();
        qDebug() << output;
        //save to textEdit
//        ui->textEdit_2->setPlainText(output);
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(output.toUtf8(), &err);

        if(doc.isObject())
        {
            QJsonObject obj = doc.object();
            QJsonObject::iterator itr = obj.find("output");
            if(itr == obj.end())
            {
                // object not found.
                qDebug() << "Not Found" ;
                ui->textEdit_2->setText("No Output Found");
            }

            // do something with the found object...
            QJsonValue val = obj.value("output");
            QJsonValue valErr = obj.value("cmpError");
//            qDebug() << val;
            ui->textEdit_2->setText(val.toString());
            ui->textEdit_3->setText(valErr.toString());
        }

    }
    else if (ui->radioButton->isChecked()){
        QEventLoop eventLoop;
        QNetworkAccessManager manager;
        QUrl url("http://ide.geeksforgeeks.org/main.php");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        //send request with header
        QNetworkReply *reply = manager.post(request, "lang=Python&code=" + ui->textEdit->toPlainText().toUtf8() + "&input=&save=false");
        eventLoop.exec();

        QString output = reply->readAll();
        qDebug() << output;
        //save to textEdit
//        ui->textEdit_2->setPlainText(output);
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(output.toUtf8(), &err);

        if(doc.isObject())
        {
            QJsonObject obj = doc.object();
            QJsonObject::iterator itr = obj.find("output");
            if(itr == obj.end())
            {
                // object not found.
                qDebug() << "Not Found" ;
                ui->textEdit_2->setText("No Output Found");
            }

            // do something with the found object...
            QJsonValue val = obj.value("output");
            QJsonValue valErr = obj.value("rntError");
//            qDebug() << val;
            ui->textEdit_2->setText(val.toString());
            ui->textEdit_3->setText(valErr.toString());
        }
    }
    else if (ui->radioButton_3->isChecked()){
        QEventLoop eventLoop;
        QNetworkAccessManager manager;
        QUrl url("http://ide.geeksforgeeks.org/main.php");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        //send request with header
        QNetworkReply *reply = manager.post(request, "lang=Csharp&code=" + ui->textEdit->toPlainText().toUtf8() + "&input=&save=false");
        eventLoop.exec();

        QString output = reply->readAll();
        qDebug() << output;
        //save to textEdit
//        ui->textEdit_2->setPlainText(output);
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(output.toUtf8(), &err);

        if(doc.isObject())
        {
            QJsonObject obj = doc.object();
            QJsonObject::iterator itr = obj.find("output");
            if(itr == obj.end())
            {
                // object not found.
                qDebug() << "Not Found" ;
                ui->textEdit_2->setText("No Output Found");
            }

            // do something with the found object...
            QJsonValue val = obj.value("output");
            QJsonValue valErr = obj.value("cmpError");
//            qDebug() << val;
            ui->textEdit_2->setText(val.toString());
            ui->textEdit_3->setText(valErr.toString());
        }
    }
    else if (ui->radioButton_4->isChecked()){
        QEventLoop eventLoop;
        QNetworkAccessManager manager;
        QUrl url("http://ide.geeksforgeeks.org/main.php");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        //send request with header
        QNetworkReply *reply = manager.post(request, "lang=Java&code=" + ui->textEdit->toPlainText().toUtf8() + "&input=&save=false");
        eventLoop.exec();

        QString output = reply->readAll();
        qDebug() << output;
        //save to textEdit
//        ui->textEdit_2->setPlainText(output);
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(output.toUtf8(), &err);

        if(doc.isObject())
        {
            QJsonObject obj = doc.object();
            QJsonObject::iterator itr = obj.find("output");
            if(itr == obj.end())
            {
                // object not found.
                qDebug() << "Not Found" ;
                ui->textEdit_2->setText("No Output Found");
            }

            // do something with the found object...
            QJsonValue val = obj.value("output");
            QJsonValue valErr = obj.value("cmpError");
//            qDebug() << val;
            ui->textEdit_2->setText(val.toString());
            ui->textEdit_3->setText(valErr.toString());
        }
    }
    else if (ui->radioButton_5->isChecked()){
        QEventLoop eventLoop;
        QNetworkAccessManager manager;
        QUrl url("http://ide.geeksforgeeks.org/main.php");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        //send request with header
        QNetworkReply *reply = manager.post(request, "lang=Perl&code=" + ui->textEdit->toPlainText().toUtf8() + "&input=&save=false");
        eventLoop.exec();

        QString output = reply->readAll();
        qDebug() << output;
        //save to textEdit
//        ui->textEdit_2->setPlainText(output);
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(output.toUtf8(), &err);

        if(doc.isObject())
        {
            QJsonObject obj = doc.object();
            QJsonObject::iterator itr = obj.find("output");
            if(itr == obj.end())
            {
                // object not found.
                qDebug() << "Not Found" ;
                ui->textEdit_2->setText("No Output Found");
            }

            // do something with the found object...
            QJsonValue val = obj.value("output");
            QJsonValue valErr = obj.value("cmpError");
//            qDebug() << val;
            ui->textEdit_2->setText(val.toString());
            ui->textEdit_3->setText(valErr.toString());
        }
    }
    else if (ui->radioButton_6->isChecked()){
        QEventLoop eventLoop;
        QNetworkAccessManager manager;
        QUrl url("http://ide.geeksforgeeks.org/main.php");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        //send request with header
        QNetworkReply *reply = manager.post(request, "lang=Php&code=" + ui->textEdit->toPlainText().toUtf8() + "&input=&save=false");
        eventLoop.exec();

        QString output = reply->readAll();
        qDebug() << output;
        //save to textEdit
//        ui->textEdit_2->setPlainText(output);
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(output.toUtf8(), &err);

        if(doc.isObject())
        {
            QJsonObject obj = doc.object();
            QJsonObject::iterator itr = obj.find("output");
            if(itr == obj.end())
            {
                // object not found.
                qDebug() << "Not Found" ;
                ui->textEdit_2->setText("No Output Found");
            }

            // do something with the found object...
            QJsonValue val = obj.value("output");
            QJsonValue valErr = obj.value("cmpError");
//            qDebug() << val;
            ui->textEdit_2->setText(val.toString());
            ui->textEdit_3->setText(valErr.toString());
        }
    }
    else if (ui->radioButton_7->isChecked()){
        QEventLoop eventLoop;
        QNetworkAccessManager manager;
        QUrl url("http://ide.geeksforgeeks.org/main.php");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
        //send request with header
        QNetworkReply *reply = manager.post(request, "lang=Scala&code=" + ui->textEdit->toPlainText().toUtf8() + "&input=&save=false");
        eventLoop.exec();

        QString output = reply->readAll();
        qDebug() << output;
        //save to textEdit
//        ui->textEdit_2->setPlainText(output);
        QJsonParseError err;
        QJsonDocument doc = QJsonDocument::fromJson(output.toUtf8(), &err);

        if(doc.isObject())
        {
            QJsonObject obj = doc.object();
            QJsonObject::iterator itr = obj.find("output");
            if(itr == obj.end())
            {
                // object not found.
                qDebug() << "Not Found" ;
                ui->textEdit_2->setText("No Output Found");
            }

            // do something with the found object...
            QJsonValue val = obj.value("output");
            QJsonValue valErr = obj.value("cmpError");
//            qDebug() << val;
            ui->textEdit_2->setText(val.toString());
            ui->textEdit_3->setText(valErr.toString());
        }
    }
    else{
        QMessageBox::warning(this,"Error", "Please checkable a language!");
    }
}

void MainWindow::on_actionOpen_File_Source_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Open File"),"/", tr(""));
    //open file
    QFile file(filePath);
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        ui->textEdit->setText(file.readAll());
    }
    else
    {
        QMessageBox::warning(this,"Error :" , "\nError To Opening File!");
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,"About", "Coded By ViRuS007\nTelegram ID : @Msf_Payload");
}
