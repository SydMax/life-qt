/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include "renderarea.h"

#include <QPainter>
#include <iostream>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    antialiased = false;
    transformed = false;
    pixmap.load(":/images/qt-logo.png");

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

//    lifeField[fieldSize][fieldSize] = {0};   //So wrong!

//    for (int i=8; i<12; i++)      // create start pattern
//    {
//        for (int j=8; j<10; j++)
//        {
//            lifeField[i][j]=1;
//        }
//    }
    lifeField[10][10]=1;
    lifeField[11][10]=1;
    lifeField[12][10]=1;
    lifeField[12][9]=1;
    lifeField[11][8]=1;

    lifeField[8][8]=1;
    lifeField[9][10]=1;
    lifeField[7][9]=1;
    lifeField[6][11]=1;
    lifeField[10][11]=1;

    lifeField[1][3]=1;
    lifeField[4][2]=1;
    lifeField[2][4]=1;
    lifeField[5][1]=1;
    lifeField[6][2]=1;
//    for (int i=0; i<fieldSize; i++)
//    {
//        for (int j=0; j<fieldSize; j++)
//        {
//            std::cout << lifeField[j][i];
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;

}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 400);
}

void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}

//void RenderArea::drawFieldFromArray(const unsigned int (&field)[fieldSize][fieldSize], QPainter &painter)
//{
////    const int cellSize = 10;
////    QPainter painter(this);
////    painter.setPen(palette().dark().color());
////    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));

//    for (int i=0; i<fieldSize; i++)
//    {
//        for (int j=0; j<fieldSize; j++)
//        {
//            if (field[i][j]==1)
//            {
//            QRect cellSquare(i*cellSize,j*cellSize,cellSize,cellSize);
//            painter.drawRect(cellSquare);
//            }
//        }
//    }
//}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setPen(palette().dark().color());
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    if (antialiased)
    painter.setRenderHint(QPainter::Antialiasing, true);

//    QRect rect(10, 20, 10, 10);
//    painter.drawRect(rect);
//    QRect rect2(50, 50, 10, 10);
//    painter.drawRect(rect2);

//    drawFieldFromArray(RenderArea::lifeField, painter);
//    lifeFieldUpdate(RenderArea::lifeField);

    const int cellSize = 10;
    QRect cellSquare[fieldSize][fieldSize];
    for (int i=0; i<fieldSize; i++)
    {
        for (int j=0; j<fieldSize; j++)
        {
            if (lifeField[i][j]==1)
            {
            cellSquare[i][j] = QRect(i*cellSize,j*cellSize,cellSize,cellSize);
            painter.drawRect(cellSquare[i][j]);
            }
        }
    }



    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}
