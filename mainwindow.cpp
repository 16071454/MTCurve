#include "mainwindow.h"
#include <QSizePolicy>
#include <QVboxLayout>
#include "guibaselib/commontitlebar.h"
#include "guibaselib/appfunctions.h"
MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent)
{
	setupUi(this);


	BaseCurveDialog *dialog1 = new BaseCurveDialog(this);
	BaseCurveDialog *dialog2 = new BaseCurveDialog(this);
	//BaseCurveDialog *dialog3 = new BaseCurveDialog(this);
	QSize wsize = this->geometry().size();
	dialog1->setMinimumHeight(wsize.height()/2);
	dialog2->setMinimumHeight(wsize.height()/2);
	dialog1->setMaximumHeight(wsize.height());
	dialog2->setMaximumHeight(wsize.height());
	verticalLayout_2->addWidget(dialog1);
	verticalLayout_2->addWidget(dialog2);
	connect(dialog1, SIGNAL(otherHide(bool)), dialog2, SLOT(slot_hide(bool)));
	connect(dialog2, SIGNAL(otherHide(bool)), dialog1, SLOT(slot_hide(bool)));
	showMaximized();
}

MainWindow::~MainWindow()
{
	//delete m_fetchData;
    //delete ui;
}

void MainWindow::init()
{
	
}

void MainWindow::initAppSkin()
{
	//构造图标路径
	QString strMtpDir = CMCParamMgr::getMtpDir();
	QString m_strIconPath = strMtpDir + "/resource/bmp/mtcurve/";

	//读取qss皮肤文件
	QString prodir = QString(getenv(SYSTEM_ROOT_DIR));
	QString curPath = QDir::currentDirPath();
	QFile file(prodir + "/resource/bmp/mtcurve/mtcurve.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = tr(file.readAll());
	styleSheet.replace("%skin%", m_strIconPath.replace('\\', '/'));
	qApp->setStyleSheet(styleSheet);
	file.close();
}

void MainWindow::slot_savePic(bool)
{
	QString gcdir = getenv(SYSTEM_ROOT_DIR);
	QString imageFilePath = QFileDialog::getSaveFileName(this, tr("Save File"),
		gcdir,
		tr("PNG (*.png )"));

	return ;
}

void MainWindow::slot_print(bool)
{
	if (m_pPrinter == NULL)
	{
		m_pPrinter = new QPrinter;
	}

	QPrintDialog dlg(m_pPrinter);
	dlg.setWindowTitle(QObject::tr("打印曲线"));
}

void MainWindow::slot_showCompareLine(bool)
{

	m_bcompare = true;
}

