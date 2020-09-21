#ifndef FILEVISITOR_H
#define FILEVISITOR_H

#include <QDir>
#include <QObject>
#include <QtDebug>
#include <QString>

class FileVisitor:public QObject
{
    Q_OBJECT
public:
    FileVisitor(QString nameFile="*",
                bool recursive=true,bool symlinks=false);
public slots:
    void processFileList(QStringList s1){};
    void processEntry(QFileInfo finfo)
    {
        qDebug() << (QString("Process (%1)").arg(finfo.fileName()));

        if(finfo.isDir())
        {
            QString dirname = finfo.fileName();
            if((dirname == ".")|| (dirname ==".."))
            {
                return;
            }
            QDir d(finfo.filePath());
            //if(skipDir(d)) return;
            processDir(d);

        }
        else {
            processFile(finfo.fileName());
        }
    }
    void processEntry(QString pathName)
    {
        QFileInfo finfo(pathName);
        processEntry(finfo);
    }
    void processDir(QDir &d)
    {
        QStringList filters;
        filters += m_nameFilter;
        d.setSorting(QDir::Name);
        QStringList files = d.entryList(filters,m_dirFilter);
        foreach(QString entry,files)
        {
            processEntry(d.filePath(entry));
        }

        if(m_recursive)
        {
            QStringList dirs = d.entryList(QDir::Dirs);
            foreach(QString dir,dirs)
            {
                processEntry(d.filePath(dir));
            }
        }
    }


signals:
    void foundFile(QString fileName);
protected:
    virtual void processFile(QString fileName)
    {
        qDebug() << QString("fileName (%1)").arg(fileName);
        emit foundFile(fileName);
    }

private:
    QString m_nameFilter;
    bool m_recursive;
    QDir::Filters m_dirFilter;
};







#endif // FILEVISITOR_H
