#pragma once

#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>

const QString version("0.105");

class Socket : public QObject {
  Q_OBJECT
 public:

  Socket();
  bool connectedToServer();
  bool versionApplication();

 private:

  void sendToServer(QString massege);

  QTcpSocket* p_socket = nullptr;
  QByteArray mData;
  quint16 m_bufer = 0;

  bool m_connect_           = false;
  bool m_version_validator_ = false;

 public slots:
  void sl_readyRead();
  void sl_sendMassege();
};

#endif // SOCKET_H
