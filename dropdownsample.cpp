#include "dropdownsample.h"
#include <QDebug>
#include <QStorageInfo>



DropDownSample::DropDownSample(QObject *parent)
    : QObject{parent}
{

    QStorageInfo storage = QStorageInfo::root();

    // Check if the file system is ready
    if (storage.isValid()) {
        qDebug() << "File system name:" << storage.displayName();
        // Convert bytes to gigabytes
        double totalGB = static_cast<double>(storage.bytesTotal()) / (1024 * 1024 * 1024);
        double availableGB = static_cast<double>(storage.bytesAvailable()) / (1024 * 1024 * 1024);

        qDebug() << "Total space:" << totalGB << "GB";
        qDebug() << "Available space:" << availableGB << "GB";
    } else {
        qDebug() << "Invalid file system.";
    }

    for (int i = 1; i <= 5; ++i) {
        m_dropdownElements.append("Number " + QString::number(i));
    }
}

void DropDownSample::onDropDownValueChanged(int index)
{
    qDebug() << "Selected element: " << index + 1;

}

void DropDownSample::addNewElement() {
    int count = m_dropdownElements.count() + 1;
    m_dropdownElements.append("Number " + QString::number(count));
    emit dropdownElementsChanged();
}
