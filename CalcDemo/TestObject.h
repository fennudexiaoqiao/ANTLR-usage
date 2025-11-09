#ifndef TESTOBJECT_H
#define TESTOBJECT_H
#include <QObject>
class TestObject : public QObject
{
    Q_OBJECT
public:
    TestObject(QObject *parent = nullptr);
};

#endif // TESTOBJECT_H
