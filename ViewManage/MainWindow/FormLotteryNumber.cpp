#include "FormLotteryNumber.h"
#include "ui_FormLotteryNumber.h"
#include <QPainter>

FormLotteryNumber::FormLotteryNumber(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLotteryNumber)
{
    ui->setupUi(this);

    m_iSpacing = 3;
    m_listNumBgColor = {"#e6de01","#0092e1","#4b4b4b","#fe7501", "#17e1e1",
                   "#5333ff","#bfbfbf","#ff2600","#780a01","#07be01"};
}

FormLotteryNumber::~FormLotteryNumber()
{
    delete ui;
}

void FormLotteryNumber::SetLotteryNumbers(QStringList list)
{
    m_listLotteryNumbers = list;
}

void FormLotteryNumber::paintEvent(QPaintEvent *event)
{
    int iwidth = this->width();
    int iheight = this->height();
    int iCount = m_listLotteryNumbers.count();
    iwidth = iwidth / iCount ;
    int iRadius = qMin(iwidth, iheight) - m_iSpacing;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);

    QPen    penText(Qt::white);
    QPen    penEllipse;
    painter.setFont(QFont("Microsoft YaHei", 14, QFont::Bold));

    int xp = m_iSpacing;
    for(QString qstrNum : m_listLotteryNumbers)
    {
        int iNum = qstrNum.toInt() - 1;

        QRect rect(xp,1, iRadius, iRadius);
        QColor clBg(m_listNumBgColor[iNum]);
        penEllipse.setColor(clBg);
        painter.setPen(penEllipse);
        painter.setBrush(QBrush(clBg));
        painter.drawEllipse(rect);

        if(iNum < 9)  qstrNum.push_front('0');
        painter.setPen(penText);
        painter.drawText(rect, Qt::AlignCenter, qstrNum);
        xp += iRadius + m_iSpacing;
    }
}
