#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QTimer>
#include <QMouseEvent>
#include "mtbasecurvedialog.h"
#include "datatabledialog.h"

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initAppSkin();

public slots:
    void init();
    void slot_savePic(bool);
    void slot_print(bool);
    void slot_showCompareLine(bool);

private slots:

signals:
    void emitaddLineDiagram(QList<CurvDataStruct> &_listdata, QString name, int id, time_t start_time, time_t end_time);

private:
    // Ui::MainWindow *ui;
    mtListThread *m_fetchData;
    HisCurveAccess curve_access;
    mtKDchart *m_kdChart;
    ChartPaintThread *m_paintThread;
    QString resourcePath;
    bool m_bvalue;
    bool isBar;
    bool m_bmark;
    bool m_bcompare;
    QColor m_curColor;
    DatatableDialog *m_tableDialog;
    int m_anaglogIndex;
    int m_row;
    QString m_labeltext;
    QPrinter* m_pPrinter;
    QVector<QColor>*m_linescolorVector;
    QVector<bool>*m_showlineVector;
    QVector<bool>*m_showValueVector;
    QVector<bool>*m_showMarkVector;
    QVector<BaseCurveDialog*>m_baseDlgVector;
    int interval;
    QList<int>insertLineList;

    BaseCurveDialog *m_selectdialog;

};

#endif // MAINWINDOW_H
