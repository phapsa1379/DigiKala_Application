#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

class Message
{

private:

    QString text;
    QString date;
    unsigned long long keySender;
    unsigned long long keyReciever;

public:
    Message();
    ~Message();

    QString getText();
    QString getDate();
    unsigned long long getKeySender();
    unsigned long long getKeyReciever();


    void setText(QString);
    void setDate(QString);
    void setKeySender(unsigned long long);
    void setKeyReciever(unsigned long long);
    void operator=(Message message);

};

#endif // MESSAGE_H
