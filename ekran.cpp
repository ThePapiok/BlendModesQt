#include "ekran.h"
#include <QPainter>
#include <QMouseEvent>
#include <algorithm>
#include <QImage>

using namespace std;

Ekran::Ekran(QWidget *parent)
    : QWidget{parent}
{
    im0=QImage(1215, 717, QImage::Format_RGB32);
    im1=QImage(":/zdj/swain.jpg");
    im2=QImage(":/zdj/orn.jpg");
    im3=QImage(":/zdj/warwick.jpg");
    lista.push_back({im1,normalMix,1});
    lista.push_back({im2,normalMix,1});
    lista.push_back({im3,normalMix,1});
    im0.fill(0);
    load();
}

void Ekran::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(0,0,im0);

}

void Ekran::load()
{
    rgb RgbB,RgbF,RgbMix;
    for(int i=0;i<lista.size();i++)
    {
        for(int j=0;j<im0.height();j++)
        {
            for(int k=0;k<im0.width();k++)
            {
                RgbB=getPixel(im0,k,j);
                RgbF=getPixel(lista[i].im,k,j);
                RgbMix=lista[i].mix(RgbB,RgbF);
                blend(k,j,RgbB,RgbMix,lista[i].alfa);
            }
        }
    }
    update();
}

rgb Ekran::normalMix(rgb B, rgb F)
{
    return F;
}

rgb Ekran::multiplyMix(rgb B, rgb F)
{
    rgb pom;
    pom.red=(B.red*F.red)>>8;
    pom.green=(B.green*F.green)>>8;
    pom.blue=(B.blue*F.blue)>>8;
    return pom;
}

rgb Ekran::subbtractiveMix(rgb B, rgb F)
{
    rgb pom;
    pom.red=max(B.red+F.red-255,0);
    pom.green=max(B.green+F.green-255,0);
    pom.blue=max(B.blue+F.blue-255,0);
    return pom;

}

rgb Ekran::additiveMix(rgb B, rgb F)
{
    rgb pom;
    pom.red=min(B.red+F.red,255);
    pom.green=min(B.green+F.green,255);
    pom.blue=min(B.blue+F.blue,255);
    return pom;

}

rgb Ekran::differenceMix(rgb B, rgb F)
{
    rgb pom;
    pom.red=abs(B.red-F.red);
    pom.green=abs(B.green-F.green);
    pom.blue=abs(B.blue-F.blue);
    return pom;

}

void Ekran::blend(int j,int i,rgb RgbB,rgb RgbMix, float alfa)
{
    rgb RgbKon;
    QRgb kon;
    RgbKon.red=(1-alfa)*RgbB.red+alfa*RgbMix.red;
    RgbKon.green=(1-alfa)*RgbB.green+alfa*RgbMix.green;
    RgbKon.blue=(1-alfa)*RgbB.blue+alfa*RgbMix.blue;
    kon=qRgb((int)RgbKon.red,(int)RgbKon.green,(int)RgbKon.blue);
    im0.setPixel(j,i,kon);
}

rgb Ekran::getPixel(QImage im,int j,int i)
{
    QRgb kolor;
    rgb pom;
    kolor=im.pixel(j,i);
    pom.red=qRed(kolor);
    pom.green=qGreen(kolor);
    pom.blue=qBlue(kolor);
    return pom;
}

void Ekran::setWarstwa(int a)
{
    warstwa=a;
}

int Ekran::getWarstwa()
{
    return warstwa;
}
