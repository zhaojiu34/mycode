#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;


class Person
{
public:
    Person(string name = "")
    {
        _name = name;
        cout << "Person " << _name << " is created." << endl;
    }

    ~Person()
    {
        cout << "Person " << _name << " is erased." << endl;
    }
protected:
    string _name;
};

class Director : public Person
{
public:
    Director(string name = "")
        :Person(name)
    {

        cout << "Director " << _name << " is created." << endl;
    }

    ~Director()
    {
        cout << "Director " << _name << " is erased." << endl;
    }
};


class Actor : public Person
{
public:
    Actor(string name = "")
        :Person(name)
    {
        cout << "Actor " << _name << " is created." << endl;
    }

    ~Actor()
    {
        cout << "Actor " << _name << " is erased." << endl;
    }

};

class Film
{
public:
    Film(string directorName, string actorName, string filmName)
        :_director(directorName)
        , _actor(actorName)
        , _film(filmName)
    {
        cout << "Film " << _film << " is created." << endl;
    }
    ~Film()
    {
        cout << "Film " << _film << " is erased." << endl;
    }
private:
    Director _director;
    Actor _actor;
    string _film;
};
int main() {
    string directorName, actorName, filmName;
    cin >> directorName >> actorName >> filmName;
    Person person(directorName);
    Director director(directorName);
    Actor actor(actorName);
    Film film(directorName, actorName, filmName);
    return 0;
}

class Mark
{
public:

    void input()
    {
        int n = 0;
        cin >> n;

        _a.resize(n, 0);
        _score.resize(n, 0);

        int i = 0;
        for (i = 0; i < n; i++)
        {
            cin >> _score[i];
        }

        int j = 0;
        for (j = 0; j < n; j++)
        {
            cin >> _a[j];
        }

    }

    double getFinalMark()
    {
        double sum = 0.0;

        for (size_t i = 0; i < _a.size(); i++)
        {
            sum += _a[i] * _score[i];
        }

        return sum;
    }

private:
    vector<double> _a;
    vector<int> _score;
};
int main()
{
    Mark mark;
    mark.input();
    cout << mark.getFinalMark() << endl;
    return 0;
}