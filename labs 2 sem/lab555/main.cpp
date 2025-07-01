#include <QCoreApplication>
#include <QTextStream>
#include <QList>
#include <QMap>
#include <QMultiMap>
#include <ctime>
#include <algorithm>
#include <random>
#include <QDebug>

void printQList(const QList<int>& qlist)
{
    for (const auto& it : qlist)
    {
        qDebug() << it << " ";
    }
}

void printStdList(const std::list<int>& stdlist)
{
    for (const auto& it : stdlist)
    {
        qDebug() << it << " ";
    }
}

std::list<int> qListToStdList(const QList<int>& qlist)
{
    return std::list<int>(qlist.begin(), qlist.end());
}

QList<int> stdListToQList(const std::list<int>& stdlist)
{
    return QList<int>(stdlist.begin(), stdlist.end());
}

void qDeleteAll(QList<int>& qlist, QList<int>::iterator begin, QList<int>::iterator end)
{
    if (begin >= qlist.begin() && end <= qlist.end() && begin < end)
    {
        qlist.erase(begin, end);

        qDebug() << "The list after deleting the items:";
        printQList(qlist);
    }
    else
    {
        qDebug() << "Iterators are out of the acceptable range";
    }
}

int qLowerBound(QList<int>& qlist)
{
    if (qlist.isEmpty())
    {
        qDebug() << "The list is empty";
        return 1;
    }
    else
    {
        int minElement = qlist.first();
        for (const int& value : qlist)
        {
            if (value < minElement)
            {
                minElement = value;
            }
        }
        return minElement;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMultiMap<int, int> qmap;
    srand(time(NULL));

    QTextStream in(stdin);
    qDebug() << "Enter the size of qMultiMap, qList, stdList";
    int size;
    in >> size;

    if (size <= 0)
    {
        qDebug() << "Incorrect size input";

        return 1;
    }

    if  (size == 0)
    {
        qDebug() << "The list is empty";

        return 1;
    }

    for (auto i = 0; i < size; ++i)
    {
        int key =  rand() % 10 + 1;
        int value = rand() % 201 - 100;
        qmap.insert(key, value);
    }

    for (auto it = qmap.begin(); it != qmap.end(); ++it)
    {
        qDebug() << "Key:" << it.key() << "\t" << "Value:" << it.value();
    }

    QList<int> qList;
    for (auto i = 0; i < size; ++i)
    {
        qList.append(rand() % 201 - 100);
    }

    std::list<int> stdList = qListToStdList(qList);
    qDebug() << "stdList:";
    printStdList(stdList);

    QList<int> convertedList = stdListToQList(stdList);
    qDebug() << "ConvertedList:";
    printQList(convertedList);

    auto begin = qList.begin() + (size - 4);
    auto end = qList.begin() + (size - 2);
    qDeleteAll(qList, begin, end);

    qDebug() << "Finding the lower bound:";
    qDebug() << qLowerBound(qList);


    qDebug() << "Current status of the list:";
    printQList(qList);

    qDebug() << "Menu of the program:";
    qDebug() << "1. Add several elements to the specified position of the array";
    qDebug() << "2. Delete an element equal to the specified one";
    qDebug() << "3. Move part of the elements (range) to the specified position (splice)";
    qDebug() << "4. Shuffles the elements in a given range randomly, using the algorithm (random_shuffle)";
    qDebug() << "5. Changes the order of the elements to the opposite";
    qDebug() << "6. Exit the program";

    int choise;
    in >> choise;

    switch(choise)
    {
    case 1:
    {
        int position, count;
        qDebug() << "Enter the position to insert and the number of elements";
        in >> position >> count;

        QList<int> newElements;
        for (int i = 0; i < count; ++i)
        {
            newElements.append(rand() % 201 - 100);
        }

        for (int i = position; i < position + count; ++i)
        {
            qList.insert(i - 1, newElements.at(i - position));
        }

        printQList(qList);
        break;
    }

    case 2:
    {
        int element;
        qDebug() << "Enter the element you want to delete";
        in >> element;

        if (qList.contains(element))
        {
            qList.removeAll(element);
        }
        else
        {
            qDebug() << "The element is not contained in the list";
        }

        printQList(qList);
        break;
    }

    case 3:
    {
        int startPosition, endPosition, specifiedPosition;
        qDebug() << "Enter the start, end and specified position";
        in >> startPosition >> endPosition >> specifiedPosition;

        QList<int> movableElements = qList.mid(startPosition - 1, endPosition - startPosition + 1);

        if (startPosition < 0 || endPosition > qList.size() || startPosition < endPosition)
        {
            qDebug() << "Wrong positions";
        }
        else
        {
            for (int i = startPosition; i < endPosition; ++i)
            {
                qList.removeAt(startPosition - 1);
            }

            for (int i = movableElements.size() - 1; i >= 0; --i)
            {
                qList.insert(specifiedPosition - 1, movableElements.at(i));
            }
        }

        printQList(qList);
        break;
    }

    case 4:
    {
        int startPosition, endPosition;
        qDebug() << "Enter the start and end position";
        in >> startPosition >> endPosition;

        if (startPosition < 0 || endPosition > qList.size() || startPosition < endPosition)
        {
            qDebug() << "Wrong positions";
        }
        else
        {
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(qList.begin() + startPosition, qList.begin() + endPosition, g);
        }

        printQList(qList);
        break;
    }

    case 5:
    {
        for (int i = 0; i < qList.size() / 2; ++i)
        {
            qList.move(qList.first() + i, qList.last() - i);
        }

        printQList(qList);
        break;
    }

    case 6:
    {
        qDebug() << "Exit the program";
        break;
    }

    default:
    {
        qDebug() << "Wrong choise";
        break;
    }
    }

    return a.exec();
}
