#ifndef ACID_H
#define ACID_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

#include <string>


class Acid {
public:
    Acid();

    Acid(const std::string &fullName, const std::string &shortName);

    Acid(Acid &acid);

    void setFullName(const std::string &fullName);

    void setShortName(const std::string &shortName);

    void printAcid();

    [[nodiscard]] const std::string &getFullName() const;

    [[nodiscard]] const std::string &getShortName() const;

private:
    std::string fullName_, shortName_;
};

#endif // ACID_H
