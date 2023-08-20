//#include "mainwindow.h"

#include <QApplication>

//#include <QRandomGenerator>

#include <iostream>
//#include "encryption.h"
#include "formregistration.h"

int main(int argc, char *argv[])
{


//    ProtocolD_H Client_1(Generation::generationIndex);
//    ProtocolD_H Client_2(Generation::noGenerationIndex);

//    Client_2.indexStartClient(Client_1.getindexStartKey());

//    Client_1.indexResultClient(Client_2.getindexResultKey());
//    Client_2.indexResultClient(Client_1.getindexResultKey());

//    Client_1.generationKey();
//    Client_2.generationKey();

//    std::cout << Client_1.getindexStartKey() << std::endl<<std::endl<<std::endl;
//    std::cout << Client_2.getindexStartKey() << std::endl<<std::endl<<std::endl;

//    std::cout << Client_1.getindexResultKey() << std::endl << std::endl<<std::endl;
//    std::cout << Client_2.getindexResultKey() << std::endl << std::endl<<std::endl;

//    Encryption aes_1(&Client_1);

//    std::cout <<"111" << std::endl << std::endl;

//    Encryption aes_2(&Client_2);

//    std::cout <<"222" << std::endl << std::endl;

//    std::string str("ASD");


//    std::string enc = aes_1.encryptionData(str);

//    std::cout <<"333" << std::endl << std::endl;

//    std::cout << enc << std::endl << std::endl<<std::endl;

//    std::cout << aes_2.decipherData(enc);

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

 QApplication a(argc, argv);
 FormRegistration as;
 as.show();

    return a.exec();
}
