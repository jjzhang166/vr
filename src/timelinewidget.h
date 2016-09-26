/**************************************************************************
This file is part of JahshakaVR, VR Authoring Toolkit
http://www.jahshaka.com
Copyright (c) 2016  GPLv3 Karsten Becker <jahshaka@gmail.com>

This is free software: you may copy, redistribute
and/or modify it under the terms of the GPLv3 License

For more information see the LICENSE file
*************************************************************************/

#ifndef TIMELINEWIDGET_H
#define TIMELINEWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include "scenenode.h"


//https://kernelcoder.wordpress.com/2010/08/25/how-to-insert-ruler-scale-type-widget-into-a-qabstractscrollarea-type-widget/
class TimelineWidget:public QWidget
{
    Q_OBJECT
private:
    int timeToPos(float timeInSeconds);
    float posToTime(int xpos);
public:
    QColor bgColor;
    QColor itemColor;

    QPen linePen;
    QPen cursorPen;

    //float maxTimeInSeconds;
    float rangeStart;
    float rangeEnd;

    //indicates current time
    int cursorPos;
    //double currentTime;

    bool dragging;
    //int scaleRatio;

    //timeline widget doesnt manage lifetime of this pointer
    SceneNode* node;

    float highlightStart;
    float highlightEnd;
    bool drawHighlight;

    TimelineWidget(QWidget* parent);

    float getStartTimeRange();
    float getEndTimeRange();

    void showHighlight(float start,float end);
    void hideHighlight();

    void setSceneNode(SceneNode* node);

    float getTimeAtCursor();
    //void setMaxTimeInSeconds(float time);
    void setTimeRange(float start,float end);
    void setStartTime(float start);
    void setEndTime(float end);
    void setTime(float time);
    void setCursorPos(int x);

    void oldpaintEvent(QPaintEvent *painter);//unused
    void paintEvent(QPaintEvent *painter);
    void mousePressEvent(QMouseEvent* evt);
    void mouseReleaseEvent(QMouseEvent* evt);
    void mouseMoveEvent(QMouseEvent* evt);
    void resizeEvent(QResizeEvent* event);

signals:
    void cursorMoved(float timeInSeconds);

};


#endif // TIMELINEWIDGET_H