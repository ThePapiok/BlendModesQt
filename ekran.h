#ifndef EKRAN_H
#define EKRAN_H

#include <QWidget>



struct rgb{
    int red;
    int green;
    int blue;
};

struct war{
    QImage im;
    rgb (*mix)(rgb,rgb);
    float alfa;
};
class Ekran : public QWidget
{
    Q_OBJECT
public:
        explicit Ekran(QWidget *parent = nullptr);
        void load();
        static rgb normalMix(rgb,rgb);
        static rgb multiplyMix(rgb,rgb);
        static rgb subbtractiveMix(rgb,rgb);
        static rgb additiveMix(rgb,rgb);
        static rgb differenceMix(rgb,rgb);
        void blend(int,int,rgb,rgb,float);
        rgb getPixel(QImage,int,int);
        void setWarstwa(int);
        int getWarstwa();
        QVector<war> lista;
protected:
        void paintEvent(QPaintEvent *);
private:

        QImage im0,im1,im2,im3;
        int warstwa=2;
signals:

};

#endif // EKRAN_H
