#ifndef PERSON_H
#define PERSON_H

#include <qstring.h>

class Person
{
public:
    Person();

    QString getName();
    int getAge();

    bool getGender();
    QString getCity();
    QString getDistrict();

    void setName(QString m_name);
    void setAge(int m_age);
    void setGender(bool m_gender);

    void setCity(QString m_city);
    void setDistrict(QString m_district);
private:

    QString name;
    int age;
    bool gender;

    QString city;
    QString district;

};

#endif // PERSON_H
