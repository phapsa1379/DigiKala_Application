#include "Message.h"

#include "ExternalFunctions.h"


Message::Message()
{
    keySender = 0;
    keyReciever = 0;
    text = "";
    date = NowTime();
    return;
}

Message::~Message(){}



QString Message::getText(){

    return text;
}

QString Message::getDate(){

    return date;
}

unsigned long long Message::getKeySender(){

    return keySender;
}

unsigned long long Message::getKeyReciever(){

    return keyReciever;
}








void Message::setText(QString a){

    text = a;
    return;
}

void Message::setDate(QString a){

    date = a;
    return;
}

void Message::setKeySender(unsigned long long a){

    keySender = a;
    return;
}

void Message::setKeyReciever(unsigned long long a){

    keyReciever = a;
    return;
}


void Message::operator=(Message message){

    keySender = message.getKeySender();
    keyReciever = message.getKeyReciever();
    text = message.getText();
    date = message.getDate();
    return;
}


