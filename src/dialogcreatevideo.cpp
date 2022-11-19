#include "dialogcreatevideo.h"
#include "ui_dialogcreatevideo.h"

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

DialogCreateVideo::DialogCreateVideo(QWidget *parent, DialogImageSerie::ImgSerie imgS) :
    QDialog(parent),
    ui(new Ui::DialogCreateVideo)
{
    ui->setupUi(this);
    this->ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setDisabled(true);

    ui->lineEditNamePrefix->setText(imgS.prefix);
    ui->lineEdit_Suffix->setText(imgS.suffix);

    ui->lineEditPath->setText(imgS.dirPath);
    ui->spinBoxNameItStart->setValue( imgS.nameStartConst );
    ui->spinBox_NameItStop->setValue( imgS.imgCountConst - 1 );



}

DialogCreateVideo::~DialogCreateVideo()
{
    delete ui;
}


QString DialogCreateVideo::getImgsPath()
{
    return ui->lineEditPath->text();
}

QString DialogCreateVideo::getPrefix()
{
    return ui->lineEditNamePrefix->text();
}

QString DialogCreateVideo::getSuffix()
{
    return ui->lineEdit_Suffix->text();
}

int DialogCreateVideo::getNameItStart()
{
    return ui->spinBoxNameItStart->value();
}

int DialogCreateVideo::getNameItEnd()
{
    return ui->spinBox_NameItStop->value();
}

int DialogCreateVideo::getFPS()
{
    return ui->spinBoxFPS->value();
}

QString DialogCreateVideo::getWaveAudio()
{
    return ui->lineEditAudioPath->text();
}

QString DialogCreateVideo::getFilePath()
{
    return ui->lineEditFilePath->text();
}

void DialogCreateVideo::on_pushButtonOpenSaveDir_clicked()
{
    QString dir_ = QFileDialog::getExistingDirectory( this, tr("Ordner auswählen"), this->ui->lineEditPath->text(), QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks );
    if(!dir_.isEmpty()) {
        this->ui->lineEditPath->setText( dir_ );
    }
}


void DialogCreateVideo::on_lineEditPath_textChanged(const QString &arg1)
{
    if(arg1 != "" && QDir(arg1).exists() && !QFile(ui->lineEditFilePath->text()).exists() && ui->lineEditFilePath->text() != "" ) {
        this->ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setDisabled(false);
    } else {
        this->ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setDisabled(true);
    }
}


void DialogCreateVideo::on_lineEditFilePath_textChanged(const QString &arg1)
{
    if(!QFile(arg1).exists() && arg1 != "" && ui->lineEditPath->text() != "" && QDir(ui->lineEditPath->text()).exists()) {
        this->ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setDisabled(false);
    } else {
        this->ui->buttonBox->button(QDialogButtonBox::StandardButton::Ok)->setDisabled(true);
    }
}


void DialogCreateVideo::on_pushButton_2_clicked()
{
    QString file = QFileDialog::getSaveFileName( this, tr("Video speichern in"), getImgsPath(), ".avi" );
    if(!file.isEmpty()) {
        ui->lineEditFilePath->setText(file);
    }
}

