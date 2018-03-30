#include "person.h"

Person::Person()
{
}

QString Person::getName()
{return name;}
int Person::getAge()
{return age;}

bool Person::getGender()
{return gender;}
QString Person::getCity()
{return city;}
QString Person::getDistrict()
{return district;}

void Person::setName(QString m_name){name = m_name;}
void Person::setAge(int m_age){age = m_age;}
void Person::setGender(bool m_gender){gender = m_gender;}

void Person::setCity(QString m_city){city = m_city;}
void Person::setDistrict(QString m_district){district = m_district;}
