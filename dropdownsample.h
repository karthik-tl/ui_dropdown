#ifndef DROPDOWNSAMPLE_H
#define DROPDOWNSAMPLE_H

#include <QObject>
#include <QStringList>


class DropDownSample : public QObject
{
    Q_OBJECT
public:
    explicit DropDownSample(QObject *parent = nullptr);

    Q_PROPERTY(QStringList dropdownElements READ dropdownElements NOTIFY dropdownElementsChanged)


signals:
    void dropdownElementsChanged();



public slots:
    void onDropDownValueChanged(int index);
    void addNewElement();


private:
    QStringList m_dropdownElements;

    QStringList dropdownElements() const {
        return m_dropdownElements;
    }
};

#endif // DROPDOWNSAMPLE_H
