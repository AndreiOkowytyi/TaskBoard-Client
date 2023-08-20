#include <socket.h>

Socket::Socket() {

    this->p_socket = new QTcpSocket(this);
    this->p_socket->connectToHost("192.168.0.107", 80);

    QObject::connect(this->p_socket, SIGNAL(readyRead()), this, SLOT(sl_readyRead()));
    QObject::connect(this->p_socket, &QTcpSocket::disconnected, this->p_socket, [this]()

        {this->p_socket->close();
        this->m_connect_ = false;
    });

    QObject::connect(this->p_socket, &QTcpSocket::connected, this, [this]() {

        this->m_connect_ = true;
        this->sendToServer(version);
    });
}

bool Socket::connectedToServer() { return this->m_connect_; }

bool Socket::versionApplication() { return this->m_version_validator_; }

void Socket::sendToServer(QString message) {

     this->mData.clear();
     QDataStream out(&mData, QIODevice::WriteOnly);
     out.setVersion(QDataStream::Version::Qt_6_0);
     out << quint16(0) << message;
     out.device()->seek(0);
     out << quint16(mData.size() - sizeof(quint16));

     if(p_socket->isOpen())this->p_socket->write(mData);
}

void Socket::sl_readyRead() {

     this->p_socket = (QTcpSocket*)sender();
     QDataStream in(this->p_socket);
     in.setVersion(QDataStream::Version::Qt_6_0);
     if(in.status() == QDataStream::Ok) {

         for(;;) {

             if(this->m_bufer == 0) {

                 if(this->p_socket->bytesAvailable() < 2) break;
                 in >> this->m_bufer;
             }

             if(this->p_socket->bytesAvailable() < this->m_bufer) break;

             QString str;

             in >> str;
             this->p_socket = 0;
             break;
         }
     }
}


void Socket::sl_sendMassege() {

     this->sendToServer("");
}
