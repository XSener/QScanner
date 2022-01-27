#include "scanner.h"
#include "ui_scanner.h"
#include <QtDebug>

Scanner::Scanner(QWidget *parent) : QWidget(parent), ui(new Ui::Scanner)
{
    ui->setupUi(this);
}

Scanner::~Scanner()
{
    delete ui;
}


void Scanner::on_scanButton_clicked()
{
   ui->portStatusDisplay->clear();
   m_ports.clear();                                                              // cleart die Ports bei mehreren durchgängen notwendig

   m_hostname = ui->hostName->text();
   m_portsStr = ui->portsToScan->text();                                        //speichert in m_portsStr den text der in der Ui portsToScan
   
   QStringList splitedPorts = m_portsStr.split(".");                              // splitet den String der in portsToScan steht in die einzelnen Zahlen

   for(auto num : splitedPorts)                                                     // for schleife mit einer List oder Vektor geht so lange durch bis nix mehr drinnen steht
   {

           m_ports.push_back(num.toInt());                        // toInt macht den String zu einem Int in diesem fall a
    }

   m_socket = new QTcpSocket(this);

   for(auto port : m_ports)
   {
        m_socket->connectToHost(m_hostname, port);

        if(!m_socket->waitForConnected(1000))
        {
            ui->portStatusDisplay->append("port: " + QString::number(port) + " is not connected");
        }
        else
        {
            m_socket->disconnectFromHost();
            ui->portStatusDisplay->append("port: " + QString::number(port) + " is connected");        // QString::number wandelt zu einem String um // append fügt in die TextBox den String hinein
        }


   }
}
