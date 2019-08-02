#include "mylinediagram.h"
#include <QPainter>
#include <QMessageBox>

MyLineDiagram::MyLineDiagram(QWidget* parent /*= 0*/, KDChart::CartesianCoordinatePlane* plane /*= 0*/)
{
    setMouseTracking(true);
    b_show = false;
}

void MyLineDiagram::setshow(bool _isshow)
{
    b_show = _isshow;
}

void MyLineDiagram::setShowValue(bool _isshow)
{
    b_showvalue = _isshow;
}

void MyLineDiagram::setShowMark(bool _isshow)
{
    b_showmark = _isshow;
}

void MyLineDiagram::mouseDoubleClickEvent(QMouseEvent *event)
{
    QPointF pos = event->posF();
    QModelIndex index = indexAt(pos.toPoint());
    if (event->button() == Qt::LeftButton  && index.isValid())
    {
        int id = this->getId();
        DatatableDialog _dataDlg;
        TableModel *model = this->getmodel();
        _dataDlg.setTitile(this->objectName());
        _dataDlg.setModal(*model);
        _dataDlg.setselectrow(index.row());
        _dataDlg.exec();
    }
}

